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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget_PanelMain;
    QWidget *tab1_FlightControl;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_AnimationDisplay;
    QWidget *widget;
    QGridLayout *gridLayout_4;
    QWidget *widget_2;
    QGridLayout *gridLayout_5;
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
    QGroupBox *groupBox_Connection;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_Network_IPAddr;
    QLineEdit *lineEdit_Network_IPAddr;
    QPushButton *pushButton_Network_Connect;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_Network_Port;
    QLineEdit *lineEdit_Network_Port;
    QPushButton *pushButton_Network_Disconnect;
    QTextBrowser *textBrowser_test;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(928, 634);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        tabWidget_PanelMain = new QTabWidget(centralwidget);
        tabWidget_PanelMain->setObjectName("tabWidget_PanelMain");
        tabWidget_PanelMain->setTabPosition(QTabWidget::West);
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

        horizontalLayout->addWidget(groupBox_GPS);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);

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

        verticalLayout_4->setStretch(1, 1);

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

        groupBox_Connection = new QGroupBox(tab2_ParameterSetting);
        groupBox_Connection->setObjectName("groupBox_Connection");
        gridLayout_3 = new QGridLayout(groupBox_Connection);
        gridLayout_3->setObjectName("gridLayout_3");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_Network_IPAddr = new QLabel(groupBox_Connection);
        label_Network_IPAddr->setObjectName("label_Network_IPAddr");

        horizontalLayout_3->addWidget(label_Network_IPAddr);

        lineEdit_Network_IPAddr = new QLineEdit(groupBox_Connection);
        lineEdit_Network_IPAddr->setObjectName("lineEdit_Network_IPAddr");

        horizontalLayout_3->addWidget(lineEdit_Network_IPAddr);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 2);

        gridLayout_3->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        pushButton_Network_Connect = new QPushButton(groupBox_Connection);
        pushButton_Network_Connect->setObjectName("pushButton_Network_Connect");

        gridLayout_3->addWidget(pushButton_Network_Connect, 0, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_Network_Port = new QLabel(groupBox_Connection);
        label_Network_Port->setObjectName("label_Network_Port");

        horizontalLayout_4->addWidget(label_Network_Port);

        lineEdit_Network_Port = new QLineEdit(groupBox_Connection);
        lineEdit_Network_Port->setObjectName("lineEdit_Network_Port");

        horizontalLayout_4->addWidget(lineEdit_Network_Port);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 2);

        gridLayout_3->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        pushButton_Network_Disconnect = new QPushButton(groupBox_Connection);
        pushButton_Network_Disconnect->setObjectName("pushButton_Network_Disconnect");
        pushButton_Network_Disconnect->setEnabled(false);

        gridLayout_3->addWidget(pushButton_Network_Disconnect, 1, 1, 1, 1);

        textBrowser_test = new QTextBrowser(groupBox_Connection);
        textBrowser_test->setObjectName("textBrowser_test");

        gridLayout_3->addWidget(textBrowser_test, 2, 0, 1, 2);


        horizontalLayout_5->addWidget(groupBox_Connection);

        tabWidget_PanelMain->addTab(tab2_ParameterSetting, QString());

        gridLayout->addWidget(tabWidget_PanelMain, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 928, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget_PanelMain->setCurrentIndex(1);
        tabWidget_FlightControlInfo->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
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
        groupBox_GPS->setTitle(QCoreApplication::translate("MainWindow", "GPS", nullptr));
        tabWidget_PanelMain->setTabText(tabWidget_PanelMain->indexOf(tab1_FlightControl), QCoreApplication::translate("MainWindow", "Flight Control", nullptr));
        toolButton_Calib_Gyto->setText(QCoreApplication::translate("MainWindow", "\351\231\200\350\236\272\344\273\252\346\240\241\345\207\206", nullptr));
        toolButton_Calib_Accelerate->setText(QCoreApplication::translate("MainWindow", "\345\212\240\351\200\237\345\272\246\346\240\241\345\207\206", nullptr));
        toolButton_Calib_Compass->setText(QCoreApplication::translate("MainWindow", "\347\243\201\347\275\227\347\233\230\346\240\241\345\207\206", nullptr));
        toolButton_Calib_AirPressure->setText(QCoreApplication::translate("MainWindow", "\346\260\224\345\216\213\350\256\241\346\240\241\345\207\206", nullptr));
        toolButton_Calib_SixDirection->setText(QCoreApplication::translate("MainWindow", "360\345\272\246\346\240\241\345\207\206", nullptr));
        groupBox_Mahony_Adjuster->setTitle(QCoreApplication::translate("MainWindow", "Mahony \350\260\203\346\225\264\345\231\250", nullptr));
        label_Mahony_Parameter->setText(QCoreApplication::translate("MainWindow", "\346\216\247\345\210\266\345\217\202\346\225\260", nullptr));
        pushButton_Mahony_Parameter_Write->setText(QCoreApplication::translate("MainWindow", "Write", nullptr));
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
        groupBox_Connection->setTitle(QCoreApplication::translate("MainWindow", "Connection", nullptr));
        label_Network_IPAddr->setText(QCoreApplication::translate("MainWindow", "IP", nullptr));
        lineEdit_Network_IPAddr->setText(QCoreApplication::translate("MainWindow", "192.168.31.213", nullptr));
        pushButton_Network_Connect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        label_Network_Port->setText(QCoreApplication::translate("MainWindow", "\347\253\257\345\217\243", nullptr));
        lineEdit_Network_Port->setText(QCoreApplication::translate("MainWindow", "12345", nullptr));
        pushButton_Network_Disconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        tabWidget_PanelMain->setTabText(tabWidget_PanelMain->indexOf(tab2_ParameterSetting), QCoreApplication::translate("MainWindow", "Parameter Setting", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
