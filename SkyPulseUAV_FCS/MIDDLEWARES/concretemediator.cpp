#include "concretemediator.h"
#include "mainwindow.h"

ConcreteMediator::ConcreteMediator(MainWindow *mainWindow)
    : mainWindow(mainWindow) {}

void ConcreteMediator::notify(const QString &message) {
    QMetaObject::invokeMethod(mainWindow, "updateUI", Q_ARG(QString, message));
}
