#ifndef __CONTROL_THREAD_H_
#define __CONTROL_THREAD_H_

#include "CppThread.hpp"

class ControlThread : public CppThread {

protected:

    void run() override;

};

#endif