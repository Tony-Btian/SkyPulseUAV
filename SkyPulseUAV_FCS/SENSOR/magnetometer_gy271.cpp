#include "magnetometer_gy271.h"
#include <QtDebug>

Magnetometer_GY271::Magnetometer_GY271(uint8_t i2cAddress, QObject *parent)
    : QObject(parent), i2cDevice(nullptr)
{
    this->i2cDevice = new I2C_Device(i2cAddress, this);
    if (!this->i2cDevice){
        qWarning("Failed to create I2C device for GY271");
        return;
    }

    if (this->initializeGY271()){
//        qWarning("GY271 Initialize Successful");
    }
    else{
        qWarning("GY271 Initialize Failed");
    }
}

bool Magnetometer_GY271::initializeGY271()
{
    connect(i2cDevice, &I2C_Device::errorOccurred, this, &Magnetometer_GY271::handleI2CError);
    /*Configuration register*/
    if (!writeByte(0x00, 0x70) // Configure register A for 8 average, 15Hz default, normal measurement
        || !writeByte(0x01, 0xA0) // Configuration Gain
        || !writeByte(0x02, 0x00)) { // Continuous measurement mode
        emit sig_errorOccurred("Failed to write configuration to Magnetometer GY271");
        return false;
    }
    return true;
}

bool Magnetometer_GY271::writeByte(uint8_t reg, uint8_t value)
{
    return i2cDevice->writeByte(reg, value);
}

void Magnetometer_GY271::readRawData()
{
    QByteArray data = i2cDevice->readBytes(0x03, 6);
    if (data.size() == 6) {
        int x = convertToRawData(data, 0);
        int y = convertToRawData(data, 2);
        int z = convertToRawData(data, 4);
        emit sig_rawDataRead(x, y, z);
        qDebug() << "GY271 Direction: " << x << "," << y << "," << z;
    }
    else{
        qWarning() << "Failed to read data from the device";
        emit sig_errorOccurred("Failed to read data from Magnetometer GY271.");
    }
}

int16_t Magnetometer_GY271::convertToRawData(const QByteArray& bytes, int offset)
{
    int16_t value = static_cast<int16_t>((bytes[offset] << 8) | (bytes[offset + 1] & 0xFF));
    return value;
}

void Magnetometer_GY271::handleI2CError(QString error)
{
    qWarning() << "I2C error: " << error;
    // Put another code her to deal with the handle I2C error
}
