#include "decodetask.h"
#include "datahandlerfactory.h"
#include <QDebug>
#include <QThread>

DecodeTask::DecodeTask(const QByteArray &data, MediatorInterface *mediator) : dataToDecode(data)
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

    // 使用DataHandlerFactory根据接收到的数据创建一个DataHandler实例
    auto handler = DataHandlerFactory::createHandler(dataToDecode, mediator);
    if (handler) {
        // 使用创建的handler处理数据
        handler->handleData(dataToDecode);
    }
    // emit decodeDataReady(result);
}
