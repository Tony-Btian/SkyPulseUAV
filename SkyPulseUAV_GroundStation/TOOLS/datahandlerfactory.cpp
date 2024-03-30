#include "datahandlerfactory.h"
#include "handlerbmp180.h"
#include <QDebug>

std::unique_ptr<DataHandler> DataHandlerFactory::createHandler(const QByteArray &data, MediatorInterface* mediator) {
    if (data.isEmpty()) return nullptr;

    /* Header Text Selector */
    switch (static_cast<unsigned char>(data[0])) {
    case 0x15:
        qDebug() << "Handler Activate";
        return std::make_unique<HandlerBMP180>(mediator);
        break;
    case 0x02:
        break;
    default:
        break;
    }
    return nullptr;
}
