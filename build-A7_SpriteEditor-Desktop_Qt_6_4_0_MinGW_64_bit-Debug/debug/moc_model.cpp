/****************************************************************************
** Meta object code from reading C++ file 'model.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../A7_SpriteEditor/model.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'model.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_Model_t {
    uint offsetsAndSizes[48];
    char stringdata0[6];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[13];
    char stringdata4[12];
    char stringdata5[18];
    char stringdata6[6];
    char stringdata7[14];
    char stringdata8[15];
    char stringdata9[12];
    char stringdata10[13];
    char stringdata11[20];
    char stringdata12[18];
    char stringdata13[4];
    char stringdata14[4];
    char stringdata15[19];
    char stringdata16[6];
    char stringdata17[6];
    char stringdata18[16];
    char stringdata19[10];
    char stringdata20[11];
    char stringdata21[12];
    char stringdata22[5];
    char stringdata23[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Model_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_Model_t qt_meta_stringdata_Model = {
    {
        QT_MOC_LITERAL(0, 5),  // "Model"
        QT_MOC_LITERAL(6, 11),  // "saveProject"
        QT_MOC_LITERAL(18, 0),  // ""
        QT_MOC_LITERAL(19, 12),  // "QJsonObject&"
        QT_MOC_LITERAL(32, 11),  // "thisProject"
        QT_MOC_LITERAL(44, 17),  // "frameEditorUpdate"
        QT_MOC_LITERAL(62, 5),  // "Frame"
        QT_MOC_LITERAL(68, 13),  // "previewUpdate"
        QT_MOC_LITERAL(82, 14),  // "QList<QPixmap>"
        QT_MOC_LITERAL(97, 11),  // "loadProject"
        QT_MOC_LITERAL(109, 12),  // "otherProject"
        QT_MOC_LITERAL(122, 19),  // "retrieveJsonProject"
        QT_MOC_LITERAL(142, 17),  // "receivePixelClick"
        QT_MOC_LITERAL(160, 3),  // "row"
        QT_MOC_LITERAL(164, 3),  // "col"
        QT_MOC_LITERAL(168, 18),  // "updateCurrentColor"
        QT_MOC_LITERAL(187, 5),  // "Pixel"
        QT_MOC_LITERAL(193, 5),  // "pixel"
        QT_MOC_LITERAL(199, 15),  // "updateBrushSize"
        QT_MOC_LITERAL(215, 9),  // "brushSize"
        QT_MOC_LITERAL(225, 10),  // "changeTool"
        QT_MOC_LITERAL(236, 11),  // "Model::Tool"
        QT_MOC_LITERAL(248, 4),  // "tool"
        QT_MOC_LITERAL(253, 8)   // "addFrame"
    },
    "Model",
    "saveProject",
    "",
    "QJsonObject&",
    "thisProject",
    "frameEditorUpdate",
    "Frame",
    "previewUpdate",
    "QList<QPixmap>",
    "loadProject",
    "otherProject",
    "retrieveJsonProject",
    "receivePixelClick",
    "row",
    "col",
    "updateCurrentColor",
    "Pixel",
    "pixel",
    "updateBrushSize",
    "brushSize",
    "changeTool",
    "Model::Tool",
    "tool",
    "addFrame"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_Model[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   74,    2, 0x06,    1 /* Public */,
       5,    1,   77,    2, 0x06,    3 /* Public */,
       7,    1,   80,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    1,   83,    2, 0x0a,    7 /* Public */,
      11,    0,   86,    2, 0x0a,    9 /* Public */,
      12,    2,   87,    2, 0x0a,   10 /* Public */,
      15,    1,   92,    2, 0x0a,   13 /* Public */,
      18,    1,   95,    2, 0x0a,   15 /* Public */,
      20,    1,   98,    2, 0x0a,   17 /* Public */,
      23,    0,  101,    2, 0x0a,   19 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 8,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   13,   14,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void, QMetaType::Int,   19,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Model::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Model.offsetsAndSizes,
    qt_meta_data_Model,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_Model_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Model, std::true_type>,
        // method 'saveProject'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonObject &, std::false_type>,
        // method 'frameEditorUpdate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Frame, std::false_type>,
        // method 'previewUpdate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<QPixmap>, std::false_type>,
        // method 'loadProject'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QJsonObject &, std::false_type>,
        // method 'retrieveJsonProject'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'receivePixelClick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'updateCurrentColor'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Pixel, std::false_type>,
        // method 'updateBrushSize'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'changeTool'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Model::Tool, std::false_type>,
        // method 'addFrame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Model::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Model *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->saveProject((*reinterpret_cast< std::add_pointer_t<QJsonObject&>>(_a[1]))); break;
        case 1: _t->frameEditorUpdate((*reinterpret_cast< std::add_pointer_t<Frame>>(_a[1]))); break;
        case 2: _t->previewUpdate((*reinterpret_cast< std::add_pointer_t<QList<QPixmap>>>(_a[1]))); break;
        case 3: _t->loadProject((*reinterpret_cast< std::add_pointer_t<QJsonObject&>>(_a[1]))); break;
        case 4: _t->retrieveJsonProject(); break;
        case 5: _t->receivePixelClick((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 6: _t->updateCurrentColor((*reinterpret_cast< std::add_pointer_t<Pixel>>(_a[1]))); break;
        case 7: _t->updateBrushSize((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->changeTool((*reinterpret_cast< std::add_pointer_t<Model::Tool>>(_a[1]))); break;
        case 9: _t->addFrame(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QList<QPixmap> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Model::*)(QJsonObject & );
            if (_t _q_method = &Model::saveProject; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Model::*)(Frame );
            if (_t _q_method = &Model::frameEditorUpdate; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Model::*)(QVector<QPixmap> );
            if (_t _q_method = &Model::previewUpdate; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *Model::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Model::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Model.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Model::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Model::saveProject(QJsonObject & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Model::frameEditorUpdate(Frame _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Model::previewUpdate(QVector<QPixmap> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
