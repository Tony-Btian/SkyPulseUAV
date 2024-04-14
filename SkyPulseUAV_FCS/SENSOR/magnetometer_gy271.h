#ifndef MAGNETOMETER_GY271_H  // Prevents the header file from being included multiple times in the same file
#define MAGNETOMETER_GY271_H

#include <QObject>      // Includes QObject class which is the base class for all Qt objects
#include <QThread>      // Includes QThread for using threading functionalities
#include <QByteArray>   // Includes QByteArray for handling byte array which is useful in reading data from devices
#include "i2c_device.h" // Includes the definition of the I2C_Device class which handles I2C communication

class Magnetometer_GY271 : public QObject // Defines the Magnetometer_GY271 class that inherits from QObject
{
    Q_OBJECT   // Macro that allows the class to use Qt's signal and slots mechanism

public:
    /**
     * @brief Constructor for the Magnetometer_GY271 class.
     * @param i2cAddress The I2C address for the magnetometer device (default 0x0D).
     * @param parent The parent QObject (default nullptr).
     */
    explicit Magnetometer_GY271(uint8_t i2cAddress = 0x0D, QObject *parent = nullptr);

    /**
     * @brief Initializes the GY-271 magnetometer to be ready for data collection.
     * @return true if initialization is successful, false otherwise.
     */
    bool initializeGY271();


public slots:
    /**
     * @brief Slot to read raw magnetometer data from the device and emit a signal with the data.
     */
    void readRawData();


private:
    I2C_Device *i2cDevice; // Pointer to an I2C_Device object for handling I2C communication

    /**
     * @brief Writes a byte of data to a specific register of the GY-271.
     * @param reg The register address where the data will be written.
     * @param value The data byte to write.
     * @return true if the write operation was successful, false otherwise.
     */
    bool writeByte(uint8_t reg, uint8_t value);

    /**
     * @brief Converts a two-byte array from the magnetometer into a 16-bit integer.
     * @param bytes The QByteArray containing the bytes to convert.
     * @param offset The starting position in the QByteArray.
     * @return The 16-bit integer value formed by two bytes starting at the offset.
     */
    int16_t convertToRawData(const QByteArray &bytes, int offset);
bytes, int offset);

private slots:
    /**
     * @brief Handles I2C communication errors.
     * @param error A string describing the error.
     */
    void handleI2CError(QString error);

signals:
    /**
     * @brief Signal emitted when new raw data is read from the magnetometer.
     * @param x The raw x-axis value.
     * @param y The raw y-axis value.
     * @param z The raw z-axis value.
     */
    void sig_rawDataRead(int x, int y, int z);

    /**
     * @brief Signal emitted when an error occurs.
     * @param error A string describing the error.
     */
    void sig_errorOccurred(const QString& error);
};

#endif // MAGNETOMETER_GY271_H  // Ends the include guard

