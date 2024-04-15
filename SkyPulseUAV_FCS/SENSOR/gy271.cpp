#include "gy271.h"
#include <QDebug>

GY271::GY271(uint8_t i2cAddress, QObject *parent)
    : QObject(parent), i2cDriver(nullptr)
{
    this->i2cDriver = new I2CDriver(i2cAddress, this);
    if (!this->i2cDriver){
        qWarning("Failed to create I2C device for GY271");
        return;
    }
    if (this->initializeGY271()){
        qWarning("GY271 Config Successful");
    }
    else{
        qWarning("GY271 Config Failed");
    }
}

bool GY271::initializeGY271()
{
    /*Configuration register*/
    if (!writeByte(0x00, 0x70) // Configure register A for 8 average, 15Hz default, normal measurement
        || !writeByte(0x01, 0xA0) // Configuration Gain
        || !writeByte(0x02, 0x00)) { // Continuous measurement mode
        qWarning("Failed to write configuration to Magnetometer GY271");
        return false;
    }
    return true;
}

bool GY271::writeByte(uint8_t reg, uint8_t value)
{
    return i2cDriver->writeByte(reg, value);
}

void GY271::readRawData(int &x, int &y, int &z)
{
    QByteArray data = i2cDriver->readBytes(0x03, 6);
    if (data.size() == 6) {
        x = convertToRawData(data, 0);
        y = convertToRawData(data, 2);
        z = convertToRawData(data, 4);
    }
    else{
        qWarning("Failed to read data from the device");
    }
}

int16_t GY271::convertToRawData(const QByteArray& bytes, int offset)
{
    int16_t value = static_cast<int16_t>((bytes[offset] << 8) | (bytes[offset + 1] & 0xFF));
    return value;
}
