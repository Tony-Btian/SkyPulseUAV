#include "bmp180.h"

BMP180::BMP180(uint8_t i2cAddress, QObject *parent)
    : QObject(parent), i2cDriver(new I2CDriver(i2cAddress, this))
{
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

// Run calibration on initialisation and read calibration values
bool BMP180::initializeBMP180()
{
    if(!readCalibrationData()){
        return false;
    }
    startPressureMeasurement(OSS);
    return true;
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

void BMP180::startPressureMeasurement(int oss)
{
    const quint8 controlReg = 0xF4;
    quint8 cmd = 0x34 + (oss << 6);
    i2cDriver->writeByte(controlReg, cmd);
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
    short rawTemp;
    if (!readShortFromRegister(0xF6, rawTemp)) {
        qWarning("Failed to read temperature data");
        return;
    }

    // Calculate the actual temperature
    long x1 = (rawTemp - (long)AC6) * (long)AC5 / 32768;
    long x2 = ((long)MC * 2048) / (x1 + MD);
    long b5 = x1 + x2;
    temperature = (b5 + 8) / 16.0 / 10.0;
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

int16_t BMP180::readRawTemperature ()
{
    const quint8 temperatureCmd = 0x2E;
    const quint8 controlReg = 0xF4;
    const quint8 tempDataReg = 0xF6;

    // Write temperature measurement commands to control registers
    i2cDriver->writeByte(controlReg, temperatureCmd);

    // Wait for conversion to complete (5 ms delay to ensure completion)
    QThread::msleep(WAIT_TIME);

    quint8 msb = 0, lsb = 0;
    // Read raw temperature value (two bytes)
    if((!i2cDriver->readByte(tempDataReg, msb)) && (!i2cDriver->readByte(tempDataReg+1, lsb))){
        qWarning("Read raw temperature reg error");
        return 0;
    }

    // Combining two bytes into a 16-bit integer
    int16_t rawTemperature = (msb << 8) | (lsb);
    return rawTemperature;
}

double BMP180::calculatePressure(int rawPressure)
{
    int32_t B5;
    int32_t UT = readRawTemperature();
    int32_t X1 = (UT - (int32_t)AC6) * ((int32_t)AC5) / pow(2, 15);
    int32_t X2 = ((int32_t)MC * pow(2, 11)) / (X1 + (int32_t)MD);
    B5 = X1 + X2;

    // Calculate B6, B3, X1, X2, X3, B4, B7
    int32_t B6 = B5 - 4000;
    X1 = (B2 * (B6 * B6 / pow(2, 12))) / pow(2, 11);
    X2 = AC2 * B6 / pow(2, 11);
    int32_t X3 = X1 + X2;
    int32_t B3 = (((AC1 * 4 + X3) << OSS) + 2) / 4;

    X1 = AC3 * B6 / pow(2, 13);
    X2 = (B1 * (B6 * B6 / pow(2, 12))) / pow(2, 16);
    X3 = ((X1 + X2) + 2) / 4;
    uint32_t B4 = AC4 * (uint32_t)(X3 + 32768) / pow(2, 15);
    uint32_t B7 = ((uint32_t)rawPressure - B3) * (50000 >> OSS);

    int32_t p;
    if (B7 < 0x80000000) {
        p = (B7 * 2) / B4;
    } else {
        p = (B7 / B4) * 2;
    }

    X1 = (p / pow(2, 8)) * (p / pow(2, 8));
    X1 = (X1 * 3038) / pow(2, 16);
    X2 = (-7357 * p) / pow(2, 16);
    p = p + (X1 + X2 + 3791) / pow(2, 4);

    return p;
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
