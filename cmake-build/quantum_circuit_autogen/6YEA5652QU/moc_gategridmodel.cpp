/****************************************************************************
** Meta object code from reading C++ file 'gategridmodel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../include/gategridmodel.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gategridmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSGateGridModelENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSGateGridModelENDCLASS = QtMocHelpers::stringData(
    "GateGridModel",
    "insertGate",
    "",
    "gateType",
    "row",
    "column",
    "removeGate",
    "addBitRow",
    "removeBitRow",
    "clearAll",
    "syncFromCircuit",
    "syncToCircuit",
    "rowCount",
    "QModelIndex",
    "parent",
    "columnCount",
    "bitCount",
    "timeCount"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSGateGridModelENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   92,    2, 0x0a,    1 /* Public */,
       6,    2,   99,    2, 0x0a,    5 /* Public */,
       7,    0,  104,    2, 0x0a,    8 /* Public */,
       8,    0,  105,    2, 0x0a,    9 /* Public */,
       9,    0,  106,    2, 0x0a,   10 /* Public */,
      10,    0,  107,    2, 0x0a,   11 /* Public */,
      11,    0,  108,    2, 0x0a,   12 /* Public */,
      12,    1,  109,    2, 0x10a,   13 /* Public | MethodIsConst  */,
      12,    0,  112,    2, 0x12a,   15 /* Public | MethodCloned | MethodIsConst  */,
      15,    1,  113,    2, 0x10a,   16 /* Public | MethodIsConst  */,
      15,    0,  116,    2, 0x12a,   18 /* Public | MethodCloned | MethodIsConst  */,
      16,    0,  117,    2, 0x10a,   19 /* Public | MethodIsConst  */,
      17,    0,  118,    2, 0x10a,   20 /* Public | MethodIsConst  */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, 0x80000000 | 13,   14,
    QMetaType::Int,
    QMetaType::Int, 0x80000000 | 13,   14,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,

       0        // eod
};

Q_CONSTINIT const QMetaObject GateGridModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractTableModel::staticMetaObject>(),
    qt_meta_stringdata_CLASSGateGridModelENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSGateGridModelENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSGateGridModelENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<GateGridModel, std::true_type>,
        // method 'insertGate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'removeGate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'addBitRow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'removeBitRow'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clearAll'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'syncFromCircuit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'syncToCircuit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'rowCount'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'rowCount'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'columnCount'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'columnCount'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'bitCount'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'timeCount'
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void GateGridModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GateGridModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->insertGate((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 1: _t->removeGate((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 2: _t->addBitRow(); break;
        case 3: _t->removeBitRow(); break;
        case 4: _t->clearAll(); break;
        case 5: _t->syncFromCircuit(); break;
        case 6: _t->syncToCircuit(); break;
        case 7: { int _r = _t->rowCount((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: { int _r = _t->rowCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 9: { int _r = _t->columnCount((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 10: { int _r = _t->columnCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 11: { int _r = _t->bitCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 12: { int _r = _t->timeCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject *GateGridModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GateGridModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSGateGridModelENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QAbstractTableModel::qt_metacast(_clname);
}

int GateGridModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
