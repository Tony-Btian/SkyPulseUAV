#include "decodetask.h"
#include <QDebug>
#include <QThread>
#include "DataHandlerFactory.h"

DecodeTask::DecodeTask(const QByteArray &data, MediatorInterface *mediator) : dataToDecode(data), mediator(mediator)
{

}

void DecodeTask::run()
{
    qDebug() << "Decode Thread:" << QThread::currentThreadId();
    // Decode the data. This is a placeholder for your decoding logic.
    QString result;
    for(int i = 0; i < dataToDecode.size(); ++i) {
        QString byteString = QString::number(static_cast<unsigned char>(dataToDecode[i]), 16).rightJustified(2, '0');
        result.append(byteString + " ");
    }
    qDebug() << "Decoded data:" << result;

    DataHandler* handler = DataHandlerFactory::createHandler(dataToDecode, mediator);
    if (handler) {
        handler->handleData(dataToDecode);
        delete handler;  // Release resources
    }

    // emit decodeDataReady(result);
}
