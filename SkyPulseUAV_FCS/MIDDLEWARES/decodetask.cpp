#include "decodetask.h"
#include <QDebug>

DecodeTask::DecodeTask(const QByteArray &data) : data(data)
{

}

void DecodeTask::run()
{
//    QString decodeData = decode(data);
//    qDebug() << "Decoded data: " << decodeData;
    if (data.isEmpty()) return;
    switch (static_cast<unsigned char>(data[0])) {
    case 0x00:
        qDebug() << "0x00 data reveived";
        break;
    default:
        break;
    }
}

QString DecodeTask::decodeFunction(const QByteArray &data)
{
    return nullptr;
}
