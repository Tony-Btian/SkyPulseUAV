#ifndef __BMP180__THREAD_H__
#define __BMP180__THREAD_H__

#include "CppThread.hpp"

class BMP180Thread : public CppThread {

protected:

    void run() override;

};

#endif