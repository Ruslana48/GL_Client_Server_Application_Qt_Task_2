/****************************************************************************
** Meta object code from reading C++ file 'client.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../client.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.3. It"
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
struct qt_meta_stringdata_CLASSClientENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSClientENDCLASS = QtMocHelpers::stringData(
    "Client",
    "hostChanged",
    "",
    "portChanged",
    "statusChanged",
    "processListReceived",
    "processList",
    "processClosed",
    "result",
    "errorOccurred",
    "errorString",
    "connectionTimeout",
    "handleConnected",
    "handleReadyRead",
    "handleError",
    "QAbstractSocket::SocketError",
    "socketError",
    "connectToServer",
    "requestProcessList",
    "typeOfProcess",
    "pid",
    "sendSignal",
    "signal",
    "closeProcess",
    "closeConnection",
    "host",
    "port",
    "status",
    "statusText"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSClientENDCLASS_t {
    uint offsetsAndSizes[58];
    char stringdata0[7];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[14];
    char stringdata5[20];
    char stringdata6[12];
    char stringdata7[14];
    char stringdata8[7];
    char stringdata9[14];
    char stringdata10[12];
    char stringdata11[18];
    char stringdata12[16];
    char stringdata13[16];
    char stringdata14[12];
    char stringdata15[29];
    char stringdata16[12];
    char stringdata17[16];
    char stringdata18[19];
    char stringdata19[14];
    char stringdata20[4];
    char stringdata21[11];
    char stringdata22[7];
    char stringdata23[13];
    char stringdata24[16];
    char stringdata25[5];
    char stringdata26[5];
    char stringdata27[7];
    char stringdata28[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSClientENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSClientENDCLASS_t qt_meta_stringdata_CLASSClientENDCLASS = {
    {
        QT_MOC_LITERAL(0, 6),  // "Client"
        QT_MOC_LITERAL(7, 11),  // "hostChanged"
        QT_MOC_LITERAL(19, 0),  // ""
        QT_MOC_LITERAL(20, 11),  // "portChanged"
        QT_MOC_LITERAL(32, 13),  // "statusChanged"
        QT_MOC_LITERAL(46, 19),  // "processListReceived"
        QT_MOC_LITERAL(66, 11),  // "processList"
        QT_MOC_LITERAL(78, 13),  // "processClosed"
        QT_MOC_LITERAL(92, 6),  // "result"
        QT_MOC_LITERAL(99, 13),  // "errorOccurred"
        QT_MOC_LITERAL(113, 11),  // "errorString"
        QT_MOC_LITERAL(125, 17),  // "connectionTimeout"
        QT_MOC_LITERAL(143, 15),  // "handleConnected"
        QT_MOC_LITERAL(159, 15),  // "handleReadyRead"
        QT_MOC_LITERAL(175, 11),  // "handleError"
        QT_MOC_LITERAL(187, 28),  // "QAbstractSocket::SocketError"
        QT_MOC_LITERAL(216, 11),  // "socketError"
        QT_MOC_LITERAL(228, 15),  // "connectToServer"
        QT_MOC_LITERAL(244, 18),  // "requestProcessList"
        QT_MOC_LITERAL(263, 13),  // "typeOfProcess"
        QT_MOC_LITERAL(277, 3),  // "pid"
        QT_MOC_LITERAL(281, 10),  // "sendSignal"
        QT_MOC_LITERAL(292, 6),  // "signal"
        QT_MOC_LITERAL(299, 12),  // "closeProcess"
        QT_MOC_LITERAL(312, 15),  // "closeConnection"
        QT_MOC_LITERAL(328, 4),  // "host"
        QT_MOC_LITERAL(333, 4),  // "port"
        QT_MOC_LITERAL(338, 6),  // "status"
        QT_MOC_LITERAL(345, 10)   // "statusText"
    },
    "Client",
    "hostChanged",
    "",
    "portChanged",
    "statusChanged",
    "processListReceived",
    "processList",
    "processClosed",
    "result",
    "errorOccurred",
    "errorString",
    "connectionTimeout",
    "handleConnected",
    "handleReadyRead",
    "handleError",
    "QAbstractSocket::SocketError",
    "socketError",
    "connectToServer",
    "requestProcessList",
    "typeOfProcess",
    "pid",
    "sendSignal",
    "signal",
    "closeProcess",
    "closeConnection",
    "host",
    "port",
    "status",
    "statusText"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSClientENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       4,  137, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  104,    2, 0x06,    5 /* Public */,
       3,    0,  105,    2, 0x06,    6 /* Public */,
       4,    0,  106,    2, 0x06,    7 /* Public */,
       5,    1,  107,    2, 0x06,    8 /* Public */,
       7,    1,  110,    2, 0x06,   10 /* Public */,
       9,    1,  113,    2, 0x06,   12 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      11,    0,  116,    2, 0x08,   14 /* Private */,
      12,    0,  117,    2, 0x08,   15 /* Private */,
      13,    0,  118,    2, 0x08,   16 /* Private */,
      14,    1,  119,    2, 0x08,   17 /* Private */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      17,    0,  122,    2, 0x02,   19 /* Public */,
      18,    2,  123,    2, 0x02,   20 /* Public */,
      21,    2,  128,    2, 0x02,   23 /* Public */,
      23,    1,  133,    2, 0x02,   26 /* Public */,
      24,    0,  136,    2, 0x02,   28 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantList,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   19,   20,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   20,   22,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void,

 // properties: name, type, flags
      25, QMetaType::QString, 0x00015103, uint(0), 0,
      26, QMetaType::Int, 0x00015103, uint(1), 0,
      27, QMetaType::Bool, 0x00015001, uint(2), 0,
      28, QMetaType::QString, 0x00015001, uint(2), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject Client::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSClientENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSClientENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSClientENDCLASS_t,
        // property 'host'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // property 'port'
        QtPrivate::TypeAndForceComplete<int, std::true_type>,
        // property 'status'
        QtPrivate::TypeAndForceComplete<bool, std::true_type>,
        // property 'statusText'
        QtPrivate::TypeAndForceComplete<QString, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Client, std::true_type>,
        // method 'hostChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'portChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'statusChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'processListReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVariantList &, std::false_type>,
        // method 'processClosed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'errorOccurred'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'connectionTimeout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleConnected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleReadyRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QAbstractSocket::SocketError, std::false_type>,
        // method 'connectToServer'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'requestProcessList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const int &, std::false_type>,
        // method 'sendSignal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'closeProcess'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'closeConnection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Client *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->hostChanged(); break;
        case 1: _t->portChanged(); break;
        case 2: _t->statusChanged(); break;
        case 3: _t->processListReceived((*reinterpret_cast< std::add_pointer_t<QVariantList>>(_a[1]))); break;
        case 4: _t->processClosed((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->errorOccurred((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->connectionTimeout(); break;
        case 7: _t->handleConnected(); break;
        case 8: _t->handleReadyRead(); break;
        case 9: _t->handleError((*reinterpret_cast< std::add_pointer_t<QAbstractSocket::SocketError>>(_a[1]))); break;
        case 10: _t->connectToServer(); break;
        case 11: _t->requestProcessList((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 12: _t->sendSignal((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 13: _t->closeProcess((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 14: _t->closeConnection(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Client::*)();
            if (_t _q_method = &Client::hostChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Client::*)();
            if (_t _q_method = &Client::portChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Client::*)();
            if (_t _q_method = &Client::statusChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Client::*)(const QVariantList & );
            if (_t _q_method = &Client::processListReceived; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Client::*)(const QString & );
            if (_t _q_method = &Client::processClosed; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Client::*)(const QString & );
            if (_t _q_method = &Client::errorOccurred; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Client *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->host(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->port(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->getStatus(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->statusText(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Client *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setHost(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setPort(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *Client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Client::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSClientENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Client::hostChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Client::portChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Client::statusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Client::processListReceived(const QVariantList & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Client::processClosed(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Client::errorOccurred(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
