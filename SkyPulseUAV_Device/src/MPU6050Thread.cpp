#include <pigpio.h>
#include <thread>
#include <cmath>

#include "MPU6050.h"
#include "MahonyFilter.h"
#include "MPU6050Thread.h"

void MPU6050Thread::run() {

    float a[3] = {0}, g[3] = {0}, m[3] = {0};
    float roll, pitch, yaw;
    float g_out[3];

    MPU6050 mpu6050(200, 1000);
    MahonyFilter Mahonyfilter;

    initializeMPUISR();

    for(;;) {

        if(mpu6050.checkNewData()) {
            
            mpu6050.getData(a, g, m);
            Mahonyfilter.readRawData(a, g, m);
            Mahonyfilter.MahonyAHRSupdateIMU();
            Mahonyfilter.getAngle(&roll, &pitch, &yaw, g_out);

            // std::cout << g[0] << "|" << g[2] << "|" << g[1] << std::endl;

            std::cout << roll << "|" << pitch << "|" << yaw << std::endl;          
        }

    }

}
