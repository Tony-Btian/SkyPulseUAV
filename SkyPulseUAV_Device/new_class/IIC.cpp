#include "IIC.h"

IIC::IIC(int address) {

    {
        std::lock_guard<std::mutex> lock(i2cmtx);
        if (gpioInitialise() < 0) {
        std::cerr << "Failed to initialize pigpio" << std::endl;
        exit(1);
        }
        handle = i2cOpen(IIC_BUS, address, 0); 
    }
    
    if (handle < 0) {
        std::cerr << "Failed to open I2C device" << std::endl;
        exit(1);
    }
}

IIC::~IIC() {
    {
        std::lock_guard<std::mutex> lock(i2cmtx);
        i2cClose(handle); 
        gpioTerminate(); 
    }
}


int IIC::write(char* dataArray, int arrayLength) {

    {
        std::lock_guard<std::mutex> lock(i2cmtx);
        if ((err = i2cWriteDevice(handle, dataArray, arrayLength)) != 0) {
        std::cerr << "Can't write to IIC device " << handle << "." << std::endl;
        i2cClose(handle);
        gpioTerminate();
        return err;
	    }
    }
}

int IIC::read(char* dataArray, int arrayLength, int regAddr) {
    
    {
        std::lock_guard<std::mutex> lock(i2cmtx);
        if ((err = i2cWriteByte(handle, regAddr)) != 0) {
        std::cerr << "Can't write address to IIC device " << handle << " before reading." << std::endl;
        i2cClose(handle);
        gpioTerminate();
        return err;
        }

        if ((err = i2cReadDevice(handle, dataArray, arrayLength)) <= 0) {
        std::cerr << "Can't read data from IIC device " << handle << "." << std::endl;
        i2cClose(handle);
        gpioTerminate();
        return err;
        }
    }
}