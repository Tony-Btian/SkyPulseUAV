#ifndef CONCRETEMEDIATOR_H
#define CONCRETEMEDIATOR_H

#include "MediatorInterface.h"
#include <QObject>

class MainSystem; // Forward declaration

class ConcreteMediator : public QObject, public MediatorInterface {
    Q_OBJECT
public:
    explicit ConcreteMediator(MainSystem *mainSystem);
    void notify(const QString &message) override;

private:
    MainSystem *mainSystem; // Holds a reference or pointer to MainWindow
};

#endif // CONCRETEMEDIATOR_H
