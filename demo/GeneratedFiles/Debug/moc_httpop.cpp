/****************************************************************************
** Meta object code from reading C++ file 'httpop.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../httpop.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'httpop.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HttpOp_t {
    QByteArrayData data[8];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HttpOp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HttpOp_t qt_meta_stringdata_HttpOp = {
    {
QT_MOC_LITERAL(0, 0, 6), // "HttpOp"
QT_MOC_LITERAL(1, 7, 22), // "signal_requestFinished"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 8), // "bSuccess"
QT_MOC_LITERAL(4, 40, 14), // "QNetworkReply&"
QT_MOC_LITERAL(5, 55, 5), // "reply"
QT_MOC_LITERAL(6, 61, 20), // "slot_requestFinished"
QT_MOC_LITERAL(7, 82, 19) // "slot_requestTimeout"

    },
    "HttpOp\0signal_requestFinished\0\0bSuccess\0"
    "QNetworkReply&\0reply\0slot_requestFinished\0"
    "slot_requestTimeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HttpOp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   34,    2, 0x0a /* Public */,
       7,    0,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 4,    3,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void HttpOp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HttpOp *_t = static_cast<HttpOp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_requestFinished((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QNetworkReply(*)>(_a[2]))); break;
        case 1: _t->slot_requestFinished(); break;
        case 2: _t->slot_requestTimeout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (HttpOp::*_t)(bool , QNetworkReply & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HttpOp::signal_requestFinished)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HttpOp::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_HttpOp.data,
      qt_meta_data_HttpOp,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *HttpOp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HttpOp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HttpOp.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int HttpOp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void HttpOp::signal_requestFinished(bool _t1, QNetworkReply & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
