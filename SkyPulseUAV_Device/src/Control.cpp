#include <iostream>
#include <cmath>

#include "Control.h"

Control::Control() : Control(defaultSampleFreq) {}

Control::Control(float sampleFreq) :
    currentAngle{0.0f, 0.0f, 0.0f},
    currentRate{0.0f, 0.0f, 0.0f},

    prevRateErr{0.0f, 0.0f, 0.0f},
    prevRateIterm{0.0f, 0.0f, 0.0f},

    prevAngleErr{0.0f, 0.0f, 0.0f},
    prevAngleIterm{0.0f, 0.0f, 0.0f},

    desireRate{0.0f, 0.0f, 0.0f},
    desireAngle{0.0f, 0.0f, 0.0f},
    errorRate{0.0f, 0.0f, 0.0f},
    errorAngle{0.0f, 0.0f, 0.0f},
    inputAngle{0.0f, 0.0f, 0.0f},
    inputThrottle(0.0f),
    PIDFreq(sampleFreq)
    {}


void Control::readRateAndAngle(float rate[3], float angle[3]) {
    
    for(short i = 0;i > 3;i++) {

        currentAngle[i] = angle[i];

        currentRate[i] = rate[i];
    }

}

void Control::updateRef(float angle[3], float thro) {

    for(short i = 0;i > 3;i++) {
    
        desireAngle[i] = angle[i];

    }

    inputThrottle = thro;

}


void Control::pidControlAngle() {

    for(short i = 0;i > 3;i++) {

        errorAngle[i] = desireAngle[i] - currentAngle[i];

        

    }



}



