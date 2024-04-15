#include <iostream>
#include <pigpio.h>

#include "STM32.h"

STM32::STM32() : 
IRDetected{0},
USDistance(0),
handle(0) 
{
    
    // Set SPI channel to 0 and baud rate to 1M.
    // Open SPI.
    handle = spiOpen(SPI_CHANNEL_0, 1000000, 0);
    if(handle < 0) cerr << "Can't open SPI oto STM32" << endl;

}

STM32::~STM32() 
{

    if(spiClose(handle)) cerr << "Can't close SPI interface!" << endl;

}

void STM32::getData() 
{

    char buff[4] = {0};

    if(spiRead(handle, buff, DATA_SIZE) == DATA_SIZE) 
    cerr << "Can't read data from STM32!" << endl;

    // Dispatch the first byte.
    
    // The second byte is IR detection.
    //      00000001 -- IR 1 sensor detects obstacles.
    //      00000010 -- IR 2 sensor detects obstacles.
    //      00000100 -- IR 3 sensor detects obstacles.
    //      00001000 -- IR 4 sensor detects obstacles.
    // Of course mixture of them can be derived by yourself.
    IRDetected = buff[1];

    // Distance from ultrasensor to the nearest obstacle.
    USDistance = buff[2] << 8 | buff[3];

    // Transmit data to other thread by callback function.
    if(callback_) {

        callback_(IRDetected, USDistance);

    }

} 

// Set callback function.
void STM32::setCallback(CallbackFunction callback) 
{

    callback_ = callback;

}




