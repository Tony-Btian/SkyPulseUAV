#ifndef CONCRETEMEDIATOR_H
#define CONCRETEMEDIATOR_H

#include "Mediatorinterface.h"
#include <QObject>

class MainWindow; // Forward declaration

class ConcreteMediator : public QObject, public MediatorInterface {
    Q_OBJECT
public:
    explicit ConcreteMediator(MainWindow *mainWindow);
    void notify(const QString &message) override;

private:
    MainWindow *mainWindow; // Holds a reference or pointer to MainWindow
};

#endif // CONCRETEMEDIATOR_H
