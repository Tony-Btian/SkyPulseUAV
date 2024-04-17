#include "flightcontrol.h"
#include <QDebug>

FlightControl::FlightControl(int pitch, int yaw, int roll, int thrust, QObject *parent)
    : QObject(parent), Pitch_(pitch), Yaw_(yaw), Roll_(roll), Thrust_(thrust)
{

}

FlightControl::~FlightControl()
{

}

void FlightControl::setPitch(int pwmValue)
{
    qDebug() << pwmValue;
    Pitch_ = pwmValue;
    updateMotorSpeeds(Pitch_, Roll_, Yaw_, Thrust_);
}

void FlightControl::setYaw(int pwmValue)
{
    Yaw_ = pwmValue;
    updateMotorSpeeds(Pitch_, Roll_, Yaw_, Thrust_);
}

void FlightControl::setRoll(int pwmValue)
{
    Roll_ = pwmValue;
    updateMotorSpeeds(Pitch_, Roll_, Yaw_, Thrust_);
}

void FlightControl::setThrust(int pwmValue)
{
    Thrust_ = pwmValue;
    updateMotorSpeeds(Pitch_, Roll_, Yaw_, Thrust_);
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
