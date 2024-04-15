#ifndef MEDIATORINTERFACE_H
#define MEDIATORINTERFACE_H

#include <QString>

class MediatorInterface {
public:
    virtual ~MediatorInterface() {}
    virtual void notify(const QString &message) = 0; // 用于从Handler通知MainWindow的方法
};

#endif // MEDIATORINTERFACE_H
