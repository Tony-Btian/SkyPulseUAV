#ifndef __MPU6050_THREAD_H__
#define __MPU6050_THREAD_H__

#include "CppThread.hpp"

class MPU6050Thread : public CppThread {

protected:

    void run() override;

};

#endif