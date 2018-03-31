/****************************************************************************
** Meta object code from reading C++ file 'frame_query.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../frame_query.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frame_query.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Frame_query_t {
    QByteArrayData data[11];
    char stringdata0[158];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Frame_query_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Frame_query_t qt_meta_stringdata_Frame_query = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Frame_query"
QT_MOC_LITERAL(1, 12, 12), // "get_signList"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 9), // "course_id"
QT_MOC_LITERAL(4, 36, 12), // "get_signInfo"
QT_MOC_LITERAL(5, 49, 18), // "queryAll_byStudent"
QT_MOC_LITERAL(6, 68, 30), // "slot_requestCourseSignFinished"
QT_MOC_LITERAL(7, 99, 8), // "bSuccess"
QT_MOC_LITERAL(8, 108, 14), // "QNetworkReply&"
QT_MOC_LITERAL(9, 123, 5), // "reply"
QT_MOC_LITERAL(10, 129, 28) // "slot_requestSignInfoFinished"

    },
    "Frame_query\0get_signList\0\0course_id\0"
    "get_signInfo\0queryAll_byStudent\0"
    "slot_requestCourseSignFinished\0bSuccess\0"
    "QNetworkReply&\0reply\0slot_requestSignInfoFinished"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Frame_query[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08 /* Private */,
       4,    1,   42,    2, 0x08 /* Private */,
       5,    0,   45,    2, 0x08 /* Private */,
       6,    2,   46,    2, 0x08 /* Private */,
      10,    2,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QModelIndex,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 8,    7,    9,
    QMetaType::Void, QMetaType::Bool, 0x80000000 | 8,    7,    9,

       0        // eod
};

void Frame_query::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Frame_query *_t = static_cast<Frame_query *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->get_signList((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->get_signInfo((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->queryAll_byStudent(); break;
        case 3: _t->slot_requestCourseSignFinished((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QNetworkReply(*)>(_a[2]))); break;
        case 4: _t->slot_requestSignInfoFinished((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QNetworkReply(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Frame_query::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Frame_query.data,
      qt_meta_data_Frame_query,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Frame_query::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Frame_query::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Frame_query.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Frame_query::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
