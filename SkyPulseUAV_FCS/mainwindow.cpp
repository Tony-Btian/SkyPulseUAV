#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textBrowser_Main->append("SkyPulse UAV Startup");
    ui->textBrowser_Main->append("=============================");

    PWMDriver = new ESC_PWM_Driver(this);  // PWM Driver
    gpiointerrupt = new GpioInterruptHandler();
    addObserver(PWMDriver);  // Registered Observers
    addObserver(gpiointerrupt);

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
    IMU = new MPU6050(0x68, this);  // MPU6050
    TCPServer = new TCP();  // TCP Server

    connect(this, &MainWindow::sig_TCPStartServer, TCPServer, &TCP::startServer);
    connect(this, &MainWindow::sig_TCPBroadCastMessage, TCPServer, &TCP::broadcastMessage);
    connect(TCPServer, &TCP::sig_sendPWMSignal, PWMDriver, &ESC_PWM_Driver::setPwmSignal);
    connect(TCPServer, &TCP::sig_MPU6050ReadAll, IMU, &MPU6050::readAllMPU6050Reg);
    connect(gpiointerrupt, &GpioInterruptHandler::mpu6050Interrupt, this, &MainWindow::callBackTest);

    emit sig_TCPStartServer(12345);  // Listening on port 12345
}

MainWindow::~MainWindow()
{
    qDebug() << "End!";
    // Release of dynamically allocated resources
    delete gpiointerrupt;
    delete PWMDriver;
    delete TCPServer;
    delete IMU;
    gpioTerminate();
    delete ui;
}

void MainWindow::on_pushButton_BMP_clicked()
{
    qDebug() << "Main Window Thread: " << QThread::currentThreadId();
//    emit sig_TCPBroadCastMessage("Hello from Raspberry Pi");
    readSensorData();

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
    gpioSetMode(18, PI_OUTPUT);
    gpioHardwarePWM(18, 100, 300000);
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

void MainWindow::callBackTest()
{
    qDebug() << "Detected";
}
