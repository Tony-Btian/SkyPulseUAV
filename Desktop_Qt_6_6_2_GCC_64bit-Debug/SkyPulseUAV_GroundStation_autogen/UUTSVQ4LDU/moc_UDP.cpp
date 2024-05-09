/****************************************************************************
** Meta object code from reading C++ file 'UDP.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../SkyPulseUAV_GroundStation/COMM/UDP.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UDP.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSUDPENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSUDPENDCLASS = QtMocHelpers::stringData(
    "UDP",
    "messageReceived",
    "",
    "message",
    "ServerStartSucessful",
    "ServerStopSucessful",
    "startUDPServer",
    "port",
    "stopUDPServer",
    "udpInitial",
    "readPendingDatagrams"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSUDPENDCLASS_t {
    uint offsetsAndSizes[22];
    char stringdata0[4];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[21];
    char stringdata5[20];
    char stringdata6[15];
    char stringdata7[5];
    char stringdata8[14];
    char stringdata9[11];
    char stringdata10[21];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSUDPENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSUDPENDCLASS_t qt_meta_stringdata_CLASSUDPENDCLASS = {
    {
        QT_MOC_LITERAL(0, 3),  // "UDP"
        QT_MOC_LITERAL(4, 15),  // "messageReceived"
        QT_MOC_LITERAL(20, 0),  // ""
        QT_MOC_LITERAL(21, 7),  // "message"
        QT_MOC_LITERAL(29, 20),  // "ServerStartSucessful"
        QT_MOC_LITERAL(50, 19),  // "ServerStopSucessful"
        QT_MOC_LITERAL(70, 14),  // "startUDPServer"
        QT_MOC_LITERAL(85, 4),  // "port"
        QT_MOC_LITERAL(90, 13),  // "stopUDPServer"
        QT_MOC_LITERAL(104, 10),  // "udpInitial"
        QT_MOC_LITERAL(115, 20)   // "readPendingDatagrams"
    },
    "UDP",
    "messageReceived",
    "",
    "message",
    "ServerStartSucessful",
    "ServerStopSucessful",
    "startUDPServer",
    "port",
    "stopUDPServer",
    "udpInitial",
    "readPendingDatagrams"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSUDPENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   56,    2, 0x06,    1 /* Public */,
       4,    0,   59,    2, 0x06,    3 /* Public */,
       5,    0,   60,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    1,   61,    2, 0x0a,    5 /* Public */,
       8,    0,   64,    2, 0x0a,    7 /* Public */,
       9,    0,   65,    2, 0x08,    8 /* Private */,
      10,    0,   66,    2, 0x08,    9 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::UShort,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject UDP::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSUDPENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSUDPENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSUDPENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<UDP, std::true_type>,
        // method 'messageReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'ServerStartSucessful'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'ServerStopSucessful'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'startUDPServer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<quint16, std::false_type>,
        // method 'stopUDPServer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'udpInitial'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'readPendingDatagrams'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void UDP::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UDP *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->messageReceived((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->ServerStartSucessful(); break;
        case 2: _t->ServerStopSucessful(); break;
        case 3: _t->startUDPServer((*reinterpret_cast< std::add_pointer_t<quint16>>(_a[1]))); break;
        case 4: _t->stopUDPServer(); break;
        case 5: _t->udpInitial(); break;
        case 6: _t->readPendingDatagrams(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UDP::*)(const QString & );
            if (_t _q_method = &UDP::messageReceived; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (UDP::*)();
            if (_t _q_method = &UDP::ServerStartSucessful; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (UDP::*)();
            if (_t _q_method = &UDP::ServerStopSucessful; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *UDP::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UDP::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSUDPENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int UDP::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void UDP::messageReceived(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void UDP::ServerStartSucessful()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void UDP::ServerStopSucessful()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
