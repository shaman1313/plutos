/****************************************************************************
** Meta object code from reading C++ file 'additemsform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../additemsform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'additemsform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_addItemsForm_t {
    QByteArrayData data[7];
    char stringdata0[187];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_addItemsForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_addItemsForm_t qt_meta_stringdata_addItemsForm = {
    {
QT_MOC_LITERAL(0, 0, 12), // "addItemsForm"
QT_MOC_LITERAL(1, 13, 38), // "on_pushButton_additemsform_ad..."
QT_MOC_LITERAL(2, 52, 0), // ""
QT_MOC_LITERAL(3, 53, 41), // "on_pushButton_additemsform_ca..."
QT_MOC_LITERAL(4, 95, 41), // "on_pushButton_additemsform_de..."
QT_MOC_LITERAL(5, 137, 11), // "recalculate"
QT_MOC_LITERAL(6, 149, 37) // "on_pushButton_additemsform_ok..."

    },
    "addItemsForm\0on_pushButton_additemsform_add_clicked\0"
    "\0on_pushButton_additemsform_cancel_clicked\0"
    "on_pushButton_additemsform_delete_clicked\0"
    "recalculate\0on_pushButton_additemsform_ok_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_addItemsForm[] = {

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
       6,    0,   45,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void addItemsForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        addItemsForm *_t = static_cast<addItemsForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_additemsform_add_clicked(); break;
        case 1: _t->on_pushButton_additemsform_cancel_clicked(); break;
        case 2: _t->on_pushButton_additemsform_delete_clicked(); break;
        case 3: _t->recalculate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_pushButton_additemsform_ok_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject addItemsForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_addItemsForm.data,
      qt_meta_data_addItemsForm,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *addItemsForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *addItemsForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_addItemsForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int addItemsForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
