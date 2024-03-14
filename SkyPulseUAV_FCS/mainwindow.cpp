#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textBrowser_Main->append("SkyPulse UAV Startup");
    ui->textBrowser_Main->append("=============================");

//    DatabaseManager dbManager("config.db");
//    dbManager.addOrUpdateParam("height", 100.1);
//    double height = dbManager.getParam("height");
//    qDebug() << "Height parameter value is: " << height;

    // Initial GPIO

    while(true){
        if (gpioInitialise() < 0) {
            qDebug() << "Failed to initialize pigpio. Retrying in 1 second...";
            ui->textBrowser_Main->append("Failed to initialize pigpio. Retrying in 1 second...");
            QThread::sleep(1); // wait for 1 s
            continue; // continue loop
        }
        qDebug() << "Pigpio initialized successfully.";
        ui->textBrowser_Main->append("Pigpio initialized successfully.");
        break; // Successful initialization, jump out of the loop
    }

    // BaroMeter BMP180
    BaroMeter = new Barometer_BMP180();
    BMP_Thread = new QThread();
    BaroMeter->moveToThread(BMP_Thread);
    BMP_Thread->start();

    connect(this, &MainWindow::sig_readPressure, BaroMeter, &Barometer_BMP180::readPressureData);
    connect(this, &MainWindow::sig_readTemperature, BaroMeter, &Barometer_BMP180::readTemperatureData);
    connect(BMP_Thread, &QThread::finished, BaroMeter, &QThread::deleteLater);

    // Magnetometer HMC5883L
    // meg_compass = new MEG_Compass();


    // TCP Server
    TCPServer = new TCP(this);
    TCPServer->startServer(12345);  // Listening on port 12345

    // PWM Driver
    PWMDriver = new ESC_PWM_Driver(this);
    connect(TCPServer, &TCP::sig_sendPWMSignal, PWMDriver, &ESC_PWM_Driver::setPwmSignal);
}

MainWindow::~MainWindow()
{
    if(BMP_Thread->isRunning()){
        BMP_Thread->quit();
        BMP_Thread->wait();
    }
    delete BMP_Thread;

    // Release of dynamically allocated resources
    delete BaroMeter;
    delete MagnetoMeter;
    delete TCPServer;
    gpioTerminate();

    delete ui;
}

void MainWindow::prepareForQuit() {
    if(BaroMeter) {
        BaroMeter->readingStop();
        BaroMeter->waitForThreadCompletion();
    }
}

void MainWindow::on_pushButton_BMP_clicked()
{
    qDebug() << "Main Window Thread: " << QThread::currentThreadId();
//    emit sig_readPressure();
//    emit sig_readTemperature();
    TCPServer->broadcastMessage("Hello from Raspberry Pi");
}


void MainWindow::on_pushButton_HMC_clicked()
{

}

void MainWindow::closeEvent(QCloseEvent *event) {
//    barometer->readingStop();
//    barometer->waitForThreadCompletion();
    prepareForQuit();
//    BaroMeter->readingStop();
//    BaroMeter->waitForThreadCompletion();
    QMainWindow::closeEvent(event);
}
