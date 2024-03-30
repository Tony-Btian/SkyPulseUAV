#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <QByteArray>

class DataHandler{
public:
    virtual ~DataHandler() {}
    virtual void handleData(const QByteArray &data) = 0;
};

#endif // DATAHANDLER_H
