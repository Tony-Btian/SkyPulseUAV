#include "mpu6050.h"

MPU6050::MPU6050(uint8_t i2cAddress, QObject *parent)
    : QObject(parent), i2cDriver(new I2CDriver(i2cAddress, this))
{
    if(!this->i2cDriver){
        qWarning("Failed to create I2C device for MPU6050");
        return;
    }
    if(initializeMPU6050()){
        qWarning("MPU6050 Config Successful");
    }
    else{
        qWarning("MPU6050 Config Failed");
    }
}

bool MPU6050::initializeMPU6050()
{
    // Write to registers to initialise the sensor
    if(!i2cDriver->writeByte(PWR_MGMT_1, 0x00)){  // Wake up the device by writing 0 to the power management register.
        qWarning("MPU6050 wake up failed");
        return false;
    }
    if(!i2cDriver->writeByte(INT_ENABLE, 0x01)){  // Enable Data Ready interrupt
        qWarning("MPU6050 enable interrupt failed");
        return false;
    }
    if(!i2cDriver->writeByte(INT_PIN_CFG, 0x30)){  // Configure interrupt pin to be active high, push-pull, hold until cleared, clear on read
        qWarning("MPU6050 configure interrupt pin failed");
        return false;
    }
    collectSensorDataForCalibration();
    return true;
}

void MPU6050::collectSensorDataForCalibration()
{
    const int samples = 1000;
    float gyroSum[3] = {0, 0, 0};
    float accelSum[3] = {0, 0, 0};

    for (int i = 0; i < samples; ++i) {
        float ax=0.0f, ay=0.0f, az=0.0f, gx=0.0f, gy=0.0f, gz=0.0f;
        readAllSensors(ax, ay, az, gx, gy, gz);
        gyroSum[0] += gx;
        gyroSum[1] += gy;
        gyroSum[2] += gz;
        accelSum[0] += ax;
        accelSum[1] += ay;
        accelSum[2] += az - 1;  // Assuming the sensor is aligned with gravity
        QThread::msleep(2);
    }

    for (int i = 0; i < 3; ++i) {
        gyroOffset[i] = gyroSum[i] / samples;
        accelOffset[i] = accelSum[i] / samples;
    }
}


bool MPU6050::readBytes(uint8_t reg, uint8_t *buffer, size_t length) {
    QByteArray data = i2cDriver->readBytes(reg, length);
    if (data.size() == length) {
        memcpy(buffer, data.data(), length);
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

void MPU6050::applyCalibration(float &ax, float &ay, float &az, float &gx, float &gy, float &gz)
{
    ax -= accelOffset[0];
    ay -= accelOffset[1];
    az -= accelOffset[2];
    gx -= gyroOffset[0];
    gy -= gyroOffset[1];
    gz -= gyroOffset[2];
}

void MPU6050::readAllMPU6050Reg()
{
    qWarning("Read all MPU6050 Reg Action");
}
