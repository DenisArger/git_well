/****************************************************************************
** Meta object code from reading C++ file 'cardservicewindows.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Gui/cardservicewindows.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cardservicewindows.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CardServiceWindows_t {
    QByteArrayData data[10];
    char stringdata0[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CardServiceWindows_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CardServiceWindows_t qt_meta_stringdata_CardServiceWindows = {
    {
QT_MOC_LITERAL(0, 0, 18), // "CardServiceWindows"
QT_MOC_LITERAL(1, 19, 10), // "closeEvent"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 12), // "QCloseEvent*"
QT_MOC_LITERAL(4, 44, 5), // "event"
QT_MOC_LITERAL(5, 50, 12), // "fillDistrict"
QT_MOC_LITERAL(6, 63, 15), // "clickSaveButton"
QT_MOC_LITERAL(7, 79, 20), // "changedCurrtentUndex"
QT_MOC_LITERAL(8, 100, 5), // "index"
QT_MOC_LITERAL(9, 106, 10) // "showWindow"

    },
    "CardServiceWindows\0closeEvent\0\0"
    "QCloseEvent*\0event\0fillDistrict\0"
    "clickSaveButton\0changedCurrtentUndex\0"
    "index\0showWindow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CardServiceWindows[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   42,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x0a /* Public */,
       7,    1,   44,    2, 0x0a /* Public */,
       9,    0,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,

       0        // eod
};

void CardServiceWindows::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CardServiceWindows *_t = static_cast<CardServiceWindows *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 1: _t->fillDistrict(); break;
        case 2: _t->clickSaveButton(); break;
        case 3: _t->changedCurrtentUndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->showWindow(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CardServiceWindows::*_t)(QCloseEvent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CardServiceWindows::closeEvent)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject CardServiceWindows::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CardServiceWindows.data,
      qt_meta_data_CardServiceWindows,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CardServiceWindows::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CardServiceWindows::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CardServiceWindows.stringdata0))
        return static_cast<void*>(const_cast< CardServiceWindows*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int CardServiceWindows::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void CardServiceWindows::closeEvent(QCloseEvent * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
