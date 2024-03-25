#ifndef __CONTROL_H__
#define __CONTROL_H__

#include <functional>

#include "CppThread.hpp"

#define defaultSampleFreq 100.0f
#define ROLL 0
#define PITCH 1
#define YAW 2

#define ITERM_MAX 1500.0f

// Define maximum roll and pitch angles (in degrees)
const float MAX_ROLL_ANGLE = 45.0f;
const float MAX_PITCH_ANGLE = 45.0f;

using namespace std;

class ControlThread : public CppThread {

protected:

    void run() override;

};

class Control {

public:

    using CallbackFunction = function<void(int[4])>;

    Control();

    Control(float sampleFreq);

    void getControlOuput(int motorDutyCycle[4]);

    void readRef(float angle[3], float alt);

    void readCur(float rate[3], float angle[3], float alt);

    // If mode is true, manned mode is enabled. Else, automatic mode is enabled.
    void setMode(bool mode);

    void setCallback ();

protected:

    void doublePIDControl();

    void altControl();

    // void pidControlRate();

    // void cascadedPID();


private:

    CallbackFunction callback_;

    bool mode;

    float desireAlt;

    float altVelocity;

    float errorAlt;

    float currentAlt;

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