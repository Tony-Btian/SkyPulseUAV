#include <QApplication>
#include <QVector>
#include "mainsystem.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qRegisterMetaType<QVector<quint8>>("QVector<quint8>");
    MainSystem mainSystem;
    mainSystem.resize(200, 60);
    mainSystem.show();
    return a.exec();
}
