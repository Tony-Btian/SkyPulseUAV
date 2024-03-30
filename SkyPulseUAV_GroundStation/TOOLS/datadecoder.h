#ifndef DATADECODER_H
#define DATADECODER_H

#include <QObject>
#include <QByteArray>
#include <QDebug>

class DataDecoder : public QObject
{
    Q_OBJECT

public:
    explicit DataDecoder(QObject *parent = nullptr);

public slots:
    void decodeData(const QByteArray &data);

signals:
    void dataDecoded(const QString &decodedData);

};

#endif // DATADECODER_H
