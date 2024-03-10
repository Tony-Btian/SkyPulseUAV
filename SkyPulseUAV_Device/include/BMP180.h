#ifndef __BMP180_H__
#define __BMP180_H__

#include <atomic>

#include "IIC.h"


#define BMP180_ADDRESS 0x77
/**************************************************************************************/
#define MY_ALTITUDE 10.0f  // Before calibration, set the altitude of your location here!
/**************************************************************************************/

class BMP180  {

public:
    BMP180();

    BMP180(float loaclAltitude);

    float getData();

protected:

    void BMP180ReadEEPROM(char* eeprom);

    void sealevelPresCorrect(float sealevelPressure);

    // void baroGetAbsAlti(int handle, long p, float sealevelPressure, bool* needToExit);

    void BMP180ReadTempAndPres();

private:

    IIC iicBMP180;

    long p;
    float t;

    float myLocalAltitude;
    float sealevelPressure;

    std::atomic<float> droneAltitude;

    char eeprom;

};


#endif