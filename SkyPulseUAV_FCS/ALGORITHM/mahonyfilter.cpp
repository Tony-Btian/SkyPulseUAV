#include "mahonyfilter.h"
#include <cmath>

MahonyFilter::MahonyFilter(float sampleFrequency, float propGain, float intGain, QObject *parent)
    : QObject(parent),
      twoKp(2.0f * propGain),   // Update to use the provided proportional gain
      twoKi(2.0f * intGain),    // Update to use the provided integral gain
      frequency(sampleFrequency),
      q{1, 0, 0, 0},            // Identity quaternion
      integralFBx(0), integralFBy(0), integralFBz(0), // Zero integral feedback initially
      roll(0), pitch(0), yaw(0), // Atomic floats initialized to zero
      mpu_data_ready(false)     // Initialize data ready flag to false
{
}

MahonyFilter::~MahonyFilter()
{

}

void MahonyFilter::setFrequency(float f)
{
    frequency = f;
}

void MahonyFilter::setKp(float kp)
{
    twoKp = 2.0f * kp;
}

void MahonyFilter::setKi(float ki)
{
    twoKi = 2.0f * ki;
}

void MahonyFilter::updateIMUData(float ax, float ay, float az, float gx, float gy, float gz, float mx, float my, float mz)
{
    QMutexLocker locker(&dataMutex); // Protect data access
    this->ax = ax;
    this->ay = ay;
    this->az = az;
    this->gx = gx;
    this->gy = gy;
    this->gz = gz;
    this->mx = mx;
    this->my = my;
    this->mz = mz;
    mpu_data_ready = true;
}

void MahonyFilter::registerCallbackA(CallbackFunction callback)
{
    callbackA_ = callback;
}

void MahonyFilter::registerCallbackB(CallbackFunction callback)
{
    callbackB_ = callback;
}

