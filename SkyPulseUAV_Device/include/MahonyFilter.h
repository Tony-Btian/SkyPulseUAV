#ifndef __MAHONY_FILTER_H__
#define __MAHONY_FILTER_H__

#include <atomic>

#define sampleFreq	200.0f			// sample frequency in Hz
#define twoKpDef	(2.0f * 0.03f)	// 2 * proportional gain
#define twoKiDef	(2.0f * 0.01f)	// 2 * integral gain

class MahonyFilter {

public:

    MahonyFilter();

    MahonyFilter(float filterSample, float twoPropGain, float twoInteGain);

    void getAngle(float* roll, float* pitch, float* yaw, float g[3]);

    //void getQuaternion(float q_new[4]);

    void setFrequency(float f);

    void readRawData(float a[3], float g[3], float m[3]);

    void MahonyAHRSupdate();

    void MahonyAHRSupdateIMU();

    short checkFilterReady();

protected:

    float invSqrt(float x);

    void setKi(float twokiSet);

    void setKp(float twokpSet);

private:

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

    std::atomic<short> filter_done; 
};


#endif