#ifndef HANDLERBMP180_H
#define HANDLERBMP180_H

#include "DataHandler.h"
#include "MediatorInterface.h"

class HandlerBMP180 : public DataHandler
{
public:
    explicit HandlerBMP180(MediatorInterface *mediator);
    void handleData(const QByteArray &data) override;

private:
    MediatorInterface* mediator;
};

#endif // HANDLERBMP180_H
