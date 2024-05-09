#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "concretemediator.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "Main Thread ID: " << QThread::currentThreadId();

    mediator = new ConcreteMediator(this);
    TCPServer = new TCP(nullptr, mediator);
    UDPServer = new UDP();
    MahonyPlotObject = new Mahony_Plot();

    // BluetoothThread = new QThread(this);
    // BluetoothServer = new Bluetooth();
    // BluetoothServer->moveToThread(BluetoothThread);
    // BluetoothThread->start();

    connect(ui->pushButton_Mahony_Plot_Launch, &QPushButton::clicked, MahonyPlotObject, &Mahony_Plot::startPlotting);
    connect(ui->pushButton_Mahony_Plot_Stop, &QPushButton::clicked, MahonyPlotObject, &Mahony_Plot::stopPlotting);


    /* TCP Server Connection Signals */
    connect(this, &MainWindow::sig_StartTCPServer,  TCPServer, &TCP::startTCPServer);
    connect(this, &MainWindow::sig_StopTCPServer,   TCPServer, &TCP::stopTCPServer);
    connect(this, &MainWindow::sig_StartUDPServer,  UDPServer, &UDP::startUDPServer);
    connect(this, &MainWindow::sig_StopUDPServer,   UDPServer, &UDP::stopUDPServer);

    connect(this, &MainWindow::sig_sendRequestToFCS, TCPServer, &TCP::commendToFCS);
    connect(this, &MainWindow::sig_sendPWMControlToFCS, TCPServer, &TCP::PWM_Controler);
    connect(this, &MainWindow::sig_sendFlightControlToFCS, TCPServer, &TCP::Flight_Controler);
    connect(this, &MainWindow::sig_sendMinThrottle, TCPServer, &TCP::Flight_Config_Setting);

    connect(TCPServer, &TCP::sig_startSuccessful,   this, &MainWindow::onTCPStartSuccessful);
    connect(TCPServer, &TCP::sig_stopSuccessful,    this, &MainWindow::onTCPStopSuccessful);
    connect(TCPServer, &TCP::sig_connectionError,   this, &MainWindow::onTCPConnectionError);
    connect(TCPServer, &TCP::sig_UIupdate,          this, &MainWindow::updateUI);


    /* UDP Server Connection Signals */

    connect(UDPServer, &UDP::ServerStartSucessful, this, &MainWindow::onUDPServerStartSuccessful);
    connect(UDPServer, &UDP::ServerStopSucessful, this, &MainWindow::onUDPServerStopSuccessful);

    /* Bluetooth Server Connection Signals */
    // connect(BluetoothThread, &QThread::finished, BluetoothServer, &QObject::deleteLater);

}

MainWindow::~MainWindow()
{
    emit sig_sendRequestToFCS(0x06);
    delete MahonyPlotObject;
    delete mediator;  // 如果需要，清理中介者实例
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QCoreApplication::quit();
}

void MainWindow::on_pushButton_Network_Connect_clicked()
{
    bool ok;
    // Network UI Reading
    QString NetworkIPAddr = ui->lineEdit_Network_IPAddr->text();
    quint16 NetworkPort = ui->lineEdit_Network_Port->text().toInt(&ok,10);

    // 判断端口输入是否有效
    if(ok){
        emit sig_StartTCPServer(NetworkIPAddr, NetworkPort);  // 采用信号的方式进行连接
        emit sig_StartUDPServer(NetworkPort);  // 开启UDP服务
    }
    else{
        QMessageBox::critical(this, "Error", "Error Port Input");
        ui->lineEdit_Network_Port->clear();
    }
}

void MainWindow::on_pushButton_Network_Disconnect_clicked()
{
    emit sig_StopTCPServer();
    emit sig_StopUDPServer();
}

void MainWindow::onTCPStartSuccessful()
{
    // 处理连接成功事件，更新UI状态
    ui->pushButton_Network_Connect->setEnabled(false);
    ui->pushButton_Network_Disconnect->setEnabled(true);
    ui->icon_TCP_Connection->setPixmap(QPixmap(":/qrc/icon/yes.png"));
}

void MainWindow::onTCPStopSuccessful()
{
    // 处理连接失败事件，更新UI状态
    ui->pushButton_Network_Connect->setEnabled(true);
    ui->pushButton_Network_Disconnect->setEnabled(false);
    ui->icon_TCP_Connection->setPixmap(QPixmap(":/qrc/icon/no.png"));
}

void MainWindow::onTCPConnectionError()
{
    // 处理连接失败事件，例如更新UI状态
    ui->pushButton_Network_Connect->setEnabled(true);
    ui->pushButton_Network_Disconnect->setEnabled(false);
    QMessageBox::critical(this, "Error", "TCP Connection Error. Please check the client device and try again.");
    ui->icon_TCP_Connection->setPixmap(QPixmap(":/qrc/icon/no.png"));
}

void MainWindow::onUDPServerStartSuccessful()
{
    ui->icon_UDP_Connection->setPixmap(QPixmap(":/qrc/icon/yes.png"));
}

void MainWindow::onUDPServerStopSuccessful()
{
    ui->icon_UDP_Connection->setPixmap(QPixmap(":/qrc/icon/no.png"));
}


/*========================================================================
* Fligth Control Panel
*=========================================================================*/
void MainWindow::on_pushButton_TAKE_OFF_clicked()
{
    emit sig_sendRequestToFCS(0x05);
}
void MainWindow::on_pushButton_LANDING_clicked()
{
    emit sig_sendRequestToFCS(0x06);
}


/*========================================================================
* Parameter Setting Panel
*=========================================================================*/
void MainWindow::on_pushButton_Mahony_Plot_Launch_clicked()
{
    emit sig_Mahony_PlottingStart();
}

