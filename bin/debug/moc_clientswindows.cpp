/****************************************************************************
** Meta object code from reading C++ file 'clientswindows.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Gui/clientswindows.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clientswindows.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ClientsWindows_t {
    QByteArrayData data[10];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClientsWindows_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClientsWindows_t qt_meta_stringdata_ClientsWindows = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ClientsWindows"
QT_MOC_LITERAL(1, 15, 10), // "fillRegion"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 12), // "fillDistrict"
QT_MOC_LITERAL(4, 40, 17), // "clickFilterButton"
QT_MOC_LITERAL(5, 58, 22), // "clickClearFilterButton"
QT_MOC_LITERAL(6, 81, 23), // "clickDoubleClickedTable"
QT_MOC_LITERAL(7, 105, 5), // "index"
QT_MOC_LITERAL(8, 111, 10), // "showWindow"
QT_MOC_LITERAL(9, 122, 11) // "updateModel"

    },
    "ClientsWindows\0fillRegion\0\0fillDistrict\0"
    "clickFilterButton\0clickClearFilterButton\0"
    "clickDoubleClickedTable\0index\0showWindow\0"
    "updateModel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClientsWindows[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x0a /* Public */,
       4,    0,   51,    2, 0x0a /* Public */,
       5,    0,   52,    2, 0x0a /* Public */,
       6,    1,   53,    2, 0x0a /* Public */,
       8,    0,   56,    2, 0x0a /* Public */,
       9,    0,   57,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    7,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ClientsWindows::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ClientsWindows *_t = static_cast<ClientsWindows *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->fillRegion(); break;
        case 1: _t->fillDistrict(); break;
        case 2: _t->clickFilterButton(); break;
        case 3: _t->clickClearFilterButton(); break;
        case 4: _t->clickDoubleClickedTable((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 5: _t->showWindow(); break;
        case 6: _t->updateModel(); break;
        default: ;
        }
    }
}

const QMetaObject ClientsWindows::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ClientsWindows.data,
      qt_meta_data_ClientsWindows,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ClientsWindows::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClientsWindows::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ClientsWindows.stringdata0))
        return static_cast<void*>(const_cast< ClientsWindows*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ClientsWindows::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
