#ifndef __CONTROL_H__
#define __CONTROL_H__

#define defaultSampleFreq 100.0f
#define ROLL 0
#define PITCH 1
#define YAW 2

class Control {

public:

    Control();

    Control(float sampleFreq);

    void getControlOuput(int* motorDutyCycle[4]);

    void updateRef(float angle[3], float thro);

    void readRateAndAngle(float rate[3], float angle[3]);

protected:

    void pidControlAngle();

private:

    float currentRate[3];

    float currentAngle[3];
   
    float prevRateErr[3];

    float prevAngleErr[3];

    float prevRateIterm[3];

    float prevAngleIterm[3];

    float desireRate[3];

    float desireAngle[3];

    float errorRate[3];

    float errorAngle[3];

    float outputAngle[3];

    float inputThrottle;

    float PIDFreq;

    int motorOutput[4];

    float Kp[3];

    float Ki[3];

    float Kd[3];
};



#endif