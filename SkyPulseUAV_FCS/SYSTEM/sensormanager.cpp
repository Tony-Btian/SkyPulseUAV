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
    qWarning("Function Button 1 Click");
    int x, y, z;
    float ax, ay, az, gx, gy, gz;
    double pressure, tempreture;

    MPU6050_HANDLE->readAllSensors(ax, ay, az, gx, gy, gz);
    BMP180_HANDLE->readPressure(pressure);
    BMP180_HANDLE->readTemperature(tempreture);
    GY271_HANDLE->readRawData(x, y, z);

    qDebug() << "Acceleration:" << ax << ay << az;
    qDebug() << "Gyroscope:" << gx << gy << gz;
    qDebug() << "Presure:" << pressure;
    qDebug() << "Temperature:" << tempreture;
    qDebug() << "Direction: " << x << "," << y << "," << z;
}
