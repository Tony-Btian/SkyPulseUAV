#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThreadPool>
#include <QThread>
#include "i2c_device.h"
#include "meg_compass.h"
#include "barometer_bmp180.h"

#define HMC5883l_DEVICE_ADDR 0x0D


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_BMP_clicked();
    void on_pushButton_HMC_clicked();

private:
    Ui::MainWindow *ui;
    QThreadPool threadPool;
    QThread *BMP_Thread;
    MEG_Compass *meg_compass;
    Barometer_BMP180 *BaroMeter;

signals:
    void sig_readPressure();
    void sig_readTemperature();

};
#endif // MAINWINDOW_H
