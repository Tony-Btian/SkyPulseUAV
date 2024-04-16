#include "Control.h"

void ControlThread::run() 
{

    // Register callback functions.
    MahonyFilterIns.setCallbackB([this](float roll, float pitch, float yaw, float rate[3])
    {

        ControlIns.readDataFromFilter(roll, pitch, yaw, rate);
        
    });

    BMP180Ins.setCallbackB([this](float alt)
    {

        ControlIns.readDataFromBMP180(alt);

    });

    IRSensorIns.setCallbackB([this](uint8_t IRObstacleDetected)
    {

        ControlIns.readDataFromIR(IRObstacleDetected);

    });

    USSensorIns.setCallbackB([this](int distance)
    {

        ControlIns.readDataFromIR(distance);

    });

    // Read reference from TCP (ground station).
    TCPIns.setCallback([this](float desiredAngles[3], float desiredAlt)
    {

        ControlIns.readRef(desiredAngles, desiredAlt);

    });


    for(;;)
    {

        ControlIns.getControlOuput();
        
    }




}