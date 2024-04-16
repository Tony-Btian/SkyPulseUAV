#include "gy271.h"

GY271::GY271(uint8_t i2cAddress, QObject *parent)
    : QObject(parent), i2cDriver(new I2CDriver(i2cAddress, this))
{
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
    if (!i2cDriver->writeByte(0x0B, 0x01) // Configure register A for 8 average, 15Hz default, normal measurement
        || !i2cDriver->writeByte(0x09, 0x1D)) { // Configuration Gain
        qWarning("Failed to write configuration to Magnetometer GY271");
        return false;
    }
    return true;
}

double GY271::readHeading(int x, int y)
{
    double headingRadians = atan2(double(y), double(x)); // Calculate the angle in radians
    double headingDegrees = headingRadians * (180.0 / M_PI); // Convert to degrees

    // Normalize to 0-360 degrees
    if (headingDegrees < 0) {
        headingDegrees += 360.0;
    }
    return headingDegrees;
}

void GY271::readRawData(int &x, int &y, int &z, double &headingDegree)
{
    QByteArray data = i2cDriver->readBytes(0x00, 6);
    if (data.size() == 6) {
        x = convertToRawData(data, 0);
        y = convertToRawData(data, 2);
        z = convertToRawData(data, 4);
        headingDegree = readHeading(x, y);
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
