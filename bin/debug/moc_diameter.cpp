/****************************************************************************
** Meta object code from reading C++ file 'diameter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Gui/diameter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'diameter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_diameter_t {
    QByteArrayData data[9];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_diameter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_diameter_t qt_meta_stringdata_diameter = {
    {
QT_MOC_LITERAL(0, 0, 8), // "diameter"
QT_MOC_LITERAL(1, 9, 14), // "parsingIdInstr"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 5), // "index"
QT_MOC_LITERAL(4, 31, 11), // "showHistory"
QT_MOC_LITERAL(5, 43, 13), // "updateWindows"
QT_MOC_LITERAL(6, 57, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(7, 81, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(8, 103, 23) // "on_clearButtton_clicked"

    },
    "diameter\0parsingIdInstr\0\0index\0"
    "showHistory\0updateWindows\0"
    "on_pushButton_3_clicked\0on_pushButton_clicked\0"
    "on_clearButtton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_diameter[] = {

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
       1,    1,   44,    2, 0x0a /* Public */,
       4,    0,   47,    2, 0x0a /* Public */,
       5,    0,   48,    2, 0x0a /* Public */,
       6,    0,   49,    2, 0x08 /* Private */,
       7,    0,   50,    2, 0x08 /* Private */,
       8,    0,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void diameter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        diameter *_t = static_cast<diameter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->parsingIdInstr((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 1: _t->showHistory(); break;
        case 2: _t->updateWindows(); break;
        case 3: _t->on_pushButton_3_clicked(); break;
        case 4: _t->on_pushButton_clicked(); break;
        case 5: _t->on_clearButtton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject diameter::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_diameter.data,
      qt_meta_data_diameter,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *diameter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *diameter::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_diameter.stringdata0))
        return static_cast<void*>(const_cast< diameter*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int diameter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
