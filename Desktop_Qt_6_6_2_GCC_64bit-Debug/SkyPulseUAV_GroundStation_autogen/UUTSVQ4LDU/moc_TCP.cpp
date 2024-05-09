/****************************************************************************
** Meta object code from reading C++ file 'TCP.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../SkyPulseUAV_GroundStation/COMM/TCP.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'TCP.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSTCPENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSTCPENDCLASS = QtMocHelpers::stringData(
    "TCP",
    "sig_startSuccessful",
    "",
    "sig_stopSuccessful",
    "sig_connectionError",
    "sig_UIupdate",
    "datalist",
    "sendMessage",
    "message",
    "sendMessageQByte",
    "readMessage",
    "PWM_Controler",
    "QList<uint8_t>",
    "pwm_value",
    "Flight_Controler",
    "control_data",
    "Flight_Config_Setting",
    "config_data",
    "commendToFCS",
    "uint8_t",
    "command_code",
    "tcpInitial",
    "onConnected",
    "onDisconnected",
    "onErrorOccurred"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSTCPENDCLASS_t {
    uint offsetsAndSizes[50];
    char stringdata0[4];
    char stringdata1[20];
    char stringdata2[1];
    char stringdata3[19];
    char stringdata4[20];
    char stringdata5[13];
    char stringdata6[9];
    char stringdata7[12];
    char stringdata8[8];
    char stringdata9[17];
    char stringdata10[12];
    char stringdata11[14];
    char stringdata12[15];
    char stringdata13[10];
    char stringdata14[17];
    char stringdata15[13];
    char stringdata16[22];
    char stringdata17[12];
    char stringdata18[13];
    char stringdata19[8];
    char stringdata20[13];
    char stringdata21[11];
    char stringdata22[12];
    char stringdata23[15];
    char stringdata24[16];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSTCPENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSTCPENDCLASS_t qt_meta_stringdata_CLASSTCPENDCLASS = {
    {
        QT_MOC_LITERAL(0, 3),  // "TCP"
        QT_MOC_LITERAL(4, 19),  // "sig_startSuccessful"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 18),  // "sig_stopSuccessful"
        QT_MOC_LITERAL(44, 19),  // "sig_connectionError"
        QT_MOC_LITERAL(64, 12),  // "sig_UIupdate"
        QT_MOC_LITERAL(77, 8),  // "datalist"
        QT_MOC_LITERAL(86, 11),  // "sendMessage"
        QT_MOC_LITERAL(98, 7),  // "message"
        QT_MOC_LITERAL(106, 16),  // "sendMessageQByte"
        QT_MOC_LITERAL(123, 11),  // "readMessage"
        QT_MOC_LITERAL(135, 13),  // "PWM_Controler"
        QT_MOC_LITERAL(149, 14),  // "QList<uint8_t>"
        QT_MOC_LITERAL(164, 9),  // "pwm_value"
        QT_MOC_LITERAL(174, 16),  // "Flight_Controler"
        QT_MOC_LITERAL(191, 12),  // "control_data"
        QT_MOC_LITERAL(204, 21),  // "Flight_Config_Setting"
        QT_MOC_LITERAL(226, 11),  // "config_data"
        QT_MOC_LITERAL(238, 12),  // "commendToFCS"
        QT_MOC_LITERAL(251, 7),  // "uint8_t"
        QT_MOC_LITERAL(259, 12),  // "command_code"
        QT_MOC_LITERAL(272, 10),  // "tcpInitial"
        QT_MOC_LITERAL(283, 11),  // "onConnected"
        QT_MOC_LITERAL(295, 14),  // "onDisconnected"
        QT_MOC_LITERAL(310, 15)   // "onErrorOccurred"
    },
    "TCP",
    "sig_startSuccessful",
    "",
    "sig_stopSuccessful",
    "sig_connectionError",
    "sig_UIupdate",
    "datalist",
    "sendMessage",
    "message",
    "sendMessageQByte",
    "readMessage",
    "PWM_Controler",
    "QList<uint8_t>",
    "pwm_value",
    "Flight_Controler",
    "control_data",
    "Flight_Config_Setting",
    "config_data",
    "commendToFCS",
    "uint8_t",
    "command_code",
    "tcpInitial",
    "onConnected",
    "onDisconnected",
    "onErrorOccurred"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSTCPENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  104,    2, 0x06,    1 /* Public */,
       3,    0,  105,    2, 0x06,    2 /* Public */,
       4,    0,  106,    2, 0x06,    3 /* Public */,
       5,    1,  107,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    1,  110,    2, 0x0a,    6 /* Public */,
       9,    1,  113,    2, 0x0a,    8 /* Public */,
      10,    0,  116,    2, 0x0a,   10 /* Public */,
      11,    1,  117,    2, 0x0a,   11 /* Public */,
      14,    1,  120,    2, 0x0a,   13 /* Public */,
      16,    1,  123,    2, 0x0a,   15 /* Public */,
      18,    1,  126,    2, 0x0a,   17 /* Public */,
      21,    0,  129,    2, 0x08,   19 /* Private */,
      22,    0,  130,    2, 0x08,   20 /* Private */,
      23,    0,  131,    2, 0x08,   21 /* Private */,
      24,    0,  132,    2, 0x08,   22 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QByteArray,    8,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 12,   15,
    QMetaType::Void, 0x80000000 | 12,   17,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject TCP::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSTCPENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSTCPENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSTCPENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<TCP, std::true_type>,
        // method 'sig_startSuccessful'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sig_stopSuccessful'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sig_connectionError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'sig_UIupdate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QStringList, std::false_type>,
        // method 'sendMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'sendMessageQByte'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QByteArray &, std::false_type>,
        // method 'readMessage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'PWM_Controler'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVector<uint8_t> &, std::false_type>,
        // method 'Flight_Controler'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVector<uint8_t> &, std::false_type>,
        // method 'Flight_Config_Setting'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVector<uint8_t> &, std::false_type>,
        // method 'commendToFCS'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const uint8_t &, std::false_type>,
        // method 'tcpInitial'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onConnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDisconnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onErrorOccurred'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void TCP::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TCP *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sig_startSuccessful(); break;
        case 1: _t->sig_stopSuccessful(); break;
        case 2: _t->sig_connectionError(); break;
        case 3: _t->sig_UIupdate((*reinterpret_cast< std::add_pointer_t<QStringList>>(_a[1]))); break;
        case 4: _t->sendMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->sendMessageQByte((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 6: _t->readMessage(); break;
        case 7: _t->PWM_Controler((*reinterpret_cast< std::add_pointer_t<QList<uint8_t>>>(_a[1]))); break;
        case 8: _t->Flight_Controler((*reinterpret_cast< std::add_pointer_t<QList<uint8_t>>>(_a[1]))); break;
        case 9: _t->Flight_Config_Setting((*reinterpret_cast< std::add_pointer_t<QList<uint8_t>>>(_a[1]))); break;
        case 10: _t->commendToFCS((*reinterpret_cast< std::add_pointer_t<uint8_t>>(_a[1]))); break;
        case 11: _t->tcpInitial(); break;
        case 12: _t->onConnected(); break;
        case 13: _t->onDisconnected(); break;
        case 14: _t->onErrorOccurred(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TCP::*)();
            if (_t _q_method = &TCP::sig_startSuccessful; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TCP::*)();
            if (_t _q_method = &TCP::sig_stopSuccessful; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TCP::*)();
            if (_t _q_method = &TCP::sig_connectionError; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TCP::*)(QStringList );
            if (_t _q_method = &TCP::sig_UIupdate; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject *TCP::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TCP::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSTCPENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TCP::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void TCP::sig_startSuccessful()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TCP::sig_stopSuccessful()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void TCP::sig_connectionError()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void TCP::sig_UIupdate(QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
