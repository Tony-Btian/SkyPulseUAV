#include "mahonyfilter.h"

MahonyFilter::MahonyFilter(float sampleFrequency, float twoKpDef, float twoKiDef, QObject *parent)
{

}

MahonyFilter::~MahonyFilter()
{

}

void MahonyFilter::updateData(const QVector3D &accel, const QVector3D &gyro, const QVector3D &magneto)
{
    QMutexLocker locker(&dataMutex); // Ensuring thread safety
    accelData = accel;
    gyroData = gyro;
    magnetoData = magneto;
    emit newDataReady(); // Notification data updated
}

void MahonyFilter::process() {
    QMutexLocker locker(&dataMutex);
    // Here the Mahony algorithm is called to process accelData, gyroData, magnetoData
    // Suppose the processing yields roll, pitch, yaw
    float roll = 0.0, pitch = 0.0, yaw = 0.0;

    // Extract roll, pitch, yaw values from the algorithm

    emit newAngleData(roll, pitch, yaw); // Transmit new angle data signal
}
