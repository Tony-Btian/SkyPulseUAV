#ifndef __TOSTM32_H__
#define __TOSTM32_H__

#include <functional>

#include "CppThread.hpp"
#include "chrono"
#include <iostream>
#include <pigpio.h>

#define SPI0_MOSI 10
#define SPI0_MISO 9
#define SPI0_SCLK 11
#define SPI0_CS 8

#define SPI_CHANNEL_0 0
#define SPI_CHANNEL_1 1
#define DATA_SIZE 4

using namespace std;
using namespace std::chrono;

class STM32 {

public:

    using CallbackFunction = function<void(uint8_t[3], uint8_t)>;

    STM32();

    ~STM32();

    void getData();

    void setCallback(CallbackFunction callback);

protected:




private:

    CallbackFunction callback_;

    int handle;

    uint8_t IRDistance[3];

    uint16_t USDistance;

};

class STM32Thread : public CppThread {

public:

    STM32Thread(STM32& STM32Ins_) : 
    STM32Ins(STM32Ins_) {};

protected:

    void run() override;

private:

    STM32& STM32Ins;

};


#endif