#ifndef BAROMETER_THREAD
#define BAROMETER_THREAD

#include "CppThread.hpp"
#include "sensor_data.hpp"

#define BMP180_ADDRESS 0x77
#define IIC_BUS 1
/**************************************************************************************/
#define MY_ALTITUDE 10.0f  // Before calibration, set the altitude of your location here!
/**************************************************************************************/

class BaroDataCollectionThread : public CppThread {
public:
	//BaroDataCollectionThread(BaroData& data) : sharedBaro(data) {}

private:
	void run();

protected:
	//BaroData& sharedBaro;
};

void initializeBaro(int* handle, bool* needToExit);

void baroReadEEPROM(int handle, char* eeprom, bool* needToExit);

void baroReadTempAndPres(int handle, float* t, long* p, bool* needToExit);

void baroGetAbsAlti(int handle, long p, float sealevelPressure, bool* needToExit);

void sealevelPresCorrect(float* sealevelPressure, long p);

#endif