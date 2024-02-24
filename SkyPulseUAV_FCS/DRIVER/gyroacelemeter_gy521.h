#ifndef GYROACELEMETER_GY521_H
#define GYROACELEMETER_GY521_H

#include <QObject>
#include <QFutureWatcher>
#include "i2c_device.h"

// MPU6050 I2C Device Address
#define MPU6050_ADDR 0x68

// MPU6050 Reg Address
#define PWR_MGMT_1   0x6B
#define ACCEL_XOUT_H 0x3B
#define GYRO_XOUT_H  0x43

#define MPU6050_ADDR 0x68
#define ACCEL_CONFIG 0x1C
#define GYRO_CONFIG  0x1B

//class GyroAcelemeter_GY521 : public QObject
//{
//    Q_OBJECT

//public:
//    explicit GyroAcelemeter_GY521(QObject *parent = nullptr);
//    ~GyroAcelemeter_GY521();

//private:
//    I2C_Device *i2cdevice;
//    QFutureWatcher<void> watcher;
//    QAtomicInt _stop;
//};

// MPU6050Data Struct Definition
struct MPU6050Data{
    float ax, ay, az; // Accelerometer
    float gx, gy, gz; // Gyroscope
};

bool initMPU6050(int handle);
MPU6050Data readMPU6050Data(int handle);
int readAccelRange(int handle);
int readGyroRange(int handle);

#endif // GYROACELEMETER_GY521_H
