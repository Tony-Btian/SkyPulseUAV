#ifndef __BMP180_H__
#define __BMP180_H__

#include <atomic>
#include <functional>

#include "IIC.h"
#include "CppThread.hpp"

#define BMP180_ADDRESS 0x77
/**************************************************************************************/
#define MY_ALTITUDE 10.0f  // Before calibration, set the altitude of your location here!
/**************************************************************************************/

using namespace std;
using namespace std::chrono;

class BMP180  
{
    
public:

    using CallbackFunction = function<void(float)>;

    BMP180();

    BMP180(float loaclAltitude);

    float getData();

    void setCallbackA(CallbackFunction callback);

    void setCallbackB(CallbackFunction callback);

protected:

    void BMP180ReadEEPROM(char* eeprom);

    void sealevelPresCorrect(float sealevelPressure);

    // void baroGetAbsAlti(int handle, long p, float sealevelPressure, bool* needToExit);

    void BMP180ReadTempAndPres();

private:

    CallbackFunction callbackA_;

    CallbackFunction callbackB_;

    IIC iicBMP180;

    long p;
    float t;

    float myLocalAltitude;
    float sealevelPressure;

    std::atomic<float> droneAltitude;

    char eeprom;

};

class BMP180Thread : public CppThread 
{

public:

    BMP180Thread(BMP180& BMP180Ins_) : BMP180Ins(BMP180Ins_) {};

protected:

    void run() override;

private:

    BMP180& BMP180Ins;

};

#endif