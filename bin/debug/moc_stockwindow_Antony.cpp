/****************************************************************************
** Meta object code from reading C++ file 'stockwindow_Antony.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Gui/stockwindow_Antony.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stockwindow_Antony.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_StockWindow_Antony_t {
    QByteArrayData data[16];
    char stringdata0[205];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StockWindow_Antony_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StockWindow_Antony_t qt_meta_stringdata_StockWindow_Antony = {
    {
QT_MOC_LITERAL(0, 0, 18), // "StockWindow_Antony"
QT_MOC_LITERAL(1, 19, 14), // "parsingIdInstr"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 5), // "index"
QT_MOC_LITERAL(4, 41, 11), // "showHistory"
QT_MOC_LITERAL(5, 53, 13), // "updateWindows"
QT_MOC_LITERAL(6, 67, 16), // "clickClearButton"
QT_MOC_LITERAL(7, 84, 14), // "clickSumButton"
QT_MOC_LITERAL(8, 99, 22), // "clickCurrBalanceButton"
QT_MOC_LITERAL(9, 122, 8), // "clickAdd"
QT_MOC_LITERAL(10, 131, 9), // "clickEdit"
QT_MOC_LITERAL(11, 141, 11), // "clickDelete"
QT_MOC_LITERAL(12, 153, 19), // "clickAddInstruments"
QT_MOC_LITERAL(13, 173, 6), // "addTab"
QT_MOC_LITERAL(14, 180, 13), // "setCurrentTab"
QT_MOC_LITERAL(15, 194, 10) // "showWindow"

    },
    "StockWindow_Antony\0parsingIdInstr\0\0"
    "index\0showHistory\0updateWindows\0"
    "clickClearButton\0clickSumButton\0"
    "clickCurrBalanceButton\0clickAdd\0"
    "clickEdit\0clickDelete\0clickAddInstruments\0"
    "addTab\0setCurrentTab\0showWindow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StockWindow_Antony[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x0a /* Public */,
       4,    0,   82,    2, 0x0a /* Public */,
       5,    0,   83,    2, 0x0a /* Public */,
       6,    0,   84,    2, 0x0a /* Public */,
       7,    0,   85,    2, 0x0a /* Public */,
       8,    0,   86,    2, 0x0a /* Public */,
       9,    0,   87,    2, 0x0a /* Public */,
      10,    0,   88,    2, 0x0a /* Public */,
      11,    0,   89,    2, 0x0a /* Public */,
      12,    0,   90,    2, 0x0a /* Public */,
      13,    0,   91,    2, 0x0a /* Public */,
      14,    1,   92,    2, 0x0a /* Public */,
      15,    0,   95,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,

       0        // eod
};

void StockWindow_Antony::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StockWindow_Antony *_t = static_cast<StockWindow_Antony *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->parsingIdInstr((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 1: _t->showHistory(); break;
        case 2: _t->updateWindows(); break;
        case 3: _t->clickClearButton(); break;
        case 4: _t->clickSumButton(); break;
        case 5: _t->clickCurrBalanceButton(); break;
        case 6: _t->clickAdd(); break;
        case 7: _t->clickEdit(); break;
        case 8: _t->clickDelete(); break;
        case 9: _t->clickAddInstruments(); break;
        case 10: _t->addTab(); break;
        case 11: _t->setCurrentTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->showWindow(); break;
        default: ;
        }
    }
}

const QMetaObject StockWindow_Antony::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_StockWindow_Antony.data,
      qt_meta_data_StockWindow_Antony,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *StockWindow_Antony::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StockWindow_Antony::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_StockWindow_Antony.stringdata0))
        return static_cast<void*>(const_cast< StockWindow_Antony*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int StockWindow_Antony::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
