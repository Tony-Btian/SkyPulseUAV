#ifndef SENSOR_DATA
#define SENSOR_DATA

#include <mutex>
#include <atomic>
#include <shared_mutex>

extern std::atomic<bool> initialise_ready;
extern std::atomic<bool> calibrate_ready;
extern std::atomic<bool> mpu6050_newdata;

extern std::atomic<bool> srf05_ready;
extern std::atomic<uint32_t> risingEdgeTime;
extern std::atomic<uint32_t> fallingEdgeTime;
extern std::atomic<float> distance;

extern std::atomic<float> altitude;

extern std::mutex i2cmtx;
extern std::mutex cvmtx;

struct MPU6050Data {
    std::atomic<float> ax;
    std::atomic<float> ay;
    std::atomic<float> az;
    std::atomic<float> gx;
    std::atomic<float> gy;
    std::atomic<float> gz;
    std::atomic<float> mx;
    std::atomic<float> my;
    std::atomic<float> mz;
    //bool initialise_ready;  // flag for initialisation of sensors
    //bool calibrate_ready;  // flag for successfully calibration of sensors
    //std::shared_mutex rawdata_mutex;
};

struct AttitudeData {
    float roll;
    float pitch;
    float yaw;
    std::shared_mutex attitude_mutex;
};


#endif // SENSOR_DATA_H