void MahonyFilter::MahonyAHRSupdate(float gx, float gy, float gz, float ax, float ay, float az, float mx, float my, float mz)
{
    // Disable data flag until next update
    mpu_data_ready = false;

    float recipNorm;
    float q0q0, q0q1, q0q2, q0q3, q1q1, q1q2, q1q3, q2q2, q2q3, q3q3;
    float hx, hy, bx, bz;
    float halfvx, halfvy, halfvz, halfwx, halfwy, halfwz;
    float halfex, halfey, halfez;
    float qa, qb, qc;

    // Only use magnetometer data if it's valid (avoids NaN in normalization)
    if ((mx == 0.0f) && (my == 0.0f) && (mz == 0.0f)) {
        MahonyAHRSupdateIMU(gx, gy, gz, ax, ay, az);
        return;
    }

    // Normalize accelerometer (this is safe as we already checked for zero length vector)
    recipNorm = invSqrt(ax * ax + ay * ay + az * az);
    ax *= recipNorm;
    ay *= recipNorm;
    az *= recipNorm;

    // Normalize magnetometer
    recipNorm = invSqrt(mx * mx + my * my + mz * mz);
    mx *= recipNorm;
    my *= recipNorm;
    mz *= recipNorm;

    // Auxiliary variables to avoid repeated calculations
    q0q0 = q[0] * q[0];
    q0q1 = q[0] * q[1];
    q0q2 = q[0] * q[2];
    q0q3 = q[0] * q[3];
    q1q1 = q[1] * q[1];
    q1q2 = q[1] * q[2];
    q1q3 = q[1] * q[3];
    q2q2 = q[2] * q[2];
    q2q3 = q[2] * q[3];
    q3q3 = q[3] * q[3];

    // Reference directions of Earth's magnetic field
    hx = 2.0f * (mx * (0.5f - q2q2 - q3q3) + my * (q1q2 - q0q3) + mz * (q1q3 + q0q2));
    hy = 2.0f * (mx * (q1q2 + q0q3) + my * (0.5f - q1q1 - q3q3) + mz * (q2q3 - q0q1));
    bx = sqrt(hx * hx + hy * hy);
    bz = 2.0f * (mx * (q1q3 - q0q2) + my * (q2q3 + q0q1) + mz * (0.5f - q1q1 - q2q2));

    // Estimated direction of gravity and magnetic field
    halfvx = q1q3 - q0q2;
    halfvy = q0q1 + q2q3;
    halfvz = q0q0 - 0.5f + q3q3;
    halfwx = bx * (0.5f - q2q2 - q3q3) + bz * (q1q3 - q0q2);
    halfwy = bx * (q1q2 - q0q3) + bz * (q0q1 + q2q3);
    halfwz = bx * (q0q2 + q1q3) + bz * (0.5f - q1q1 - q2q2);

    // Error is sum of cross product between estimated direction and measured direction of field vectors
    halfex = (ay * halfvz - az * halfvy) + (my * halfwz - mz * halfwy);
    halfey = (az * halfvx - ax * halfvz) + (mz * halfwx - mx * halfwz);
    halfez = (ax * halfvy - ay * halfvx) + (mx * halfwy - my * halfwx);

    // Integral feedback if enabled
    if (twoKi > 0.0f) {
        integralFBx += twoKi * halfex * (1.0f / frequency);  // integral error scaled by Ki
        integralFBy += twoKi * halfey * (1.0f / frequency);
        integralFBz += twoKi * halfez * (1.0f / frequency);
        gx += integralFBx;  // apply integral feedback
        gy += integralFBy;
        gz += integralFBz;
    } else {
        integralFBx = 0.0f;  // prevent integral windup
        integralFBy = 0.0f;
        integralFBz = 0.0f;
    }

    // Apply proportional feedback
    gx += twoKp * halfex;
    gy += twoKp * halfey;
    gz += twoKp * halfez;

    // Integrate rate of change of quaternion
    gx *= (0.5f * (1.0f / frequency));  // pre-multiply common factors
    gy *= (0.5f * (1.0f / frequency));
    gz *= (0.5f * (1.0f / frequency));
    qa = q[0];
    qb = q[1];
    qc = q[2];
    q[0] += (-qb * gx - qc * gy - q[3] * gz);
    q[1] += (qa * gx + qc * gz - q[3] * gy);
    q[2] += (qa * gy - qb * gz + q[3] * gx);
    q[3] += (qa * gz + qb * gy - qc * gx);

    // Normalize quaternion
    recipNorm = invSqrt(q[0] * q[0] + q[1] * q[1] + q[2] * q[2] + q[3] * q[3]);
    q[0] *= recipNorm;
    q[1] *= recipNorm;
    q[2] *= recipNorm;
    q[3] *= recipNorm;
}

void MahonyFilter::MahonyAHRSupdateIMU(float gx, float gy, float gz, float ax, float ay, float az)
{
    // Here you would add the implementation details of the Mahony AHRS IMU update algorithm
}

float MahonyFilter::invSqrt(float x) {
    return 1.0f / std::sqrt(x);
}

void MahonyFilter::process() {
    if (mpu_data_ready) {
        float roll, pitch, yaw; // Variables to hold computed angles

        // Compute angles here using update functions
        MahonyAHRSupdateIMU(gx, gy, gz, ax, ay, az);

        if (callbackA_) {
            callbackA_(roll, pitch, yaw, {gx, gy, gz});
        }
        if (callbackB_) {
            callbackB_(roll, pitch, yaw, {gx, gy, gz});
        }

        emit newAngleData(roll, pitch, yaw);
    }
}

void MahonyFilter::updateData(const QVector3D &accel, const QVector3D &gyro, const QVector3D &magneto) {
    updateIMUData(accel.x(), accel.y(), accel.z(), gyro.x(), gyro.y(), gyro.z(), magneto.x(), magneto.y(), magneto.z());
}
