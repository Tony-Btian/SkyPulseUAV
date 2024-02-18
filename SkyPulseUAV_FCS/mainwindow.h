#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThreadPool>

#include "meg_compass.h"
#include "i2c_manager.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    QThreadPool threadPool;
    I2C_Manager *i2cManager;
    MEG_Compass *hmc5883l;

};
#endif // MAINWINDOW_H
