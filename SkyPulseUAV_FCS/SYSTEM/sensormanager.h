#ifndef SENSORMANAGER_H
#define SENSORMANAGER_H

#define MPU6059_DEVICE_ADDR 0x68
#define BMP180_DEVICE_ADDR 0x77
#define GY271_DEVICE_ADDR 0x0D

#include <QObject>
#include "mpu6050.h"
#include "bmp180.h"
#include "gy271.h"

class SensorManager : public QObject
{
    Q_OBJECT

public:
    SensorManager();
    ~SensorManager();

private:
    MPU6050 *MPU6050_HANDLE;
    BMP180 *BMP180_HANDLE;
    GY271 *GY271_HANDLE;

    void SENSOR_Initial();

public slots:
    void ReadAllSensorData();

};

#endif // SENSORMANAGER_H
