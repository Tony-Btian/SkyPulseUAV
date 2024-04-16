#include "IRAndUS.h"

bool IRSensor::IRIsEnabled = false;

gpioTimerFunc_t IRSensor::TimerISRHandler = timerInterruptCallback;

// IR sensor source code.
IRSensor::IRSensor(gpioTimerFunc_t timerInterruptHandler) :
IRObstacleDetected{0}
{

    gpioSetMode(IR_EN, PI_OUTPUT);
    gpioSetMode(IR1_IN, PI_INPUT);
    gpioSetMode(IR2_IN, PI_INPUT);
    gpioSetMode(IR3_IN, PI_INPUT);
    gpioSetMode(IR4_IN, PI_INPUT);

    if (timerInterruptCallback  == nullptr)
    {

        cerr << "IR:Timer callback handler parameter is NULL, default handler is used." << endl;

        if(gpioSetTimerFunc(0, 10, TimerISRHandler) != 0)
        {
            cerr << "Can't enable timer 0!" << endl;
        }

    }

    else
    {

        if(gpioSetTimerFunc(0, 10, timerInterruptHandler) != 0)
        {
            cerr << "Can't disable timer 0!" << endl;
        }

    }

}

IRSensor::~IRSensor()
{

    if(gpioSetTimerFunc(0, 10, NULL) != 0)
    {

        cerr << "Can't disable timer 0." << endl;

    }

}

void IRSensor::getData()
{
    if(IRIsEnabled = true)
    {
        IRIsEnabled = false;

        this_thread::sleep_for(microseconds(210));

        for (int i = IR1_IN; i < 25; i++)
        {

            if(gpioRead(IR1_IN))
            {

                IRObstacleDetected &= ~(1 << (i - IR1_IN));

            }

            else 
            {
                this_thread::sleep_for(microseconds(400));

                if(gpioRead(IR1_IN))
                {

                    IRObstacleDetected &= ~(1 << (i - IR1_IN));

                }

                else
                {

                    IRObstacleDetected |= (1 << (i - IR1_IN));

                }
            }
        }

        gpioWrite(IR_EN, 0);
    }

    if(callbackA_)
    {
        callbackA_(IRObstacleDetected);
    }

    if(callbackB_)
    {
        callbackB_(IRObstacleDetected);
    }

}

void IRSensor::timerInterruptCallback()
{
    gpioWrite(IR_EN, 1);

    IRIsEnabled = true;
}

// Set callback functions.
void IRSensor::setCallbackA(CallbackFunction callback) 
{

    callbackA_ = callback;

}

void IRSensor::setCallbackB(CallbackFunction callback) 
{

    callbackB_ = callback;

}

/******************************************************/

// Ultrasonic sensor source code

int USSensor::RisingTime = 0;
int USSensor::FallingTime = 0;
int USSensor::USDistance = 0;
bool USSensor::isReady = false;

gpioISRFunc_t USSensor::ISRHandler = interruptCallback;

gpioTimerFunc_t USSensor::TimerISRHandler = timerInterruptCallback;

USSensor::USSensor(gpioTimerFunc_t timerInterruptCallback, gpioISRFunc_t interruptCallback)
{

    gpioSetMode(US_Trig, PI_OUTPUT);
    gpioSetMode(US_Echo, PI_INPUT);

    if (timerInterruptCallback  == nullptr)
    {

        cerr << "Timer callback handler parameter is NULL, default handler is used." << endl;

        if(gpioSetTimerFunc(1, 100, TimerISRHandler) != 0)
        {
            cerr << "Can't enable timer 0!" << endl;
        }

    }

    else
    {

        if(gpioSetTimerFunc(1, 100, timerInterruptCallback) != 0)
        {
            cerr << "Can't disable timer 0!" << endl;
        }

    }

    if (interruptCallback == nullptr)
    {

        cerr << "Interrupt callback handler parameter is NULL, default handler is used." << endl;

        if(gpioSetISRFunc(US_Echo, EITHER_EDGE, 50, ISRHandler) != 0)
        {
            cerr << "Can't disable interrupt of ultrasonic sensor!" << endl;
        }

    }

    else
    {

        if(gpioSetISRFunc(US_Echo, EITHER_EDGE, 50, interruptCallback) != 0)
        {
            cerr << "Can't disable interrupt of ultrasonic sensor!" << endl;
        }

    }

}

USSensor::~USSensor()
{

    if(gpioSetTimerFunc(1, 10, nullptr) != 0)
    {
        cerr << "Can't disable timer 0!" << endl;
    }
        
    if(gpioSetISRFunc(US_Echo, EITHER_EDGE, 50, nullptr) != 0)
    {
        cerr << "Can't disable interrupt of ultrasonic sensor!" << endl;
    }

}

void USSensor::getData()
{

    if (isReady)
    {

        isReady = false;

        if(callbackA_)
        {
            callbackA_(USDistance);
        }

        if(callbackB_)
        {
            callbackB_(USDistance);
        }

    }

}

void USSensor::setCallbackA(CallbackFunction callback)
{

    callbackA_ = callback;

}

void USSensor::setCallbackB(CallbackFunction callback)
{

    callbackB_ = callback;

}

void USSensor::timerInterruptCallback()
{

    gpioWrite(US_Trig, 1);
    this_thread::sleep_for(microseconds(20));
    gpioWrite(US_Trig, 0);

}

void USSensor::interruptCallback(int gpio, int level, uint32_t tick)
{

    if(gpio == US_Echo)
    {

        if(level == 1)
        {
            RisingTime = tick;
        }

        else if(level == 0)
        {
            FallingTime = tick;

            if(FallingTime > RisingTime)
            {

                USDistance = (FallingTime - RisingTime) / 5.88;

                isReady = true;

            }

        }

    }

    else 
    {
        cerr << "ERROR PIN OF ULTRASONIC SENSOR!!" << endl;
    }

}

void IRAndUSThread::run()
{

    // Given that ultrasonic sensor runs at a rate of 10Hz, there is no need to 
    // set another thread for it.
    for(;;)
    {
        // Get data and sent it to TCP thread.
        IRSensorIns.getData();
        USSensorIns.getData();

    }

}





