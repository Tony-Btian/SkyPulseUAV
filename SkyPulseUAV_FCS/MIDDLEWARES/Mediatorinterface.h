#ifndef MEDIATORINTERFACE_H
#define MEDIATORINTERFACE_H

#include <QString>

class MediatorInterface {
public:
    virtual ~MediatorInterface() {}
    virtual void notify(const QString &message) = 0; // Method used to notify MainWindow from Handler
};

#endif // MEDIATORINTERFACE_H
