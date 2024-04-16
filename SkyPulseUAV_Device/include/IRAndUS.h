#ifndef __IRANDUS_H__
#define __IRANDUS_H__

#include <functional>
#include <iostream>

#include "CppThread.hpp"
#include "pigpio.h"

// IR sensor pins.
#define IR_EN 20
#define IR1_IN 21
#define IR2_IN 22
#define IR3_IN 23
#define IR4_IN 24

// Ultrasonic sensor pins.
#define US_Trig 28
#define US_Echo 29

using namespace std;
using namespace std::chrono;

// Class for IR sensors (4).
class IRSensor
{

public:

    using CallbackFunction = function<void(uint8_t)>;

    IRSensor(gpioTimerFunc_t timerInterruptHandler);

    ~IRSensor();

    void getData();

    void setCallbackA(CallbackFunction callback);

    void setCallbackB(CallbackFunction callback);

    static void timerInterruptCallback();

    static gpioTimerFunc_t TimerISRHandler;

private:

    // Callback functions.
    CallbackFunction callbackA_;

    CallbackFunction callbackB_;

    // If IR sensors detect obstacles, 
    //      00000001 -- IR 1 sensor detects obstacles.
    //      00000010 -- IR 2 sensor detects obstacles.
    //      00000100 -- IR 3 sensor detects obstacles.
    //      00001000 -- IR 4 sensor detects obstacles.
    // Mixture of them can be derived by yourself.
    uint8_t IRObstacleDetected;

    static bool IRIsEnabled;

};

// Class for ultrasonic sensor.
class USSensor
{

public:

    using CallbackFunction = function<void(int)>;

    USSensor(gpioTimerFunc_t timerInterruptHandler, gpioISRFunc_t interruptHandler);

    ~USSensor();

    void getData();

    void setCallbackA(CallbackFunction callback);

    void setCallbackB(CallbackFunction callback);

    static gpioISRFunc_t ISRHandler;

    static gpioTimerFunc_t TimerISRHandler;

private:

    static void timerInterruptCallback();

    static void interruptCallback(int gpio, int level, uint32_t tick);

    CallbackFunction callbackA_;

    CallbackFunction callbackB_;

    // Accept distance sampled from ultrasonic sensor.
    static int USDistance;
    static int RisingTime;
    static int FallingTime;

    static bool isReady;

};

class IRAndUSThread : public CppThread
{

public:

    IRAndUSThread(IRSensor& IRSensorIns_, USSensor& USSensorIns_) :
    IRSensorIns(IRSensorIns_),
    USSensorIns(USSensorIns_) {};

protected:

    void run() override;

private:

    IRSensor& IRSensorIns;
    USSensor& USSensorIns;

};

#endif