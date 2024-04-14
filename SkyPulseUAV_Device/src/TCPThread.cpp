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

    MahonyFilterIns.setCallbackA([this](float roll, float pitch, float yaw, float rate[3]){

        TCPIns.readDataFromFilter(roll, pitch, yaw, rate);
        
    });

    BMP180Ins.setCallbackA([this](float alt){

        TCPIns.readDataFromBMP180(alt);

    });

    for(;;) {
        
        TCPIns.write(TCPIns.mergeData());

        this_thread::sleep_for(microseconds(1000));

    }

}