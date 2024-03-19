#include <iostream>
#include <pigpio.h>

#include "MPU6050.h"
#include "IIC.h"
#include "MahonyFilter.h"

int main(int argc, const char* argv[]) {

    if (gpioInitialise() < 0) {
        std::cerr << "Failed to initialize pigpio" << std::endl;
        exit(1);
    }

    MPU6050Thread mpu6050thread;

    mpu6050thread.start();

    mpu6050thread.join();

    return 0;
}
