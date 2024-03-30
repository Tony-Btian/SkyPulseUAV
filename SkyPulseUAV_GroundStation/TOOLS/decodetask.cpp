#include "decodetask.h"
#include <QDebug>

DecodeTask::DecodeTask(const QByteArray &data)
    : dataToDecode{data}
{

}

void DecodeTask::run()
{
    // Decode the data. This is a placeholder for your decoding logic.
    QString result;
    for(int i = 0; i < dataToDecode.size(); ++i) {
        QString byteString = QString::number(static_cast<unsigned char>(dataToDecode[i]), 16).rightJustified(2, '0');
        result.append(byteString + " ");
        if ((i+1) % 16 == 0) result.append("\n"); // New line after every 16 bytes for readability
    }

    qDebug() << "Decoded data:" << result;
    emit decodeDataReady(result);
}
