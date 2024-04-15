#include <QApplication>
#include "mainsystem.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainSystem mainSystem;
    mainSystem.resize(200, 60);
    mainSystem.show();
    return a.exec();
}
