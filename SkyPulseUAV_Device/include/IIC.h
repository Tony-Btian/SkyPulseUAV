#ifndef __IIC_H__
#define __IIC_H__

#include <pigpio.h>
#include <iostream>
#include <mutex>

#define IIC_BUS 1

extern std::mutex i2cmtx;

class IIC {

public:

    IIC(int address);

    ~IIC();
    
    int write(char* dataArray, int arrayLength);

    int read(char* dataArray, int arrayLength, int regAddr);

private:

    static std::mutex i2cmtx;
    
    int handle;
    int err;

};



#endif