/****************************************************************************
** Meta object code from reading C++ file 'cardclientwindows.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Gui/cardclientwindows.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cardclientwindows.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CardClientWindows_t {
    QByteArrayData data[9];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CardClientWindows_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CardClientWindows_t qt_meta_stringdata_CardClientWindows = {
    {
QT_MOC_LITERAL(0, 0, 17), // "CardClientWindows"
QT_MOC_LITERAL(1, 18, 11), // "closeSignal"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 12), // "fillDistrict"
QT_MOC_LITERAL(4, 44, 15), // "clickSaveButton"
QT_MOC_LITERAL(5, 60, 22), // "clickDataBeginCheckBox"
QT_MOC_LITERAL(6, 83, 20), // "clickDataEndCheckBox"
QT_MOC_LITERAL(7, 104, 19), // "defaultContenWindow"
QT_MOC_LITERAL(8, 124, 10) // "showWindow"

    },
    "CardClientWindows\0closeSignal\0\0"
    "fillDistrict\0clickSaveButton\0"
    "clickDataBeginCheckBox\0clickDataEndCheckBox\0"
    "defaultContenWindow\0showWindow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CardClientWindows[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   50,    2, 0x0a /* Public */,
       4,    0,   51,    2, 0x0a /* Public */,
       5,    0,   52,    2, 0x0a /* Public */,
       6,    0,   53,    2, 0x0a /* Public */,
       7,    0,   54,    2, 0x0a /* Public */,
       8,    0,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CardClientWindows::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CardClientWindows *_t = static_cast<CardClientWindows *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closeSignal(); break;
        case 1: _t->fillDistrict(); break;
        case 2: _t->clickSaveButton(); break;
        case 3: _t->clickDataBeginCheckBox(); break;
        case 4: _t->clickDataEndCheckBox(); break;
        case 5: _t->defaultContenWindow(); break;
        case 6: _t->showWindow(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CardClientWindows::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CardClientWindows::closeSignal)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject CardClientWindows::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CardClientWindows.data,
      qt_meta_data_CardClientWindows,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CardClientWindows::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CardClientWindows::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CardClientWindows.stringdata0))
        return static_cast<void*>(const_cast< CardClientWindows*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int CardClientWindows::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void CardClientWindows::closeSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
