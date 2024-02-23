#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QDebug>
#include <QNetworkInterface>

#include "TCP.h"
#include "UDP.h"
#include "Bluetooth.h"

#include "Mahony_Plot.h"

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
    /*Network Protocol*/
    TCP *TcpServer;
    UDP *UdpServer;
    Bluetooth *BluetoothServer;
    /*Ploting*/
    Mahony_Plot *MahonyPlotObject;
    /*Multi-threaded*/
    QThread *UdpThread;
    QThread *BluetoothThread;


    void initialTCPServer();
    void initialUDPServer();
    void initialBluetoothServer();
    QString getLocalIP();

private slots:
    void on_pushButton_Network_Connect_clicked();
    void on_pushButton_Network_Disconnect_clicked();

    void on_pushButton_Mahony_Plot_Launch_clicked();

    void onTCPConnectionSuccessful();
    void onTCPDisconnectionSuccessful();
    void onTCPConnectionError();

    void onUDPServerStartSuccessful();
    void onUDPServerStopSuccessful();



    void on_pushButton_Mahony_Plot_Stop_clicked();

signals:
    void sig_StartUDPServer(const quint16 &port);
    void sig_StopUDPServer();
    void sig_Mahony_PlottingStart();
    void sig_Mahony_PlottingStop();

};
#endif // MAINWINDOW_H
