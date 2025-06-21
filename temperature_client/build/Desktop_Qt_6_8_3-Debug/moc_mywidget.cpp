/****************************************************************************
** Meta object code from reading C++ file 'mywidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mywidget.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mywidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.3. It"
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
struct qt_meta_tag_ZN8MyWidgetE_t {};
} // unnamed namespace


#ifdef QT_MOC_HAS_STRINGDATA
static constexpr auto qt_meta_stringdata_ZN8MyWidgetE = QtMocHelpers::stringData(
    "MyWidget",
    "automode_start",
    "",
    "automode_send_value",
    "singleshot_send_value",
    "read_server_message",
    "read_server_message_loopback",
    "wait_for_connection",
    "change_transport_protocol",
    "protocol_text",
    "loopback_button_statechanged",
    "network_connectivity_check",
    "QNetworkReply*",
    "reply",
    "http_connection_timeout",
    "update_serial_port",
    "store_serialPort_data",
    "extract_serialPort_data",
    "SerialPort_box_textchanged",
    "text",
    "BaudRate_box_textchange",
    "DataBits_box_textchange",
    "FlowControl_box_textchange",
    "Parity_box_textchange",
    "StopBits_box_textchange"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA

Q_CONSTINIT static const uint qt_meta_data_ZN8MyWidgetE[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  128,    2, 0x08,    1 /* Private */,
       3,    0,  129,    2, 0x08,    2 /* Private */,
       4,    0,  130,    2, 0x08,    3 /* Private */,
       5,    0,  131,    2, 0x08,    4 /* Private */,
       6,    0,  132,    2, 0x08,    5 /* Private */,
       7,    0,  133,    2, 0x08,    6 /* Private */,
       8,    1,  134,    2, 0x08,    7 /* Private */,
      10,    0,  137,    2, 0x08,    9 /* Private */,
      11,    1,  138,    2, 0x08,   10 /* Private */,
      14,    0,  141,    2, 0x08,   12 /* Private */,
      15,    0,  142,    2, 0x08,   13 /* Private */,
      16,    0,  143,    2, 0x08,   14 /* Private */,
      17,    0,  144,    2, 0x08,   15 /* Private */,
      18,    1,  145,    2, 0x08,   16 /* Private */,
      20,    1,  148,    2, 0x08,   18 /* Private */,
      21,    1,  151,    2, 0x08,   20 /* Private */,
      22,    1,  154,    2, 0x08,   22 /* Private */,
      23,    1,  157,    2, 0x08,   24 /* Private */,
      24,    1,  160,    2, 0x08,   26 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Double,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::QString,   19,

       0        // eod
};

Q_CONSTINIT const QMetaObject MyWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ZN8MyWidgetE.offsetsAndSizes,
    qt_meta_data_ZN8MyWidgetE,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_tag_ZN8MyWidgetE_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MyWidget, std::true_type>,
        // method 'automode_start'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'automode_send_value'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'singleshot_send_value'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'read_server_message'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'read_server_message_loopback'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'wait_for_connection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'change_transport_protocol'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'loopback_button_statechanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'network_connectivity_check'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QNetworkReply *, std::false_type>,
        // method 'http_connection_timeout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'update_serial_port'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'store_serialPort_data'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'extract_serialPort_data'
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'SerialPort_box_textchanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'BaudRate_box_textchange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'DataBits_box_textchange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'FlowControl_box_textchange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'Parity_box_textchange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'StopBits_box_textchange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void MyWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MyWidget *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->automode_start(); break;
        case 1: _t->automode_send_value(); break;
        case 2: _t->singleshot_send_value(); break;
        case 3: _t->read_server_message(); break;
        case 4: _t->read_server_message_loopback(); break;
        case 5: _t->wait_for_connection(); break;
        case 6: _t->change_transport_protocol((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->loopback_button_statechanged(); break;
        case 8: _t->network_connectivity_check((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        case 9: _t->http_connection_timeout(); break;
        case 10: _t->update_serial_port(); break;
        case 11: _t->store_serialPort_data(); break;
        case 12: { double _r = _t->extract_serialPort_data();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 13: _t->SerialPort_box_textchanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 14: _t->BaudRate_box_textchange((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 15: _t->DataBits_box_textchange((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 16: _t->FlowControl_box_textchange((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 17: _t->Parity_box_textchange((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 18: _t->StopBits_box_textchange((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

const QMetaObject *MyWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZN8MyWidgetE.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MyWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}
QT_WARNING_POP
