#ifndef __MAHONY_FILTER_H__
#define __MAHONY_FILTER_H__

#define sampleFreq	200.0f			// sample frequency in Hz
#define twoKpDef	(2.0f * 0.2f)	// 2 * proportional gain
#define twoKiDef	(2.0f * 0.001f)	// 2 * integral gain

class MahonyFilter {

public:

    MahonyFilter();

    MahonyFilter(float filterSample, float twoPropGain, float twoInteGain);

    void MahonyAHRSupdate(float gx, float gy, float gz, float ax, float ay, float az, float mx, float my, float mz);

    void MahonyAHRSupdateIMU(float gx, float gy, float gz, float ax, float ay, float az);

    void getQuaternion(float q_new[4]);

    void setKi(float twokiSet);

    void setKp(float twokpSet);

    void setFrequency(float f);

protected:

    float invSqrt(float x);

private:

    float twoKp;
    float twoKi;
    float q[4];
    float frequency;
    float integralFBx; 
    float integralFBy;
    float integralFBz;
};


#endif