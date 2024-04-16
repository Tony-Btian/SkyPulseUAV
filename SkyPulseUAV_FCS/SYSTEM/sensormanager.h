#ifndef SENSORMANAGER_H
#define SENSORMANAGER_H

#define MPU6059_DEVICE_ADDR 0x68
#define BMP180_DEVICE_ADDR 0x77
#define GY271_DEVICE_ADDR 0x0D

#include <QObject>
#include <QThreadPool>
#include <QtConcurrent/QtConcurrent>

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
    void packageAndSendSensorData(float ax, float ay, float az, float gx, float gy, float gz, double pressure, double temperature, int x, int y, int z, double heading);

public slots:
    void ReadAllSensorData();

signals:
    void updateSensorData(float ax, float ay, float az, float gx, float gy, float gz, double pressure, double temperature, int x, int y, int z, double heading);
    void sig_sendMessage64Bytes(QByteArray data_buffer);
};

#endif // SENSORMANAGER_H
