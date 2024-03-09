#include <iostream>
#include <pigpio.h>

#include "MPU6050.h"
#include "IIC.h"
#include "MahonyFilter.h"
#include "MPU6050Thread.h"

int main(int argc, const char* argv[]) {

    MPU6050Thread mpu6050thread;

    mpu6050thread.start();

    mpu6050thread.join();

    return 0;
}
