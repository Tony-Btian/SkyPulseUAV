#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("SkyPulse UAV Flight Control System");
    w.show();

//    QObject::connect(&a, &QApplication::aboutToQuit, [&w]() {
//        w.prepareForQuit();
//    });

    return a.exec();
}
