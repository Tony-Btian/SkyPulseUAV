#ifndef __UART_H__
#define __UART_H__

#include <cstdint>

class UART {

public:

    UART(uint16_t baudRate);

    ~UART();

protected:

    int serialInit();

private:

    int handle;

    uint16_t baudRate;

};

#endif