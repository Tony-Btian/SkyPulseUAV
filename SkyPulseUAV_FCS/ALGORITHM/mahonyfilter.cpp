#include "mahonyfilter.h"
#include <cmath>

MahonyFilter::MahonyFilter(float sampleFrequency, float twoKpDef, float twoKiDef, QObject *parent)
    : QObject(parent),
      sampleFreq(sampleFrequency),
      twoKp(twoKpDef),
      twoKi(twoKiDef),
      q(1, 0, 0, 0), // Identity quaternion
      integralFB(0, 0, 0) // Zero integral feedback initially
{
}


MahonyFilter::~MahonyFilter()
{

}

// Set the frequency of the IMU data updates
void MahonyFilter::setFrequency(float frequency)
{
    sampleFreq = frequency;
}

// Set the proportional gain (Kp)
void MahonyFilter::setKp(float kp)
{
    twoKp = 2.0f * kp;
}

// Set the integral gain (Ki)
void MahonyFilter::setKi(float ki)
{
    twoKi = 2.0f * ki;
}

// Update IMU data
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
    imuDataReady = true;
    emit newDataReady();
}

// Register callback for type A notifications
void MahonyFilter::registerCallbackA(CallbackFunction callback)
{
    callbackA_ = callback;
}

// Register callback for type B notifications
void MahonyFilter::registerCallbackB(CallbackFunction callback)
{
    callbackB_ = callback;
}

// Mahony AHRS algorithm update (with magnetometer)
void MahonyFilter::MahonyAHRSupdate(float gx, float gy, float gz, float ax, float ay, float az, float mx, float my, float mz)
{

}

// Mahony AHRS algorithm update (without magnetometer)
void MahonyFilter::MahonyAHRSupdateIMU(float gx, float gy, float gz, float ax, float ay, float az) {

}

// Calculate the reciprocal of the square root
float MahonyFilter::invSqrt(float x) {
    return 1.0f / std::sqrt(x);
}

// Process sensor data and notify listeners
void MahonyFilter::process() {
    if (imuDataReady) {
        float roll, pitch, yaw; // Variables to hold computed angles

        if (callbackA_) {
            callbackA_(this, roll, pitch, yaw, gyroData);
        }
        if (callbackB_) {
            callbackB_(this, roll, pitch, yaw, gyroData);
        }

        emit newAngleData(roll, pitch, yaw);
    }
}

// Qt Slot to receive new IMU data directly as QVector3D objects
void MahonyFilter::updateData(const QVector3D &accel, const QVector3D &gyro, const QVector3D &magneto) {
    updateIMUData(accel.x(), accel.y(), accel.z(), gyro.x(), gyro.y(), gyro.z(), magneto.x(), magneto.y(), magneto.z());
}
