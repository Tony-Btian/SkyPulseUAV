#ifndef ACCELERATION_THREAD
#define ACCELERATION_THREAD

#include "CppThread.hpp"
#include "sensor_data.hpp"

//typedef void (*gpioISRFunc_t) (int gpio, int level, uint32_t tick);

#define MPU6050_ADDRESS 0x68
#define GY_271_ADDRESS 0x0D
#define IIC_BUS 1
#define INT_PIN 16  // interrupt pin(BCM)
#define RAD_TO_DEG 57.295779513082320876798154814105   // radium to degree
#define DEG_TO_RAD 0.01745329251994329576923690768489 // degree to radium

extern int handle_MPU6050;
extern int handle_GY_271;

class DataCollectionThread : public CppThread {
public:
	DataCollectionThread(AttitudeData& atti) : sharedAtti(atti) {}
private:
	void run();

protected:
	AttitudeData& sharedAtti;
};

void initializeMPU(int* handle, char* sampleRate, bool* needToExit);

void initializeMag(int* handle, bool* needToExit);

void setRangeOfAcce(int handle, bool* needToExit);

void setRangeOfGyro(int handle, bool* needToExit);

void getAGMData(int GPIO, int level, unsigned int tick);

void initializeMPUISR(bool* needToExit);

void initializeMPU6050Data(MPU6050Data& mpu6050Data);

void MPU6050ReadData(int handle, char* data);

//void gyroReadData(int handle, char* data, bool* needToExit, int dataSize = 6);

void magReadData(int handle, char* data);

#endif
