#ifndef DATAHANDLERFACTORY_H
#define DATAHANDLERFACTORY_H

#include <QByteArray>
#include <memory>
#include "DataHandler.h"
#include "MediatorInterface.h"

class DataHandlerFactory
{
public:
    static std::unique_ptr<DataHandler> createHandler(const QByteArray &data, MediatorInterface* mediator);
};

#endif // DATAHANDLERFACTORY_H
