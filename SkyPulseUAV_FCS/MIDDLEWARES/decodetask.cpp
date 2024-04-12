#include "decodetask.h"
#include <QDebug>

DecodeTask::DecodeTask(const QByteArray &data) : data(data)
{
    // Constructor initializes DecodeTask with data to be decoded
}

void DecodeTask::run()
{
    QString decodeData = decode(data); // Call the decode function on the provided data
    qDebug() << "Decoded data: " << decodeData; // Output decoded data to the debug log
}

QString DecodeTask::decode(const QByteArray &data)
{
    return QString::fromUtf8(data).toUpper(); // Convert data from UTF-8 and make it uppercase
}

