#ifndef GYROACELEMETER_GY521_H
#define GYROACELEMETER_GY521_H

#include <QObject>
#include "i2c_device.h"


class MPU6050 : public I2C_Device
{
    Q_OBJECT

public:
    explicit MPU6050 (int deviceAddress, QObject *parent = nullptr);
    bool initialize();
    bool readAcceleration(float &ax, float &ay, float &az);
    bool readGyroscope(float &gx, float &gy, float &gz);

private:
    bool writeByte(uint8_t reg, uint8_t value);
    bool readBytes(uint8_t reg, uint8_t *buffer, size_t length);

    float accelScaleFactor;
    float gyroScaleFactor;

    // MPU-6050 Register Addresses
    static constexpr uint8_t PWR_MGMT_1 = 0x6B;
    static constexpr uint8_t ACCEL_XOUT_H = 0x3B;
    static constexpr uint8_t GYRO_XOUT_H = 0x43;

    // Scale factors
    static constexpr float ACCEL_FS_SEL_2G = 16384.0;
    static constexpr float GYRO_FS_SEL_250DEG = 131.0;

};

#endif // GYROACELEMETER_GY521_H
