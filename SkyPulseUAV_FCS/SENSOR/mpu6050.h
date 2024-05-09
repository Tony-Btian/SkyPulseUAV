#ifndef MPU6050_H
#define MPU6050_H

#include <QObject>
#include <QThread>
#include "i2cdriver.h"

class MPU6050 : public QObject
{
    Q_OBJECT

public:
    explicit MPU6050(uint8_t i2cAddress = 0x68, QObject *parent = nullptr);
    void readAllSensors(float &ax, float &ay, float &az, float &gx, float &gy, float &gz);
    void calibrateGyro();
    void calibrateAccel();
    bool readBytes(uint8_t reg, uint8_t *buffer, size_t length);

public slots:
    void readAllMPU6050Reg();

private:
    I2CDriver *i2cDriver;

    // Calibration offsets
    float gyroOffset[3] = {0, 0, 0};
    float accelOffset[3] = {0, 0, 0};

    static constexpr uint8_t PWR_MGMT_1 = 0x6B;
    static constexpr uint8_t ACCEL_XOUT_H = 0x3B;
    static constexpr uint8_t GYRO_XOUT_H = 0x43;
    static constexpr uint8_t INT_ENABLE = 0x38;  // Interrupt Enable Register
    static constexpr uint8_t INT_PIN_CFG = 0x37;  // Interrupt Pin/Bypass Enable Configuration Register
    static constexpr float   ACCEL_FS_SEL_2G = 16384.0;
    static constexpr float   GYRO_FS_SEL_250DEG = 131.0;

    bool initializeMPU6050();
    void collectSensorDataForCalibration();
    void applyCalibration(float &ax, float &ay, float &az, float &gx, float &gy, float &gz);
};

#endif // MPU6050_H
