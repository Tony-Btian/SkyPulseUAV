#ifndef GYROACELEMETER_GY521_H  // Prevents the file from being included multiple times in a single compilation unit
#define GYROACELEMETER_GY521_H

#include <QObject>    // Includes QObject class which is the base class for all Qt objects
#include <QThread>    // Includes QThread for using thread-related functions
#include "i2c_device.h"  // Include the header for I2C device interface class

class MPU6050 : public QObject  // Defines MPU6050 class inheriting from QObject
{
    Q_OBJECT  // Enables the object to use signal and slot mechanism by Qt

public:
    /**
     * @brief Constructor for the MPU6050 class.
     * @param i2cAddress I2C address for the MPU6050 device (default 0x68)
     * @param parent Pointer to the parent QObject (default nullptr)
     */
    explicit MPU6050(uint8_t i2cAddress = 0x68, QObject *parent = nullptr);

    /**
     * @brief Reads all sensor data from MPU6050 and applies calibration.
     * @param ax Reference to store the calibrated x-axis acceleration
     * @param ay Reference to store the calibrated y-axis acceleration
     * @param az Reference to store the calibrated z-axis acceleration
     * @param gx Reference to store the calibrated x-axis gyroscope reading
     * @param gy Reference to store the calibrated y-axis gyroscope reading
     * @param gz Reference to store the calibrated z-axis gyroscope reading
     */
    void readAllSensors(float &ax, float &ay, float &az, float &gx, float &gy, float &gz);

    /**
     * @brief Performs gyroscope calibration by computing the average zero-rate offset.
     */
    void calibrateGyro();

    /**
     * @brief Performs accelerometer calibration by determining the gravity offset.
     */
    void calibrateAccel();

    /**
     * @brief Writes a byte to a specified register.
     * @param reg Register address where the byte is to be written
     * @param value Byte value to write
     * @return true if the write operation was successful, false otherwise
     */
    bool writeByte(uint8_t reg, uint8_t value);

    /**
     * @brief Reads multiple bytes from a specified register.
     * @param reg Register address to start reading from
     * @param buffer Pointer to the buffer where read data will be stored
     * @param length Number of bytes to read
     * @return true if the specified number of bytes are successfully read, false otherwise
     */
    bool readBytes(uint8_t reg, uint8_t *buffer, size_t length);

public slots:
    /**
     * @brief Slot to trigger reading all registers from the MPU6050 for debugging.
     */
    void readAllMPU6050Reg();

private:
    I2C_Device *i2cDevice;  // Pointer to an I2C_Device object for communication

    // Calibration offsets
    float gyroOffset[3] = {0, 0, 0};  // Gyroscope offsets for zero-rate calibration
    float accelOffset[3] = {0, 0, 0}; // Accelerometer offsets for gravity offset calibration

    // Register addresses defined as static constants
    static constexpr uint8_t PWR_MGMT_1 = 0x6B;  // Power management register
    static constexpr uint8_t ACCEL_XOUT_H = 0x3B;  // High byte of the X acceleration data
    static constexpr uint8_t GYRO_XOUT_H = 0x43;   // High byte of the X gyroscope data
    static constexpr uint8_t INT_ENABLE = 0x38;    // Interrupt Enable Register
    static constexpr uint8_t INT_PIN_CFG = 0x37;   // Interrupt Pin/Bypass Enable Configuration Register

    // Scale selectors as static constants
    static constexpr float ACCEL_FS_SEL_2G = 16384.0; // Accelerometer scale selector for 2g
    static constexpr float GYRO_FS_SEL_250DEG = 131.0; // Gyroscope scale selector for 250 degrees/second

    /**
     * @brief Initializes the MPU6050 device with default settings.
     * @return true if initialization is successful, false otherwise
     */
    bool initializeMPU6050();
    void applyCalibration(float &ax, float &ay, float &az, float &gx, float &gy, float &gz);
};

#endif // GYROACELEMETER_GY521_H  // End of the include guard
