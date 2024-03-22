#include "gyroacelemeter_gy521.h"

MPU6050::MPU6050(int deviceAddress, QObject *parent)
    : I2C_Device(deviceAddress, parent), accelScaleFactor(ACCEL_FS_SEL_2G), gyroScaleFactor(GYRO_FS_SEL_250DEG) {
}

bool MPU6050::initialize() {
    // Wake the device up from sleep mode
    return writeByte(PWR_MGMT_1, 0x00);
}

bool MPU6050::writeByte(uint8_t reg, uint8_t value) {
//    return this->write(reg, &value, 1);
}

bool MPU6050::readBytes(uint8_t reg, uint8_t *buffer, size_t length) {
//    return this->read(reg, buffer, length);
}

bool MPU6050::readAcceleration(float &ax, float &ay, float &az) {
    uint8_t buffer[6];
    if (!readBytes(ACCEL_XOUT_H, buffer, sizeof(buffer))) {
        return false;
    }

    ax = (float)((int16_t)(buffer[0] << 8 | buffer[1])) / accelScaleFactor;
    ay = (float)((int16_t)(buffer[2] << 8 | buffer[3])) / accelScaleFactor;
    az = (float)((int16_t)(buffer[4] << 8 | buffer[5])) / accelScaleFactor;

    return true;
}

bool MPU6050::readGyroscope(float &gx, float &gy, float &gz) {
    uint8_t buffer[6];
    if (!readBytes(GYRO_XOUT_H, buffer, sizeof(buffer))) {
        return false;
    }

    gx = (float)((int16_t)(buffer[0] << 8 | buffer[1])) / gyroScaleFactor;
    gy = (float)((int16_t)(buffer[2] << 8 | buffer[3])) / gyroScaleFactor;
    gz = (float)((int16_t)(buffer[4] << 8 | buffer[5])) / gyroScaleFactor;

    return true;
}
