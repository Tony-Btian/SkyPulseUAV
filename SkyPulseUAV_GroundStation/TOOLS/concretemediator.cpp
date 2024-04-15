#include "concretemediator.h"
#include "mainwindow.h"

ConcreteMediator::ConcreteMediator(MainWindow *mainWindow)
    : mainWindow(mainWindow) {}

void ConcreteMediator::notify(const QString &message) {
    // 假设MainWindow有一个更新UI的槽函数updateUI
    QMetaObject::invokeMethod(mainWindow, "updateUI", Q_ARG(QString, message));
}
