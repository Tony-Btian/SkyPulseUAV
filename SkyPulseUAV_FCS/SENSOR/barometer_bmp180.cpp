#include "barometer_bmp180.h"
#include <QDebug>

Barometer_BMP180::Barometer_BMP180(uint8_t i2cAddress, QObject *parent)
    : QObject(parent), i2cDevice(nullptr)
{
    this->i2cDevice = new I2C_Device(i2cAddress, this);  // Create an instance os I2C_Device using the provided I2C address
    if(!this->i2cDevice){
        qWarning("Failed to create I2C device for BMP180");
        return;
    }

    if(!readCalibrationData()){
        emit errorOccurred("Failed to read calibration data from BMP180.");
    }
}

void Barometer_BMP180::readPressure()
{
    if (!i2cDevice) {
        emit errorOccurred("I2C device is not initialized.");
        return;
    }

    quint8 reg = 0xF6;
    quint8 count = 3;
    QByteArray rawData = i2cDevice->readBytes(reg, count);

    if (rawData.size() == count) {
        int rawPressure = (static_cast<unsigned char>(rawData[0]) << 16 |
                           static_cast<unsigned char>(rawData[1]) << 8 |
                           static_cast<unsigned char>(rawData[2])) >> (8 /* oversampling_setting */);
        double pressure = calculatePressure(rawPressure);
        emit pressureRead(pressure);
    } else {
        emit errorOccurred("Failed to read pressure data from BMP180.");
    }
}

void Barometer_BMP180::readTemperature()
{
    if (!i2cDevice) {
        emit errorOccurred("I2C device is not initialized.");
        return;
    }
    // Write temperature measurement commands to the BMP180
    if(!i2cDevice->writeByte(0xF4, 0x2E)) {
        emit errorOccurred("Failed to initiate temperature measurement.");
        return;
    }
    // Wait for the conversion to complete, the BMP180 datasheet suggests waiting for at least 4.5ms
    QThread::msleep(5);
    // Read raw temperature data
    short rawTemp;
    if (!readShortFromRegister(0xF6, rawTemp)) {
        emit errorOccurred("Failed to read temperature data.");
        return;
    }
    // Calculate the actual temperature
    long x1 = ((long)rawTemp - (long)ac6) * (long)ac5 / 32768;
    long x2 = ((long)mc * 2048) / (x1 + md);
    long b5 = x1 + x2;
    double temperature = (b5 + 8) / 16.0 / 10.0;

    emit temperatureRead(temperature);
    qDebug() << "BMP180 Temperature: " << temperature;
}

bool Barometer_BMP180::readCalibrationData()
{
    if(!i2cDevice){
        return false;
    }

    // Read calibration data
    if (!readShortFromRegister(0xAA, ac1) || !readShortFromRegister(0xAC, ac2) ||
        !readShortFromRegister(0xAE, ac3) || !readShortFromRegister(0xB0, ac4) ||
        !readShortFromRegister(0xB2, ac5) || !readShortFromRegister(0xB4, ac6) ||
        !readShortFromRegister(0xB6, b1)  || !readShortFromRegister(0xB8, b2)  ||
        !readShortFromRegister(0xBA, mb)  || !readShortFromRegister(0xBC, mc)  ||
        !readShortFromRegister(0xBE, md)) {
        emit errorOccurred("Error reading calibration data from BMP180.");
        return false;
    }
    return true;
}

bool Barometer_BMP180::readShortFromRegister(uint8_t registerAddress, short &value)
{
    QByteArray data = i2cDevice->readBytes(registerAddress, 2);
    if (data.size() == 2) {
        value = static_cast<short>((data[0] << 8) | data[1]);
        return true;
    }
    return false;
}

double Barometer_BMP180::calculatePressure(int rawPressure) const
{

}
