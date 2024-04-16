#include "bmp180.h"
#include <QDebug>
#include <QThread>

BMP180::BMP180(uint8_t i2cAddress, QObject *parent)
    : QObject(parent), i2cDriver(nullptr)
{
    this->i2cDriver = new I2CDriver(i2cAddress, this);  // Create an instance os I2CDriver using the provided I2C address
    if(!this->i2cDriver){
        qWarning("Failed to create I2C device for BMP180");
        return;
    }
    if(initializeBMP180()){
        qWarning("BMP180 Config Successful");
    }
    else{
        qWarning("BMP180 Config Failed");
    }
}

bool BMP180::initializeBMP180()
{
    if(!readCalibrationData()){
        return false;
    }
    return true;
}

void BMP180::readPressure(double &pressure)
{
    if (!i2cDriver) {
        qWarning("I2C device is not initialized");
        return;
    }
    quint8 reg = 0xF6;
    quint8 count = 3;
    QByteArray rawData = i2cDriver->readBytes(reg, count);

    if (rawData.size() == count) {
        int rawPressure = (static_cast<unsigned char>(rawData[0]) << 16 |
                           static_cast<unsigned char>(rawData[1]) << 8 |
                           static_cast<unsigned char>(rawData[2])) >> (8 /* oversampling_setting */);
        pressure = calculatePressure(rawPressure);
    } else {
        qWarning("Failed to read pressure data from BMP180");
        return;
    }
}

void BMP180::readTemperature(double &temperature)
{
    if (!i2cDriver) {
        qWarning("I2C device is not initialized");
        return;
    }

    // Write temperature measurement commands to the BMP180
    if(!i2cDriver->writeByte(0xF4, 0x2E)) {
        qWarning("Failed to initiate temperature measurement");
        return;
    }
    // Wait for the conversion to complete, the BMP180 datasheet suggests waiting for at least 4.5ms
    QThread::msleep(5);
    // Read raw temperature data
    short rawTemp_MSB, rawTemp_LSB;
    long rawTemp;
    if (!readShortFromRegister(0xF6, rawTemp_MSB) && !readShortFromRegister(0xF7, rawTemp_LSB)) {
        qWarning("Failed to read temperature data");
        return;
    }

    // Calculate the actual temperature
    rawTemp = rawTemp_MSB << 8 + rawTemp_LSB;
    long x1 = (rawTemp - (long)AC6) * (long)AC5 / 32768;
    long x2 = ((long)MC * 2048) / (x1 + MD);
    long b5 = x1 + x2;
    temperature = (b5 + 8) / 16.0 / 10.0;
}

bool BMP180::readCalibrationData()
{
    if(!i2cDriver){
        return false;
    }
    // Read calibration data
    if (!readShortFromRegister(0xAA, AC1) || !readShortFromRegister(0xAC, AC2) ||
        !readShortFromRegister(0xAE, AC3) || !readShortFromRegister(0xB0, AC4) ||
        !readShortFromRegister(0xB2, AC5) || !readShortFromRegister(0xB4, AC6) ||
        !readShortFromRegister(0xB6, B1)  || !readShortFromRegister(0xB8, B2)  ||
        !readShortFromRegister(0xBA, MB)  || !readShortFromRegister(0xBC, MC)  ||
        !readShortFromRegister(0xBE, MD)) {
        qWarning("Error reading calibration data from BMP180");
        return false;
    }
    return true;
}


bool BMP180::readShortFromRegister(uint8_t registerAddress, short &value)
{
    QByteArray data = i2cDriver->readBytes(registerAddress, 2);
    if (data.size() == 2) {
        value = static_cast<short>((data[0] << 8) | data[1]);
        return true;
    }
    return false;
}

double BMP180::calculatePressure(int rawPressure) const
{
    return 0.00;
}

void BMP180::readAllRegisters()
{
    if (!i2cDriver) {
        emit sig_errorOccurred("I2C device is not initialized.");
        return;
    }

    QByteArray data_buffer;
//    data_buffer.append(BMP180_DATAHEAD);
    // Read calibration coefficient register
    quint8 startReg = 0xAA;
    quint8 endReg = 0xBF;
    quint8 count = endReg - startReg + 1;
    QByteArray data_c = i2cDriver->readBytes(startReg, count);
    if(!data_c.isEmpty()){
        data_buffer.append(data_c);
    }
    else{
        emit sig_errorOccurred("Failed to read calibration register");
        return; // If the read fails, terminate
    }

    // Read pressure and temperature data registers
    QByteArray data_d = i2cDriver->readBytes(0xF6, 3); // Read 3 consecutive bytes starting at 0xF6
    if (!data_d.isEmpty()) {
        data_buffer.append(data_d);
        emit sig_allRegistersData(data_buffer);
    }
    else {
        emit sig_errorOccurred("Failed to read measurement data.");
        return; // If the read fails, terminate
    }
}
