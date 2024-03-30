#ifndef DATAHANDLERFACTORY_H
#define DATAHANDLERFACTORY_H

#include "DataHandler.h"
#include "handler_bmp180.h"

class DataHandlerFactory {
public:
    static DataHandler* createHandler(const QByteArray &data, MediatorInterface* mediator) {
        if (data.isEmpty()) return nullptr;

        DataHandler* handler = nullptr;
        switch (static_cast<unsigned char>(data[0])) {
        case 0x15:
            return new Handler_BMP180(mediator);
        case 0x02:

        default:
            return nullptr;
        }
    }
};

#endif // DATAHANDLERFACTORY_H
