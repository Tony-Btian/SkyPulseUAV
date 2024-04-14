#ifndef BAROMETER_BMP180_H  // Prevents the header file from being included multiple times in a single compilation, which can cause issues such as redefinition errors.
#define BAROMETER_BMP180_H

#include <QObject>  // Includes the QObject class, which is the base class for all Qt objects. QObject provides support for signals and slots mechanism, among other features.
#include <QThread>  // Includes the QThread class for managing threads in Qt which allows for operations like thread sleep (used in implementation).
#include "i2c_device.h"  // Includes the header file for the I2C_Device class, which handles I2C communication specifically designed for this application.

/**
 * @class Barometer_BMP180
 * @brief The Barometer_BMP180 class interfaces with the BMP180 sensor to provide temperature and pressure readings.
 * 
 * This class inherits from QObject to utilize Qt's signal and slot mechanisms for asynchronous I2C communication and event handling.
 */
class Barometer_BMP180 : public QObject
{
    Q_OBJECT  // Enables the class to use Qt's signal and slot mechanism.

public:
    /**
     * @brief Constructs a Barometer_BMP180 object.
     * @param i2cAddress I2C address of the BMP180 sensor (default is 0x77).
     * @param parent Pointer to the parent QObject which may be used to organize objects into hierarchies (default is nullptr).
     */
    explicit Barometer_BMP180(uint8_t i2cAddress = 0x77, QObject *parent = nullptr);

    /**
     * @brief Reads the calibration coefficients from the sensor which are needed to calculate the correct pressure and temperature values.
     * @return Returns true if all calibration data is successfully read, false otherwise.
     */
    bool readCalibrationData();

public slots:  // Section for slots which are functions that can be invoked via signals
    /**
     * @brief Reads the current atmospheric pressure from the BMP180 sensor and emits it via a signal.
     */
    void readPressure();

    /**
     * @brief Reads the current temperature from the BMP180 sensor and emits it via a signal.
     */
    void readTemperature();

    /**
     * @brief Reads all the data from sensor's registers and compiles it into a QByteArray which is then emitted via a signal.
     */
    void readAllRegisters();

private:
    I2C_Device* i2cDevice;  // Pointer to an I2C_Device object for handling I2C communication.

    // Calibration coefficients that are stored internally and used in calculations
    short ac1;  // Calibration coefficient AC1
    short ac2;  // Calibration coefficient AC2
    short ac3;  // Calibration coefficient AC3
    short ac4;  // Calibration coefficient AC4
    short ac5;  // Calibration coefficient AC5
    short ac6;  // Calibration coefficient AC6
    short b1;   // Calibration coefficient B1
    short b2;   // Calibration coefficient B2
    short mb;   // Calibration coefficient MB
    short mc;   // Calibration coefficient MC
    short md;   // Calibration coefficient MD

    // Private utility functions for internal use
    /**
     * @brief Reads a 16-bit integer (short) from a specific register address on the BMP180.
     * @param registerAddress The register address from which to read.
     * @param value Reference to the short variable where the data will be stored.
     * @return Returns true if data is successfully read, false otherwise.
     */
    bool readShortFromRegister(uint8_t registerAddress, short &value);

    /**
     * @brief Calculates the atmospheric pressure from raw sensor data.
     * @param rawPressure Raw pressure data from the sensor.
     * @return Calculated atmospheric pressure.
     */
    double calculatePressure(int rawPressure) const;

signals:  // Qt signals to be emitted upon completing different tasks
    void sig_temperatureRead(double temperature);  // Emitted after temperature is read and calculated.
    void sig_pressureRead(double pressure);  // Emitted after atmospheric pressure is read and calculated.
    void sig_allRegistersData(const QByteArray &data);  // Emitted after all registers are read.
    void sig_errorOccurred(const QString& message);  // Emitted when an error occurs in sensor reading or data handling.

};

#endif // BAROMETER_BMP180_H

