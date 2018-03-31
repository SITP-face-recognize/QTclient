/****************************************************************************
** Meta object code from reading C++ file 'frame_stumanage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../frame_stumanage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'frame_stumanage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Frame_stuManage_t {
    QByteArrayData data[7];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Frame_stuManage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Frame_stuManage_t qt_meta_stringdata_Frame_stuManage = {
    {
QT_MOC_LITERAL(0, 0, 15), // "Frame_stuManage"
QT_MOC_LITERAL(1, 16, 22), // "on_btn_addFace_clicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 25), // "on_btn_updateFace_clicked"
QT_MOC_LITERAL(4, 66, 21), // "on_btn_delete_clicked"
QT_MOC_LITERAL(5, 88, 27), // "on_tb_id_update_textChanged"
QT_MOC_LITERAL(6, 116, 27) // "on_tb_id_delete_textChanged"

    },
    "Frame_stuManage\0on_btn_addFace_clicked\0"
    "\0on_btn_updateFace_clicked\0"
    "on_btn_delete_clicked\0on_tb_id_update_textChanged\0"
    "on_tb_id_delete_textChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Frame_stuManage[] = {

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
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    0,   41,    2, 0x08 /* Private */,
       5,    1,   42,    2, 0x08 /* Private */,
       6,    1,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void Frame_stuManage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Frame_stuManage *_t = static_cast<Frame_stuManage *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_btn_addFace_clicked(); break;
        case 1: _t->on_btn_updateFace_clicked(); break;
        case 2: _t->on_btn_delete_clicked(); break;
        case 3: _t->on_tb_id_update_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->on_tb_id_delete_textChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Frame_stuManage::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Frame_stuManage.data,
      qt_meta_data_Frame_stuManage,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Frame_stuManage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Frame_stuManage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Frame_stuManage.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Frame_stuManage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
