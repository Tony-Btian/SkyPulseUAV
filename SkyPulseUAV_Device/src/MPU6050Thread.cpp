#include <pigpio.h>
#include <thread>
#include <cmath>

#include "MPU6050.h"
#include "MahonyFilter.h"
#include "MPU6050Thread.h"

void MPU6050Thread::run() {

    float a[3] = {0}, g[3] = {0}, m[3] = {0};
    float roll, pitch, yaw;

    MPU6050 mpu6050;
    MahonyFilter Mahonyfilter;

    initializeMPUISR();

    for(;;) {

        if(mpu6050.checkNewData()) {
            
            mpu6050.getData(a, g, m);
            Mahonyfilter.readRawData(a, g, m);
            Mahonyfilter.MahonyAHRSupdateIMU();
            Mahonyfilter.getAngle(&roll, &pitch, &yaw);

            std::cout << roll << "|" << pitch << "|" << yaw << std::endl;
            std::cout << gpioTick() << std::endl;            
        }

    }

}
