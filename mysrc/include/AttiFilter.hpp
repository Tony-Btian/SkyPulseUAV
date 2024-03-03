#ifndef ATTI_FILTER
#define ATTI_FILTER

#include "CppThread.hpp"
#include "sensor_data.hpp"

#define RAD_TO_DEG 57.295779513082320876798154814105   // radium to degree
#define DEG_TO_RAD 0.01745329251994329576923690768489 // degree to radium

class AttiFilterThread : public CppThread {
public:
	//AttiFilterThread(SensorData& data, AttitudeData& atti) : sharedData(data), sharedAtti(atti) {}
	AttiFilterThread(AttitudeData& atti) :sharedAtti(atti) {}

private:
	void run();

protected:
	//SensorData& sharedData;
	AttitudeData& sharedAtti;

};

float invSqrt(float x);

#endif