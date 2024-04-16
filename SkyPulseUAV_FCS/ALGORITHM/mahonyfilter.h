#ifndef MAHONYFILTER_H
#define MAHONYFILTER_H

#include <QObject>
#include <QVector3D>
#include <QQuaternion>
#include <QMutexLocker>
#include <QMutex>
#include <atomic>

// Forward declaration
class MahonyFilter;

// Callback function type
using CallbackFunction = void (*)(MahonyFilter*, float roll, float pitch, float yaw, const QVector3D &rate);

class MahonyFilter : public QObject
{
    Q_OBJECT

public:
    explicit MahonyFilter(float sampleFrequency = 200.0f,
                 float twoKpDef = 2.0f * 0.5f,
                 float twoKiDef = 2.0f * 0.0f,
                 QObject *parent = nullptr);
    ~MahonyFilter();

    // Setting Filter Parameters
    void setFrequency(float frequency);
    void setKp(float kp);
    void setKi(float ki);

    // Updating IMU data
    void updateIMUData(float ax, float ay, float az, float gx, float gy, float gz, float mx = 0.0f, float my = 0.0f, float mz = 0.0f);

    // Registering Callback Functions
    void registerCallbackA(CallbackFunction callback);
    void registerCallbackB(CallbackFunction callback);

private:
    QVector3D accelData, gyroData, magnetoData;
    QMutex dataMutex;

    std::atomic<float> sampleFreq;
    std::atomic<float> twoKp; // 2x proportional gain
    std::atomic<float> twoKi; // 2x proportional gain

    QQuaternion q; // Quaternions used to represent directions
    QVector3D integralFB; // Integral error term, scaled by Ki

    std::atomic<bool> imuDataReady{false}; // IMU data readiness

    // Stores acceleration, gyroscope, magnetometer data
    std::atomic<float> ax{0}, ay{0}, az{0};
    std::atomic<float> gx{0}, gy{0}, gz{0};
    std::atomic<float> mx{0}, my{0}, mz{0};

    // pointer to a callback function
    CallbackFunction callbackA_ = nullptr;
    CallbackFunction callbackB_ = nullptr;

    // private member function
    void MahonyAHRSupdate(float gx, float gy, float gz, float ax, float ay, float az, float mx, float my, float mz);
    void MahonyAHRSupdateIMU(float gx, float gy, float gz, float ax, float ay, float az);
    float invSqrt(float x); // Calculate the reciprocal of the square root of x

public slots:
    void updateData(const QVector3D &accel, const QVector3D &gyro, const QVector3D &magneto); // Slots used to update data
    void process();

signals:
    void newAngleData(float roll, float pitch, float yaw);
    void newDataReady();
};

#endif // MAHONYFILTER_H
