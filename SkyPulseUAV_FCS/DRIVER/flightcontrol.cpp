#include "flightcontrol.h"

FlightControl::FlightControl(int pitch, int yaw, int roll, int thrust, QObject *parent)
    : QObject(parent), Pitch_(pitch), Yaw_(yaw), Roll_(roll), Thrust_(thrust)
{

}

FlightControl::~FlightControl()
{

}

void FlightControl::initialize()
{

}

void FlightControl::setPitch(int pwmValue)
{

}

void FlightControl::setYaw(int pwmValue)
{

}

void FlightControl::setRoll(int pwmValue)
{

}

void FlightControl::setThrust(int pwmValue)
{

}

void FlightControl::updateMotorSpeeds(double pitch, double roll, double yaw, double thrust)
{
    QVector<quint8> MotorPWM{
        clampToUint8(thrust + pitch - roll - yaw),
        clampToUint8(thrust + pitch + roll + yaw),
        clampToUint8(thrust - pitch + roll - yaw),
        clampToUint8(thrust - pitch - roll + yaw)
    };
    emit sig_sendMotorData(MotorPWM);
}

quint8 FlightControl::clampToUint8(double value)
{
    if (value < 0) return 0;
    if (value > 255) return 255;
    return static_cast<quint8>(value);
}
