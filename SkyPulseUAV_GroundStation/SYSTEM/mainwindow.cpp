#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "concretemediator.h"


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
    connect(TCPServer, &TCP::sig_connectionSuccessful,      this, &MainWindow::onTCPConnectionSuccessful);
    connect(TCPServer, &TCP::sig_disconnectionSuccessful,   this, &MainWindow::onTCPDisconnectionSuccessful);
    connect(TCPServer, &TCP::sig_connectionError,           this, &MainWindow::onTCPConnectionError);

    connect(this, &MainWindow::sig_StartTCPServer, TCPServer, &TCP::connectToServer);
    connect(this, &MainWindow::sig_StopTCPServer, TCPServer, &TCP::disconnectToServer);
    connect(this, &MainWindow::sig_sendMessageToTCP, TCPServer, &TCP::controlMessageSender);

    /* UDP Server Connection Signals */
    connect(this, &MainWindow::sig_StartUDPServer, UDPServer, &UDP::startServer);
    connect(this, &MainWindow::sig_StopUDPServer, UDPServer, &UDP::stopServer);
    connect(UDPServer, &UDP::ServerStartSucessful, this, &MainWindow::onUDPServerStartSuccessful);
    connect(UDPServer, &UDP::ServerStopSucessful, this, &MainWindow::onUDPServerStopSuccessful);

    /* Bluetooth Server Connection Signals */
    // connect(BluetoothThread, &QThread::finished, BluetoothServer, &QObject::deleteLater);

}

MainWindow::~MainWindow()
{
    delete MahonyPlotObject;
    delete mediator;  // 如果需要，清理中介者实例
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QCoreApplication::quit();
}

void MainWindow::displayReceivedMessage(const QString &message)
{
    ui->textBrowser_test->append(message);
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
        // TcpServer->connectToServer(NetworkIPAddr, NetworkPort);  // 根据IP地址和端口连接服务端
        emit sig_StartUDPServer(NetworkPort);  // 开启UDP服务
    }
    else{
        qDebug() << "端口输入有误";
    }
}

void MainWindow::on_pushButton_Network_Disconnect_clicked()
{
    TCPServer->disconnectToServer();
    emit sig_StopUDPServer();
}

void MainWindow::onTCPConnectionSuccessful()
{
    // 处理连接成功事件，例如更新UI状态
    qDebug() << "Connection successful!";
    ui->pushButton_Network_Connect->setEnabled(false);
    ui->pushButton_Network_Disconnect->setEnabled(true);
    ui->textBrowser_test->append("TCP连接成功");
}

void MainWindow::onTCPConnectionError()
{
    // 处理连接失败事件，例如更新UI状态
    qDebug() << "Connection Error!";
    ui->pushButton_Network_Connect->setEnabled(true);
    ui->pushButton_Network_Disconnect->setEnabled(false);
    ui->textBrowser_test->append("TCP连接失败");
}

void MainWindow::onTCPDisconnectionSuccessful()
{
    // 处理连接失败事件，例如更新UI状态
    qDebug() << "Connection Disconnected!";
    ui->pushButton_Network_Connect->setEnabled(true);
    ui->pushButton_Network_Disconnect->setEnabled(false);
    ui->textBrowser_test->append("TCP断开成功");
}

void MainWindow::onUDPServerStartSuccessful()
{
    qDebug() << "UDP开启成功信号返回";
    ui->textBrowser_test->append("UDP开启成功");
}

void MainWindow::onUDPServerStopSuccessful()
{
    qDebug() << "UDP关闭成功信号返回";
    ui->textBrowser_test->append("UDP关闭成功");
}

QString MainWindow::getLocalIP()
{
    const QHostAddress &localhost = QHostAddress(QHostAddress::LocalHost);
    for (const QHostAddress &address: QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != localhost) {
            return address.toString();
        }
    }
    return NULL;
}

void MainWindow::on_pushButton_Mahony_Plot_Launch_clicked()
{
    emit sig_Mahony_PlottingStart();
}

void MainWindow::on_pushButton_Mahony_Plot_Stop_clicked()
{
    emit sig_Mahony_PlottingStop();
}

/* GPIO Controler*/
void MainWindow::on_horizontalSlider_P12PWM0_valueChanged(int duty_cycle)
{
    ui->doubleSpinBox_P12PWM0->setValue(duty_cycle/255.0);
    // emit sig_sendMessageToTCP(12, duty_cycle);
}

void MainWindow::on_horizontalSlider_P13PWM1_valueChanged(int duty_cycle)
{
    ui->doubleSpinBox_P13PWM1->setValue(duty_cycle/255.0);
    // emit sig_sendMessageToTCP(13, duty_cycle);
}

void MainWindow::on_horizontalSlider_P19PWM2_valueChanged(int duty_cycle)
{
    ui->doubleSpinBox_P19PWM2->setValue(duty_cycle/255.0);
    // emit sig_sendMessageToTCP(19, duty_cycle);
}

void MainWindow::on_horizontalSlider_P18PWM3_valueChanged(int duty_cycle)
{
    ui->doubleSpinBox_P18PWM3->setValue(duty_cycle/255.0);
    // emit sig_sendMessageToTCP(18, duty_cycle);
}

// Read MPU6050 Config Button Slots
void MainWindow::on_toolButton_REG_READ_ALL_clicked()
{
    emit sig_sendMessageToTCP(READ, 0x03, 0x01);
}

void MainWindow::updateUI(const QString &message)
{
    qDebug() << "Update UI:" << message;
}
