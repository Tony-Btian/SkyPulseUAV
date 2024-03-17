#ifndef __UART_H__
#define __UART_H__

#include <cstdint>

class UART {

public:

    UART(uint32_t baudRate);

    ~UART();

    void writeUART(char* buf, unsigned size);

    void readUART();

protected:

    // int serialInit();

private:

    int handle;

    // uint16_t baudRate;

};

#endif