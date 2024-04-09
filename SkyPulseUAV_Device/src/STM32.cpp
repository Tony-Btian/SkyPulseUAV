#include "STM32.h"

STM32::STM32() : 
IRDistance{0, 0, 0},
USDistance(0),
handle(0) 
{
    
    // Set SPI channel to 0 and baud rate to 1M.
    // Open SPI.
    handle = spiOpen(SPI_CHANNEL_0, 50000, 0);
    if(handle < 0) 
    {

        cerr << "Can't open SPI oto STM32" << endl;

    }

    else
    {
        cout << "SPI initialised successfully." <<endl;
    }
    gpioSetMode(SPI0_MOSI, PI_OUTPUT);
    gpioSetMode(SPI0_MISO, PI_INPUT);
    gpioSetMode(SPI0_SCLK, PI_OUTPUT);
    gpioSetMode(SPI0_CS, PI_OUTPUT);

}

STM32::~STM32() 
{

    if(spiClose(handle)) 
    {

        cerr << "Can't close SPi interface!" << endl;

    }

}

void STM32::getData() 
{

    char buff[4] = {0};
    char readFlag = 1;

    // if(spiWrite(handle, &readFlag, 1) != 1)
    // {
    //     cerr << "Can't write data to STM32!" << endl;
    // }
    // this_thread::sleep_for(milliseconds(100));

    gpioWrite(SPI0_CS, 0);

    if(spiXfer(handle, &readFlag, buff, DATA_SIZE) != DATA_SIZE) 
    {

        cerr << "Can't read data from STM32!" << endl;

    }

    this_thread::sleep_for(microseconds(1000));

    gpioWrite(SPI0_CS, 1);

    IRDistance[0] = buff[0];
    // IRDistance[1] = buff[2] << 8 | buff[3];
    // IRDistance[2] = buff[4] << 8 | buff[5];
    USDistance = (buff[2] << 8 | buff[3]);
    cout << static_cast<int>(buff[0]) << "," 
        << static_cast<int>(buff[1]) << "," 
        << static_cast<int>(buff[2]) << "," 
        << static_cast<int>(buff[3]) << endl;
    // cout << static_cast<int>(IRDistance[0]) << "," << static_cast<int>(USDistance) << endl;

    if(callback_) 
    {

        callback_(IRDistance, USDistance);

    }

} 

// Set callback function.
void STM32::setCallback(CallbackFunction callback) 
{

    callback_ = callback;

}




