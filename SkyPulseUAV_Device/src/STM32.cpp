#include <iostream>
#include <pigpio.h>

#include "STM32.h"

STM32::STM32() : 
IRDistance{0.0f, 0.0f, 0.0f},
USDistance(0.0f),
handle(0) {
    
    // Set SPI channel to 0 and baud rate to 1M.
    // Open SPI.
    handle = spiOpen(SPI_CHANNEL_0, 1000000, 0);
    if(handle < 0) cerr << "Can't open SPI oto STM32" << endl;

}

STM32::~STM32() {

    if(spiClose(handle)) cerr << "Can't close SPi interface!" << endl;

}

void STM32::getData() {

    char buff[8] = {0};

    if(spiRead(handle, buff, DATA_SIZE) == DATA_SIZE) 
    cerr << "Can't read data from STM32!" << endl;

    IRDistance[0] = buff[0] << 8 | buff[1];
    IRDistance[1] = buff[2] << 8 | buff[3];
    IRDistance[2] = buff[4] << 8 | buff[5];
    USDistance = buff[6] << 8 | buff[7];

    if(callback_) {

        callback_(IRDistance, USDistance);

    }

} 

// Set callback function.
void STM32::setCallback(CallbackFunction callback) {

    callback_ = callback;

}




