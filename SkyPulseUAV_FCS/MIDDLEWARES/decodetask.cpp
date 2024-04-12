#include "decodetask.h"
#include <QDebug>

DecodeTask::DecodeTask(const QByteArray &data) : data(data)
{

}

void DecodeTask::run()
{
    QString decodeData = decode(data);
    qDebug() << "Decoded data: " << decodeData;
}

QString DecodeTask::decode(const QByteArray &data)
{
    return QString::fromUtf8(data).toUpper();
}
