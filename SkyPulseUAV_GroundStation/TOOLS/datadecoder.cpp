#include "datadecoder.h"

DataDecoder::DataDecoder(QObject *parent)
    : QObject{parent}
{}

void DataDecoder::decodeData(const QByteArray &data)
{
    QString decodedData;
    for(int i = 0; i < data.size(); ++i) {
        // Convert each byte to a two-character hex string, padded with zeros if necessary
        QString byteString = QString::number(static_cast<unsigned char>(data[i]), 16).rightJustified(2, '0');
        decodedData.append(byteString + " ");
        if ((i+1) % 16 == 0) decodedData.append("\n"); // New line after every 16 bytes for readability
    }
    qDebug() << "Decoded data:" << decodedData;
    emit dataDecoded(decodedData);
}
