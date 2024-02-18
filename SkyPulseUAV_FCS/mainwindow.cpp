#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textBrowser_Main->append("SkyPulse UAV Startup");
    ui->textBrowser_Main->append("=============================");

    // Initial Threadpool
    threadPool.setMaxThreadCount(5);

    // Initial GPIO
    initialGPIO();
}

MainWindow::~MainWindow()
{
    delete ui;
    gpioTerminate();
}

void MainWindow::initialGPIO()
{
    // Initial GPIO
    if(gpioInitialise() < 0){
        ui->textBrowser_Main->append("Initial GPIO: Error!");
        qDebug() << "GPIO Initial Error";
        return;
    }
    ui->textBrowser_Main->append("Initial GPIO: Succeed!\n");
    gpioSetMode(13, PI_OUTPUT);
    gpioSetMode(23, PI_OUTPUT);
}
