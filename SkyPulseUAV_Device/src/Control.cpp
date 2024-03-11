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
    outputAngle{0.0f, 0.0f, 0.0f},
    inputThrottle(0.0f),
    PIDFreq(sampleFreq)
    {}


void Control::readRateAndAngle(float rate[3], float angle[3]) {
    
    for(short i = 0;i < 3;i++) {

        currentAngle[i] = angle[i];

        currentRate[i] = rate[i];
    }

}

void Control::updateRef(float refAngle[3], float thro) {

    for(short i = 0;i < 3;i++) {
    
        desireAngle[i] = refAngle[i];

    }

    inputThrottle = thro;

}

void Control::pidControlAngle() {

    for(short i = 0; i < 3; i++) {

        errorAngle[i] = desireAngle[i] - currentAngle[i];

        prevAngleIterm[i] += errorAngle[i] * (0.5f / PIDFreq);

        if(prevAngleIterm[i] > ITERM_MAX) prevAngleIterm[i] = ITERM_MAX;
        else if(prevAngleIterm[i] < -ITERM_MAX) prevAngleIterm[i] = -ITERM_MAX;

        outputAngle[i] = Kp_out[i] * errorAngle[i] + Ki_out[i] * prevAngleIterm[i];

        prevAngleErr[i] = errorAngle[i];

        errorRate[i] = outputAngle[i] - currentRate[i];

        prevRateIterm[i] += errorRate[i] * (0.5f / PIDFreq);

        outputRate[i] = Kp_in[i] * errorRate[i] + Ki_in[i] * prevRateIterm[i]
        + Kd[i] * (errorRate[i] - prevRateErr[i]) * (1.0f / PIDFreq);

        prevRateErr[i] = errorRate[i];
        
    }
}

// void Control::pidControlRate() {

//     for(short i = 0; i < 3; i++) {

//         errorRate[i] = outputAngle[i] - currentRate[i];

//         prevRateIterm[i] += errorRate[i] * (0.5f / PIDFreq);

//         outputRate[i] = Kp_in[i] * errorRate[i] + Ki_in[i] * prevRateIterm[i]
//         + Kd[i] * (errorRate[i] - prevRateErr[i]) * (1.0f / PIDFreq);

//         prevRateErr[i] = errorRate[i];
//     }
// }

void Control::getControlOuput(int motorDutyCycle[4]) {

    pidControlAngle();
    //pidControlRate();

    motorDutyCycle[0] = inputThrottle + outputRate[ROLL] - outputRate[PITCH] + outputRate[YAW];

}

