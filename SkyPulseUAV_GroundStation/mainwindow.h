#ifndef MAINWINDOW_H  // Protects the file from being included multiple times in a single compilation
#define MAINWINDOW_H


#include <QMainWindow>           // Base class for all Qt main windows
#include <QThread>               // Provides control over thread execution
#include <QDebug>                // Provides a stream for debug messages
#include <QNetworkInterface>     // Used to interface with network devices
#include <QCloseEvent>           // Event class for handling window close events

#include "TCP.h"                 // Custom class for handling TCP communications
#include "UDP.h"                 // Custom class for handling UDP communications
#include "Bluetooth.h"           // Custom class for handling Bluetooth communications

#include "Mahony_Plot.h"         // Custom class for plotting data using Mahony algorithm


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;  // Forward declaration of the Ui::MainWindow class, typically generated from a Qt Designer ui file
}
QT_END_NAMESPACE

/**
 * @class MainWindow
 * @brief The main window class that integrates multiple functionalities including networking, plotting, and device control.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT  // Enables the use of Qt's signals and slots mechanisms within this class


public:
    /**
     * @brief Constructs a MainWindow object.
     * @param parent Pointer to the parent widget, by default is nullptr.
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destructs the MainWindow object and cleans up.
     */
    ~MainWindow();
;

public slots:
    /**
     * @brief Slot to display messages received from various servers.
     * @param message The message to display.
     */
    void displayReceivedMessage(const QString &message);


private:
    Ui::MainWindow *ui;  // Pointer to the UI form interface

    // Network protocol objects
    TCP *TcpServer;
    UDP *UdpServer;
    Bluetooth *BluetoothServer;

    // Plotting object
    Mahony_Plot *MahonyPlotObject;

    // Threads for managing concurrent operations
    QThread *TcpThread;
    QThread *UdpThread;
    QThread *BluetoothThread;

    // Private methods for initializing servers
    void initialTCPServer();
    void initialUDPServer();
    void initialBluetoothServer();

    /**
     * @brief Retrieves the local IP address of the machine.
     * @return A string containing the local IP address.
     */
    QString getLocalIP();

private slots:
    /**
     * @brief Handles the click event on the Network Connect button.
     * Initiates the connection process for the network protocols.
     */
    void on_pushButton_Network_Connect_clicked();

    /**
     * @brief Handles the click event on the Network Disconnect button.
     * Initiates the disconnection process for the network protocols.
     */
    void on_pushButton_Network_Disconnect_clicked();

    /**
     * @brief Handles the click event on the Mahony Plot Launch button.
     * Starts the data plotting process using the Mahony algorithm.
     */
    void on_pushButton_Mahony_Plot_Launch_clicked();

    /**
     * @brief Triggered when the TCP connection is successfully established.
     */
    void onTCPConnectionSuccessful();

    /**
     * @brief Triggered when the TCP connection is successfully disconnected.
     */
    void onTCPDisconnectionSuccessful();

    /**
     * @brief Triggered when there is an error in the TCP connection process.
     */
    void onTCPConnectionError();

    /**
     * @brief Triggered when the UDP server successfully starts.
     */
    void onUDPServerStartSuccessful();

    /**
     * @brief Triggered when the UDP server is successfully stopped.
     */
    void onUDPServerStopSuccessful();

    /**
     * @brief Handles the click event on the Mahony Plot Stop button.
     * Stops the data plotting process.
     */
    void on_pushButton_Mahony_Plot_Stop_clicked();

    /**
     * @brief Handles changes in the PWM0 duty cycle from the GUI slider.
     * @param duty_cycle The new duty cycle percentage for PWM0.
     */
    void on_horizontalSlider_P12PWM0_valueChanged(int duty_cycle);

    /**
     * @brief Handles changes in the PWM1 duty cycle from the GUI slider.
     * @param duty_cycle The new duty cycle percentage for PWM1.
     */
    void on_horizontalSlider_P13PWM1_valueChanged(int duty_cycle);

    /**
     * @brief Handles changes in the PWM2 duty cycle from the GUI slider.
     * @param duty_cycle The new duty cycle percentage for PWM2.
     */
    void on_horizontalSlider_P19PWM2_valueChanged(int duty_cycle);

    /**
     * @brief Handles changes in the PWM3 duty cycle from the GUI slider.
     * @param duty_cycle The new duty cycle percentage for PWM3.
     */
    void on_horizontalSlider_P18PWM3_valueChanged(int duty_cycle);

    /**
     * @brief Handles the click event on the Register Read All button.
     * Initiates a process to read all registers and display their values.
     */
    void on_toolButton_REG_READ_ALL_clicked();

protected:
    /**
     * @brief Overrides the default close event to perform custom actions on window close.
     * @param event The close event object.
     */
    void closeEvent(QCloseEvent *event) override;
override; // Rewrite the close event

signals:
    void sig_StartTCPServer(const QString &IPAddr, const quint16 &Port);
    void sig_StopTCPServer();
    void sig_StartUDPServer(const quint16 &port);
    void sig_StopUDPServer();
    void sig_Mahony_PlottingStart();
    void sig_Mahony_PlottingStop();
    void sig_sendMessageToTCP(const uint8_t &action, the uint8_t &data_length, the uint8_t &value);

};
#endif // MAINWINDOW_H
