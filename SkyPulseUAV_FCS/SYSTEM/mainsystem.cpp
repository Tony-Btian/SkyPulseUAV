#include "mainsystem.h"
#include "concretemediator.h"
#include <QDebug>

MainSystem::MainSystem()
{
    UI_Initial();
    GPIO_Initial();
    Function_Initial();
}

MainSystem::~MainSystem()
{
    qWarning("System Quit");
//    delete motor_pwm;
    gpioTerminate();
}

void MainSystem::UI_Initial()
{
    function_button1 = new QPushButton("Function1", this);
    function_button2 = new QPushButton("Function2", this);
    layout = new QHBoxLayout();
    layout->addWidget(function_button1);
    layout->addWidget(function_button2);
    setLayout(layout);

    // QPushbutton Signal
    connect(function_button1, &QPushButton::clicked, this, &MainSystem::onButtonClicked_Function1);
    connect(function_button2, &QPushButton::clicked, this, &MainSystem::onButtonClicked_Function2);
    qWarning("SkyPluse UAV System Initialized");
    qWarning("===============================");
    qDebug() << "Main System Initialized Thread:" << QThread::currentThreadId();
}

void MainSystem::GPIO_Initial()
{
    // Initial GPIO
    while(true){
        if (gpioInitialise() < 0) {
            qWarning("Failed to initialize pigpio. Retrying in 1 second...");
            QThread::sleep(2); // wait for 1 s
            continue; // continue loop
        }
        qWarning("Pigpio initialized successfully");
        notifyObservers(true);
        break; // Successful initialization, jump out of the loop
    }
}

void MainSystem::Function_Initial()
{
    /*Sensors*/
    sensor_manager = new SensorManager();
    connect(this, &MainSystem::sig_readAllSensorDataTest, sensor_manager, &SensorManager::ReadAllSensorData);

    tcp_server = new TCP();
    motor_pwm = new MotorPWM(this);
    connect(tcp_server, &TCP::sig_sendPWMSignal, motor_pwm, &MotorPWM::setMotorPWMSignal);
}

void MainSystem::onButtonClicked_Function1()
{
    emit sig_readAllSensorDataTest();
    // Atom action
}

void MainSystem::onButtonClicked_Function2()
{
    qWarning("Function Button 2 Click");
}
