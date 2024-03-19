#include <pigpio.h>
#include <thread>
#include <cmath>
#include <sstream>
#include <cstring>

#include "MPU6050.h"
#include "MahonyFilter.h"
#include "UART.h"

using namespace std;
// using namespace std::chrono;

void MPU6050Thread::run() {

    // Define intermediate variables
    float a[3] = {0}, g[3] = {0}, m[3] = {0};
    float roll, pitch, yaw;
    float g_out[3];
    std::ostringstream ss;
    std::string angleString;

    // Create objects
    MPU6050 mpu6050(200, 2000);
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
            Mahonyfilter.MahonyAHRSupdate();
            Mahonyfilter.getAngle(&roll, &pitch, &yaw, g_out);

            // std::cout << g[0] << "|" << g[2] << "|" << g[1] << std::endl;

            cout << roll << "|" << pitch << "|" << yaw << "|"
                 << g[0] << "|" << g[1] << "|" << g[2] << "|"
                 << a[0] << "|" << a[1] << "|" << a[2]<< endl; 

            // ss << "roll=" << roll << ",pitch=" << pitch << ",yaw=" << yaw << "\r\n";

            // ss << gpioTick() << "\r\n";

            angleString = ss.str();

            // const char* data = angleString.c_str();

            // uart.writeUART(const_cast<char*>(data), strlen(data));

            // auto start = std::chrono::high_resolution_clock::now();

            // uart.writeUART(angleString.data(), angleString.length());

            // auto end = std::chrono::high_resolution_clock::now();

            // 计算程序执行时间
            // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            // double seconds = duration.count() / 1000000.0; // 将微秒转换为秒

            // std::cout << gpioTick() << std::endl;

        }

    }

}
