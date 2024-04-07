#include "handler_bmp180.h"
#include <QDebug>

Handler_BMP180::Handler_BMP180(MediatorInterface *mediator) : mediator(mediator) {}

void Handler_BMP180::handleData(const QByteArray &data) {
    qDebug() << "Handler_BMP180DataHandlerFactory is processing data: " << data;
    QString result = "Result !!!!!";  // Result of processing
    mediator->notify(result); // Notify MainWindow through the intermediary
}
