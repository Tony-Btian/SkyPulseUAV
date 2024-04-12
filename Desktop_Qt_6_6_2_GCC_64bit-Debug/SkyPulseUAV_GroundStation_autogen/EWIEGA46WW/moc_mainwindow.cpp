/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../SkyPulseUAV_GroundStation/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "sig_StartTCPServer",
    "",
    "ip_address",
    "port",
    "sig_StartUDPServer",
    "sig_StopTCPServer",
    "sig_StopUDPServer",
    "sig_Mahony_PlottingStart",
    "sig_Mahony_PlottingStop",
    "sig_sendRequestToFCS",
    "uint8_t",
    "code",
    "sig_sendPWMControlToTCP",
    "pin",
    "value",
    "onTCPStartSuccessful",
    "onTCPStopSuccessful",
    "onTCPConnectionError",
    "onUDPServerStartSuccessful",
    "onUDPServerStopSuccessful",
    "updateUI",
    "message",
    "on_pushButton_Network_Connect_clicked",
    "on_pushButton_Network_Disconnect_clicked",
    "on_pushButton_TAKE_OFF_clicked",
    "on_pushButton_Mahony_Plot_Launch_clicked",
    "on_pushButton_Mahony_Plot_Stop_clicked",
    "on_toolButton_MPU6050_REG_CONFIG_clicked",
    "on_toolButton_BMP180_REG_CONFIG_clicked",
    "on_toolButton_GY271_REG_CONFIG_clicked",
    "on_pushButton_REG_READ_ALL_MPU6050_clicked",
    "on_pushButton_REG_READ_ALL_BMP180_clicked",
    "on_pushButton_REG_READ_ALL_GY271_clicked",
    "on_horizontalSlider_P12PWM0_valueChanged",
    "duty_cycle",
    "on_horizontalSlider_P13PWM1_valueChanged",
    "on_horizontalSlider_P19PWM2_valueChanged",
    "on_horizontalSlider_P18PWM3_valueChanged",
    "on_spinBox_MinThrottle_valueChanged",
    "arg1"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[82];
    char stringdata0[11];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[11];
    char stringdata4[5];
    char stringdata5[19];
    char stringdata6[18];
    char stringdata7[18];
    char stringdata8[25];
    char stringdata9[24];
    char stringdata10[21];
    char stringdata11[8];
    char stringdata12[5];
    char stringdata13[24];
    char stringdata14[4];
    char stringdata15[6];
    char stringdata16[21];
    char stringdata17[20];
    char stringdata18[21];
    char stringdata19[27];
    char stringdata20[26];
    char stringdata21[9];
    char stringdata22[8];
    char stringdata23[38];
    char stringdata24[41];
    char stringdata25[31];
    char stringdata26[41];
    char stringdata27[39];
    char stringdata28[41];
    char stringdata29[40];
    char stringdata30[39];
    char stringdata31[43];
    char stringdata32[42];
    char stringdata33[41];
    char stringdata34[41];
    char stringdata35[11];
    char stringdata36[41];
    char stringdata37[41];
    char stringdata38[41];
    char stringdata39[36];
    char stringdata40[5];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 18),  // "sig_StartTCPServer"
        QT_MOC_LITERAL(30, 0),  // ""
        QT_MOC_LITERAL(31, 10),  // "ip_address"
        QT_MOC_LITERAL(42, 4),  // "port"
        QT_MOC_LITERAL(47, 18),  // "sig_StartUDPServer"
        QT_MOC_LITERAL(66, 17),  // "sig_StopTCPServer"
        QT_MOC_LITERAL(84, 17),  // "sig_StopUDPServer"
        QT_MOC_LITERAL(102, 24),  // "sig_Mahony_PlottingStart"
        QT_MOC_LITERAL(127, 23),  // "sig_Mahony_PlottingStop"
        QT_MOC_LITERAL(151, 20),  // "sig_sendRequestToFCS"
        QT_MOC_LITERAL(172, 7),  // "uint8_t"
        QT_MOC_LITERAL(180, 4),  // "code"
        QT_MOC_LITERAL(185, 23),  // "sig_sendPWMControlToTCP"
        QT_MOC_LITERAL(209, 3),  // "pin"
        QT_MOC_LITERAL(213, 5),  // "value"
        QT_MOC_LITERAL(219, 20),  // "onTCPStartSuccessful"
        QT_MOC_LITERAL(240, 19),  // "onTCPStopSuccessful"
        QT_MOC_LITERAL(260, 20),  // "onTCPConnectionError"
        QT_MOC_LITERAL(281, 26),  // "onUDPServerStartSuccessful"
        QT_MOC_LITERAL(308, 25),  // "onUDPServerStopSuccessful"
        QT_MOC_LITERAL(334, 8),  // "updateUI"
        QT_MOC_LITERAL(343, 7),  // "message"
        QT_MOC_LITERAL(351, 37),  // "on_pushButton_Network_Connect..."
        QT_MOC_LITERAL(389, 40),  // "on_pushButton_Network_Disconn..."
        QT_MOC_LITERAL(430, 30),  // "on_pushButton_TAKE_OFF_clicked"
        QT_MOC_LITERAL(461, 40),  // "on_pushButton_Mahony_Plot_Lau..."
        QT_MOC_LITERAL(502, 38),  // "on_pushButton_Mahony_Plot_Sto..."
        QT_MOC_LITERAL(541, 40),  // "on_toolButton_MPU6050_REG_CON..."
        QT_MOC_LITERAL(582, 39),  // "on_toolButton_BMP180_REG_CONF..."
        QT_MOC_LITERAL(622, 38),  // "on_toolButton_GY271_REG_CONFI..."
        QT_MOC_LITERAL(661, 42),  // "on_pushButton_REG_READ_ALL_MP..."
        QT_MOC_LITERAL(704, 41),  // "on_pushButton_REG_READ_ALL_BM..."
        QT_MOC_LITERAL(746, 40),  // "on_pushButton_REG_READ_ALL_GY..."
        QT_MOC_LITERAL(787, 40),  // "on_horizontalSlider_P12PWM0_v..."
        QT_MOC_LITERAL(828, 10),  // "duty_cycle"
        QT_MOC_LITERAL(839, 40),  // "on_horizontalSlider_P13PWM1_v..."
        QT_MOC_LITERAL(880, 40),  // "on_horizontalSlider_P19PWM2_v..."
        QT_MOC_LITERAL(921, 40),  // "on_horizontalSlider_P18PWM3_v..."
        QT_MOC_LITERAL(962, 35),  // "on_spinBox_MinThrottle_valueC..."
        QT_MOC_LITERAL(998, 4)   // "arg1"
    },
    "MainWindow",
    "sig_StartTCPServer",
    "",
    "ip_address",
    "port",
    "sig_StartUDPServer",
    "sig_StopTCPServer",
    "sig_StopUDPServer",
    "sig_Mahony_PlottingStart",
    "sig_Mahony_PlottingStop",
    "sig_sendRequestToFCS",
    "uint8_t",
    "code",
    "sig_sendPWMControlToTCP",
    "pin",
    "value",
    "onTCPStartSuccessful",
    "onTCPStopSuccessful",
    "onTCPConnectionError",
    "onUDPServerStartSuccessful",
    "onUDPServerStopSuccessful",
    "updateUI",
    "message",
    "on_pushButton_Network_Connect_clicked",
    "on_pushButton_Network_Disconnect_clicked",
    "on_pushButton_TAKE_OFF_clicked",
    "on_pushButton_Mahony_Plot_Launch_clicked",
    "on_pushButton_Mahony_Plot_Stop_clicked",
    "on_toolButton_MPU6050_REG_CONFIG_clicked",
    "on_toolButton_BMP180_REG_CONFIG_clicked",
    "on_toolButton_GY271_REG_CONFIG_clicked",
    "on_pushButton_REG_READ_ALL_MPU6050_clicked",
    "on_pushButton_REG_READ_ALL_BMP180_clicked",
    "on_pushButton_REG_READ_ALL_GY271_clicked",
    "on_horizontalSlider_P12PWM0_valueChanged",
    "duty_cycle",
    "on_horizontalSlider_P13PWM1_valueChanged",
    "on_horizontalSlider_P19PWM2_valueChanged",
    "on_horizontalSlider_P18PWM3_valueChanged",
    "on_spinBox_MinThrottle_valueChanged",
    "arg1"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      30,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,  194,    2, 0x06,    1 /* Public */,
       5,    1,  199,    2, 0x06,    4 /* Public */,
       6,    0,  202,    2, 0x06,    6 /* Public */,
       7,    0,  203,    2, 0x06,    7 /* Public */,
       8,    0,  204,    2, 0x06,    8 /* Public */,
       9,    0,  205,    2, 0x06,    9 /* Public */,
      10,    1,  206,    2, 0x06,   10 /* Public */,
      13,    3,  209,    2, 0x06,   12 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      16,    0,  216,    2, 0x0a,   16 /* Public */,
      17,    0,  217,    2, 0x0a,   17 /* Public */,
      18,    0,  218,    2, 0x0a,   18 /* Public */,
      19,    0,  219,    2, 0x0a,   19 /* Public */,
      20,    0,  220,    2, 0x0a,   20 /* Public */,
      21,    1,  221,    2, 0x0a,   21 /* Public */,
      23,    0,  224,    2, 0x08,   23 /* Private */,
      24,    0,  225,    2, 0x08,   24 /* Private */,
      25,    0,  226,    2, 0x08,   25 /* Private */,
      26,    0,  227,    2, 0x08,   26 /* Private */,
      27,    0,  228,    2, 0x08,   27 /* Private */,
      28,    0,  229,    2, 0x08,   28 /* Private */,
      29,    0,  230,    2, 0x08,   29 /* Private */,
      30,    0,  231,    2, 0x08,   30 /* Private */,
      31,    0,  232,    2, 0x08,   31 /* Private */,
      32,    0,  233,    2, 0x08,   32 /* Private */,
      33,    0,  234,    2, 0x08,   33 /* Private */,
      34,    1,  235,    2, 0x08,   34 /* Private */,
      36,    1,  238,    2, 0x08,   36 /* Private */,
      37,    1,  241,    2, 0x08,   38 /* Private */,
      38,    1,  244,    2, 0x08,   40 /* Private */,
      39,    1,  247,    2, 0x08,   42 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::UShort,    3,    4,
    QMetaType::Void, QMetaType::UShort,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   12,   14,   15,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   35,
    QMetaType::Void, QMetaType::Int,   35,
    QMetaType::Void, QMetaType::Int,   35,
    QMetaType::Void, QMetaType::Int,   35,
    QMetaType::Void, QMetaType::Int,   40,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'sig_StartTCPServer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const quint16 &, std::false_type>,
        // method 'sig_StartUDPServer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const quint16 &, std::false_type>,
        // method 'sig_StopTCPServer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sig_StopUDPServer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sig_Mahony_PlottingStart'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sig_Mahony_PlottingStop'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sig_sendRequestToFCS'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const uint8_t &, std::false_type>,
        // method 'sig_sendPWMControlToTCP'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'onTCPStartSuccessful'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onTCPStopSuccessful'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onTCPConnectionError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onUDPServerStartSuccessful'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onUDPServerStopSuccessful'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updateUI'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_pushButton_Network_Connect_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_Network_Disconnect_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_TAKE_OFF_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_Mahony_Plot_Launch_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_Mahony_Plot_Stop_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_toolButton_MPU6050_REG_CONFIG_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_toolButton_BMP180_REG_CONFIG_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_toolButton_GY271_REG_CONFIG_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_REG_READ_ALL_MPU6050_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_REG_READ_ALL_BMP180_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_REG_READ_ALL_GY271_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_horizontalSlider_P12PWM0_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_horizontalSlider_P13PWM1_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_horizontalSlider_P19PWM2_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_horizontalSlider_P18PWM3_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_spinBox_MinThrottle_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sig_StartTCPServer((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<quint16>>(_a[2]))); break;
        case 1: _t->sig_StartUDPServer((*reinterpret_cast< std::add_pointer_t<quint16>>(_a[1]))); break;
        case 2: _t->sig_StopTCPServer(); break;
        case 3: _t->sig_StopUDPServer(); break;
        case 4: _t->sig_Mahony_PlottingStart(); break;
        case 5: _t->sig_Mahony_PlottingStop(); break;
        case 6: _t->sig_sendRequestToFCS((*reinterpret_cast< std::add_pointer_t<uint8_t>>(_a[1]))); break;
        case 7: _t->sig_sendPWMControlToTCP((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 8: _t->onTCPStartSuccessful(); break;
        case 9: _t->onTCPStopSuccessful(); break;
        case 10: _t->onTCPConnectionError(); break;
        case 11: _t->onUDPServerStartSuccessful(); break;
        case 12: _t->onUDPServerStopSuccessful(); break;
        case 13: _t->updateUI((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 14: _t->on_pushButton_Network_Connect_clicked(); break;
        case 15: _t->on_pushButton_Network_Disconnect_clicked(); break;
        case 16: _t->on_pushButton_TAKE_OFF_clicked(); break;
        case 17: _t->on_pushButton_Mahony_Plot_Launch_clicked(); break;
        case 18: _t->on_pushButton_Mahony_Plot_Stop_clicked(); break;
        case 19: _t->on_toolButton_MPU6050_REG_CONFIG_clicked(); break;
        case 20: _t->on_toolButton_BMP180_REG_CONFIG_clicked(); break;
        case 21: _t->on_toolButton_GY271_REG_CONFIG_clicked(); break;
        case 22: _t->on_pushButton_REG_READ_ALL_MPU6050_clicked(); break;
        case 23: _t->on_pushButton_REG_READ_ALL_BMP180_clicked(); break;
        case 24: _t->on_pushButton_REG_READ_ALL_GY271_clicked(); break;
        case 25: _t->on_horizontalSlider_P12PWM0_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 26: _t->on_horizontalSlider_P13PWM1_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 27: _t->on_horizontalSlider_P19PWM2_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 28: _t->on_horizontalSlider_P18PWM3_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 29: _t->on_spinBox_MinThrottle_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(const QString & , const quint16 & );
            if (_t _q_method = &MainWindow::sig_StartTCPServer; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const quint16 & );
            if (_t _q_method = &MainWindow::sig_StartUDPServer; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::sig_StopTCPServer; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::sig_StopUDPServer; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::sig_Mahony_PlottingStart; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::sig_Mahony_PlottingStop; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const uint8_t & );
            if (_t _q_method = &MainWindow::sig_sendRequestToFCS; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const int & , const int & , const int & );
            if (_t _q_method = &MainWindow::sig_sendPWMControlToTCP; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 30)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 30;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::sig_StartTCPServer(const QString & _t1, const quint16 & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::sig_StartUDPServer(const quint16 & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::sig_StopTCPServer()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindow::sig_StopUDPServer()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MainWindow::sig_Mahony_PlottingStart()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MainWindow::sig_Mahony_PlottingStop()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void MainWindow::sig_sendRequestToFCS(const uint8_t & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MainWindow::sig_sendPWMControlToTCP(const int & _t1, const int & _t2, const int & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
