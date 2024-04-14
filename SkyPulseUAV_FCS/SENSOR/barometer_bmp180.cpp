#include "barometer_bmp180.h"    // Include the header file for the Barometer_BMP180 class
#include <QDebug>                // Include the Qt debugging tools

// Constructor for the Barometer_BMP180 class
Barometer_BMP180::Barometer_BMP180(uint8_t i2cAddress, QObject *parent)
    : QObject(parent), i2cDevice(nullptr)  // Initialize the QObject with parent, and i2cDevice with nullptr
{ this->i2cDevice = new I2C_Device(i2cAddress, this);  // Allocate memory for I2C_Device object
    if(!this->i2cDevice){
        qWarning("Failed to create I2C device for BMP180");  // Log a warning if i2cDevice is not created
        return;  // Exit if failed to create i2cDevice
    }

     if(!readCalibrationData()){
        emit sig_errorOccurred("Failed to read calibration data from BMP180.");  // Emit an error signal if calibration data read fails
    }
}

// Method to read pressure from the BMP180 sensor
void Barometer_BMP180::readPressure()
{
    if (!i2cDevice) {
        emit sig_errorOccurred("I2C device is not initialized.");  // Emit error signal if i2cDevice is not initialized
        return;
    }

   quint8 reg = 0xF6;  // Register address for pressure data
    quint8 count = 3;  // Number of bytes to read
    QByteArray rawData = i2cDevice->readBytes(reg, count);  // Read bytes from the I2C device

    if (rawData.size() == count) {
        // Combine bytes to form the raw pressure value
        int rawPressure = (static_cast<unsigned char>(rawData[0]) << 16 |
                           static_cast<unsigned char>(rawData[1]) << 8 |
                           static_cast<unsigned char>(rawData[2])) >> (8);  // Adjust for oversampling
        double pressure = calculatePressure(rawPressure);  // Calculate the actual pressure
        emit sig_pressureRead(pressure);  // Emit the pressure read signal
    } else {
        emit sig_errorOccurred("Failed to read pressure data from BMP180.");  // Emit an error signal if data read fails
    }
}

// Method to read temperature from the BMP180 sensor
void Barometer_BMP180::readTemperature()
{
    if (!i2cDevice) {
        emit sig_errorOccurred("I2C device is not initialized.");  // Emit error signal if i2cDevice is not initialized
        return;
    }
    if(!i2cDevice->writeByte(0xF4, 0x2E)) {  // Command to initiate temperature read
        emit sig_errorOccurred("Failed to initiate temperature measurement.");  // Emit error if command fails
        return;
    }
    // Wait for the conversion to complete, the BMP180 datasheet suggests waiting for at least 4.5ms
    QThread::msleep(5);  // Sleep for 5 ms to allow sensor to process the data

    short rawTemp;  // Variable to store the raw temperature data
    if (!readShortFromRegister(0xF6, rawTemp)) {
        emit sig_errorOccurred("Failed to read temperature data.");  // Emit error if reading fails
        return;
    }

    long x1 = ((long)rawTemp - (long)ac6) * (long)ac5 / 32768;  // Calculate temperature using sensor calibration data
    long x2 = ((long)mc * 2048) / (x1 + md);
    long b5 = x1 + x2;
    double temperature = (b5 + 8) / 16.0 / 10.0;  // Final temperature calculation

    emit sig_temperatureRead(temperature);  // Emit the temperature read signal
    qDebug() << "BMP180 Temperature: " << temperature;  // Log the temperature
}

/**
 * @brief Reads all calibration data from the sensor's registers.
 * @return true If all calibration data is read successfully.
 * @return false If any calibration data could not be read.
 */
// Method to read calibration data from the BMP180 sensor
bool Barometer_BMP180::readCalibrationData()
{
    if(!i2cDevice){
        return false;  // Return false if i2cDevice is not initialized
    }

    // Read calibration data
    if (!readShortFromRegister(0xAA, ac1) || !readShortFromRegister(0xAC, ac2) ||
    !readShortFromRegister(0xAE, ac3) || !readShortFromRegister(0xB0, ac4) ||
    !readShortFromRegister(0xB2, ac5) || !readShortFromRegister(0xB4, ac6) ||
    !readShortFromRegister(0xB6, b1)  || !readShortFromRegister(0xB8, b2)  ||
    !readShortFromRegister(0xBA, mb)  || !readShortFromRegister(0xBC, mc)  ||
    !readShortFromRegister(0xBE, md)) {
    emit sig_errorOccurred("Error reading calibration data from BMP180.");
    return false;
}
return true;
}

/**
 * @brief Reads a 16-bit integer (short) from a given register address.
 * @param registerAddress The register address from which to read.
 * @param value Reference to the variable where the read value will be stored.
 * @return true If the data was successfully read.
 * @return false If the data could not be read.
 */
bool Barometer_BMP180::readShortFromRegister(uint8_t registerAddress, short &value)
{
    QByteArray data = i2cDevice->readBytes(registerAddress, 2);
    if (data.size() == 2) {
        value = static_cast<short>((data[0] << 8) | data[1]);
        return true;
    }
    return false;
}

/**
 * @brief Calculates the atmospheric pressure from raw sensor data.
 * @param rawPressure The raw pressure reading from the sensor.
 * @return double The calculated pressure.
 */
double Barometer_BMP180::calculatePressure(int rawPressure) const
{
    return 0.00; // Placeholder for pressure calculation formula
}

/**
 * @brief Reads all calibration and measurement registers of the BMP180 sensor.
 * @details This function reads all data from the calibration registers and the primary measurement registers in one go, compiles them into a QByteArray, and emits a signal with this data.
 */
void Barometer_BMP180::readAllRegisters()
{
    if (!i2cDevice) {
        emit sig_errorOccurred("I2C device is not initialized.");
        return;
    }

    QByteArray data_buffer;

    // Read calibration coefficient register
    quint8 startReg = 0xAA;
    quint8 endReg = 0xBF;
    quint8 count = endReg - startReg + 1;
    QByteArray data_c = i2cDevice->readBytes(startReg, count);
    if(!data_c.isEmpty()){
        data_buffer.append(data_c);
    }
    else{
        emit sig_errorOccurred("Failed to read calibration register");
        return; // If the read fails, terminate
    }

    // Read pressure and temperature data registers
    QByteArray data_d = i2cDevice->readBytes(0xF6, 3); // Read 3 consecutive bytes starting at 0xF6
    if (!data_d.isEmpty()) {
        data_buffer.append(data_d);
        emit sig_allRegistersData(data_buffer);
    }
    else {
        emit sig_errorOccurred("Failed to read measurement data.");
        return; // If the read fails, terminate
    }
}

