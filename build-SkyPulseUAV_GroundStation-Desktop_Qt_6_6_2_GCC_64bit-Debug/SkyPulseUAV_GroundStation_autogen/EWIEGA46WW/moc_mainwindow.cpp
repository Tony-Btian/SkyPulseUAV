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
    "sig_StartUDPServer",
    "",
    "port",
    "sig_StopUDPServer",
    "displayReceivedMessage",
    "message",
    "on_pushButton_Network_Connect_clicked",
    "on_pushButton_Network_Disconnect_clicked",
    "onTCPConnectionSuccessful",
    "onTCPDisconnectionSuccessful",
    "onTCPConnectionError",
    "onUDPServerStartSuccessful",
    "onUDPServerStopSuccessful"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[28];
    char stringdata0[11];
    char stringdata1[19];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[18];
    char stringdata5[23];
    char stringdata6[8];
    char stringdata7[38];
    char stringdata8[41];
    char stringdata9[26];
    char stringdata10[29];
    char stringdata11[21];
    char stringdata12[27];
    char stringdata13[26];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 18),  // "sig_StartUDPServer"
        QT_MOC_LITERAL(30, 0),  // ""
        QT_MOC_LITERAL(31, 4),  // "port"
        QT_MOC_LITERAL(36, 17),  // "sig_StopUDPServer"
        QT_MOC_LITERAL(54, 22),  // "displayReceivedMessage"
        QT_MOC_LITERAL(77, 7),  // "message"
        QT_MOC_LITERAL(85, 37),  // "on_pushButton_Network_Connect..."
        QT_MOC_LITERAL(123, 40),  // "on_pushButton_Network_Disconn..."
        QT_MOC_LITERAL(164, 25),  // "onTCPConnectionSuccessful"
        QT_MOC_LITERAL(190, 28),  // "onTCPDisconnectionSuccessful"
        QT_MOC_LITERAL(219, 20),  // "onTCPConnectionError"
        QT_MOC_LITERAL(240, 26),  // "onUDPServerStartSuccessful"
        QT_MOC_LITERAL(267, 25)   // "onUDPServerStopSuccessful"
    },
    "MainWindow",
    "sig_StartUDPServer",
    "",
    "port",
    "sig_StopUDPServer",
    "displayReceivedMessage",
    "message",
    "on_pushButton_Network_Connect_clicked",
    "on_pushButton_Network_Disconnect_clicked",
    "onTCPConnectionSuccessful",
    "onTCPDisconnectionSuccessful",
    "onTCPConnectionError",
    "onUDPServerStartSuccessful",
    "onUDPServerStopSuccessful"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   74,    2, 0x06,    1 /* Public */,
       4,    0,   77,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,   78,    2, 0x0a,    4 /* Public */,
       7,    0,   81,    2, 0x08,    6 /* Private */,
       8,    0,   82,    2, 0x08,    7 /* Private */,
       9,    0,   83,    2, 0x08,    8 /* Private */,
      10,    0,   84,    2, 0x08,    9 /* Private */,
      11,    0,   85,    2, 0x08,   10 /* Private */,
      12,    0,   86,    2, 0x08,   11 /* Private */,
      13,    0,   87,    2, 0x08,   12 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UShort,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

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
        // method 'sig_StartUDPServer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const quint16 &, std::false_type>,
        // method 'sig_StopUDPServer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'displayReceivedMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_pushButton_Network_Connect_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_Network_Disconnect_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onTCPConnectionSuccessful'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onTCPDisconnectionSuccessful'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onTCPConnectionError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onUDPServerStartSuccessful'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onUDPServerStopSuccessful'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sig_StartUDPServer((*reinterpret_cast< std::add_pointer_t<quint16>>(_a[1]))); break;
        case 1: _t->sig_StopUDPServer(); break;
        case 2: _t->displayReceivedMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->on_pushButton_Network_Connect_clicked(); break;
        case 4: _t->on_pushButton_Network_Disconnect_clicked(); break;
        case 5: _t->onTCPConnectionSuccessful(); break;
        case 6: _t->onTCPDisconnectionSuccessful(); break;
        case 7: _t->onTCPConnectionError(); break;
        case 8: _t->onUDPServerStartSuccessful(); break;
        case 9: _t->onUDPServerStopSuccessful(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(const quint16 & );
            if (_t _q_method = &MainWindow::sig_StartUDPServer; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::sig_StopUDPServer; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
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
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::sig_StartUDPServer(const quint16 & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::sig_StopUDPServer()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
