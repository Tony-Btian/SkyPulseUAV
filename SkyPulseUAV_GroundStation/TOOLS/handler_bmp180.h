#ifndef HANDLER_BMP180_H
#define HANDLER_BMP180_H

#include "DataHandler.h"
#include "MediatorInterface.h"
#include <QObject>

class Handler_BMP180 : public QObject, public DataHandler
{
    Q_OBJECT

public:
    Handler_BMP180(MediatorInterface *mediator);
    void handleData(const QByteArray &data) override;

private:
    MediatorInterface *mediator;

signals:
    // void dataProcessed(const QString &result);

};

#endif // HANDLER_BMP180_H
