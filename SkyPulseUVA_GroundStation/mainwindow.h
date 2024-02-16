#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QNetworkInterface>

#include "TCP.h"
#include "UDP.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void displayReceivedMessage(const QString &message);

private:
    Ui::MainWindow *ui;
    TCP *TcpClient;
    UDP *UdpServer;
    QThread *UdpThread;

    void initializeTCPService();
    void initializeUDPService();
    QString getLocalIP();

private slots:
    void on_pushButton_Network_Connect_clicked();
    void on_pushButton_Network_Disconnect_clicked();

    void onTCPConnectionSuccessful();
    void onTCPDisconnectionSuccessful();
    void onTCPConnectionError();

    void onUDPServerStartSuccessful();
    void onUDPServerStopSuccessful();

signals:
    void sig_StartUDPServer(const quint16 &port);
    void sig_StopUDPServer();

};
#endif // MAINWINDOW_H
