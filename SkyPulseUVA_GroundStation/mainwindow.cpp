#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->initializeTCPService();
    this->initializeUDPService();
}

MainWindow::~MainWindow()
{
    delete ui;
    // 请求线程结束
    UdpThread->quit();
    // 等待线程安全结束
    if (!UdpThread->wait(3000)) { // 等待最多3秒
        // 如果线程在给定时间内没有结束，则强制结束（不推荐，可能导致资源泄露或不一致状态）
        UdpThread->terminate();
        UdpThread->wait(); // 再次等待确保线程已经结束
    }
    delete UdpThread; // 删除线程对象
}


void MainWindow::initializeTCPService()
{
    TcpClient = new TCP(this);  // 实体化TCP服务
    connect(TcpClient, &TCP::sig_receivedMessage, this, &MainWindow::displayReceivedMessage);
    connect(TcpClient, &TCP::sig_connectionSuccessful, this, &MainWindow::onTCPConnectionSuccessful);
    connect(TcpClient, &TCP::sig_connectionError, this, &MainWindow::onTCPConnectionError);
    connect(TcpClient, &TCP::sig_disconnectionSuccessful, this, &MainWindow::onTCPDisconnectionSuccessful);
}


void MainWindow::initializeUDPService()
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
        TcpClient->connectToServer(NetworkIPAddr, NetworkPort);  // 根据IP地址和端口连接服务端
        emit sig_StartUDPServer(NetworkPort);  // 开启UDP服务
    }
    else{
        qDebug() << "端口输入有误";
    }
}

void MainWindow::on_pushButton_Network_Disconnect_clicked()
{
    TcpClient->disconnectFromServer();
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
