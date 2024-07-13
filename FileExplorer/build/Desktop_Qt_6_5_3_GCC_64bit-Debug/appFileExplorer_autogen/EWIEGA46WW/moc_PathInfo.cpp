/****************************************************************************
** Meta object code from reading C++ file 'PathInfo.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../PathInfo.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PathInfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
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
struct qt_meta_stringdata_CLASSPathInfoENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSPathInfoENDCLASS = QtMocHelpers::stringData(
    "PathInfo",
    "QML.Element",
    "auto",
    "nameChanged",
    "",
    "pathChanged",
    "imageSourceChanged",
    "isFileChanged",
    "name",
    "path",
    "imageSource",
    "isFile"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSPathInfoENDCLASS_t {
    uint offsetsAndSizes[24];
    char stringdata0[9];
    char stringdata1[12];
    char stringdata2[5];
    char stringdata3[12];
    char stringdata4[1];
    char stringdata5[12];
    char stringdata6[19];
    char stringdata7[14];
    char stringdata8[5];
    char stringdata9[5];
    char stringdata10[12];
    char stringdata11[7];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSPathInfoENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSPathInfoENDCLASS_t qt_meta_stringdata_CLASSPathInfoENDCLASS = {
    {
        QT_MOC_LITERAL(0, 8),  // "PathInfo"
        QT_MOC_LITERAL(9, 11),  // "QML.Element"
        QT_MOC_LITERAL(21, 4),  // "auto"
        QT_MOC_LITERAL(26, 11),  // "nameChanged"
        QT_MOC_LITERAL(38, 0),  // ""
        QT_MOC_LITERAL(39, 11),  // "pathChanged"
        QT_MOC_LITERAL(51, 18),  // "imageSourceChanged"
        QT_MOC_LITERAL(70, 13),  // "isFileChanged"
        QT_MOC_LITERAL(84, 4),  // "name"
        QT_MOC_LITERAL(89, 4),  // "path"
        QT_MOC_LITERAL(94, 11),  // "imageSource"
        QT_MOC_LITERAL(106, 6)   // "isFile"
    },
    "PathInfo",
    "QML.Element",
    "auto",
    "nameChanged",
    "",
    "pathChanged",
    "imageSourceChanged",
    "isFileChanged",
    "name",
    "path",
    "imageSource",
    "isFile"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSPathInfoENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       1,   14, // classinfo
       4,   16, // methods
       4,   44, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   40,    4, 0x06,    5 /* Public */,
       5,    0,   41,    4, 0x06,    6 /* Public */,
       6,    0,   42,    4, 0x06,    7 /* Public */,
       7,    0,   43,    4, 0x06,    8 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       8, QMetaType::QString, 0x00015801, uint(0), 0,
       9, QMetaType::QString, 0x00015801, uint(1), 0,
      10, QMetaType::QUrl, 0x00015801, uint(2), 0,
      11, QMetaType::Bool, 0x00015801, uint(3), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject PathInfo::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSPathInfoENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSPathInfoENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_metaTypeArray<
        // property 'name'
        QString,
        // property 'path'
        QString,
        // property 'imageSource'
        QUrl,
        // property 'isFile'
        bool,
        // Q_OBJECT / Q_GADGET
        PathInfo,
        // method 'nameChanged'
        void,
        // method 'pathChanged'
        void,
        // method 'imageSourceChanged'
        void,
        // method 'isFileChanged'
        void
    >,
    nullptr
} };

void PathInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PathInfo *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->nameChanged(); break;
        case 1: _t->pathChanged(); break;
        case 2: _t->imageSourceChanged(); break;
        case 3: _t->isFileChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PathInfo::*)();
            if (_t _q_method = &PathInfo::nameChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PathInfo::*)();
            if (_t _q_method = &PathInfo::pathChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PathInfo::*)();
            if (_t _q_method = &PathInfo::imageSourceChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PathInfo::*)();
            if (_t _q_method = &PathInfo::isFileChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<PathInfo *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->name(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->path(); break;
        case 2: *reinterpret_cast< QUrl*>(_v) = _t->imageSource(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->isFile(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
    (void)_a;
}

const QMetaObject *PathInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PathInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSPathInfoENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PathInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void PathInfo::nameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void PathInfo::pathChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void PathInfo::imageSourceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void PathInfo::isFileChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
