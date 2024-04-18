#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QDebug>
#include <QNetworkInterface>
#include <QCloseEvent>

#include "TCP.h"
#include "UDP.h"
#include "Mahony_Plot.h"
#include "MediatorInterface.h"

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

private:
    Ui::MainWindow *ui;

    /* Network Protocol Instance*/
    TCP *TCPServer;
    UDP *UDPServer;

    /* Ploting Instance*/
    Mahony_Plot *MahonyPlotObject;

    /* Tools Instance*/
    MediatorInterface* mediator;  // 中介者成员变量

    void initialBluetoothServer();
    void SetPWM();
    void SetFlightControl();

    // QString getLocalIP();

public slots:
    void onTCPStartSuccessful();
    void onTCPStopSuccessful();
    void onTCPConnectionError();
    void onUDPServerStartSuccessful();
    void onUDPServerStopSuccessful();

    void updateUI(const QStringList &message);

private slots:
    /* Connection & Disconnection Button Slots */
    void on_pushButton_Network_Connect_clicked();
    void on_pushButton_Network_Disconnect_clicked();

    /* Flight Control Panel */
    void on_pushButton_TAKE_OFF_clicked();

    /* Parameter Setting Panel */
    void on_pushButton_Mahony_Plot_Launch_clicked();
    void on_pushButton_Mahony_Plot_Stop_clicked();

    /* Sensor Register Setting Navigation Bar Button Slots */
    void on_toolButton_MPU6050_REG_CONFIG_clicked();
    void on_toolButton_BMP180_REG_CONFIG_clicked();
    void on_toolButton_GY271_REG_CONFIG_clicked();
    // MPU6050: Gyroscope&Accelerometer Sensor
    void on_pushButton_REG_READ_ALL_MPU6050_clicked();
    // BMP180: Barometer&temperature Sensor
    void on_pushButton_REG_READ_ALL_BMP180_clicked();
    // GY271: Magnetometer
    void on_pushButton_REG_READ_ALL_GY271_clicked();

    void on_horizontalSlider_P12PWM0_valueChanged(int duty_cycle);
    void on_horizontalSlider_P13PWM1_valueChanged(int duty_cycle);
    void on_horizontalSlider_P19PWM2_valueChanged(int duty_cycle);
    void on_horizontalSlider_P18PWM3_valueChanged(int duty_cycle);

    void on_spinBox_MinThrottle_editingFinished();


    void on_verticalSlider_Pitch_valueChanged(int value);


    void on_verticalSlider_Yaw_valueChanged(int value);

    void on_verticalSlider_Roll_valueChanged(int value);

    void on_verticalSlider_Thrust_valueChanged(int value);

    void on_doubleSpinBox_Thrust_valueChanged(double arg1);

    void on_doubleSpinBox_Pitch_valueChanged(double arg1);

    void on_doubleSpinBox_Yaw_valueChanged(double arg1);

    void on_doubleSpinBox_Roll_valueChanged(double arg1);

    void on_pushButton_LANDING_clicked();



protected:
    void closeEvent(QCloseEvent *event) override; // Rewrite the close event

signals:
    /* TCP&UDP Server Signals*/
    void sig_StartTCPServer(const QString &ip_address, const quint16 &port);
    void sig_StartUDPServer(const quint16 &port);
    void sig_StopTCPServer();
    void sig_StopUDPServer();

    void sig_Mahony_PlottingStart();
    void sig_Mahony_PlottingStop();

    void sig_sendRequestToFCS(const uint8_t &code);
    void sig_sendPWMControlToFCS(const QVector<uint8_t> &pwm_value);
    void sig_sendFlightControlToFCS(const QVector<uint8_t> &control_data);

    void sig_sendMinThrottle(const QVector<uint8_t> cofig_data);
};
#endif // MAINWINDOW_H
