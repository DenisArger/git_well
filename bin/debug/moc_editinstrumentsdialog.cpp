/****************************************************************************
** Meta object code from reading C++ file 'editinstrumentsdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Gui/editinstrumentsdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editinstrumentsdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EditInstrumentsDialog_t {
    QByteArrayData data[9];
    char stringdata0[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EditInstrumentsDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EditInstrumentsDialog_t qt_meta_stringdata_EditInstrumentsDialog = {
    {
QT_MOC_LITERAL(0, 0, 21), // "EditInstrumentsDialog"
QT_MOC_LITERAL(1, 22, 10), // "applyClick"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 7), // "reCount"
QT_MOC_LITERAL(4, 42, 11), // "fillBalance"
QT_MOC_LITERAL(5, 54, 21), // "showEditBalanseWindow"
QT_MOC_LITERAL(6, 76, 24), // "showEditInstrumentWindow"
QT_MOC_LITERAL(7, 101, 10), // "setBalance"
QT_MOC_LITERAL(8, 112, 17) // "setNameInstrument"

    },
    "EditInstrumentsDialog\0applyClick\0\0"
    "reCount\0fillBalance\0showEditBalanseWindow\0"
    "showEditInstrumentWindow\0setBalance\0"
    "setNameInstrument"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EditInstrumentsDialog[] = {

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

void EditInstrumentsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        EditInstrumentsDialog *_t = static_cast<EditInstrumentsDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->applyClick(); break;
        case 1: _t->reCount(); break;
        case 2: _t->fillBalance(); break;
        case 3: _t->showEditBalanseWindow(); break;
        case 4: _t->showEditInstrumentWindow(); break;
        case 5: _t->setBalance(); break;
        case 6: _t->setNameInstrument(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (EditInstrumentsDialog::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&EditInstrumentsDialog::applyClick)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject EditInstrumentsDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_EditInstrumentsDialog.data,
      qt_meta_data_EditInstrumentsDialog,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *EditInstrumentsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EditInstrumentsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_EditInstrumentsDialog.stringdata0))
        return static_cast<void*>(const_cast< EditInstrumentsDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int EditInstrumentsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void EditInstrumentsDialog::applyClick()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
