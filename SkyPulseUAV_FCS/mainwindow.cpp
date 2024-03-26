#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textBrowser_Main->append("SkyPulse UAV Startup");
    ui->textBrowser_Main->append("=============================");

    // Class Materialisation
    IMU = new MPU6050(this);  // MPU6050
    TCPServer = new TCP();  // TCP Server
    PWMDriver = new ESC_PWM_Driver(this);  // PWM Driver

    connect(this,       &MainWindow::sig_TCPStartServer,        TCPServer,  &TCP::startServer);
    connect(this,       &MainWindow::sig_TCPBroadCastMessage,   TCPServer,  &TCP::broadcastMessage);
    connect(TCPServer,  &TCP::sig_sendPWMSignal,                PWMDriver,  &ESC_PWM_Driver::setPwmSignal);
    connect(TCPServer,  &TCP::sig_MPU6050ReadAll,               IMU,        &MPU6050::readAllMPU6050Reg);

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

    device = new I2C_Device(0x68, this);
    if(!IMU->initialize(device)){
        qDebug() << "MPU6050 initialization failed!";
    } else {
        qDebug() << "MPU6050 initialized successfully.";
    }

    emit sig_TCPStartServer(12345);  // Listening on port 12345
}

MainWindow::~MainWindow()
{
    // Release of dynamically allocated resources
    delete IMU;
    delete device;
    delete TCPServer;
    gpioTerminate();
    delete ui;
}

void MainWindow::on_pushButton_BMP_clicked()
{
    qDebug() << "Main Window Thread: " << QThread::currentThreadId();
//    emit sig_TCPBroadCastMessage("Hello from Raspberry Pi");
    readSensorData();
}


void MainWindow::on_pushButton_HMC_clicked()
{

}

void MainWindow::closeEvent(QCloseEvent *event) {
    QMainWindow::closeEvent(event);
}

void MainWindow::readSensorData()
{
    float ax, ay, az, gx, gy, gz;
    IMU->readAllSensors(ax, ay, az, gx, gy, gz);
    qDebug() << "Acceleration:" << ax << ay << az;
    qDebug() << "Gyroscope:" << gx << gy << gz;
}
