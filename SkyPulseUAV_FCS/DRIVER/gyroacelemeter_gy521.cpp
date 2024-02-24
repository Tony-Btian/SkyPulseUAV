#include "gyroacelemeter_gy521.h"
#include <pigpio.h>

//GyroAcelemeter_GY521::GyroAcelemeter_GY521()
//{

//}

// Init MPU6050
bool initMPU6050(int handle) {
    // Wakeup MPU6050
    return i2cWriteByteData(handle, PWR_MGMT_1, 0) == 0;
}

// Defining scale factor
const float ACCEL_SCALE = 16384.0;
const float GYRO_SCALE = 131.0;

int readAccelRange(int handle) {
    int range = i2cReadByteData(handle, ACCEL_CONFIG);
    range = (range >> 3) & 0x03;
    switch (range) {
        case 0: return 2; // 2g
        case 1: return 4; // 4g
        case 2: return 8; // 8g
        case 3: return 16; // 16g
    }
    return -1; // Error value
}


int readGyroRange(int handle) {
    int range = i2cReadByteData(handle, GYRO_CONFIG);
    range = (range >> 3) & 0x03;
    switch (range) {
        case 0: return 250; // 250
        case 1: return 500; // 500
        case 2: return 1000; // 1000
        case 3: return 2000; // 2000
    }
    return -1; // Error value
}

// Read MPU6050 Data
MPU6050Data readMPU6050Data(int handle) {
    char buffer[14];
    MPU6050Data data = {};

    if (i2cReadI2CBlockData(handle, ACCEL_XOUT_H, buffer, 14) == 14) {
        data.ax = ((buffer[0] << 8) | buffer[1]) / ACCEL_SCALE;
        data.ay = ((buffer[2] << 8) | buffer[3]) / ACCEL_SCALE;
        data.az = ((buffer[4] << 8) | buffer[5]) / ACCEL_SCALE;

        data.gx = ((buffer[8] << 8) | buffer[9]) / GYRO_SCALE;
        data.gy = ((buffer[10] << 8) | buffer[11]) / GYRO_SCALE;
        data.gz = ((buffer[12] << 8) | buffer[13]) / GYRO_SCALE;
    }

    return data;
}