void MainWindow::on_pushButton_Mahony_Plot_Stop_clicked()
{
    emit sig_Mahony_PlottingStop();
}


/*========================================================================
* Sensor Register Setting Panel
*=========================================================================*/
/* Navigation Bar*/
void MainWindow::on_toolButton_MPU6050_REG_CONFIG_clicked()
{
    ui->stackedWidget_REG_CONFIG->setCurrentIndex(0);
}

void MainWindow::on_toolButton_BMP180_REG_CONFIG_clicked()
{
    ui->stackedWidget_REG_CONFIG->setCurrentIndex(1);
}

void MainWindow::on_toolButton_GY271_REG_CONFIG_clicked()
{
    ui->stackedWidget_REG_CONFIG->setCurrentIndex(2);
}

/* MPU6050: Gyroscope&Accelerometer Sensor */
void MainWindow::on_pushButton_REG_READ_ALL_MPU6050_clicked()
{
    emit sig_sendRequestToFCS(0x00);
}

/* BMP180: Barometer&temperature Sensor */
void MainWindow::on_pushButton_REG_READ_ALL_BMP180_clicked()
{
    emit sig_sendRequestToFCS(0x01);
}

/* GY271: Magnetometer */
void MainWindow::on_pushButton_REG_READ_ALL_GY271_clicked()
{
    emit sig_sendRequestToFCS(0x02);
}



/* PWM Controler*/
void MainWindow::on_horizontalSlider_P12PWM0_valueChanged(int duty_cycle)
{
    ui->doubleSpinBox_P12PWM0->setValue(duty_cycle*100.0/255.0);
    SetPWM();
}
void MainWindow::on_horizontalSlider_P13PWM1_valueChanged(int duty_cycle)
{
    ui->doubleSpinBox_P13PWM1->setValue(duty_cycle*100.0/255.0);
    SetPWM();
}
void MainWindow::on_horizontalSlider_P19PWM2_valueChanged(int duty_cycle)
{
    ui->doubleSpinBox_P19PWM2->setValue(duty_cycle*100.0/255.0);
    SetPWM();
}
void MainWindow::on_horizontalSlider_P18PWM3_valueChanged(int duty_cycle)
{
    ui->doubleSpinBox_P18PWM3->setValue(duty_cycle*100.0/255.0);
    SetPWM();
}

void MainWindow::on_spinBox_MinThrottle_editingFinished()
{
    QVector<uint8_t> pwm_value { 0x07,
                               static_cast<uint8_t>(ui->spinBox_MinThrottle->value()),
                               static_cast<uint8_t>(ui->spinBox_MaxThrottle->value())
                               };

    emit sig_sendMinThrottle(pwm_value);
}


void MainWindow::on_verticalSlider_Pitch_valueChanged(int value)
{
    ui->doubleSpinBox_Pitch->setValue(value*360.0/255.0);
    SetFlightControl();
}
void MainWindow::on_verticalSlider_Yaw_valueChanged(int value)
{
    ui->doubleSpinBox_Yaw->setValue(value*360.0/255.0);
    SetFlightControl();
}
void MainWindow::on_verticalSlider_Roll_valueChanged(int value)
{
    ui->doubleSpinBox_Roll->setValue(value*360.0/255.0);
    SetFlightControl();
}
void MainWindow::on_verticalSlider_Thrust_valueChanged(int value)
{
    ui->doubleSpinBox_Thrust->setValue(value*100.0/255.0);
    SetFlightControl();
}
void MainWindow::on_doubleSpinBox_Pitch_valueChanged(double arg1)
{

}
void MainWindow::on_doubleSpinBox_Yaw_valueChanged(double arg1)
{

}
void MainWindow::on_doubleSpinBox_Roll_valueChanged(double arg1)
{

}
void MainWindow::on_doubleSpinBox_Thrust_valueChanged(double arg1)
{

}



void MainWindow::updateUI(const QStringList &message)
{
    QVector<QLineEdit*> lineEdits {ui->lineEdit_ACC_X, ui->lineEdit_ACC_Y, ui->lineEdit_ACC_Z,
        ui->lineEdit_GYR_X, ui->lineEdit_GYR_Y, ui->lineEdit_GYR_Z,
        ui->lineEdit_Altitude, ui->lineEdit_Temp,
        ui->lineEdit_MAG_X, ui->lineEdit_MAG_Y, ui->lineEdit_MAG_Z,
        ui->lineEdit_Ultrasound
    };
    for(int i = 0; i < message.size(); i++){
        lineEdits[i]->setText(message.at(i));
    }
    qDebug() << message;
}

void MainWindow::SetPWM()
{
    QVector<uint8_t> pwm_value { 0x03,
                               static_cast<uint8_t>(ui->horizontalSlider_P12PWM0->value()),
                               static_cast<unsigned char>(ui->horizontalSlider_P13PWM1->value()),
                               static_cast<unsigned char>(ui->horizontalSlider_P19PWM2->value()),
                               static_cast<unsigned char>(ui->horizontalSlider_P18PWM3->value())};

    emit sig_sendPWMControlToFCS(pwm_value);
}

void MainWindow::SetFlightControl()
{
    QVector<uint8_t> flight_control { 0x04,
                                    static_cast<uint8_t>(ui->verticalSlider_Pitch->value()),
                                    static_cast<uint8_t>(ui->verticalSlider_Yaw->value()),
                                    static_cast<uint8_t>(ui->verticalSlider_Roll->value()),
                                    static_cast<uint8_t>(ui->verticalSlider_Thrust->value())};
    emit sig_sendFlightControlToFCS(flight_control);
}


