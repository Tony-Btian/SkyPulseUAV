#ifndef DATADECODER_H
#define DATADECODER_H

#include <QObject>

class DataDecoder : public QObject
{
    Q_OBJECT

public:
    explicit DataDecoder(QObject *parent = nullptr);

public slots:
    void decodeData(const QByteArray &raw_data);

signals:
    void dataDecoded(const QString &decodedData);
};

#endif // DATADECODER_H
