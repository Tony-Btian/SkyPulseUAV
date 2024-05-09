#ifndef FLIGHTCONTROL_H
#define FLIGHTCONTROL_H

#include <QObject>
#include <QVector>

class FlightControl : public QObject
{
    Q_OBJECT
public:
    explicit FlightControl(int pitch, int yaw, int roll, int thrust, QObject *parent = nullptr);
    ~FlightControl();

    void setPitch(int pwmValue);
    void setYaw(int pwmValue);
    void setRoll(int pwmValue);
    void setThrust(int pwmValue);

    void updateMotorSpeeds(double pitch, double roll, double yaw, double thrust);

private:
    int Pitch_, Yaw_, Roll_, Thrust_;

    quint8 clampToUint8(double value);

signals:
    void sig_sendMotorData(QVector<quint8> Motor_PWM);
};

#endif // FLIGHTCONTROL_H
