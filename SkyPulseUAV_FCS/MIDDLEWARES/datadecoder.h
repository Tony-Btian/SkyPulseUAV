#ifndef DATADECODER_H
#define DATADECODER_H

#include <QObject>

class DataDecoder : public QObject
{
    Q_OBJECT // Enables signal-slot mechanism and other meta-object features

public:
    explicit DataDecoder(QObject *parent = nullptr); // Constructor with optional parent QObject

public slots:
    void decodeData(const QByteArray &raw_data); // Slot to receive and process raw data

signals:
    void dataDecoded(const QString &decodedData); // Signal emitted after data is decoded
};

#endif // DATADECODER_H

