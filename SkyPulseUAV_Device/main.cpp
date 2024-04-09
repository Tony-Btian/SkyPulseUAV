#include <iostream>
#include <pigpio.h>

#include "MPU6050.h"
#include "IIC.h"
#include "MahonyFilter.h"
#include "TCP.h"
#include "BMP180.h"
#include "STM32.h"

int main(int argc, const char* argv[]) {

    string ipAddress;
    in_port_t port;

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

    // Create threads.
    // Data threads: MPU6050, BMP180.
    MPU6050Thread mpu6050Thread(mpu6050);
    BMP180Thread bmp180Thread(bmp180);
    
    // Filter thread: Mahony filter.
    MahonyFilterThread filterThread(Mahonyfilter, mpu6050);
    
    // Communication thread: TCP.
    TCPThread tcpThread(Mahonyfilter, tcp, bmp180);

    cout << "Initialize finished." << endl;

    // mpu6050Thread.start();
    // filterThread.start();
    // tcpThread.start();
    // bmp180Thread.start();

    for(;;)
    {
        stm32.getData();
        this_thread::sleep_for(milliseconds(10));
    }

    mpu6050Thread.join();
    tcpThread.join();
    filterThread.join();
    bmp180Thread.join();

    

    return 0;
}
