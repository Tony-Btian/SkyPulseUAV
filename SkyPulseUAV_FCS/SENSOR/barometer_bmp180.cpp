#include "barometer_bmp180.h"
#include <QDebug>


Barometer_BMP180::Barometer_BMP180(I2CDevice *i2cDevice, QObject *parent)
    : QObject(parent), i2cdevice(i2cDevice)
{
    if(!readCalibrationData()){
        emit errorOccurred("Failed to read calibration data from BMP180.");
    }
}

Barometer_BMP180::~Barometer_BMP180()
{

}

bool Barometer_BMP180::readCalibrationData()
{
    if(!i2cDevice){
        return false;
    }
    QByteArray data;

    data = i2cDevice->readBytes(0xAA, 2);
    if(data.size() != 2){
        return false;
    }
    ac1 = static_cast<short>(data[0] << 8 | data[1]);

    return true;
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

void BMP180_Sensor::readCalibrationData()
{

}

double BMP180_Sensor::calculatePressure(int rawPressure) const
{

    return static_cast<double>(rawPressure);
}
