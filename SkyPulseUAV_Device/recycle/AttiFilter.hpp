#ifndef ATTI_FILTER
#define ATTI_FILTER

#include "CppThread.hpp"
#include "sensor_data.hpp"



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