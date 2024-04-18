#include "mahonyfilter.h"


MahonyFilter::MahonyFilter(float sampleFrequency, float twoKpDef, float twoKiDef, QObject *parent)
    : QObject(parent),
      sampleFreq(sampleFrequency),
      twoKp(twoKpDef),
      twoKi(twoKiDef),
      q(1, 0, 0, 0),
      integralFB(0, 0, 0) {}

MahonyFilter::~MahonyFilter(){}


void MahonyFilter::setFrequency(float frequency)
{
    sampleFreq = frequency;
}

void MahonyFilter::setKp(float kp)
{
    twoKp = 2.0f * kp;
}

void MahonyFilter::setKi(float ki)
{
    twoKi = 2.0f * ki;
}

void MahonyFilter::updateIMUData(float ax, float ay, float az,
                                 float gx, float gy, float gz,
                                 float mx, float my, float mz)
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
}

void MahonyFilter::updateData(const QVector3D &accel, const QVector3D &gyro, const QVector3D &magneto) {
    updateIMUData(accel.x(), accel.y(), accel.z(), gyro.x(), gyro.y(), gyro.z(), magneto.x(), magneto.y(), magneto.z());
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
    float recipNorm;
    float q0q0, q0q1, q0q2, q0q3, q1q1, q1q2, q1q3, q2q2, q2q3, q3q3;
    float hx, hy, bx, bz;
    float halfvx, halfvy, halfvz, halfwx, halfwy, halfwz;
    float halfex, halfey, halfez;
    float qa, qb, qc;

    // Normalize accelerometer measurement
    recipNorm = invSqrt(ax * ax + ay * ay + az * az);
    ax *= recipNorm;
    ay *= recipNorm;
    az *= recipNorm;

    // Normalize magnetometer measurement
    recipNorm = invSqrt(mx * mx + my * my + mz * mz);
    mx *= recipNorm;
    my *= recipNorm;
    mz *= recipNorm;

    // Auxiliary variables to avoid repeated arithmetic
    q0q0 = q.scalar() * q.scalar();
    q0q1 = q.scalar() * q.x();
    q0q2 = q.scalar() * q.y();
    q0q3 = q.scalar() * q.z();
    q1q1 = q.x() * q.x();
    q1q2 = q.x() * q.y();
    q1q3 = q.x() * q.z();
    q2q2 = q.y() * q.y();
    q2q3 = q.y() * q.z();
    q3q3 = q.z() * q.z();

    // Reference direction of Earth's magnetic field
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

    // Compute and apply integral feedback if non-zero gain
    if (twoKi > 0.0f) {
        integralFB += QVector3D(twoKi * halfex * (1.0f / sampleFreq), twoKi * halfey * (1.0f / sampleFreq), twoKi * halfez * (1.0f / sampleFreq));
        gx += integralFB.x();  // Apply integral feedback
        gy += integralFB.y();
        gz += integralFB.z();
    }

    // Apply proportional feedback
    gx += twoKp * halfex;
    gy += twoKp * halfey;
    gz += twoKp * halfez;

    // Integrate rate of change of quaternion
    gx *= (0.5f * (1.0f / sampleFreq));  // Pre-multiply common factors
    gy *= (0.5f * (1.0f / sampleFreq));
    gz *= (0.5f * (1.0f / sampleFreq));
    qa = q.scalar();
    qb = q.x();
    qc = q.y();
    q.setScalar(q.scalar() + (-qb * gx - qc * gy - q.z() * gz));
    q.setX(q.x() + (qa * gx + qc * gz - q.z() * gy));
    q.setY(q.y() + (qa * gy - qb * gz + q.z() * gx));
    q.setZ(q.z() + (qa * gz + qb * gy - qc * gx));

    // Normalize quaternion
    recipNorm = invSqrt(q.scalar() * q.scalar() + q.x() * q.x() + q.y() * q.y() + q.z() * q.z());
    q.setScalar(q.scalar() * recipNorm);
    q.setX(q.x() * recipNorm);
    q.setY(q.y() * recipNorm);
    q.setZ(q.z() * recipNorm);
}

void MahonyFilter::MahonyAHRSupdateIMU(float gx, float gy, float gz, float ax, float ay, float az)
{
    // Here you would add the implementation details of the Mahony AHRS IMU update algorithm
}

float MahonyFilter::invSqrt(float x) {
    float halfx = 0.5f * x;
    float y = x;
    int32_t i = *(int32_t*)&y;
    i = 0x5f3759df - (i >> 1);
    y = *(float*)&i;
    y = y * (1.5f - (halfx * y * y));
    return y;
}

void MahonyFilter::process() {
    float roll, pitch, yaw; // Variables to hold computed angles

    // Compute angles here using update functions
    MahonyAHRSupdateIMU(gx, gy, gz, ax, ay, az);

    roll = atan2(2.0f * (q.y() * q.z() + q.scalar() * q.x()), q.scalar() * q.scalar() - q.x() * q.x() - q.y() * q.y() + q.z() * q.z());
    pitch = asin(-2.0f * (q.x() * q.z() - q.scalar() * q.y()));
    yaw = atan2(2.0f * (q.x() * q.y() + q.scalar() * q.z()), q.scalar() * q.scalar() + q.x() * q.x() - q.y() * q.y() - q.z() * q.z());

    emit newAngleData(roll, pitch, yaw);
    emit newDataReady();

    if (callbackA_) {
        // Corrected callback invocation
        callbackA_(this, roll, pitch, yaw, {gx, gy, gz});
    }
    if (callbackB_) {
        // Assuming callbackB_ has the same signature
        callbackB_(this, roll, pitch, yaw, {gx, gy, gz});
    }
}
