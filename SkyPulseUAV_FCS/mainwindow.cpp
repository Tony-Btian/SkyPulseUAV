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

    i2cManager = new I2C_Manager(this);
    int deviceAddress = 0x3D;
    i2cManager->addDevice(deviceAddress);

    // Get I2C device instance and initialize HMC5883L object
    I2C_Device* device = i2cManager->getDevice(deviceAddress);
    if (device) {
        hmc5883l = new MEG_Compass(device, this);
        connect(hmc5883l, &MEG_Compass::rawDataRead, this, [this](int x, int y, int z) {
            ui->textBrowser_Main->append(QString("Raw data read from HMC5883L: X=%1, Y=%2, Z=%3").arg(x).arg(y).arg(z));
        });

        // Asynchronous reading of HMC5883L data
        hmc5883l->readRawData();
    } else {
        ui->textBrowser_Main->append("Failed to initialize HMC5883L");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

