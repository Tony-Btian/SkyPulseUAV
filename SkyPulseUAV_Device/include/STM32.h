#ifndef __TOSTM32_H__
#define __TOSTM32_H__

#include <functional>

#include "CppThread.hpp"

#define SPI_CHANNEL_0 0
#define SPI_CHANNEL_1 1
#define DATA_SIZE 8

using namespace std;

class STM32 {

public:

    using CallbackFunction = function<void(float[3], float)>;

    STM32();

    ~STM32();

    void getData();

    void setCallback(CallbackFunction callback);

protected:




private:

    CallbackFunction callback_;

    int handle;

    float IRDistance[3];

    float USDistance;

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