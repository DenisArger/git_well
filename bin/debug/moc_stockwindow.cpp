/****************************************************************************
** Meta object code from reading C++ file 'stockwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Gui/stockwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'stockwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_StockWindow_t {
    QByteArrayData data[19];
    char stringdata0[280];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StockWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StockWindow_t qt_meta_stringdata_StockWindow = {
    {
QT_MOC_LITERAL(0, 0, 11), // "StockWindow"
QT_MOC_LITERAL(1, 12, 14), // "parsingIdInstr"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 5), // "index"
QT_MOC_LITERAL(4, 34, 11), // "showHistory"
QT_MOC_LITERAL(5, 46, 13), // "updateWindows"
QT_MOC_LITERAL(6, 60, 16), // "clickClearButton"
QT_MOC_LITERAL(7, 77, 14), // "clickSumButton"
QT_MOC_LITERAL(8, 92, 22), // "deleteClassInstruments"
QT_MOC_LITERAL(9, 115, 16), // "deleteInstrument"
QT_MOC_LITERAL(10, 132, 6), // "addTab"
QT_MOC_LITERAL(11, 139, 13), // "setCurrentTab"
QT_MOC_LITERAL(12, 153, 10), // "showWindow"
QT_MOC_LITERAL(13, 164, 21), // "showReCoutInstruments"
QT_MOC_LITERAL(14, 186, 23), // "editNameClassInstrument"
QT_MOC_LITERAL(15, 210, 18), // "editNameInstrument"
QT_MOC_LITERAL(16, 229, 17), // "showConfirmDelete"
QT_MOC_LITERAL(17, 247, 9), // "setMapTab"
QT_MOC_LITERAL(18, 257, 22) // "showEditBalanceWindows"

    },
    "StockWindow\0parsingIdInstr\0\0index\0"
    "showHistory\0updateWindows\0clickClearButton\0"
    "clickSumButton\0deleteClassInstruments\0"
    "deleteInstrument\0addTab\0setCurrentTab\0"
    "showWindow\0showReCoutInstruments\0"
    "editNameClassInstrument\0editNameInstrument\0"
    "showConfirmDelete\0setMapTab\0"
    "showEditBalanceWindows"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StockWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x0a /* Public */,
       4,    0,   97,    2, 0x0a /* Public */,
       5,    0,   98,    2, 0x0a /* Public */,
       6,    0,   99,    2, 0x0a /* Public */,
       7,    0,  100,    2, 0x0a /* Public */,
       8,    1,  101,    2, 0x0a /* Public */,
       9,    0,  104,    2, 0x0a /* Public */,
      10,    0,  105,    2, 0x0a /* Public */,
      11,    1,  106,    2, 0x0a /* Public */,
      12,    0,  109,    2, 0x0a /* Public */,
      13,    1,  110,    2, 0x0a /* Public */,
      14,    1,  113,    2, 0x0a /* Public */,
      15,    0,  116,    2, 0x0a /* Public */,
      16,    1,  117,    2, 0x0a /* Public */,
      17,    0,  120,    2, 0x0a /* Public */,
      18,    0,  121,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void StockWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StockWindow *_t = static_cast<StockWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->parsingIdInstr((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 1: _t->showHistory(); break;
        case 2: _t->updateWindows(); break;
        case 3: _t->clickClearButton(); break;
        case 4: _t->clickSumButton(); break;
        case 5: _t->deleteClassInstruments((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->deleteInstrument(); break;
        case 7: _t->addTab(); break;
        case 8: _t->setCurrentTab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->showWindow(); break;
        case 10: _t->showReCoutInstruments((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->editNameClassInstrument((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->editNameInstrument(); break;
        case 13: _t->showConfirmDelete((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->setMapTab(); break;
        case 15: _t->showEditBalanceWindows(); break;
        default: ;
        }
    }
}

const QMetaObject StockWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_StockWindow.data,
      qt_meta_data_StockWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *StockWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StockWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_StockWindow.stringdata0))
        return static_cast<void*>(const_cast< StockWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int StockWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
