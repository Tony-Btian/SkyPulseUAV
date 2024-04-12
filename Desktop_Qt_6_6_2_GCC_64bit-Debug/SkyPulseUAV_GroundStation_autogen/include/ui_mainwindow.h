/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupbox_Connection_Control;
    QHBoxLayout *horizontalLayout_12;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_Network_IPAddr;
    QLineEdit *lineEdit_Network_IPAddr;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_Network_Port;
    QLineEdit *lineEdit_Network_Port;
    QFrame *line_4;
    QPushButton *pushButton_Network_Connect;
    QPushButton *pushButton_Network_Disconnect;
    QFrame *line_5;
    QLabel *label_TCP_Connection;
    QLabel *icon_TCP_Connection;
    QFrame *line_6;
    QLabel *label_UDP_Connection;
    QLabel *icon_UDP_Connection;
    QTabWidget *tabWidget_PanelMain;
    QWidget *tab1_FlightControl;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_AnimationDisplay;
    QWidget *widget;
    QGridLayout *gridLayout_4;
    QWidget *widget_2;
    QGridLayout *gridLayout_5;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget_FlightControlInfo;
    QWidget *FlightControlinfo_Status;
    QWidget *FlightControlinfo_Graph;
    QGroupBox *groupBox_SensorData;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_SensorData_Upper;
    QVBoxLayout *verticalLayout_ACC;
    QHBoxLayout *horizontalLayout_ACC_X;
    QLabel *label_ACC_X;
    QLineEdit *lineEdit_ACC_X;
    QHBoxLayout *horizontalLayout_ACC_Y;
    QLabel *label_ACC_Y;
    QLineEdit *lineEdit_ACC_Y;
    QHBoxLayout *horizontalLayout_ACC_Z;
    QLabel *label_ACC_Z;
    QLineEdit *lineEdit_ACC_Z;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_GYR;
    QHBoxLayout *horizontalLayout_GYR_X;
    QLabel *label_GYR_X;
    QLineEdit *lineEdit_GYR_X;
    QHBoxLayout *horizontalLayout_GYR_Y;
    QLabel *label_GYR_Y;
    QLineEdit *lineEdit_GYR_Y;
    QHBoxLayout *horizontalLayout_GYR_Z;
    QLabel *label_GYR_Z;
    QLineEdit *lineEdit_GYR_Z;
    QFrame *line_SensorData;
    QHBoxLayout *horizontalLayout_SensorData_Bottom;
    QVBoxLayout *verticalLayout_MAG;
    QHBoxLayout *horizontalLayout_MAG_X;
    QLabel *label_MAG_X;
    QLineEdit *lineEdit_MAG_X;
    QHBoxLayout *horizontalLayout_MAG_Y;
    QLabel *label_MAG_Y;
    QLineEdit *lineEdit_MAG_Y;
    QHBoxLayout *horizontalLayout_MAG_Z;
    QLabel *label_MAG_Z;
    QLineEdit *lineEdit_MAG_Z;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_Altitude;
    QHBoxLayout *horizontalLayout_Altitude;
    QLabel *label_Altitude;
    QLineEdit *lineEdit_Altitude;
    QHBoxLayout *horizontalLayout_Ultrasound;
    QLabel *label_Ultrasound;
    QLineEdit *lineEdit_Ultrasound;
    QHBoxLayout *horizontalLayout_Temp;
    QLabel *label_Temp;
    QLineEdit *lineEdit_Temp;
    QGroupBox *groupBox_GPS;
    QPushButton *pushButton_TAKE_OFF;
    QWidget *tab2_ParameterSetting;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_Calibration_Control;
    QToolButton *toolButton_Calib_Gyto;
    QToolButton *toolButton_Calib_Accelerate;
    QToolButton *toolButton_Calib_Compass;
    QToolButton *toolButton_Calib_AirPressure;
    QToolButton *toolButton_Calib_SixDirection;
    QGroupBox *groupBox_Mahony_Adjuster;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_Mahony_Parameter;
    QDoubleSpinBox *doubleSpinBox_Mahony_Parameter_1;
    QDoubleSpinBox *doubleSpinBox_Mahony_Parameter_2;
    QDoubleSpinBox *doubleSpinBox_Mahony_Parameter_3;
    QPushButton *pushButton_Mahony_Parameter_Write;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox;
    QSpacerItem *horizontalSpacer_4;
    QCustomPlot *PlotDisplay_Mahony;
    QGridLayout *gridLayout_6;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_Mahony_Plot_Launch;
    QPushButton *pushButton_Mahony_Plot_Stop;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox_PID_Control;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_Rate_Adjust;
    QHBoxLayout *horizontalLayout_PITRate;
    QLabel *label_PITRate;
    QDoubleSpinBox *doubleSpinBox_PITRate_P_Value;
    QDoubleSpinBox *doubleSpinBox_PITRate_I_Value;
    QDoubleSpinBox *doubleSpinBox_PITRate_D_Value;
    QPushButton *pushButton_PITRate_Write;
    QHBoxLayout *horizontalLayout_ROLRate;
    QLabel *label_ROLRate;
    QDoubleSpinBox *doubleSpinBox_ROLRate_P_Value;
    QDoubleSpinBox *doubleSpinBox_ROLRate_I_Value;
    QDoubleSpinBox *doubleSpinBox_ROLRate_D_Value;
    QPushButton *pushButton_ROLRate_Write;
    QHBoxLayout *horizontalLayout_YAWRate;
    QLabel *label_YAWRate;
    QDoubleSpinBox *doubleSpinBox_YAWRate_P_Value;
    QDoubleSpinBox *doubleSpinBox_YAWRate_I_Value;
    QDoubleSpinBox *doubleSpinBox_YAWRate_D_Value;
    QPushButton *pushButton_YAWRate_Write;
    QFrame *line;
    QVBoxLayout *verticalLayout_Self_Stabilization;
    QHBoxLayout *horizontalLayout_PIT_SelfStable;
    QLabel *label_PITSelfStable;
    QDoubleSpinBox *doubleSpinBox_PITSelfStable_P_Value;
    QDoubleSpinBox *doubleSpinBox_PITSelfStable_I_Value;
    QDoubleSpinBox *doubleSpinBox_PITSelfStable_D_Value;
    QPushButton *pushButton_PITSelfStable_Write;
    QHBoxLayout *horizontalLayout_ROL_SelfStable;
    QLabel *label_ROLSelfStable;
    QDoubleSpinBox *doubleSpinBox_ROLSelfStable_P_Value;
    QDoubleSpinBox *doubleSpinBox_ROLSelfStable_I_Value;
    QDoubleSpinBox *doubleSpinBox_ROLSelfStable_D_Value;
    QPushButton *pushButton_ROLSelfStable_Write;
    QHBoxLayout *horizontalLayout_YAW_SelfStable;
    QLabel *label_YAWSelfStable;
    QDoubleSpinBox *doubleSpinBox_YAWSelfStable_P_Value;
    QDoubleSpinBox *doubleSpinBox_YAWSelfStable_I_Value;
    QDoubleSpinBox *doubleSpinBox_YAWSelfStable_D_Value;
    QPushButton *pushButton_YAWSelfStable_Write;
    QWidget *tab3_ParameterTesting;
    QPushButton *pushButton_PWMValue_Save;
    QCustomPlot *widget_3;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_16;
    QGroupBox *groupBox_ESC_Features;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_25;
    QSpinBox *spinBox_MinThrottle;
    QLabel *label_MinThrottle;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_26;
    QSpinBox *spinBox_MaxThrottle;
    QLabel *label_MaxThrottle;
    QSpacerItem *horizontalSpacer_9;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_P12PWM0;
    QSlider *horizontalSlider_P12PWM0;
    QDoubleSpinBox *doubleSpinBox_P12PWM0;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_P13PWM1;
    QSlider *horizontalSlider_P13PWM1;
    QDoubleSpinBox *doubleSpinBox_P13PWM1;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_P19PWM2;
    QSlider *horizontalSlider_P19PWM2;
    QDoubleSpinBox *doubleSpinBox_P19PWM2;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_P18PWM3;
    QSlider *horizontalSlider_P18PWM3;
    QDoubleSpinBox *doubleSpinBox_P18PWM3;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_17;
    QSlider *verticalSlider;
    QLabel *label_Trust_Control;
    QWidget *tab4_SensorRegistersSetting;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_17;
    QSpacerItem *horizontalSpacer_7;
    QToolButton *toolButton_MPU6050_REG_CONFIG;
    QToolButton *toolButton_BMP180_REG_CONFIG;
    QToolButton *toolButton_GY271_REG_CONFIG;
    QSpacerItem *horizontalSpacer_6;
    QStackedWidget *stackedWidget_REG_CONFIG;
    QWidget *MPU6050_Page;
    QVBoxLayout *verticalLayout_15;
    QHBoxLayout *horizontalLayout_24;
    QPushButton *pushButton_REG_READ_ALL_MPU6050;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_8;
    QVBoxLayout *verticalLayout_14;
    QHBoxLayout *horizontalLayout_20;
    QGroupBox *groupBox_GYRO_CONFIG;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_SelfTest_GYRO;
    QCheckBox *checkBox_XG_SelfTest;
    QCheckBox *checkBox_YG_SelfTest;
    QCheckBox *checkBox_ZG_SelfTest;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_FullScaleRange_GYRO;
    QComboBox *comboBox_FullScaleRange_GYRO;
    QGroupBox *groupBox_ACCEL_CONFIG;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_SelfTest_ACCEL;
    QCheckBox *checkBox_XA_SelfTest;
    QCheckBox *checkBox_YA_SelfTest;
    QCheckBox *checkBox_ZA_SelfTest;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_FullScaleRange_ACCEL;
    QComboBox *comboBox_FullScaleRange_ACCEL;
    QGroupBox *groupBox_FIFO_EN;
    QVBoxLayout *verticalLayout_11;
    QCheckBox *checkBox_TEMP_FIFO_EN;
    QHBoxLayout *horizontalLayout_18;
    QCheckBox *checkBox_XG_FIFO_EN;
    QCheckBox *checkBox_YG_FIFO_EN;
    QCheckBox *checkBox_ZG_FIFO_EN;
    QCheckBox *checkBox_ACCEL_FIFO_EN;
    QHBoxLayout *horizontalLayout_19;
    QCheckBox *checkBox_SLV2_FIFO_EN;
    QCheckBox *checkBox_SLV1_FIFO_EN;
    QCheckBox *checkBox_SLV0_FIFO_EN;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_13;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_INT_LEVEL;
    QComboBox *comboBox_INT_LEVEL;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_INT_OPEN;
    QComboBox *comboBox_INT_OPEN;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_LATCH_INT_EN;
    QComboBox *comboBox_LATCH_INT_EN;
    QWidget *BMP180_Page;
    QPushButton *pushButton_REG_READ_ALL_BMP180;
    QWidget *GY271_Page;
    QPushButton *pushButton_REG_READ_ALL_GY271;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(835, 752);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_7 = new QVBoxLayout(centralwidget);
        verticalLayout_7->setObjectName("verticalLayout_7");
        groupbox_Connection_Control = new QGroupBox(centralwidget);
        groupbox_Connection_Control->setObjectName("groupbox_Connection_Control");
        groupbox_Connection_Control->setFlat(true);
        horizontalLayout_12 = new QHBoxLayout(groupbox_Connection_Control);
        horizontalLayout_12->setSpacing(15);
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_Network_IPAddr = new QLabel(groupbox_Connection_Control);
        label_Network_IPAddr->setObjectName("label_Network_IPAddr");

        horizontalLayout_3->addWidget(label_Network_IPAddr);

        lineEdit_Network_IPAddr = new QLineEdit(groupbox_Connection_Control);
        lineEdit_Network_IPAddr->setObjectName("lineEdit_Network_IPAddr");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_Network_IPAddr->sizePolicy().hasHeightForWidth());
        lineEdit_Network_IPAddr->setSizePolicy(sizePolicy);
        lineEdit_Network_IPAddr->setMinimumSize(QSize(136, 0));

        horizontalLayout_3->addWidget(lineEdit_Network_IPAddr);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);

        horizontalLayout_12->addLayout(horizontalLayout_3);

        line_3 = new QFrame(groupbox_Connection_Control);
        line_3->setObjectName("line_3");
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_12->addWidget(line_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_Network_Port = new QLabel(groupbox_Connection_Control);
        label_Network_Port->setObjectName("label_Network_Port");

        horizontalLayout_4->addWidget(label_Network_Port);

        lineEdit_Network_Port = new QLineEdit(groupbox_Connection_Control);
        lineEdit_Network_Port->setObjectName("lineEdit_Network_Port");
        sizePolicy.setHeightForWidth(lineEdit_Network_Port->sizePolicy().hasHeightForWidth());
        lineEdit_Network_Port->setSizePolicy(sizePolicy);
        lineEdit_Network_Port->setMinimumSize(QSize(90, 0));

        horizontalLayout_4->addWidget(lineEdit_Network_Port);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);

        horizontalLayout_12->addLayout(horizontalLayout_4);

        line_4 = new QFrame(groupbox_Connection_Control);
        line_4->setObjectName("line_4");
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout_12->addWidget(line_4);

        pushButton_Network_Connect = new QPushButton(groupbox_Connection_Control);
        pushButton_Network_Connect->setObjectName("pushButton_Network_Connect");

        horizontalLayout_12->addWidget(pushButton_Network_Connect);

        pushButton_Network_Disconnect = new QPushButton(groupbox_Connection_Control);
        pushButton_Network_Disconnect->setObjectName("pushButton_Network_Disconnect");
        pushButton_Network_Disconnect->setEnabled(false);

        horizontalLayout_12->addWidget(pushButton_Network_Disconnect);

        line_5 = new QFrame(groupbox_Connection_Control);
        line_5->setObjectName("line_5");
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout_12->addWidget(line_5);

        label_TCP_Connection = new QLabel(groupbox_Connection_Control);
        label_TCP_Connection->setObjectName("label_TCP_Connection");

        horizontalLayout_12->addWidget(label_TCP_Connection);

        icon_TCP_Connection = new QLabel(groupbox_Connection_Control);
        icon_TCP_Connection->setObjectName("icon_TCP_Connection");
        icon_TCP_Connection->setMinimumSize(QSize(25, 25));
        icon_TCP_Connection->setMaximumSize(QSize(25, 25));
        icon_TCP_Connection->setPixmap(QPixmap(QString::fromUtf8(":/qrc/icon/no.png")));
        icon_TCP_Connection->setScaledContents(true);

        horizontalLayout_12->addWidget(icon_TCP_Connection);

        line_6 = new QFrame(groupbox_Connection_Control);
        line_6->setObjectName("line_6");
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        horizontalLayout_12->addWidget(line_6);

        label_UDP_Connection = new QLabel(groupbox_Connection_Control);
        label_UDP_Connection->setObjectName("label_UDP_Connection");

        horizontalLayout_12->addWidget(label_UDP_Connection);

        icon_UDP_Connection = new QLabel(groupbox_Connection_Control);
        icon_UDP_Connection->setObjectName("icon_UDP_Connection");
        icon_UDP_Connection->setMinimumSize(QSize(25, 25));
        icon_UDP_Connection->setMaximumSize(QSize(25, 25));
        icon_UDP_Connection->setPixmap(QPixmap(QString::fromUtf8(":/qrc/icon/no.png")));
        icon_UDP_Connection->setScaledContents(true);

        horizontalLayout_12->addWidget(icon_UDP_Connection);

        horizontalLayout_12->setStretch(0, 1);
        horizontalLayout_12->setStretch(2, 1);
        horizontalLayout_12->setStretch(4, 1);
        horizontalLayout_12->setStretch(5, 1);

        verticalLayout_7->addWidget(groupbox_Connection_Control);

        tabWidget_PanelMain = new QTabWidget(centralwidget);
        tabWidget_PanelMain->setObjectName("tabWidget_PanelMain");
        tabWidget_PanelMain->setTabPosition(QTabWidget::North);
        tab1_FlightControl = new QWidget();
        tab1_FlightControl->setObjectName("tab1_FlightControl");
        gridLayout_2 = new QGridLayout(tab1_FlightControl);
        gridLayout_2->setObjectName("gridLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_AnimationDisplay = new QHBoxLayout();
        horizontalLayout_AnimationDisplay->setObjectName("horizontalLayout_AnimationDisplay");
        widget = new QWidget(tab1_FlightControl);
        widget->setObjectName("widget");
        gridLayout_4 = new QGridLayout(widget);
        gridLayout_4->setObjectName("gridLayout_4");

        horizontalLayout_AnimationDisplay->addWidget(widget);

        widget_2 = new QWidget(tab1_FlightControl);
        widget_2->setObjectName("widget_2");
        gridLayout_5 = new QGridLayout(widget_2);
        gridLayout_5->setObjectName("gridLayout_5");

        horizontalLayout_AnimationDisplay->addWidget(widget_2);


        verticalLayout->addLayout(horizontalLayout_AnimationDisplay);

        line_2 = new QFrame(tab1_FlightControl);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        tabWidget_FlightControlInfo = new QTabWidget(tab1_FlightControl);
        tabWidget_FlightControlInfo->setObjectName("tabWidget_FlightControlInfo");
        FlightControlinfo_Status = new QWidget();
        FlightControlinfo_Status->setObjectName("FlightControlinfo_Status");
        tabWidget_FlightControlInfo->addTab(FlightControlinfo_Status, QString());
        FlightControlinfo_Graph = new QWidget();
        FlightControlinfo_Graph->setObjectName("FlightControlinfo_Graph");
        tabWidget_FlightControlInfo->addTab(FlightControlinfo_Graph, QString());

        horizontalLayout->addWidget(tabWidget_FlightControlInfo);

        groupBox_SensorData = new QGroupBox(tab1_FlightControl);
        groupBox_SensorData->setObjectName("groupBox_SensorData");
        verticalLayout_2 = new QVBoxLayout(groupBox_SensorData);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_SensorData_Upper = new QHBoxLayout();
        horizontalLayout_SensorData_Upper->setObjectName("horizontalLayout_SensorData_Upper");
        verticalLayout_ACC = new QVBoxLayout();
        verticalLayout_ACC->setObjectName("verticalLayout_ACC");
        horizontalLayout_ACC_X = new QHBoxLayout();
        horizontalLayout_ACC_X->setObjectName("horizontalLayout_ACC_X");
        label_ACC_X = new QLabel(groupBox_SensorData);
        label_ACC_X->setObjectName("label_ACC_X");

        horizontalLayout_ACC_X->addWidget(label_ACC_X);

        lineEdit_ACC_X = new QLineEdit(groupBox_SensorData);
        lineEdit_ACC_X->setObjectName("lineEdit_ACC_X");

        horizontalLayout_ACC_X->addWidget(lineEdit_ACC_X);

        horizontalLayout_ACC_X->setStretch(0, 1);
        horizontalLayout_ACC_X->setStretch(1, 1);

        verticalLayout_ACC->addLayout(horizontalLayout_ACC_X);

        horizontalLayout_ACC_Y = new QHBoxLayout();
        horizontalLayout_ACC_Y->setObjectName("horizontalLayout_ACC_Y");
        label_ACC_Y = new QLabel(groupBox_SensorData);
        label_ACC_Y->setObjectName("label_ACC_Y");

        horizontalLayout_ACC_Y->addWidget(label_ACC_Y);

        lineEdit_ACC_Y = new QLineEdit(groupBox_SensorData);
        lineEdit_ACC_Y->setObjectName("lineEdit_ACC_Y");

        horizontalLayout_ACC_Y->addWidget(lineEdit_ACC_Y);

        horizontalLayout_ACC_Y->setStretch(0, 1);
        horizontalLayout_ACC_Y->setStretch(1, 1);

        verticalLayout_ACC->addLayout(horizontalLayout_ACC_Y);

        horizontalLayout_ACC_Z = new QHBoxLayout();
        horizontalLayout_ACC_Z->setObjectName("horizontalLayout_ACC_Z");
        label_ACC_Z = new QLabel(groupBox_SensorData);
        label_ACC_Z->setObjectName("label_ACC_Z");

        horizontalLayout_ACC_Z->addWidget(label_ACC_Z);

        lineEdit_ACC_Z = new QLineEdit(groupBox_SensorData);
        lineEdit_ACC_Z->setObjectName("lineEdit_ACC_Z");

        horizontalLayout_ACC_Z->addWidget(lineEdit_ACC_Z);

        horizontalLayout_ACC_Z->setStretch(0, 1);
        horizontalLayout_ACC_Z->setStretch(1, 1);

        verticalLayout_ACC->addLayout(horizontalLayout_ACC_Z);


        horizontalLayout_SensorData_Upper->addLayout(verticalLayout_ACC);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_SensorData_Upper->addItem(horizontalSpacer);

        verticalLayout_GYR = new QVBoxLayout();
        verticalLayout_GYR->setObjectName("verticalLayout_GYR");
        horizontalLayout_GYR_X = new QHBoxLayout();
        horizontalLayout_GYR_X->setObjectName("horizontalLayout_GYR_X");
        label_GYR_X = new QLabel(groupBox_SensorData);
        label_GYR_X->setObjectName("label_GYR_X");

        horizontalLayout_GYR_X->addWidget(label_GYR_X);

        lineEdit_GYR_X = new QLineEdit(groupBox_SensorData);
        lineEdit_GYR_X->setObjectName("lineEdit_GYR_X");

        horizontalLayout_GYR_X->addWidget(lineEdit_GYR_X);

        horizontalLayout_GYR_X->setStretch(0, 1);
        horizontalLayout_GYR_X->setStretch(1, 1);

        verticalLayout_GYR->addLayout(horizontalLayout_GYR_X);

        horizontalLayout_GYR_Y = new QHBoxLayout();
        horizontalLayout_GYR_Y->setObjectName("horizontalLayout_GYR_Y");
        label_GYR_Y = new QLabel(groupBox_SensorData);
        label_GYR_Y->setObjectName("label_GYR_Y");

        horizontalLayout_GYR_Y->addWidget(label_GYR_Y);

        lineEdit_GYR_Y = new QLineEdit(groupBox_SensorData);
        lineEdit_GYR_Y->setObjectName("lineEdit_GYR_Y");

        horizontalLayout_GYR_Y->addWidget(lineEdit_GYR_Y);

        horizontalLayout_GYR_Y->setStretch(0, 1);
        horizontalLayout_GYR_Y->setStretch(1, 1);

        verticalLayout_GYR->addLayout(horizontalLayout_GYR_Y);

        horizontalLayout_GYR_Z = new QHBoxLayout();
        horizontalLayout_GYR_Z->setObjectName("horizontalLayout_GYR_Z");
        label_GYR_Z = new QLabel(groupBox_SensorData);
        label_GYR_Z->setObjectName("label_GYR_Z");

        horizontalLayout_GYR_Z->addWidget(label_GYR_Z);

        lineEdit_GYR_Z = new QLineEdit(groupBox_SensorData);
        lineEdit_GYR_Z->setObjectName("lineEdit_GYR_Z");

        horizontalLayout_GYR_Z->addWidget(lineEdit_GYR_Z);

        horizontalLayout_GYR_Z->setStretch(0, 1);
        horizontalLayout_GYR_Z->setStretch(1, 1);

        verticalLayout_GYR->addLayout(horizontalLayout_GYR_Z);


        horizontalLayout_SensorData_Upper->addLayout(verticalLayout_GYR);

        horizontalLayout_SensorData_Upper->setStretch(0, 1);
        horizontalLayout_SensorData_Upper->setStretch(2, 1);

        verticalLayout_2->addLayout(horizontalLayout_SensorData_Upper);

        line_SensorData = new QFrame(groupBox_SensorData);
        line_SensorData->setObjectName("line_SensorData");
        line_SensorData->setFrameShape(QFrame::HLine);
        line_SensorData->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_SensorData);

        horizontalLayout_SensorData_Bottom = new QHBoxLayout();
        horizontalLayout_SensorData_Bottom->setObjectName("horizontalLayout_SensorData_Bottom");
        verticalLayout_MAG = new QVBoxLayout();
        verticalLayout_MAG->setObjectName("verticalLayout_MAG");
        horizontalLayout_MAG_X = new QHBoxLayout();
        horizontalLayout_MAG_X->setObjectName("horizontalLayout_MAG_X");
        label_MAG_X = new QLabel(groupBox_SensorData);
        label_MAG_X->setObjectName("label_MAG_X");

        horizontalLayout_MAG_X->addWidget(label_MAG_X);

        lineEdit_MAG_X = new QLineEdit(groupBox_SensorData);
        lineEdit_MAG_X->setObjectName("lineEdit_MAG_X");

        horizontalLayout_MAG_X->addWidget(lineEdit_MAG_X);

        horizontalLayout_MAG_X->setStretch(0, 1);
        horizontalLayout_MAG_X->setStretch(1, 1);

        verticalLayout_MAG->addLayout(horizontalLayout_MAG_X);

        horizontalLayout_MAG_Y = new QHBoxLayout();
        horizontalLayout_MAG_Y->setObjectName("horizontalLayout_MAG_Y");
        label_MAG_Y = new QLabel(groupBox_SensorData);
        label_MAG_Y->setObjectName("label_MAG_Y");

        horizontalLayout_MAG_Y->addWidget(label_MAG_Y);

        lineEdit_MAG_Y = new QLineEdit(groupBox_SensorData);
        lineEdit_MAG_Y->setObjectName("lineEdit_MAG_Y");

        horizontalLayout_MAG_Y->addWidget(lineEdit_MAG_Y);

        horizontalLayout_MAG_Y->setStretch(0, 1);
        horizontalLayout_MAG_Y->setStretch(1, 1);

        verticalLayout_MAG->addLayout(horizontalLayout_MAG_Y);

        horizontalLayout_MAG_Z = new QHBoxLayout();
        horizontalLayout_MAG_Z->setObjectName("horizontalLayout_MAG_Z");
        label_MAG_Z = new QLabel(groupBox_SensorData);
        label_MAG_Z->setObjectName("label_MAG_Z");

        horizontalLayout_MAG_Z->addWidget(label_MAG_Z);

        lineEdit_MAG_Z = new QLineEdit(groupBox_SensorData);
        lineEdit_MAG_Z->setObjectName("lineEdit_MAG_Z");

        horizontalLayout_MAG_Z->addWidget(lineEdit_MAG_Z);

        horizontalLayout_MAG_Z->setStretch(0, 1);
        horizontalLayout_MAG_Z->setStretch(1, 1);

        verticalLayout_MAG->addLayout(horizontalLayout_MAG_Z);


        horizontalLayout_SensorData_Bottom->addLayout(verticalLayout_MAG);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_SensorData_Bottom->addItem(horizontalSpacer_2);

        verticalLayout_Altitude = new QVBoxLayout();
        verticalLayout_Altitude->setObjectName("verticalLayout_Altitude");
        horizontalLayout_Altitude = new QHBoxLayout();
        horizontalLayout_Altitude->setObjectName("horizontalLayout_Altitude");
        label_Altitude = new QLabel(groupBox_SensorData);
        label_Altitude->setObjectName("label_Altitude");

        horizontalLayout_Altitude->addWidget(label_Altitude);

        lineEdit_Altitude = new QLineEdit(groupBox_SensorData);
        lineEdit_Altitude->setObjectName("lineEdit_Altitude");

        horizontalLayout_Altitude->addWidget(lineEdit_Altitude);

        horizontalLayout_Altitude->setStretch(0, 1);
        horizontalLayout_Altitude->setStretch(1, 1);

        verticalLayout_Altitude->addLayout(horizontalLayout_Altitude);

        horizontalLayout_Ultrasound = new QHBoxLayout();
        horizontalLayout_Ultrasound->setObjectName("horizontalLayout_Ultrasound");
        label_Ultrasound = new QLabel(groupBox_SensorData);
        label_Ultrasound->setObjectName("label_Ultrasound");

        horizontalLayout_Ultrasound->addWidget(label_Ultrasound);

        lineEdit_Ultrasound = new QLineEdit(groupBox_SensorData);
        lineEdit_Ultrasound->setObjectName("lineEdit_Ultrasound");

        horizontalLayout_Ultrasound->addWidget(lineEdit_Ultrasound);

        horizontalLayout_Ultrasound->setStretch(0, 1);
        horizontalLayout_Ultrasound->setStretch(1, 1);

        verticalLayout_Altitude->addLayout(horizontalLayout_Ultrasound);

        horizontalLayout_Temp = new QHBoxLayout();
        horizontalLayout_Temp->setObjectName("horizontalLayout_Temp");
        label_Temp = new QLabel(groupBox_SensorData);
        label_Temp->setObjectName("label_Temp");

        horizontalLayout_Temp->addWidget(label_Temp);

        lineEdit_Temp = new QLineEdit(groupBox_SensorData);
        lineEdit_Temp->setObjectName("lineEdit_Temp");

        horizontalLayout_Temp->addWidget(lineEdit_Temp);

        horizontalLayout_Temp->setStretch(0, 1);
        horizontalLayout_Temp->setStretch(1, 1);

        verticalLayout_Altitude->addLayout(horizontalLayout_Temp);


        horizontalLayout_SensorData_Bottom->addLayout(verticalLayout_Altitude);

        horizontalLayout_SensorData_Bottom->setStretch(0, 1);
        horizontalLayout_SensorData_Bottom->setStretch(2, 1);

        verticalLayout_2->addLayout(horizontalLayout_SensorData_Bottom);


        horizontalLayout->addWidget(groupBox_SensorData);

        groupBox_GPS = new QGroupBox(tab1_FlightControl);
        groupBox_GPS->setObjectName("groupBox_GPS");
        pushButton_TAKE_OFF = new QPushButton(groupBox_GPS);
        pushButton_TAKE_OFF->setObjectName("pushButton_TAKE_OFF");
        pushButton_TAKE_OFF->setGeometry(QRect(30, 50, 89, 25));

        horizontalLayout->addWidget(groupBox_GPS);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 2);

        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(2, 1);

        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        tabWidget_PanelMain->addTab(tab1_FlightControl, QString());
        tab2_ParameterSetting = new QWidget();
        tab2_ParameterSetting->setObjectName("tab2_ParameterSetting");
        horizontalLayout_5 = new QHBoxLayout(tab2_ParameterSetting);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout_Calibration_Control = new QHBoxLayout();
        horizontalLayout_Calibration_Control->setObjectName("horizontalLayout_Calibration_Control");
        toolButton_Calib_Gyto = new QToolButton(tab2_ParameterSetting);
        toolButton_Calib_Gyto->setObjectName("toolButton_Calib_Gyto");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/qrc/icon/gyroscope.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_Calib_Gyto->setIcon(icon);
        toolButton_Calib_Gyto->setIconSize(QSize(50, 50));
        toolButton_Calib_Gyto->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_Calibration_Control->addWidget(toolButton_Calib_Gyto);

        toolButton_Calib_Accelerate = new QToolButton(tab2_ParameterSetting);
        toolButton_Calib_Accelerate->setObjectName("toolButton_Calib_Accelerate");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/qrc/icon/accelerometer.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_Calib_Accelerate->setIcon(icon1);
        toolButton_Calib_Accelerate->setIconSize(QSize(50, 50));
        toolButton_Calib_Accelerate->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_Calibration_Control->addWidget(toolButton_Calib_Accelerate);

        toolButton_Calib_Compass = new QToolButton(tab2_ParameterSetting);
        toolButton_Calib_Compass->setObjectName("toolButton_Calib_Compass");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/qrc/icon/compass.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_Calib_Compass->setIcon(icon2);
        toolButton_Calib_Compass->setIconSize(QSize(50, 50));
        toolButton_Calib_Compass->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_Calibration_Control->addWidget(toolButton_Calib_Compass);

        toolButton_Calib_AirPressure = new QToolButton(tab2_ParameterSetting);
        toolButton_Calib_AirPressure->setObjectName("toolButton_Calib_AirPressure");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/qrc/icon/barometer.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_Calib_AirPressure->setIcon(icon3);
        toolButton_Calib_AirPressure->setIconSize(QSize(50, 50));
        toolButton_Calib_AirPressure->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_Calibration_Control->addWidget(toolButton_Calib_AirPressure);

        toolButton_Calib_SixDirection = new QToolButton(tab2_ParameterSetting);
        toolButton_Calib_SixDirection->setObjectName("toolButton_Calib_SixDirection");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/qrc/icon/360direction.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_Calib_SixDirection->setIcon(icon4);
        toolButton_Calib_SixDirection->setIconSize(QSize(50, 50));
        toolButton_Calib_SixDirection->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_Calibration_Control->addWidget(toolButton_Calib_SixDirection);


        verticalLayout_5->addLayout(horizontalLayout_Calibration_Control);

        groupBox_Mahony_Adjuster = new QGroupBox(tab2_ParameterSetting);
        groupBox_Mahony_Adjuster->setObjectName("groupBox_Mahony_Adjuster");
        verticalLayout_4 = new QVBoxLayout(groupBox_Mahony_Adjuster);
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_Mahony_Parameter = new QLabel(groupBox_Mahony_Adjuster);
        label_Mahony_Parameter->setObjectName("label_Mahony_Parameter");

        horizontalLayout_2->addWidget(label_Mahony_Parameter);

        doubleSpinBox_Mahony_Parameter_1 = new QDoubleSpinBox(groupBox_Mahony_Adjuster);
        doubleSpinBox_Mahony_Parameter_1->setObjectName("doubleSpinBox_Mahony_Parameter_1");

        horizontalLayout_2->addWidget(doubleSpinBox_Mahony_Parameter_1);

        doubleSpinBox_Mahony_Parameter_2 = new QDoubleSpinBox(groupBox_Mahony_Adjuster);
        doubleSpinBox_Mahony_Parameter_2->setObjectName("doubleSpinBox_Mahony_Parameter_2");

        horizontalLayout_2->addWidget(doubleSpinBox_Mahony_Parameter_2);

        doubleSpinBox_Mahony_Parameter_3 = new QDoubleSpinBox(groupBox_Mahony_Adjuster);
        doubleSpinBox_Mahony_Parameter_3->setObjectName("doubleSpinBox_Mahony_Parameter_3");

        horizontalLayout_2->addWidget(doubleSpinBox_Mahony_Parameter_3);

        pushButton_Mahony_Parameter_Write = new QPushButton(groupBox_Mahony_Adjuster);
        pushButton_Mahony_Parameter_Write->setObjectName("pushButton_Mahony_Parameter_Write");

        horizontalLayout_2->addWidget(pushButton_Mahony_Parameter_Write);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        checkBox_3 = new QCheckBox(groupBox_Mahony_Adjuster);
        checkBox_3->setObjectName("checkBox_3");

        horizontalLayout_7->addWidget(checkBox_3);

        checkBox_2 = new QCheckBox(groupBox_Mahony_Adjuster);
        checkBox_2->setObjectName("checkBox_2");

        horizontalLayout_7->addWidget(checkBox_2);

        checkBox = new QCheckBox(groupBox_Mahony_Adjuster);
        checkBox->setObjectName("checkBox");

        horizontalLayout_7->addWidget(checkBox);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);


        verticalLayout_4->addLayout(horizontalLayout_7);

        PlotDisplay_Mahony = new QCustomPlot(groupBox_Mahony_Adjuster);
        PlotDisplay_Mahony->setObjectName("PlotDisplay_Mahony");
        gridLayout_6 = new QGridLayout(PlotDisplay_Mahony);
        gridLayout_6->setObjectName("gridLayout_6");

        verticalLayout_4->addWidget(PlotDisplay_Mahony);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        pushButton_Mahony_Plot_Launch = new QPushButton(groupBox_Mahony_Adjuster);
        pushButton_Mahony_Plot_Launch->setObjectName("pushButton_Mahony_Plot_Launch");

        horizontalLayout_6->addWidget(pushButton_Mahony_Plot_Launch);

        pushButton_Mahony_Plot_Stop = new QPushButton(groupBox_Mahony_Adjuster);
        pushButton_Mahony_Plot_Stop->setObjectName("pushButton_Mahony_Plot_Stop");

        horizontalLayout_6->addWidget(pushButton_Mahony_Plot_Stop);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);


        verticalLayout_4->addLayout(horizontalLayout_6);

        verticalLayout_4->setStretch(2, 2);

        verticalLayout_5->addWidget(groupBox_Mahony_Adjuster);

        groupBox_PID_Control = new QGroupBox(tab2_ParameterSetting);
        groupBox_PID_Control->setObjectName("groupBox_PID_Control");
        verticalLayout_3 = new QVBoxLayout(groupBox_PID_Control);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_Rate_Adjust = new QVBoxLayout();
        verticalLayout_Rate_Adjust->setSpacing(1);
        verticalLayout_Rate_Adjust->setObjectName("verticalLayout_Rate_Adjust");
        horizontalLayout_PITRate = new QHBoxLayout();
        horizontalLayout_PITRate->setObjectName("horizontalLayout_PITRate");
        label_PITRate = new QLabel(groupBox_PID_Control);
        label_PITRate->setObjectName("label_PITRate");

        horizontalLayout_PITRate->addWidget(label_PITRate);

        doubleSpinBox_PITRate_P_Value = new QDoubleSpinBox(groupBox_PID_Control);
        doubleSpinBox_PITRate_P_Value->setObjectName("doubleSpinBox_PITRate_P_Value");

        horizontalLayout_PITRate->addWidget(doubleSpinBox_PITRate_P_Value);

        doubleSpinBox_PITRate_I_Value = new QDoubleSpinBox(groupBox_PID_Control);
        doubleSpinBox_PITRate_I_Value->setObjectName("doubleSpinBox_PITRate_I_Value");

        horizontalLayout_PITRate->addWidget(doubleSpinBox_PITRate_I_Value);

        doubleSpinBox_PITRate_D_Value = new QDoubleSpinBox(groupBox_PID_Control);
        doubleSpinBox_PITRate_D_Value->setObjectName("doubleSpinBox_PITRate_D_Value");

        horizontalLayout_PITRate->addWidget(doubleSpinBox_PITRate_D_Value);

        pushButton_PITRate_Write = new QPushButton(groupBox_PID_Control);
        pushButton_PITRate_Write->setObjectName("pushButton_PITRate_Write");

        horizontalLayout_PITRate->addWidget(pushButton_PITRate_Write);

        horizontalLayout_PITRate->setStretch(0, 1);
        horizontalLayout_PITRate->setStretch(1, 1);
        horizontalLayout_PITRate->setStretch(2, 1);
        horizontalLayout_PITRate->setStretch(3, 1);
        horizontalLayout_PITRate->setStretch(4, 1);

        verticalLayout_Rate_Adjust->addLayout(horizontalLayout_PITRate);

        horizontalLayout_ROLRate = new QHBoxLayout();
        horizontalLayout_ROLRate->setObjectName("horizontalLayout_ROLRate");
        label_ROLRate = new QLabel(groupBox_PID_Control);
        label_ROLRate->setObjectName("label_ROLRate");

        horizontalLayout_ROLRate->addWidget(label_ROLRate);

        doubleSpinBox_ROLRate_P_Value = new QDoubleSpinBox(groupBox_PID_Control);
        doubleSpinBox_ROLRate_P_Value->setObjectName("doubleSpinBox_ROLRate_P_Value");

        horizontalLayout_ROLRate->addWidget(doubleSpinBox_ROLRate_P_Value);

        doubleSpinBox_ROLRate_I_Value = new QDoubleSpinBox(groupBox_PID_Control);
        doubleSpinBox_ROLRate_I_Value->setObjectName("doubleSpinBox_ROLRate_I_Value");

        horizontalLayout_ROLRate->addWidget(doubleSpinBox_ROLRate_I_Value);

        doubleSpinBox_ROLRate_D_Value = new QDoubleSpinBox(groupBox_PID_Control);
        doubleSpinBox_ROLRate_D_Value->setObjectName("doubleSpinBox_ROLRate_D_Value");

        horizontalLayout_ROLRate->addWidget(doubleSpinBox_ROLRate_D_Value);

        pushButton_ROLRate_Write = new QPushButton(groupBox_PID_Control);
        pushButton_ROLRate_Write->setObjectName("pushButton_ROLRate_Write");

        horizontalLayout_ROLRate->addWidget(pushButton_ROLRate_Write);

        horizontalLayout_ROLRate->setStretch(0, 1);
        horizontalLayout_ROLRate->setStretch(1, 1);
        horizontalLayout_ROLRate->setStretch(2, 1);
        horizontalLayout_ROLRate->setStretch(3, 1);
        horizontalLayout_ROLRate->setStretch(4, 1);

        verticalLayout_Rate_Adjust->addLayout(horizontalLayout_ROLRate);

        horizontalLayout_YAWRate = new QHBoxLayout();
        horizontalLayout_YAWRate->setObjectName("horizontalLayout_YAWRate");
        label_YAWRate = new QLabel(groupBox_PID_Control);
        label_YAWRate->setObjectName("label_YAWRate");

        horizontalLayout_YAWRate->addWidget(label_YAWRate);

        doubleSpinBox_YAWRate_P_Value = new QDoubleSpinBox(groupBox_PID_Control);
        doubleSpinBox_YAWRate_P_Value->setObjectName("doubleSpinBox_YAWRate_P_Value");

        horizontalLayout_YAWRate->addWidget(doubleSpinBox_YAWRate_P_Value);

        doubleSpinBox_YAWRate_I_Value = new QDoubleSpinBox(groupBox_PID_Control);
        doubleSpinBox_YAWRate_I_Value->setObjectName("doubleSpinBox_YAWRate_I_Value");

        horizontalLayout_YAWRate->addWidget(doubleSpinBox_YAWRate_I_Value);

        doubleSpinBox_YAWRate_D_Value = new QDoubleSpinBox(groupBox_PID_Control);
        doubleSpinBox_YAWRate_D_Value->setObjectName("doubleSpinBox_YAWRate_D_Value");

        horizontalLayout_YAWRate->addWidget(doubleSpinBox_YAWRate_D_Value);

        pushButton_YAWRate_Write = new QPushButton(groupBox_PID_Control);
        pushButton_YAWRate_Write->setObjectName("pushButton_YAWRate_Write");

        horizontalLayout_YAWRate->addWidget(pushButton_YAWRate_Write);

        horizontalLayout_YAWRate->setStretch(0, 1);
        horizontalLayout_YAWRate->setStretch(1, 1);
        horizontalLayout_YAWRate->setStretch(2, 1);
        horizontalLayout_YAWRate->setStretch(3, 1);
        horizontalLayout_YAWRate->setStretch(4, 1);

        verticalLayout_Rate_Adjust->addLayout(horizontalLayout_YAWRate);

        verticalLayout_Rate_Adjust->setStretch(0, 1);
        verticalLayout_Rate_Adjust->setStretch(1, 1);
        verticalLayout_Rate_Adjust->setStretch(2, 1);

        verticalLayout_3->addLayout(verticalLayout_Rate_Adjust);

        line = new QFrame(groupBox_PID_Control);
        line->setObjectName("line");
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);

        verticalLayout_Self_Stabilization = new QVBoxLayout();
        verticalLayout_Self_Stabilization->setSpacing(1);
        verticalLayout_Self_Stabilization->setObjectName("verticalLayout_Self_Stabilization");
        horizontalLayout_PIT_SelfStable = new QHBoxLayout();
        horizontalLayout_PIT_SelfStable->setObjectName("horizontalLayout_PIT_SelfStable");
        label_PITSelfStable = new QLabel(groupBox_PID_Control);
        label_PITSelfStable->setObjectName("label_PITSelfStable");

        horizontalLayout_PIT_SelfStable->addWidget(label_PITSelfStable);

        doubleSpinBox_PITSelfStable_P_Value = new QDoubleSpinBox(groupBox_PID_Control);
        doubleSpinBox_PITSelfStable_P_Value->setObjectName("doubleSpinBox_PITSelfStable_P_Value");

        horizontalLayout_PIT_SelfStable->addWidget(doubleSpinBox_PITSelfStable_P_Value);

        doubleSpinBox_PITSelfStable_I_Value = new QDoubleSpinBox(groupBox_PID_Control);
        doubleSpinBox_PITSelfStable_I_Value->setObjectName("doubleSpinBox_PITSelfStable_I_Value");

        horizontalLayout_PIT_SelfStable->addWidget(doubleSpinBox_PITSelfStable_I_Value);

        doubleSpinBox_PITSelfStable_D_Value = new QDoubleSpinBox(groupBox_PID_Control);
        doubleSpinBox_PITSelfStable_D_Value->setObjectName("doubleSpinBox_PITSelfStable_D_Value");

        horizontalLayout_PIT_SelfStable->addWidget(doubleSpinBox_PITSelfStable_D_Value);

        pushButton_PITSelfStable_Write = new QPushButton(groupBox_PID_Control);
        pushButton_PITSelfStable_Write->setObjectName("pushButton_PITSelfStable_Write");

        horizontalLayout_PIT_SelfStable->addWidget(pushButton_PITSelfStable_Write);

        horizontalLayout_PIT_SelfStable->setStretch(0, 1);
        horizontalLayout_PIT_SelfStable->setStretch(1, 1);
        horizontalLayout_PIT_SelfStable->setStretch(2, 1);
        horizontalLayout_PIT_SelfStable->setStretch(3, 1);
        horizontalLayout_PIT_SelfStable->setStretch(4, 1);

        verticalLayout_Self_Stabilization->addLayout(horizontalLayout_PIT_SelfStable);

        horizontalLayout_ROL_SelfStable = new QHBoxLayout();
        horizontalLayout_ROL_SelfStable->setObjectName("horizontalLayout_ROL_SelfStable");
        label_ROLSelfStable = new QLabel(groupBox_PID_Control);
        label_ROLSelfStable->setObjectName("label_ROLSelfStable");

        horizontalLayout_ROL_SelfStable->addWidget(label_ROLSelfStable);

        doubleSpinBox_ROLSelfStable_P_Value = new QDoubleSpinBox(groupBox_PID_Control);
        doubleSpinBox_ROLSelfStable_P_Value->setObjectName("doubleSpinBox_ROLSelfStable_P_Value");

        horizontalLayout_ROL_SelfStable->addWidget(doubleSpinBox_ROLSelfStable_P_Value);

        doubleSpinBox_ROLSelfStable_I_Value = new QDoubleSpinBox(groupBox_PID_Control);
        doubleSpinBox_ROLSelfStable_I_Value->setObjectName("doubleSpinBox_ROLSelfStable_I_Value");

        horizontalLayout_ROL_SelfStable->addWidget(doubleSpinBox_ROLSelfStable_I_Value);

        doubleSpinBox_ROLSelfStable_D_Value = new QDoubleSpinBox(groupBox_PID_Control);
        doubleSpinBox_ROLSelfStable_D_Value->setObjectName("doubleSpinBox_ROLSelfStable_D_Value");

        horizontalLayout_ROL_SelfStable->addWidget(doubleSpinBox_ROLSelfStable_D_Value);

        pushButton_ROLSelfStable_Write = new QPushButton(groupBox_PID_Control);
        pushButton_ROLSelfStable_Write->setObjectName("pushButton_ROLSelfStable_Write");

        horizontalLayout_ROL_SelfStable->addWidget(pushButton_ROLSelfStable_Write);

        horizontalLayout_ROL_SelfStable->setStretch(0, 1);
        horizontalLayout_ROL_SelfStable->setStretch(1, 1);
        horizontalLayout_ROL_SelfStable->setStretch(2, 1);
        horizontalLayout_ROL_SelfStable->setStretch(3, 1);
        horizontalLayout_ROL_SelfStable->setStretch(4, 1);

        verticalLayout_Self_Stabilization->addLayout(horizontalLayout_ROL_SelfStable);

        horizontalLayout_YAW_SelfStable = new QHBoxLayout();
        horizontalLayout_YAW_SelfStable->setObjectName("horizontalLayout_YAW_SelfStable");
        label_YAWSelfStable = new QLabel(groupBox_PID_Control);
        label_YAWSelfStable->setObjectName("label_YAWSelfStable");

        horizontalLayout_YAW_SelfStable->addWidget(label_YAWSelfStable);

        doubleSpinBox_YAWSelfStable_P_Value = new QDoubleSpinBox(groupBox_PID_Control);
        doubleSpinBox_YAWSelfStable_P_Value->setObjectName("doubleSpinBox_YAWSelfStable_P_Value");

        horizontalLayout_YAW_SelfStable->addWidget(doubleSpinBox_YAWSelfStable_P_Value);

        doubleSpinBox_YAWSelfStable_I_Value = new QDoubleSpinBox(groupBox_PID_Control);
        doubleSpinBox_YAWSelfStable_I_Value->setObjectName("doubleSpinBox_YAWSelfStable_I_Value");

        horizontalLayout_YAW_SelfStable->addWidget(doubleSpinBox_YAWSelfStable_I_Value);

        doubleSpinBox_YAWSelfStable_D_Value = new QDoubleSpinBox(groupBox_PID_Control);
        doubleSpinBox_YAWSelfStable_D_Value->setObjectName("doubleSpinBox_YAWSelfStable_D_Value");

        horizontalLayout_YAW_SelfStable->addWidget(doubleSpinBox_YAWSelfStable_D_Value);

        pushButton_YAWSelfStable_Write = new QPushButton(groupBox_PID_Control);
        pushButton_YAWSelfStable_Write->setObjectName("pushButton_YAWSelfStable_Write");

        horizontalLayout_YAW_SelfStable->addWidget(pushButton_YAWSelfStable_Write);

        horizontalLayout_YAW_SelfStable->setStretch(0, 1);
        horizontalLayout_YAW_SelfStable->setStretch(1, 1);
        horizontalLayout_YAW_SelfStable->setStretch(2, 1);
        horizontalLayout_YAW_SelfStable->setStretch(3, 1);
        horizontalLayout_YAW_SelfStable->setStretch(4, 1);

        verticalLayout_Self_Stabilization->addLayout(horizontalLayout_YAW_SelfStable);

        verticalLayout_Self_Stabilization->setStretch(0, 1);
        verticalLayout_Self_Stabilization->setStretch(1, 1);
        verticalLayout_Self_Stabilization->setStretch(2, 1);

        verticalLayout_3->addLayout(verticalLayout_Self_Stabilization);


        verticalLayout_5->addWidget(groupBox_PID_Control);


        horizontalLayout_5->addLayout(verticalLayout_5);

        tabWidget_PanelMain->addTab(tab2_ParameterSetting, QString());
        tab3_ParameterTesting = new QWidget();
        tab3_ParameterTesting->setObjectName("tab3_ParameterTesting");
        pushButton_PWMValue_Save = new QPushButton(tab3_ParameterTesting);
        pushButton_PWMValue_Save->setObjectName("pushButton_PWMValue_Save");
        pushButton_PWMValue_Save->setGeometry(QRect(10, 530, 89, 25));
        widget_3 = new QCustomPlot(tab3_ParameterTesting);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(10, 10, 501, 211));
        layoutWidget = new QWidget(tab3_ParameterTesting);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 230, 501, 288));
        verticalLayout_16 = new QVBoxLayout(layoutWidget);
        verticalLayout_16->setObjectName("verticalLayout_16");
        verticalLayout_16->setContentsMargins(0, 0, 0, 0);
        groupBox_ESC_Features = new QGroupBox(layoutWidget);
        groupBox_ESC_Features->setObjectName("groupBox_ESC_Features");
        verticalLayout_6 = new QVBoxLayout(groupBox_ESC_Features);
        verticalLayout_6->setObjectName("verticalLayout_6");
        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName("horizontalLayout_25");
        spinBox_MinThrottle = new QSpinBox(groupBox_ESC_Features);
        spinBox_MinThrottle->setObjectName("spinBox_MinThrottle");
        spinBox_MinThrottle->setMinimumSize(QSize(100, 0));

        horizontalLayout_25->addWidget(spinBox_MinThrottle);

        label_MinThrottle = new QLabel(groupBox_ESC_Features);
        label_MinThrottle->setObjectName("label_MinThrottle");

        horizontalLayout_25->addWidget(label_MinThrottle);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_25->addItem(horizontalSpacer_5);

        horizontalLayout_25->setStretch(0, 1);
        horizontalLayout_25->setStretch(1, 1);

        verticalLayout_6->addLayout(horizontalLayout_25);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setObjectName("horizontalLayout_26");
        spinBox_MaxThrottle = new QSpinBox(groupBox_ESC_Features);
        spinBox_MaxThrottle->setObjectName("spinBox_MaxThrottle");
        spinBox_MaxThrottle->setMinimumSize(QSize(100, 0));

        horizontalLayout_26->addWidget(spinBox_MaxThrottle);

        label_MaxThrottle = new QLabel(groupBox_ESC_Features);
        label_MaxThrottle->setObjectName("label_MaxThrottle");

        horizontalLayout_26->addWidget(label_MaxThrottle);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_26->addItem(horizontalSpacer_9);

        horizontalLayout_26->setStretch(0, 1);
        horizontalLayout_26->setStretch(1, 1);

        verticalLayout_6->addLayout(horizontalLayout_26);


        verticalLayout_16->addWidget(groupBox_ESC_Features);

        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_P12PWM0 = new QLabel(groupBox);
        label_P12PWM0->setObjectName("label_P12PWM0");

        horizontalLayout_9->addWidget(label_P12PWM0);

        horizontalSlider_P12PWM0 = new QSlider(groupBox);
        horizontalSlider_P12PWM0->setObjectName("horizontalSlider_P12PWM0");
        horizontalSlider_P12PWM0->setMaximum(255);
        horizontalSlider_P12PWM0->setOrientation(Qt::Horizontal);

        horizontalLayout_9->addWidget(horizontalSlider_P12PWM0);

        doubleSpinBox_P12PWM0 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_P12PWM0->setObjectName("doubleSpinBox_P12PWM0");
        doubleSpinBox_P12PWM0->setDecimals(2);
        doubleSpinBox_P12PWM0->setMaximum(100.000000000000000);
        doubleSpinBox_P12PWM0->setSingleStep(0.010000000000000);

        horizontalLayout_9->addWidget(doubleSpinBox_P12PWM0);


        gridLayout->addLayout(horizontalLayout_9, 0, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_P13PWM1 = new QLabel(groupBox);
        label_P13PWM1->setObjectName("label_P13PWM1");

        horizontalLayout_8->addWidget(label_P13PWM1);

        horizontalSlider_P13PWM1 = new QSlider(groupBox);
        horizontalSlider_P13PWM1->setObjectName("horizontalSlider_P13PWM1");
        horizontalSlider_P13PWM1->setMaximum(255);
        horizontalSlider_P13PWM1->setOrientation(Qt::Horizontal);
        horizontalSlider_P13PWM1->setInvertedAppearance(false);
        horizontalSlider_P13PWM1->setInvertedControls(false);

        horizontalLayout_8->addWidget(horizontalSlider_P13PWM1);

        doubleSpinBox_P13PWM1 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_P13PWM1->setObjectName("doubleSpinBox_P13PWM1");
        doubleSpinBox_P13PWM1->setDecimals(2);
        doubleSpinBox_P13PWM1->setMaximum(100.000000000000000);
        doubleSpinBox_P13PWM1->setSingleStep(0.010000000000000);

        horizontalLayout_8->addWidget(doubleSpinBox_P13PWM1);


        gridLayout->addLayout(horizontalLayout_8, 1, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        label_P19PWM2 = new QLabel(groupBox);
        label_P19PWM2->setObjectName("label_P19PWM2");

        horizontalLayout_10->addWidget(label_P19PWM2);

        horizontalSlider_P19PWM2 = new QSlider(groupBox);
        horizontalSlider_P19PWM2->setObjectName("horizontalSlider_P19PWM2");
        horizontalSlider_P19PWM2->setMaximum(255);
        horizontalSlider_P19PWM2->setOrientation(Qt::Horizontal);

        horizontalLayout_10->addWidget(horizontalSlider_P19PWM2);

        doubleSpinBox_P19PWM2 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_P19PWM2->setObjectName("doubleSpinBox_P19PWM2");
        doubleSpinBox_P19PWM2->setDecimals(2);
        doubleSpinBox_P19PWM2->setMaximum(100.000000000000000);
        doubleSpinBox_P19PWM2->setSingleStep(0.010000000000000);

        horizontalLayout_10->addWidget(doubleSpinBox_P19PWM2);


        gridLayout->addLayout(horizontalLayout_10, 2, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        label_P18PWM3 = new QLabel(groupBox);
        label_P18PWM3->setObjectName("label_P18PWM3");

        horizontalLayout_11->addWidget(label_P18PWM3);

        horizontalSlider_P18PWM3 = new QSlider(groupBox);
        horizontalSlider_P18PWM3->setObjectName("horizontalSlider_P18PWM3");
        horizontalSlider_P18PWM3->setMaximum(255);
        horizontalSlider_P18PWM3->setOrientation(Qt::Horizontal);

        horizontalLayout_11->addWidget(horizontalSlider_P18PWM3);

        doubleSpinBox_P18PWM3 = new QDoubleSpinBox(groupBox);
        doubleSpinBox_P18PWM3->setObjectName("doubleSpinBox_P18PWM3");
        doubleSpinBox_P18PWM3->setDecimals(2);
        doubleSpinBox_P18PWM3->setMaximum(100.000000000000000);
        doubleSpinBox_P18PWM3->setSingleStep(0.010000000000000);

        horizontalLayout_11->addWidget(doubleSpinBox_P18PWM3);


        gridLayout->addLayout(horizontalLayout_11, 3, 0, 1, 1);


        verticalLayout_16->addWidget(groupBox);

        widget1 = new QWidget(tab3_ParameterTesting);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(540, 20, 52, 181));
        verticalLayout_17 = new QVBoxLayout(widget1);
        verticalLayout_17->setObjectName("verticalLayout_17");
        verticalLayout_17->setContentsMargins(0, 0, 0, 0);
        verticalSlider = new QSlider(widget1);
        verticalSlider->setObjectName("verticalSlider");
        verticalSlider->setMinimumSize(QSize(50, 0));
        verticalSlider->setOrientation(Qt::Vertical);

        verticalLayout_17->addWidget(verticalSlider);

        label_Trust_Control = new QLabel(widget1);
        label_Trust_Control->setObjectName("label_Trust_Control");
        label_Trust_Control->setAlignment(Qt::AlignCenter);

        verticalLayout_17->addWidget(label_Trust_Control);

        tabWidget_PanelMain->addTab(tab3_ParameterTesting, QString());
        tab4_SensorRegistersSetting = new QWidget();
        tab4_SensorRegistersSetting->setObjectName("tab4_SensorRegistersSetting");
        verticalLayout_10 = new QVBoxLayout(tab4_SensorRegistersSetting);
        verticalLayout_10->setObjectName("verticalLayout_10");
        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(30);
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_7);

        toolButton_MPU6050_REG_CONFIG = new QToolButton(tab4_SensorRegistersSetting);
        toolButton_MPU6050_REG_CONFIG->setObjectName("toolButton_MPU6050_REG_CONFIG");
        toolButton_MPU6050_REG_CONFIG->setMinimumSize(QSize(80, 50));
        toolButton_MPU6050_REG_CONFIG->setCheckable(true);
        toolButton_MPU6050_REG_CONFIG->setChecked(true);
        toolButton_MPU6050_REG_CONFIG->setAutoExclusive(true);

        horizontalLayout_17->addWidget(toolButton_MPU6050_REG_CONFIG);

        toolButton_BMP180_REG_CONFIG = new QToolButton(tab4_SensorRegistersSetting);
        toolButton_BMP180_REG_CONFIG->setObjectName("toolButton_BMP180_REG_CONFIG");
        toolButton_BMP180_REG_CONFIG->setMinimumSize(QSize(80, 50));
        toolButton_BMP180_REG_CONFIG->setCheckable(true);
        toolButton_BMP180_REG_CONFIG->setAutoExclusive(true);

        horizontalLayout_17->addWidget(toolButton_BMP180_REG_CONFIG);

        toolButton_GY271_REG_CONFIG = new QToolButton(tab4_SensorRegistersSetting);
        toolButton_GY271_REG_CONFIG->setObjectName("toolButton_GY271_REG_CONFIG");
        toolButton_GY271_REG_CONFIG->setMinimumSize(QSize(80, 50));
        toolButton_GY271_REG_CONFIG->setCheckable(true);
        toolButton_GY271_REG_CONFIG->setAutoExclusive(true);

        horizontalLayout_17->addWidget(toolButton_GY271_REG_CONFIG);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_6);


        verticalLayout_10->addLayout(horizontalLayout_17);

        stackedWidget_REG_CONFIG = new QStackedWidget(tab4_SensorRegistersSetting);
        stackedWidget_REG_CONFIG->setObjectName("stackedWidget_REG_CONFIG");
        stackedWidget_REG_CONFIG->setFrameShape(QFrame::Box);
        stackedWidget_REG_CONFIG->setFrameShadow(QFrame::Plain);
        MPU6050_Page = new QWidget();
        MPU6050_Page->setObjectName("MPU6050_Page");
        verticalLayout_15 = new QVBoxLayout(MPU6050_Page);
        verticalLayout_15->setObjectName("verticalLayout_15");
        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setSpacing(20);
        horizontalLayout_24->setObjectName("horizontalLayout_24");
        pushButton_REG_READ_ALL_MPU6050 = new QPushButton(MPU6050_Page);
        pushButton_REG_READ_ALL_MPU6050->setObjectName("pushButton_REG_READ_ALL_MPU6050");

        horizontalLayout_24->addWidget(pushButton_REG_READ_ALL_MPU6050);

        pushButton = new QPushButton(MPU6050_Page);
        pushButton->setObjectName("pushButton");

        horizontalLayout_24->addWidget(pushButton);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_24->addItem(horizontalSpacer_8);


        verticalLayout_15->addLayout(horizontalLayout_24);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName("verticalLayout_14");
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName("horizontalLayout_20");
        groupBox_GYRO_CONFIG = new QGroupBox(MPU6050_Page);
        groupBox_GYRO_CONFIG->setObjectName("groupBox_GYRO_CONFIG");
        verticalLayout_8 = new QVBoxLayout(groupBox_GYRO_CONFIG);
        verticalLayout_8->setObjectName("verticalLayout_8");
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        label_SelfTest_GYRO = new QLabel(groupBox_GYRO_CONFIG);
        label_SelfTest_GYRO->setObjectName("label_SelfTest_GYRO");

        horizontalLayout_13->addWidget(label_SelfTest_GYRO);

        checkBox_XG_SelfTest = new QCheckBox(groupBox_GYRO_CONFIG);
        checkBox_XG_SelfTest->setObjectName("checkBox_XG_SelfTest");

        horizontalLayout_13->addWidget(checkBox_XG_SelfTest);

        checkBox_YG_SelfTest = new QCheckBox(groupBox_GYRO_CONFIG);
        checkBox_YG_SelfTest->setObjectName("checkBox_YG_SelfTest");

        horizontalLayout_13->addWidget(checkBox_YG_SelfTest);

        checkBox_ZG_SelfTest = new QCheckBox(groupBox_GYRO_CONFIG);
        checkBox_ZG_SelfTest->setObjectName("checkBox_ZG_SelfTest");

        horizontalLayout_13->addWidget(checkBox_ZG_SelfTest);

        horizontalLayout_13->setStretch(0, 3);
        horizontalLayout_13->setStretch(1, 1);
        horizontalLayout_13->setStretch(2, 1);
        horizontalLayout_13->setStretch(3, 1);

        verticalLayout_8->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        label_FullScaleRange_GYRO = new QLabel(groupBox_GYRO_CONFIG);
        label_FullScaleRange_GYRO->setObjectName("label_FullScaleRange_GYRO");

        horizontalLayout_14->addWidget(label_FullScaleRange_GYRO);

        comboBox_FullScaleRange_GYRO = new QComboBox(groupBox_GYRO_CONFIG);
        comboBox_FullScaleRange_GYRO->addItem(QString());
        comboBox_FullScaleRange_GYRO->addItem(QString());
        comboBox_FullScaleRange_GYRO->addItem(QString());
        comboBox_FullScaleRange_GYRO->addItem(QString());
        comboBox_FullScaleRange_GYRO->setObjectName("comboBox_FullScaleRange_GYRO");

        horizontalLayout_14->addWidget(comboBox_FullScaleRange_GYRO);

        horizontalLayout_14->setStretch(0, 1);
        horizontalLayout_14->setStretch(1, 1);

        verticalLayout_8->addLayout(horizontalLayout_14);


        horizontalLayout_20->addWidget(groupBox_GYRO_CONFIG);

        groupBox_ACCEL_CONFIG = new QGroupBox(MPU6050_Page);
        groupBox_ACCEL_CONFIG->setObjectName("groupBox_ACCEL_CONFIG");
        verticalLayout_9 = new QVBoxLayout(groupBox_ACCEL_CONFIG);
        verticalLayout_9->setObjectName("verticalLayout_9");
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        label_SelfTest_ACCEL = new QLabel(groupBox_ACCEL_CONFIG);
        label_SelfTest_ACCEL->setObjectName("label_SelfTest_ACCEL");

        horizontalLayout_15->addWidget(label_SelfTest_ACCEL);

        checkBox_XA_SelfTest = new QCheckBox(groupBox_ACCEL_CONFIG);
        checkBox_XA_SelfTest->setObjectName("checkBox_XA_SelfTest");

        horizontalLayout_15->addWidget(checkBox_XA_SelfTest);

        checkBox_YA_SelfTest = new QCheckBox(groupBox_ACCEL_CONFIG);
        checkBox_YA_SelfTest->setObjectName("checkBox_YA_SelfTest");

        horizontalLayout_15->addWidget(checkBox_YA_SelfTest);

        checkBox_ZA_SelfTest = new QCheckBox(groupBox_ACCEL_CONFIG);
        checkBox_ZA_SelfTest->setObjectName("checkBox_ZA_SelfTest");

        horizontalLayout_15->addWidget(checkBox_ZA_SelfTest);

        horizontalLayout_15->setStretch(0, 3);
        horizontalLayout_15->setStretch(1, 1);
        horizontalLayout_15->setStretch(2, 1);
        horizontalLayout_15->setStretch(3, 1);

        verticalLayout_9->addLayout(horizontalLayout_15);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        label_FullScaleRange_ACCEL = new QLabel(groupBox_ACCEL_CONFIG);
        label_FullScaleRange_ACCEL->setObjectName("label_FullScaleRange_ACCEL");

        horizontalLayout_16->addWidget(label_FullScaleRange_ACCEL);

        comboBox_FullScaleRange_ACCEL = new QComboBox(groupBox_ACCEL_CONFIG);
        comboBox_FullScaleRange_ACCEL->addItem(QString());
        comboBox_FullScaleRange_ACCEL->addItem(QString());
        comboBox_FullScaleRange_ACCEL->addItem(QString());
        comboBox_FullScaleRange_ACCEL->addItem(QString());
        comboBox_FullScaleRange_ACCEL->setObjectName("comboBox_FullScaleRange_ACCEL");

        horizontalLayout_16->addWidget(comboBox_FullScaleRange_ACCEL);

        horizontalLayout_16->setStretch(0, 1);
        horizontalLayout_16->setStretch(1, 1);

        verticalLayout_9->addLayout(horizontalLayout_16);


        horizontalLayout_20->addWidget(groupBox_ACCEL_CONFIG);


        verticalLayout_14->addLayout(horizontalLayout_20);

        groupBox_FIFO_EN = new QGroupBox(MPU6050_Page);
        groupBox_FIFO_EN->setObjectName("groupBox_FIFO_EN");
        verticalLayout_11 = new QVBoxLayout(groupBox_FIFO_EN);
        verticalLayout_11->setObjectName("verticalLayout_11");
        checkBox_TEMP_FIFO_EN = new QCheckBox(groupBox_FIFO_EN);
        checkBox_TEMP_FIFO_EN->setObjectName("checkBox_TEMP_FIFO_EN");

        verticalLayout_11->addWidget(checkBox_TEMP_FIFO_EN);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        checkBox_XG_FIFO_EN = new QCheckBox(groupBox_FIFO_EN);
        checkBox_XG_FIFO_EN->setObjectName("checkBox_XG_FIFO_EN");

        horizontalLayout_18->addWidget(checkBox_XG_FIFO_EN);

        checkBox_YG_FIFO_EN = new QCheckBox(groupBox_FIFO_EN);
        checkBox_YG_FIFO_EN->setObjectName("checkBox_YG_FIFO_EN");

        horizontalLayout_18->addWidget(checkBox_YG_FIFO_EN);

        checkBox_ZG_FIFO_EN = new QCheckBox(groupBox_FIFO_EN);
        checkBox_ZG_FIFO_EN->setObjectName("checkBox_ZG_FIFO_EN");

        horizontalLayout_18->addWidget(checkBox_ZG_FIFO_EN);

        horizontalLayout_18->setStretch(0, 1);
        horizontalLayout_18->setStretch(1, 1);
        horizontalLayout_18->setStretch(2, 1);

        verticalLayout_11->addLayout(horizontalLayout_18);

        checkBox_ACCEL_FIFO_EN = new QCheckBox(groupBox_FIFO_EN);
        checkBox_ACCEL_FIFO_EN->setObjectName("checkBox_ACCEL_FIFO_EN");

        verticalLayout_11->addWidget(checkBox_ACCEL_FIFO_EN);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName("horizontalLayout_19");
        checkBox_SLV2_FIFO_EN = new QCheckBox(groupBox_FIFO_EN);
        checkBox_SLV2_FIFO_EN->setObjectName("checkBox_SLV2_FIFO_EN");

        horizontalLayout_19->addWidget(checkBox_SLV2_FIFO_EN);

        checkBox_SLV1_FIFO_EN = new QCheckBox(groupBox_FIFO_EN);
        checkBox_SLV1_FIFO_EN->setObjectName("checkBox_SLV1_FIFO_EN");

        horizontalLayout_19->addWidget(checkBox_SLV1_FIFO_EN);

        checkBox_SLV0_FIFO_EN = new QCheckBox(groupBox_FIFO_EN);
        checkBox_SLV0_FIFO_EN->setObjectName("checkBox_SLV0_FIFO_EN");

        horizontalLayout_19->addWidget(checkBox_SLV0_FIFO_EN);

        horizontalLayout_19->setStretch(0, 1);
        horizontalLayout_19->setStretch(1, 1);
        horizontalLayout_19->setStretch(2, 1);

        verticalLayout_11->addLayout(horizontalLayout_19);

        verticalLayout_11->setStretch(0, 1);
        verticalLayout_11->setStretch(1, 1);
        verticalLayout_11->setStretch(2, 1);
        verticalLayout_11->setStretch(3, 1);

        verticalLayout_14->addWidget(groupBox_FIFO_EN);

        groupBox_2 = new QGroupBox(MPU6050_Page);
        groupBox_2->setObjectName("groupBox_2");
        verticalLayout_13 = new QVBoxLayout(groupBox_2);
        verticalLayout_13->setObjectName("verticalLayout_13");
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName("verticalLayout_12");
        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName("horizontalLayout_21");
        label_INT_LEVEL = new QLabel(groupBox_2);
        label_INT_LEVEL->setObjectName("label_INT_LEVEL");

        horizontalLayout_21->addWidget(label_INT_LEVEL);

        comboBox_INT_LEVEL = new QComboBox(groupBox_2);
        comboBox_INT_LEVEL->addItem(QString());
        comboBox_INT_LEVEL->addItem(QString());
        comboBox_INT_LEVEL->setObjectName("comboBox_INT_LEVEL");

        horizontalLayout_21->addWidget(comboBox_INT_LEVEL);

        horizontalLayout_21->setStretch(0, 1);
        horizontalLayout_21->setStretch(1, 2);

        verticalLayout_12->addLayout(horizontalLayout_21);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName("horizontalLayout_22");
        label_INT_OPEN = new QLabel(groupBox_2);
        label_INT_OPEN->setObjectName("label_INT_OPEN");

        horizontalLayout_22->addWidget(label_INT_OPEN);

        comboBox_INT_OPEN = new QComboBox(groupBox_2);
        comboBox_INT_OPEN->addItem(QString());
        comboBox_INT_OPEN->addItem(QString());
        comboBox_INT_OPEN->setObjectName("comboBox_INT_OPEN");

        horizontalLayout_22->addWidget(comboBox_INT_OPEN);

        horizontalLayout_22->setStretch(0, 1);
        horizontalLayout_22->setStretch(1, 2);

        verticalLayout_12->addLayout(horizontalLayout_22);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName("horizontalLayout_23");
        label_LATCH_INT_EN = new QLabel(groupBox_2);
        label_LATCH_INT_EN->setObjectName("label_LATCH_INT_EN");

        horizontalLayout_23->addWidget(label_LATCH_INT_EN);

        comboBox_LATCH_INT_EN = new QComboBox(groupBox_2);
        comboBox_LATCH_INT_EN->addItem(QString());
        comboBox_LATCH_INT_EN->addItem(QString());
        comboBox_LATCH_INT_EN->setObjectName("comboBox_LATCH_INT_EN");

        horizontalLayout_23->addWidget(comboBox_LATCH_INT_EN);

        horizontalLayout_23->setStretch(0, 1);
        horizontalLayout_23->setStretch(1, 2);

        verticalLayout_12->addLayout(horizontalLayout_23);


        verticalLayout_13->addLayout(verticalLayout_12);


        verticalLayout_14->addWidget(groupBox_2);


        verticalLayout_15->addLayout(verticalLayout_14);

        stackedWidget_REG_CONFIG->addWidget(MPU6050_Page);
        BMP180_Page = new QWidget();
        BMP180_Page->setObjectName("BMP180_Page");
        pushButton_REG_READ_ALL_BMP180 = new QPushButton(BMP180_Page);
        pushButton_REG_READ_ALL_BMP180->setObjectName("pushButton_REG_READ_ALL_BMP180");
        pushButton_REG_READ_ALL_BMP180->setGeometry(QRect(40, 30, 89, 25));
        stackedWidget_REG_CONFIG->addWidget(BMP180_Page);
        GY271_Page = new QWidget();
        GY271_Page->setObjectName("GY271_Page");
        pushButton_REG_READ_ALL_GY271 = new QPushButton(GY271_Page);
        pushButton_REG_READ_ALL_GY271->setObjectName("pushButton_REG_READ_ALL_GY271");
        pushButton_REG_READ_ALL_GY271->setGeometry(QRect(50, 40, 89, 25));
        stackedWidget_REG_CONFIG->addWidget(GY271_Page);

        verticalLayout_10->addWidget(stackedWidget_REG_CONFIG);

        tabWidget_PanelMain->addTab(tab4_SensorRegistersSetting, QString());

        verticalLayout_7->addWidget(tabWidget_PanelMain);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 835, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget_PanelMain->setCurrentIndex(2);
        tabWidget_FlightControlInfo->setCurrentIndex(1);
        stackedWidget_REG_CONFIG->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupbox_Connection_Control->setTitle(QCoreApplication::translate("MainWindow", "Connection Control", nullptr));
        label_Network_IPAddr->setText(QCoreApplication::translate("MainWindow", "IP Address", nullptr));
        lineEdit_Network_IPAddr->setText(QCoreApplication::translate("MainWindow", "192.168.31.213", nullptr));
        label_Network_Port->setText(QCoreApplication::translate("MainWindow", "Port", nullptr));
        lineEdit_Network_Port->setText(QCoreApplication::translate("MainWindow", "12345", nullptr));
        pushButton_Network_Connect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        pushButton_Network_Disconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        label_TCP_Connection->setText(QCoreApplication::translate("MainWindow", "TCP", nullptr));
        icon_TCP_Connection->setText(QString());
        label_UDP_Connection->setText(QCoreApplication::translate("MainWindow", "UDP", nullptr));
        icon_UDP_Connection->setText(QString());
        tabWidget_FlightControlInfo->setTabText(tabWidget_FlightControlInfo->indexOf(FlightControlinfo_Status), QCoreApplication::translate("MainWindow", "Status Info", nullptr));
        tabWidget_FlightControlInfo->setTabText(tabWidget_FlightControlInfo->indexOf(FlightControlinfo_Graph), QCoreApplication::translate("MainWindow", "Attitude Chart", nullptr));
        groupBox_SensorData->setTitle(QCoreApplication::translate("MainWindow", "Sensor Data", nullptr));
        label_ACC_X->setText(QCoreApplication::translate("MainWindow", "ACC-X", nullptr));
        label_ACC_Y->setText(QCoreApplication::translate("MainWindow", "ACC-Y", nullptr));
        label_ACC_Z->setText(QCoreApplication::translate("MainWindow", "ACC-Z", nullptr));
        label_GYR_X->setText(QCoreApplication::translate("MainWindow", "GYR-X", nullptr));
        label_GYR_Y->setText(QCoreApplication::translate("MainWindow", "GYR-Y", nullptr));
        label_GYR_Z->setText(QCoreApplication::translate("MainWindow", "GYR-Z", nullptr));
        label_MAG_X->setText(QCoreApplication::translate("MainWindow", "MAG-X", nullptr));
        label_MAG_Y->setText(QCoreApplication::translate("MainWindow", "MAG-Y", nullptr));
        label_MAG_Z->setText(QCoreApplication::translate("MainWindow", "MAG-Z", nullptr));
        label_Altitude->setText(QCoreApplication::translate("MainWindow", "Altitude", nullptr));
        label_Ultrasound->setText(QCoreApplication::translate("MainWindow", "Ultrasou", nullptr));
        label_Temp->setText(QCoreApplication::translate("MainWindow", "Temp", nullptr));
        groupBox_GPS->setTitle(QCoreApplication::translate("MainWindow", "Flight Control Panel", nullptr));
        pushButton_TAKE_OFF->setText(QCoreApplication::translate("MainWindow", "TAKE OFF", nullptr));
        tabWidget_PanelMain->setTabText(tabWidget_PanelMain->indexOf(tab1_FlightControl), QCoreApplication::translate("MainWindow", "Flight Control", nullptr));
        toolButton_Calib_Gyto->setText(QCoreApplication::translate("MainWindow", "\351\231\200\350\236\272\344\273\252\346\240\241\345\207\206", nullptr));
        toolButton_Calib_Accelerate->setText(QCoreApplication::translate("MainWindow", "\345\212\240\351\200\237\345\272\246\346\240\241\345\207\206", nullptr));
        toolButton_Calib_Compass->setText(QCoreApplication::translate("MainWindow", "\347\243\201\347\275\227\347\233\230\346\240\241\345\207\206", nullptr));
        toolButton_Calib_AirPressure->setText(QCoreApplication::translate("MainWindow", "\346\260\224\345\216\213\350\256\241\346\240\241\345\207\206", nullptr));
        toolButton_Calib_SixDirection->setText(QCoreApplication::translate("MainWindow", "360\345\272\246\346\240\241\345\207\206", nullptr));
        groupBox_Mahony_Adjuster->setTitle(QCoreApplication::translate("MainWindow", "Mahony \350\260\203\346\225\264\345\231\250", nullptr));
        label_Mahony_Parameter->setText(QCoreApplication::translate("MainWindow", "\346\216\247\345\210\266\345\217\202\346\225\260", nullptr));
        pushButton_Mahony_Parameter_Write->setText(QCoreApplication::translate("MainWindow", "Write", nullptr));
        checkBox_3->setText(QCoreApplication::translate("MainWindow", "Rol", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "Yaw", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Pit", nullptr));
        pushButton_Mahony_Plot_Launch->setText(QCoreApplication::translate("MainWindow", "Launch", nullptr));
        pushButton_Mahony_Plot_Stop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        groupBox_PID_Control->setTitle(QCoreApplication::translate("MainWindow", "PID Control", nullptr));
        label_PITRate->setText(QCoreApplication::translate("MainWindow", "PIT\351\200\237\347\216\207", nullptr));
        pushButton_PITRate_Write->setText(QCoreApplication::translate("MainWindow", "Write", nullptr));
        label_ROLRate->setText(QCoreApplication::translate("MainWindow", "ROL\351\200\237\347\216\207", nullptr));
        pushButton_ROLRate_Write->setText(QCoreApplication::translate("MainWindow", "Write", nullptr));
        label_YAWRate->setText(QCoreApplication::translate("MainWindow", "YAW\351\200\237\347\216\207", nullptr));
        pushButton_YAWRate_Write->setText(QCoreApplication::translate("MainWindow", "Write", nullptr));
        label_PITSelfStable->setText(QCoreApplication::translate("MainWindow", "\350\207\252\347\250\263PIT", nullptr));
        pushButton_PITSelfStable_Write->setText(QCoreApplication::translate("MainWindow", "Write", nullptr));
        label_ROLSelfStable->setText(QCoreApplication::translate("MainWindow", "\350\207\252\347\250\263ROL", nullptr));
        pushButton_ROLSelfStable_Write->setText(QCoreApplication::translate("MainWindow", "Write", nullptr));
        label_YAWSelfStable->setText(QCoreApplication::translate("MainWindow", "\350\207\252\347\250\263YAW", nullptr));
        pushButton_YAWSelfStable_Write->setText(QCoreApplication::translate("MainWindow", "Write", nullptr));
        tabWidget_PanelMain->setTabText(tabWidget_PanelMain->indexOf(tab2_ParameterSetting), QCoreApplication::translate("MainWindow", "Parameter Setting", nullptr));
        pushButton_PWMValue_Save->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        groupBox_ESC_Features->setTitle(QCoreApplication::translate("MainWindow", "ESC Features", nullptr));
        label_MinThrottle->setText(QCoreApplication::translate("MainWindow", "Minimum Throttle (Lowest ESC value when armed)", nullptr));
        label_MaxThrottle->setText(QCoreApplication::translate("MainWindow", "Maximum Throttle (Highest ESC value when armed)", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Duty Cycle Adjustment", nullptr));
        label_P12PWM0->setText(QCoreApplication::translate("MainWindow", "GPIO12 PWM0", nullptr));
        doubleSpinBox_P12PWM0->setSuffix(QCoreApplication::translate("MainWindow", "%", nullptr));
        label_P13PWM1->setText(QCoreApplication::translate("MainWindow", "GPIO13 PWM1", nullptr));
        doubleSpinBox_P13PWM1->setSuffix(QCoreApplication::translate("MainWindow", "%", nullptr));
        label_P19PWM2->setText(QCoreApplication::translate("MainWindow", "GPIO19 PWM2", nullptr));
        doubleSpinBox_P19PWM2->setSuffix(QCoreApplication::translate("MainWindow", "%", nullptr));
        label_P18PWM3->setText(QCoreApplication::translate("MainWindow", "GPIO18 PWM3", nullptr));
        doubleSpinBox_P18PWM3->setSuffix(QCoreApplication::translate("MainWindow", "%", nullptr));
        label_Trust_Control->setText(QCoreApplication::translate("MainWindow", "Trust", nullptr));
        tabWidget_PanelMain->setTabText(tabWidget_PanelMain->indexOf(tab3_ParameterTesting), QCoreApplication::translate("MainWindow", "Parameter Testing", nullptr));
        toolButton_MPU6050_REG_CONFIG->setText(QCoreApplication::translate("MainWindow", "MPU6050", nullptr));
        toolButton_BMP180_REG_CONFIG->setText(QCoreApplication::translate("MainWindow", "BMP180", nullptr));
        toolButton_GY271_REG_CONFIG->setText(QCoreApplication::translate("MainWindow", "GY271", nullptr));
        pushButton_REG_READ_ALL_MPU6050->setText(QCoreApplication::translate("MainWindow", "Read All", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Clean All", nullptr));
        groupBox_GYRO_CONFIG->setTitle(QCoreApplication::translate("MainWindow", "GYRO CONFIG", nullptr));
        label_SelfTest_GYRO->setText(QCoreApplication::translate("MainWindow", "Self Test", nullptr));
        checkBox_XG_SelfTest->setText(QCoreApplication::translate("MainWindow", "XG", nullptr));
        checkBox_YG_SelfTest->setText(QCoreApplication::translate("MainWindow", "YG", nullptr));
        checkBox_ZG_SelfTest->setText(QCoreApplication::translate("MainWindow", "ZG", nullptr));
        label_FullScaleRange_GYRO->setText(QCoreApplication::translate("MainWindow", "Full Scale Range", nullptr));
        comboBox_FullScaleRange_GYRO->setItemText(0, QCoreApplication::translate("MainWindow", "\302\261 250 \302\260/s", nullptr));
        comboBox_FullScaleRange_GYRO->setItemText(1, QCoreApplication::translate("MainWindow", "\302\261 500 \302\260/s", nullptr));
        comboBox_FullScaleRange_GYRO->setItemText(2, QCoreApplication::translate("MainWindow", "\302\261 1000 \302\260/s", nullptr));
        comboBox_FullScaleRange_GYRO->setItemText(3, QCoreApplication::translate("MainWindow", "\302\261 2000 \302\260/s", nullptr));

        groupBox_ACCEL_CONFIG->setTitle(QCoreApplication::translate("MainWindow", "ACCEL CONFIG", nullptr));
        label_SelfTest_ACCEL->setText(QCoreApplication::translate("MainWindow", "Self Test", nullptr));
        checkBox_XA_SelfTest->setText(QCoreApplication::translate("MainWindow", "XA", nullptr));
        checkBox_YA_SelfTest->setText(QCoreApplication::translate("MainWindow", "YA", nullptr));
        checkBox_ZA_SelfTest->setText(QCoreApplication::translate("MainWindow", "ZA", nullptr));
        label_FullScaleRange_ACCEL->setText(QCoreApplication::translate("MainWindow", "Full Scale Range", nullptr));
        comboBox_FullScaleRange_ACCEL->setItemText(0, QCoreApplication::translate("MainWindow", "\302\261 2g", nullptr));
        comboBox_FullScaleRange_ACCEL->setItemText(1, QCoreApplication::translate("MainWindow", "\302\261 4g", nullptr));
        comboBox_FullScaleRange_ACCEL->setItemText(2, QCoreApplication::translate("MainWindow", "\302\261 8g", nullptr));
        comboBox_FullScaleRange_ACCEL->setItemText(3, QCoreApplication::translate("MainWindow", "\302\261 16g", nullptr));

        groupBox_FIFO_EN->setTitle(QCoreApplication::translate("MainWindow", "FIFO EN", nullptr));
        checkBox_TEMP_FIFO_EN->setText(QCoreApplication::translate("MainWindow", "TEMP FIFO EN", nullptr));
        checkBox_XG_FIFO_EN->setText(QCoreApplication::translate("MainWindow", "XG FIFO EN", nullptr));
        checkBox_YG_FIFO_EN->setText(QCoreApplication::translate("MainWindow", "YG FIFO EN", nullptr));
        checkBox_ZG_FIFO_EN->setText(QCoreApplication::translate("MainWindow", "ZG FIFO EN", nullptr));
        checkBox_ACCEL_FIFO_EN->setText(QCoreApplication::translate("MainWindow", "ACCEL FIFO EN", nullptr));
        checkBox_SLV2_FIFO_EN->setText(QCoreApplication::translate("MainWindow", "SLV2 FIFO EN", nullptr));
        checkBox_SLV1_FIFO_EN->setText(QCoreApplication::translate("MainWindow", "SLV1 FIFO EN", nullptr));
        checkBox_SLV0_FIFO_EN->setText(QCoreApplication::translate("MainWindow", "SLV0 FIFO EN", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "INT Pin Config", nullptr));
        label_INT_LEVEL->setText(QCoreApplication::translate("MainWindow", "INT LEVEL", nullptr));
        comboBox_INT_LEVEL->setItemText(0, QCoreApplication::translate("MainWindow", "INT Pin active high", nullptr));
        comboBox_INT_LEVEL->setItemText(1, QCoreApplication::translate("MainWindow", "INT Pin active low", nullptr));

        label_INT_OPEN->setText(QCoreApplication::translate("MainWindow", "INT OPEN", nullptr));
        comboBox_INT_OPEN->setItemText(0, QCoreApplication::translate("MainWindow", "INT push-pull", nullptr));
        comboBox_INT_OPEN->setItemText(1, QCoreApplication::translate("MainWindow", "INT open drain", nullptr));

        label_LATCH_INT_EN->setText(QCoreApplication::translate("MainWindow", "LATCH INT EN", nullptr));
        comboBox_LATCH_INT_EN->setItemText(0, QCoreApplication::translate("MainWindow", "INT Pin emits 50us long pulse", nullptr));
        comboBox_LATCH_INT_EN->setItemText(1, QCoreApplication::translate("MainWindow", "INT Pin held high until the interrupt is cleared", nullptr));

        pushButton_REG_READ_ALL_BMP180->setText(QCoreApplication::translate("MainWindow", "Read All", nullptr));
        pushButton_REG_READ_ALL_GY271->setText(QCoreApplication::translate("MainWindow", "Read All", nullptr));
        tabWidget_PanelMain->setTabText(tabWidget_PanelMain->indexOf(tab4_SensorRegistersSetting), QCoreApplication::translate("MainWindow", "Sensor Reg Setting", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
