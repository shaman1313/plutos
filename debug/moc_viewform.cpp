/****************************************************************************
** Meta object code from reading C++ file 'viewform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../viewform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'viewform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_viewForm_t {
    QByteArrayData data[8];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_viewForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_viewForm_t qt_meta_stringdata_viewForm = {
    {
QT_MOC_LITERAL(0, 0, 8), // "viewForm"
QT_MOC_LITERAL(1, 9, 10), // "getContent"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 1), // "f"
QT_MOC_LITERAL(4, 23, 37), // "on_pushButton_viewForm_cancel..."
QT_MOC_LITERAL(5, 61, 37), // "on_pushButton_viewform_search..."
QT_MOC_LITERAL(6, 99, 35), // "on_pushButton_viewForm_exel_c..."
QT_MOC_LITERAL(7, 135, 33) // "on_pushButton_viewForm_ok_cli..."

    },
    "viewForm\0getContent\0\0f\0"
    "on_pushButton_viewForm_cancel_clicked\0"
    "on_pushButton_viewform_search_clicked\0"
    "on_pushButton_viewForm_exel_clicked\0"
    "on_pushButton_viewForm_ok_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_viewForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x08 /* Private */,
       1,    0,   47,    2, 0x28 /* Private | MethodCloned */,
       4,    0,   48,    2, 0x08 /* Private */,
       5,    0,   49,    2, 0x08 /* Private */,
       6,    0,   50,    2, 0x08 /* Private */,
       7,    0,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString,    3,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void viewForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        viewForm *_t = static_cast<viewForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->getContent((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: { bool _r = _t->getContent();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->on_pushButton_viewForm_cancel_clicked(); break;
        case 3: _t->on_pushButton_viewform_search_clicked(); break;
        case 4: _t->on_pushButton_viewForm_exel_clicked(); break;
        case 5: _t->on_pushButton_viewForm_ok_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject viewForm::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_viewForm.data,
      qt_meta_data_viewForm,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *viewForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *viewForm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_viewForm.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int viewForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
