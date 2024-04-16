#include <iostream>
#include <pigpio.h>

#include "MPU6050.h"
#include "IIC.h"
#include "MahonyFilter.h"
#include "TCP.h"
#include "BMP180.h"
#include "STM32.h"
#include "IRAndUS.h"
#include "Control.h"

int main(int argc, const char* argv[]) 
{

    // Edit the variables below to choose your own ground station. 
    string ipAddress;
    in_port_t port;

    // Toggle comments below if you want to define TCP address and port every time
    // the program launches. 

    // if(argc != 3) {

    //     cout << "Usage: ./altitude [IP address] [port], try again!" << endl;

    //     return 0;

    // } else {

    //     ipAddress = argv[1];
    //     port = stoi(argv[2]); 
    // }

    if (gpioInitialise() < 0) {
        std::cerr << "Failed to initialize pigpio" << std::endl;
        exit(1);
    }

    // Create objects.
    MahonyFilter Mahonyfilter;
    MPU6050 mpu6050(200, 2000);
    TCP tcp(ipAddress, port);
    BMP180 bmp180;
    STM32 stm32;
    IRSensor ir(nullptr);
    USSensor us(nullptr, nullptr);
    Control control;

    // Create threads.
    // Data threads: MPU6050, BMP180, IR and US.
    MPU6050Thread mpu6050Thread(mpu6050);
    BMP180Thread bmp180Thread(bmp180);
    IRAndUSThread irandusThread(ir, us);
    
    // Algorithm threads: Mahony filter, PID controller.
    MahonyFilterThread filterThread(Mahonyfilter, mpu6050);
    ControlThread controlthread(control, Mahonyfilter, bmp180, ir, us, tcp);
    
    // Communication thread: TCP.
    // TCP is used to connect with ground station.
    TCPThread tcpThread(Mahonyfilter, tcp, bmp180, stm32, ir, us);

    cout << "Initialize finished." << endl;

    mpu6050Thread.start();
    filterThread.start();
    tcpThread.start();
    bmp180Thread.start();
    irandusThread.start();

    mpu6050Thread.join();
    tcpThread.join();
    filterThread.join();
    bmp180Thread.join();
    irandusThread.join();

    return 0;
}
