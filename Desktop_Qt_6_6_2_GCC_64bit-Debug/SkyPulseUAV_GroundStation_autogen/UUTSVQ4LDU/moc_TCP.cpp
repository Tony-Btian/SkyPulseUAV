/****************************************************************************
** Meta object code from reading C++ file 'TCP.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../SkyPulseUAV_GroundStation/COMM/TCP.h"
#include <QtCore/qmetatype.h>

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
    "sendMessage",
    "message",
    "sendMessageQByte",
    "readMessage",
    "PWM_Controler",
    "code",
    "pin",
    "value",
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
    uint offsetsAndSizes[40];
    char stringdata0[4];
    char stringdata1[20];
    char stringdata2[1];
    char stringdata3[19];
    char stringdata4[20];
    char stringdata5[12];
    char stringdata6[8];
    char stringdata7[17];
    char stringdata8[12];
    char stringdata9[14];
    char stringdata10[5];
    char stringdata11[4];
    char stringdata12[6];
    char stringdata13[13];
    char stringdata14[8];
    char stringdata15[13];
    char stringdata16[11];
    char stringdata17[12];
    char stringdata18[15];
    char stringdata19[16];
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
        QT_MOC_LITERAL(64, 11),  // "sendMessage"
        QT_MOC_LITERAL(76, 7),  // "message"
        QT_MOC_LITERAL(84, 16),  // "sendMessageQByte"
        QT_MOC_LITERAL(101, 11),  // "readMessage"
        QT_MOC_LITERAL(113, 13),  // "PWM_Controler"
        QT_MOC_LITERAL(127, 4),  // "code"
        QT_MOC_LITERAL(132, 3),  // "pin"
        QT_MOC_LITERAL(136, 5),  // "value"
        QT_MOC_LITERAL(142, 12),  // "commendToFCS"
        QT_MOC_LITERAL(155, 7),  // "uint8_t"
        QT_MOC_LITERAL(163, 12),  // "command_code"
        QT_MOC_LITERAL(176, 10),  // "tcpInitial"
        QT_MOC_LITERAL(187, 11),  // "onConnected"
        QT_MOC_LITERAL(199, 14),  // "onDisconnected"
        QT_MOC_LITERAL(214, 15)   // "onErrorOccurred"
    },
    "TCP",
    "sig_startSuccessful",
    "",
    "sig_stopSuccessful",
    "sig_connectionError",
    "sendMessage",
    "message",
    "sendMessageQByte",
    "readMessage",
    "PWM_Controler",
    "code",
    "pin",
    "value",
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
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x06,    1 /* Public */,
       3,    0,   87,    2, 0x06,    2 /* Public */,
       4,    0,   88,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,   89,    2, 0x0a,    4 /* Public */,
       7,    1,   92,    2, 0x0a,    6 /* Public */,
       8,    0,   95,    2, 0x0a,    8 /* Public */,
       9,    3,   96,    2, 0x0a,    9 /* Public */,
      13,    1,  103,    2, 0x0a,   13 /* Public */,
      16,    0,  106,    2, 0x08,   15 /* Private */,
      17,    0,  107,    2, 0x08,   16 /* Private */,
      18,    0,  108,    2, 0x08,   17 /* Private */,
      19,    0,  109,    2, 0x08,   18 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QByteArray,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   10,   11,   12,
    QMetaType::Void, 0x80000000 | 14,   15,
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
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
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
        case 3: _t->sendMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->sendMessageQByte((*reinterpret_cast< std::add_pointer_t<QByteArray>>(_a[1]))); break;
        case 5: _t->readMessage(); break;
        case 6: _t->PWM_Controler((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 7: _t->commendToFCS((*reinterpret_cast< std::add_pointer_t<uint8_t>>(_a[1]))); break;
        case 8: _t->tcpInitial(); break;
        case 9: _t->onConnected(); break;
        case 10: _t->onDisconnected(); break;
        case 11: _t->onErrorOccurred(); break;
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
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
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
QT_WARNING_POP
