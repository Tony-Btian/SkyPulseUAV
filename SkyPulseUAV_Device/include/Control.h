#ifndef __CONTROL_H__
#define __CONTROL_H__

#include "CppThread.hpp"

#define defaultSampleFreq 100.0f
#define ROLL 0
#define PITCH 1
#define YAW 2

#define ITERM_MAX 1500.0f

class ControlThread : public CppThread {

protected:

    void run() override;

};

class Control {

public:

    Control();

    Control(float sampleFreq);

    void getControlOuput(int motorDutyCycle[4]);

    void updateRef(float angle[3], float thro);

    void readRateAndAngle(float rate[3], float angle[3]);

protected:

    void doublepidControl();

    // void pidControlRate();

    // void cascadedPID();


private:

    float currentRate[3];

    float currentAngle[3];
   
    float prevRateErr[3];

    float prevAngleErr[3];

    float prevRateIterm[3];

    float prevAngleIterm[3];

    //float desireRate[3];

    float desireAngle[3];

    float errorRate[3];

    float errorAngle[3];

    float outputAngle[3];

    float outputRate[3];

    float inputThrottle;

    float PIDFreq;

    int motorOutput[4];

    float Kp_out[3];

    float Kp_in[3];

    float Ki_out[3];

    float Ki_in[3];

    float Kd[3];
};



#endif