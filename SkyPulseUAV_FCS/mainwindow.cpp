#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textBrowser_Main->append("SkyPulse UAV Startup");
    ui->textBrowser_Main->append("=============================");

    PWMDriver = new ESC_PWM_Driver(this);  // PWM Driver
//    gpiointerrupt = new GpioInterruptHandler();
    addObserver(PWMDriver);  // Registered Observers
//    addObserver(gpiointerrupt);

    // Initial GPIO
    while(true){
        if (gpioInitialise() < 0) {
            ui->textBrowser_Main->append("Failed to initialize pigpio. Retrying in 1 second...");
            QThread::sleep(1); // wait for 1 s
            continue; // continue loop
        }
        ui->textBrowser_Main->append("Pigpio initialized successfully.");
        notifyObservers(true);
        break; // Successful initialization, jump out of the loop
    }

    // Class Materialisation
    IMU = new MPU6050(0x68, this);              // MPU6050
    BMP180 = new Barometer_BMP180(0x77, this);  // BMP180
    GY271 = new Magnetometer_GY271(0x0D, this); // GY271
    TCPServer = new TCP();  // TCP Server


    connect(this, &MainWindow::sig_TCPBroadCastMessage, TCPServer, &TCP::broadcastMessage);
    connect(this, &MainWindow::sig_readTemperature, BMP180, &Barometer_BMP180::readTemperature);
    connect(this, &MainWindow::sig_readAllRegisters_BMP180, BMP180, &Barometer_BMP180::readAllRegisters);
    connect(this, &MainWindow::sig_readDirection, GY271, &Magnetometer_GY271::readRawData);

    /* TCP Server Signals */
    connect(TCPServer, &TCP::sig_requestReadAllReg_BMP180, BMP180, &Barometer_BMP180::readAllRegisters);
    connect(TCPServer, &TCP::sig_sendPWM0Signal, PWMDriver, &ESC_PWM_Driver::setPWM0Signal);

    /* Read All Register Signals */
    connect(BMP180, &Barometer_BMP180::sig_allRegistersData, TCPServer, &TCP::sendMessage64Bytes);

}

MainWindow::~MainWindow()
{
    qDebug() << "End!";
    // Release of dynamically allocated resources
    delete PWMDriver;
    delete IMU;
    delete BMP180;
    delete GY271;
    gpioTerminate();
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMainWindow::closeEvent(event);
}

void MainWindow::on_pushButton_BMP_clicked()
{
    qDebug() << "Main Window Thread: " << QThread::currentThreadId();
//    emit sig_TCPBroadCastMessage("Hello from Raspberry Pi");
    readSensorData();
    emit sig_readTemperature();
    emit sig_readDirection();

//    int level = gpioRead(17);
//    if (level == PI_HIGH) {
//        qDebug()<<"GPIO is HIGH\n";
//    } else if (level == PI_LOW) {
//        qDebug()<< "GPIO is LOW\n";
//    } else {
//        qDebug()<<"Failed to read GPIO %d\n";
//    }
}

void MainWindow::on_pushButton_HMC_clicked()
{
//    gpioSetMode(18, PI_OUTPUT);
//    gpioHardwarePWM(18, 100, 300000);
    emit sig_readAllRegisters_BMP180();
}

void MainWindow::on_pushButton_Take_Off_clicked()
{

}



void MainWindow::readSensorData()
{
    float ax, ay, az, gx, gy, gz;
    IMU->readAllSensors(ax, ay, az, gx, gy, gz);
    qDebug() << "Acceleration:" << ax << ay << az;
    qDebug() << "Gyroscope:" << gx << gy << gz;
}

void MainWindow::callBackTest()
{
    qDebug() << "Detected";
}




