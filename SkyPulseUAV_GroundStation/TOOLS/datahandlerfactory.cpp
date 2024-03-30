#include "datahandlerfactory.h"
#include "MediatorInterface.h"
#include "handlerbmp180.h"
#include <QDebug>

std::unique_ptr<DataHandler> DataHandlerFactory::createHandler(const QByteArray &data) {
    if (data.isEmpty()) return nullptr;
    MediatorInterface *mediator;
    DataHandler* handler = nullptr;
    switch (static_cast<unsigned char>(data[0])) { // 确保第一个字节是无符号字符
    case 0x15:
        qDebug() << "Handler Activate";
        handler = new HandlerBMP180(mediator);
        break;
    case 0x02:
        break;
    // 可以根据需要添加更多的case
    default:
        break;
    }
    return handler;
}
