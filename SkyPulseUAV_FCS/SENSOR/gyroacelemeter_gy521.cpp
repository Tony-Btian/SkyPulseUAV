#include "gyroacelemeter_gy521.h"  // Include the header file for the gyro and accelerometer MPU6050
#include <QDebug>  // Include the Qt Debugging tool

/**
 * @brief Constructor for MPU6050 class that initializes an I2C connection with the MPU6050 device.
 * @param i2cAddress The I2C address for the MPU6050 device.
 * @param parent The parent QObject.
 */
MPU6050::MPU6050(uint8_t i2cAddress, QObject *parent)
    : QObject(parent), i2cDevice(nullptr)  // Initialize the QObject part of this class and set i2cDevice pointer to nullptr.
{
    this->i2cDevice = new I2C_Device(i2cAddress, this);  // Allocate a new I2C_Device object.
    if(!this->i2cDevice){
        qDebug() << "Failed to create I2C device for MPU6050";  // Output error if the device could not be created.
        return;  // Exit constructor to prevent further execution.
    }

    if(this->initializeMPU6050()){
//        qWarning("MPU6050 Config Successful");
    }
    else{
        qWarning("MPU6050 Config Failed");  // Log configuration failure.
    }
}


/**
 * @brief Initializes the MPU6050 sensor with default settings.
 * @return true if initialization succeeds, false otherwise.
 */
bool MPU6050::initializeMPU6050()
{
    // Initialize the MPU6050 by writing to various registers.
    if(!writeByte(PWR_MGMT_1, 0x00)){  // Wake up the device by writing 0 to the power management register.
        qDebug() << "MPU6050 wake up failed.";
        return false;  // Return false if wake-up command fails.
    }
    if(!writeByte(INT_ENABLE, 0x01)){  // Enable data ready interrupt.
        qDebug() << "MPU6050 enable interrupt failed";
        return false;  // Return false if unable to enable interrupts.
    }
    if(!writeByte(INT_PIN_CFG, 0x30)){  // Configure interrupt pin settings.
        qDebug() << "MPU6050 configure interrupt pin failed";
        return false;  // Return false if configuration fails.
    }
    return true;  // Return true if all configurations are successful.
    // Further calibration methods are commented out.
}

/**
 * @brief Writes a byte to a register on the MPU6050.
 * @param reg The register address to write to.
 * @param value The byte value to write.
 * @return true if the write operation was successful, false otherwise.
 */
bool MPU6050::writeByte(uint8_t reg, uint8_t value)
{
    return i2cDevice->writeByte(reg, value);  // Delegate to I2C_Device's writeByte method.
}

/**
 * @brief Reads multiple bytes from a specific register.
 * @param reg The register address to start reading from.
 * @param buffer Pointer to the buffer where read data should be stored.
 * @param length Number of bytes to read.
 * @return true if the requested number of bytes were read, false otherwise.
 */
bool MPU6050::readBytes(uint8_t reg, uint8_t *buffer, size_t length) {
    QByteArray data = i2cDevice->readBytes(reg, length);  // Use I2C_Device to read bytes.
    if (data.size() == length) {
        memcpy(buffer, data.data(), length);  // Copy read data into buffer if correct amount of data was read.
        return true;
    }
    return false;
}


void MPU6050::readAllSensors(float &ax, float &ay, float &az, float &gx, float &gy, float &gz) {
    uint8_t buffer[14];
    if (readBytes(ACCEL_XOUT_H, buffer, sizeof(buffer))) {
        ax = (float)((int16_t)(buffer[0]  << 8 | buffer[1]))  / ACCEL_FS_SEL_2G;
        ay = (float)((int16_t)(buffer[2]  << 8 | buffer[3]))  / ACCEL_FS_SEL_2G;
        az = (float)((int16_t)(buffer[4]  << 8 | buffer[5]))  / ACCEL_FS_SEL_2G;
        gx = (float)((int16_t)(buffer[8]  << 8 | buffer[9]))  / GYRO_FS_SEL_250DEG;
        gy = (float)((int16_t)(buffer[10] << 8 | buffer[11])) / GYRO_FS_SEL_250DEG;
        gz = (float)((int16_t)(buffer[12] << 8 | buffer[13])) / GYRO_FS_SEL_250DEG;

        applyCalibration(ax,ay,az,gx,gy,gz);  // Applying calibration offsets
    }
}

