#ifndef __MAHONY_FILTER_H__
#define __MAHONY_FILTER_H__

#include <atomic>
#include <functional>

#include "CppThread.hpp"
#include "MPU6050.h"

#define sampleFreq	200.0f			// sample frequency in Hz
#define twoKpDef	(2.0f * 0.05f)	// 2 * proportional gain
#define twoKiDef	(2.0f * 0.001f)	// 2 * integral gain

class MahonyFilter {

public:

    using CallbackFunction = std::function<void(float, float, float, float[3])>;

    MahonyFilter();

    MahonyFilter(float filterSample, float twoPropGain, float twoInteGain);

    //void getAngle(float* roll, float* pitch, float* yaw, float g[3]);

    void getAngleRate(float g[3]);

    //void getQuaternion(float q_new[4]);

    void setFrequency(float f);

    void readRawData(float a[3], float g[3], float m[3]);

    void MahonyAHRSupdate();

    void MahonyAHRSupdateIMU();

    bool isDataReady();

    // bool checkFilterReady_A();

    // bool checkFilterReady_B();

    // void resetFilterReady();

    void setCallbackA(CallbackFunction callback);

    void setCallbackB(CallbackFunction callback);

    void getAngle();

protected:

    float invSqrt(float x);

    void setKi(float twokiSet);

    void setKp(float twokpSet);

private:

    CallbackFunction callbackA_;
    CallbackFunction callbackB_;

    float twoKp;
    float twoKi;

    float q[4];
    float ax, ay, az;
    float gx, gy, gz;
    float mx, my, mz;

    std::atomic<float> gx_out;
    std::atomic<float> gy_out;
    std::atomic<float> gz_out;

    float frequency;
    float integralFBx; 
    float integralFBy;
    float integralFBz;

    std::atomic<float> roll;
    std::atomic<float> pitch;
    std::atomic<float> yaw;

    bool mpu_data_ready;

    // Two flags for two interfaces with different frequencies.
    bool filter_ready_A; 
    bool filter_ready_B;

};

class MahonyFilterThread : public CppThread {

public:

    MahonyFilterThread(MahonyFilter& MahonyFilterIns_, MPU6050& MPU6050Ins_) : 
    MahonyFilterIns(MahonyFilterIns_),
    MPU6050Ins(MPU6050Ins_) {};

protected:

    void run() override;

private:

    MahonyFilter& MahonyFilterIns;
    MPU6050& MPU6050Ins;

};

#endif