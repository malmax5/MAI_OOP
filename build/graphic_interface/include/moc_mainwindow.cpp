/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../graphic_interface/include/mainwindow.hpp"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.8.0. It"
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
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "KnightAdded",
    "",
    "std::shared_ptr<NPC>",
    "knight",
    "x",
    "y",
    "PegasusAdded",
    "pegasus",
    "SquirrelAdded",
    "squirrel",
    "OnCreateGame",
    "OnStartGame",
    "OnStopGame",
    "OnDeleteGame",
    "OnIncludeKnight",
    "OnIncludePegasus",
    "OnIncludeSquirrel",
    "OnLoadNPCToFile",
    "OnExportNPCFromFile",
    "OnExit",
    "OnInfo"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   98,    2, 0x06,    1 /* Public */,
       7,    3,  105,    2, 0x06,    5 /* Public */,
       9,    3,  112,    2, 0x06,    9 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      11,    0,  119,    2, 0x08,   13 /* Private */,
      12,    0,  120,    2, 0x08,   14 /* Private */,
      13,    0,  121,    2, 0x08,   15 /* Private */,
      14,    0,  122,    2, 0x08,   16 /* Private */,
      15,    0,  123,    2, 0x08,   17 /* Private */,
      16,    0,  124,    2, 0x08,   18 /* Private */,
      17,    0,  125,    2, 0x08,   19 /* Private */,
      18,    0,  126,    2, 0x08,   20 /* Private */,
      19,    0,  127,    2, 0x08,   21 /* Private */,
      20,    0,  128,    2, 0x08,   22 /* Private */,
      21,    0,  129,    2, 0x08,   23 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int,    4,    5,    6,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int,    8,    5,    6,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int,   10,    5,    6,

 // slots: parameters
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
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'KnightAdded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::shared_ptr<NPC>, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'PegasusAdded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::shared_ptr<NPC>, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'SquirrelAdded'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<std::shared_ptr<NPC>, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'OnCreateGame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'OnStartGame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'OnStopGame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'OnDeleteGame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'OnIncludeKnight'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'OnIncludePegasus'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'OnIncludeSquirrel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'OnLoadNPCToFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'OnExportNPCFromFile'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'OnExit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'OnInfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->KnightAdded((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<NPC>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 1: _t->PegasusAdded((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<NPC>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 2: _t->SquirrelAdded((*reinterpret_cast< std::add_pointer_t<std::shared_ptr<NPC>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 3: _t->OnCreateGame(); break;
        case 4: _t->OnStartGame(); break;
        case 5: _t->OnStopGame(); break;
        case 6: _t->OnDeleteGame(); break;
        case 7: _t->OnIncludeKnight(); break;
        case 8: _t->OnIncludePegasus(); break;
        case 9: _t->OnIncludeSquirrel(); break;
        case 10: _t->OnLoadNPCToFile(); break;
        case 11: _t->OnExportNPCFromFile(); break;
        case 12: _t->OnExit(); break;
        case 13: _t->OnInfo(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(std::shared_ptr<NPC> , int , int );
            if (_t _q_method = &MainWindow::KnightAdded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(std::shared_ptr<NPC> , int , int );
            if (_t _q_method = &MainWindow::PegasusAdded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(std::shared_ptr<NPC> , int , int );
            if (_t _q_method = &MainWindow::SquirrelAdded; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::KnightAdded(std::shared_ptr<NPC> _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::PegasusAdded(std::shared_ptr<NPC> _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::SquirrelAdded(std::shared_ptr<NPC> _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