/**
 * @brief Calibrates the gyroscope by calculating the average offset from a series of measurements.
 */
void MPU6050::calibrateGyro()
{
    const int samples = 1000;  // Number of samples to collect for calibration
    float sum[3] = {0, 0, 0};  // Array to sum gyroscope readings

    // Collect multiple samples to average out the gyroscope offset
    for (int i = 0; i < samples; ++i) {
        float ax=0.0f, ay=0.0f, az=0.0f, gx=0.0f, gy=0.0f, gz=0.0f;  // Temporary variables to hold sensor data
        readAllSensors(ax, ay, az, gx, gy, gz);  // Read sensor data
        sum[0] += gx;  // Sum up x-axis gyroscope data
        sum[1] += gy;  // Sum up y-axis gyroscope data
        sum[2] += gz;  // Sum up z-axis gyroscope data
        QThread::msleep(2);  // Sleep for a short time between samples to not overload the I2C bus
    }

    // Calculate the average offset for each axis
    for (int i = 0; i < 3; ++i) {
        gyroOffset[i] = sum[i] / samples;  // Store the computed average offset in the gyroOffset array
    }
}


/**
 * @brief Calibrates the accelerometer by calculating the average offset, assuming the sensor is stationary and aligned with gravity.
 */
void MPU6050::calibrateAccel()
{
    const int samples = 1000;  // Number of samples to collect
    float sum[3] = {0, 0, 0};  // Array to sum accelerometer readings

    // Collect multiple samples to average out the accelerometer offset
    for (int i = 0; i < samples; ++i) {
        float ax=0.0f, ay=0.0f, az=0.0f, gx=0.0f, gy=0.0f, gz=0.0f;  // Temporary variables to hold sensor data
        readAllSensors(ax, ay, az, gx, gy, gz);  // Read sensor data
        sum[0] += ax;  // Sum up x-axis accelerometer data
        sum[1] += ay;  // Sum up y-axis accelerometer data
        sum[2] += az - 1; // Sum up z-axis data, adjusting for gravity
        QThread::msleep(2);  // Sleep to avoid overloading the I2C bus
    }

    // Compute the average offset for each axis
    for (int i = 0; i < 3; ++i) {
        accelOffset[i] = sum[i] / samples;  // Store the computed average offset
    }
}


/**
 * @brief Applies the calculated calibration offsets to the sensor readings.
 * @param ax Address of the variable holding the accelerometer x-value.
 * @param ay Address of the variable holding the accelerometer y-value.
 * @param az Address of the variable holding the accelerometer z-value.
 * @param gx Address of the variable holding the gyroscope x-value.
 * @param gy Address of the variable holding the gyroscope y-value.
 * @param gz Address of the variable holding the gyroscope z-value.
 */
void MPU6050::applyCalibration(float &ax, float &ay, float &az, float &gx, float &gy, float &gz)
{
    ax -= accelOffset[0];  // Subtract x-axis accelerometer offset
    ay -= accelOffset[1];  // Subtract y-axis accelerometer offset
    az -= accelOffset[2];  // Subtract z-axis accelerometer offset
    gx -= gyroOffset[0];   // Subtract x-axis gyroscope offset
    gy -= gyroOffset[1];   // Subtract y-axis gyroscope offset
    gz -= gyroOffset[2];   // Subtract z-axis gyroscope offset
}

void MPU6050::readAllMPU6050Reg()
{
    qDebug() << "Read all reg action!";
}
