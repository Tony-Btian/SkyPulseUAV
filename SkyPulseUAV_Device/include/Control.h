#ifndef __CONTROL_H__
#define __CONTROL_H__

#include <functional>
#include <chrono>
#include <iostream>

#include "CppThread.hpp"
#include "Motor.h"
#include "TCP.h"

#define defaultSampleFreq 100.0f
#define ROLL 0
#define PITCH 1
#define YAW 2

#define ITERM_MAX 1500.0f

// Define maximum roll and pitch angles (in degrees)
const float MAX_ROLL_ANGLE = 45.0f;
const float MAX_PITCH_ANGLE = 45.0f;

using namespace std;
using namespace std::chrono;

class Control 
{

public:

    using CallbackFunction = function<void(int[4])>;

    Control();

    Control(float userDefinedFreq);

    void getControlOuput();

    int getControlFreqInv();

    void readRef(float angle[3], float alt);

    void readCur(float rate[3], float angle[3], float alt);

    // If mode is true, manned mode is enabled. Else, automatic mode is enabled.
    void setMode(bool mode);

    void setCallback(CallbackFunction callback);

    void readDataFromFilter(float roll, float pitch, float yaw, float rate[3]);

    void readDataFromBMP180(float altitude);

    void readDataFromMotor();

    void readDataFromIR(uint8_t IRObstacleDetected);

    void readDataFromUS(int USDistance);

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

    int PIDFreqInv;

    int motorOutput[4];

    float Kp_out[3];

    float Kp_in[3];

    float Ki_out[3];

    float Ki_in[3];

    float Kd[3];

    uint8_t IRObstacleDetected;

    int USDistance;
};

class ControlThread : public CppThread 
{

public:

    ControlThread(Control& ControlIns_, MahonyFilter& MahonyFilterIns_, 
    BMP180& BMP180Ins_, IRSensor& IRSensorIns_, USSensor& USSensorIns_, 
    TCP& TCPIns_) :
    MahonyFilterIns(MahonyFilterIns_),
    BMP180Ins(BMP180Ins_),
    IRSensorIns(IRSensorIns_),
    USSensorIns(USSensorIns_),
    ControlIns(ControlIns_),
    TCPIns(TCPIns_)
    {};

protected:

    void run() override;

private:

    Control& ControlIns;
    MahonyFilter& MahonyFilterIns;
    BMP180& BMP180Ins;
    IRSensor& IRSensorIns;
    USSensor& USSensorIns;
    TCP& TCPIns;

};


#endif