#ifndef CONCRETEMEDIATOR_H
#define CONCRETEMEDIATOR_H

#include "MediatorInterface.h"
#include <QObject>

class MainWindow; // 前向声明

class ConcreteMediator : public QObject, public MediatorInterface {
    Q_OBJECT
public:
    explicit ConcreteMediator(MainWindow *mainWindow);
    void notify(const QString &message) override;

private:
    MainWindow *mainWindow; // 持有MainWindow的引用或指针
};

#endif // CONCRETEMEDIATOR_H
