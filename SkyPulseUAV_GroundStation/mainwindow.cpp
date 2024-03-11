#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MahonyPlotObject = new Mahony_Plot();
    qDebug() << "Main Thread ID: " << QThread::currentThreadId();
    connect(ui->pushButton_Mahony_Plot_Launch, &QPushButton::clicked, MahonyPlotObject, &Mahony_Plot::startPlotting);
    connect(ui->pushButton_Mahony_Plot_Stop, &QPushButton::clicked, MahonyPlotObject, &Mahony_Plot::stopPlotting);

    this->initialTCPServer();
    this->initialUDPServer();
    // this->initialBluetoothServer();
}

MainWindow::~MainWindow()
{
    delete ui;

    // 请求TCP线程结束
    TcpThread->quit();  // 等待线程安全结束
    if (!TcpThread->wait(3000)) { // 等待最多3秒
        TcpThread->terminate();
        TcpThread->wait(); // 再次等待确保线程已经结束
    }
    delete TcpThread; // 删除线程对象

    // 请求UDP线程结束
    UdpThread->quit();  // 等待线程安全结束
    if (!UdpThread->wait(3000)) { // 等待最多3秒
        UdpThread->terminate();
        UdpThread->wait(); // 再次等待确保线程已经结束
    }
    delete UdpThread; // 删除线程对象

    /*
    // 请求线程结束
    BluetoothThread->quit();  // 等待线程安全结束
    if (!BluetoothThread->wait(3000)) { // 等待最多3秒
        BluetoothThread->terminate();
        BluetoothThread->wait(); // 再次等待确保线程已经结束
    }
    delete BluetoothThread; // 删除线程对象
*/
}


void MainWindow::initialTCPServer()
{
    TcpThread = new QThread(this);
    TcpServer = new TCP();  // 实体化TCP服务
    TcpServer->moveToThread(TcpThread);
    connect(this, &MainWindow::sig_StartTCPServer, TcpServer, &TCP::connectToServer);
    connect(this, &MainWindow::sig_StopTCPServer, TcpServer, &TCP::disconnectToServer);
    connect(TcpServer, &TCP::sig_receivedMessage, this, &MainWindow::displayReceivedMessage);
    connect(TcpServer, &TCP::sig_connectionSuccessful, this, &MainWindow::onTCPConnectionSuccessful);
    connect(TcpServer, &TCP::sig_connectionError, this, &MainWindow::onTCPConnectionError);
    connect(TcpServer, &TCP::sig_disconnectionSuccessful, this, &MainWindow::onTCPDisconnectionSuccessful);
    connect(TcpThread, &QThread::finished, TcpServer, &QObject::deleteLater);
    TcpThread->start();
}


void MainWindow::initialUDPServer()
{
    UdpThread = new QThread(this);
    UdpServer = new UDP();  // 实体化UDP服务
    UdpServer->moveToThread(UdpThread);
    connect(this, &MainWindow::sig_StartUDPServer, UdpServer, &UDP::startServer);
    connect(this, &MainWindow::sig_StopUDPServer, UdpServer, &UDP::stopServer);
    connect(UdpServer, &UDP::ServerStartSucessful, this, &MainWindow::onUDPServerStartSuccessful);
    connect(UdpServer, &UDP::ServerStopSucessful, this, &MainWindow::onUDPServerStopSuccessful);
    connect(UdpThread, &QThread::finished, UdpServer, &QObject::deleteLater);
    UdpThread->start();
}

void MainWindow::initialBluetoothServer()
{
    BluetoothThread = new QThread(this);
    BluetoothServer = new Bluetooth();
    BluetoothServer->moveToThread(BluetoothThread);
    connect(BluetoothThread, &QThread::finished, BluetoothServer, &QObject::deleteLater);
    BluetoothThread->start();
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
    TcpServer->disconnectToServer();
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

void MainWindow::closeEvent(QCloseEvent *event)
{
    QCoreApplication::quit();
}
