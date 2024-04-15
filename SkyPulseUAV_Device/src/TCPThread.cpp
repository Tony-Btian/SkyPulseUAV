#include "TCP.h"
#include "MahonyFilter.h"

// test
// void TCPThread::run() {

//     for(;;) {

//         TCPIns.write("Hello world!");

//         this_thread::sleep_for(seconds(1));

//     }

// }

void TCPThread::run() 
{
    // Register callback functions.
    MahonyFilterIns.setCallbackA([this](float roll, float pitch, float yaw, float rate[3])
    {

        TCPIns.readDataFromFilter(roll, pitch, yaw, rate);
        
    });

    BMP180Ins.setCallbackA([this](float alt)
    {

        TCPIns.readDataFromBMP180(alt);

    });

    IRSensorIns.setCallback([this](uint8_t IRObstacleDetected)
    {

        TCPIns.readDataFromIR(IRObstacleDetected);

    });

     USSensorIns.setCallback([this](int distance)
    {

        TCPIns.readDataFromIR(distance);

    });

    for(;;) {
        
        // Transmit data to ground station.
        TCPIns.write(TCPIns.mergeData());

        this_thread::sleep_for(microseconds(1000));

    }

}