#include "sensormanager.h"
#include <QDebug>

SensorManager::SensorManager()
{
    SENSOR_Initial();
}

SensorManager::~SensorManager()
{
    delete MPU6050_HANDLE;
    delete BMP180_HANDLE;
    delete GY271_HANDLE;
}

void SensorManager::SENSOR_Initial()
{
    MPU6050_HANDLE = new MPU6050(MPU6059_DEVICE_ADDR, this);
    BMP180_HANDLE = new BMP180(BMP180_DEVICE_ADDR, this);
    GY271_HANDLE = new GY271(GY271_DEVICE_ADDR, this);
}

void SensorManager::ReadAllSensorData()
{
    QtConcurrent::run([this]() {
        qDebug() << "Starting sensor read operation in a separate thread" << QThread::currentThreadId();
        int x, y, z;
        float ax, ay, az, gx, gy, gz;
        double pressure, temperature, headingDegree;

        MPU6050_HANDLE->readAllSensors(ax, ay, az, gx, gy, gz);
        BMP180_HANDLE->readPressure(pressure);
        BMP180_HANDLE->readTemperature(temperature);
        GY271_HANDLE->readRawData(x, y, z, headingDegree);

        emit updateSensorData(ax, ay, az, gx, gy, gz, pressure, temperature, x, y, z, headingDegree);
        packageAndSendSensorData(ax, ay, az, gx, gy, gz, pressure, temperature, x, y, z, headingDegree);
    });
}

void SensorManager::packageAndSendSensorData(float ax, float ay, float az, float gx, float gy, float gz, double pressure, double temperature, int x, int y, int z, double heading)
{
    QByteArray buffer;
    QDataStream stream(&buffer, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::LittleEndian);
    stream << ax << ay << az << gx << gy << gz << pressure << temperature << x << y << z << heading;
    emit sig_sendMessage64Bytes(buffer);
}
