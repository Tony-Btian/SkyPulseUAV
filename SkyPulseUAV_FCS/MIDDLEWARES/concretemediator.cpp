#include "concretemediator.h"
#include "mainsystem.h"

ConcreteMediator::ConcreteMediator(MainSystem *mainSystem)
    : mainSystem(mainSystem) {}

void ConcreteMediator::notify(const QString &message) {
    QMetaObject::invokeMethod(mainSystem, "BroadcastReceiver", Q_ARG(QString, message));
}
