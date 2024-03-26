#include "gyroacelemeter_gy521.h"
#include <QDebug>

MPU6050::MPU6050(uint8_t i2cAddress, QObject *parent)
    : QObject(parent), i2cDevice(nullptr)
{
    this->i2cDevice = new I2C_Device(i2cAddress, this);  // Create an instance os I2C_Device using the provided I2C address
    if(!this->i2cDevice){
        qDebug() << "Failed to create I2C device for MPU6050";
        return;
    }

    // Write to registers to initialise the sensor
    if(!writeByte(PWR_MGMT_1, 0x00)){  // Wake up the device by writing 0 to the power management register.
        qDebug() << "MPU6050 wake up failed.";
    }
    if(!writeByte(INT_ENABLE, 0x01)){  // Enable Data Ready interrupt
        qDebug() << "MPU6050 enable interrupt failed";
    }
    if(!writeByte(INT_PIN_CFG, 0x30)){  // Configure interrupt pin to be active high, push-pull, hold until cleared, clear on read
        qDebug() << "MPU6050 configure interrupt pin failed";
    }
}

void MPU6050::readAllSensors(float &ax, float &ay, float &az, float &gx, float &gy, float &gz) {
    uint8_t buffer[14];
    if (readBytes(ACCEL_XOUT_H, buffer, sizeof(buffer))) {
        ax = (float)((int16_t)(buffer[0] << 8 | buffer[1])) / ACCEL_FS_SEL_2G;
        ay = (float)((int16_t)(buffer[2] << 8 | buffer[3])) / ACCEL_FS_SEL_2G;
        az = (float)((int16_t)(buffer[4] << 8 | buffer[5])) / ACCEL_FS_SEL_2G;
        // Skipping temperature bytes buffer[6] and buffer[7]
        gx = (float)((int16_t)(buffer[8] << 8 | buffer[9])) / GYRO_FS_SEL_250DEG;
        gy = (float)((int16_t)(buffer[10] << 8 | buffer[11])) / GYRO_FS_SEL_250DEG;
        gz = (float)((int16_t)(buffer[12] << 8 | buffer[13])) / GYRO_FS_SEL_250DEG;
    }
}

bool MPU6050::writeByte(uint8_t reg, uint8_t value) {
    return i2cDevice->writeBytes(reg, QByteArray(1, value));
}

bool MPU6050::readBytes(uint8_t reg, uint8_t *buffer, size_t length) {
    QByteArray data = i2cDevice->readBytes(reg, length);
    if (data.size() == length) {
        memcpy(buffer, data.data(), length);
        return true;
    }
    return false;
}

void MPU6050::readAllMPU6050Reg()
{
    qDebug() << "Read all reg action!";
}
