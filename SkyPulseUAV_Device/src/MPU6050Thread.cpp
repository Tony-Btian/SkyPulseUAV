#include <pigpio.h>
#include <thread>
#include <cmath>
#include <sstream>
#include <cstring>

#include "MPU6050.h"
#include "MahonyFilter.h"
#include "UART.h"

void MPU6050Thread::run() {

    // Define intermediate variables
    float a[3] = {0}, g[3] = {0}, m[3] = {0};
    float roll, pitch, yaw;
    float g_out[3];
    std::ostringstream ss;

    // Create objects
    MPU6050 mpu6050(200, 1000);
    MahonyFilter Mahonyfilter;
    UART uart(115200);

    // Initialize interrupt callback function
    initializeMPUISR();

    // Goes into infinite loop
    for(;;) {

        // Do Mahonyfilter algorithm and get three Euler's angles
        if(mpu6050.checkNewData()) {
            
            mpu6050.getData(a, g, m);
            Mahonyfilter.readRawData(a, g, m);
            Mahonyfilter.MahonyAHRSupdateIMU();
            Mahonyfilter.getAngle(&roll, &pitch, &yaw, g_out);

            // std::cout << g[0] << "|" << g[2] << "|" << g[1] << std::endl;

            // std::cout << roll << "|" << pitch << "|" << yaw << std::endl; 

            ss << roll << ", " << pitch << ", " << yaw;

            std::string angleString = ss.str();

            const char* data = angleString.c_str();

            uart.writeUART(const_cast<char*>(data), strlen(data));

        }

    }

}
