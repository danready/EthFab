/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../UniversalPMACSender/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[26];
    char stringdata[457];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 11),
QT_MOC_LITERAL(2, 23, 0),
QT_MOC_LITERAL(3, 24, 6),
QT_MOC_LITERAL(4, 31, 28),
QT_MOC_LITERAL(5, 60, 10),
QT_MOC_LITERAL(6, 71, 26),
QT_MOC_LITERAL(7, 98, 24),
QT_MOC_LITERAL(8, 123, 10),
QT_MOC_LITERAL(9, 134, 7),
QT_MOC_LITERAL(10, 142, 7),
QT_MOC_LITERAL(11, 150, 23),
QT_MOC_LITERAL(12, 174, 35),
QT_MOC_LITERAL(13, 210, 43),
QT_MOC_LITERAL(14, 254, 33),
QT_MOC_LITERAL(15, 288, 18),
QT_MOC_LITERAL(16, 307, 10),
QT_MOC_LITERAL(17, 318, 12),
QT_MOC_LITERAL(18, 331, 17),
QT_MOC_LITERAL(19, 349, 12),
QT_MOC_LITERAL(20, 362, 17),
QT_MOC_LITERAL(21, 380, 9),
QT_MOC_LITERAL(22, 390, 14),
QT_MOC_LITERAL(23, 405, 13),
QT_MOC_LITERAL(24, 419, 15),
QT_MOC_LITERAL(25, 435, 20)
    },
    "MainWindow\0readTcpData\0\0Errore\0"
    "QAbstractSocket::SocketError\0sock_error\0"
    "on_actionConnect_triggered\0"
    "AppendMessageToQtextEdit\0QTextEdit*\0"
    "MexArea\0Message\0on_SendBaseCase_clicked\0"
    "on_pushButton_SendStructure_clicked\0"
    "on_actionDeltaTau_PMAC_Geobrick_2_triggered\0"
    "on_actionTest_LocalHost_triggered\0"
    "HumanReadableError\0error_code\0"
    "DecodeErrors\0std::vector<int>&\0"
    "decode_array\0converting_number\0DecodeSum\0"
    "converting_sum\0table_pointer\0"
    "PartialDecoding\0tmp_vector_reference\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08,
       3,    1,   75,    2, 0x08,
       6,    0,   78,    2, 0x08,
       7,    2,   79,    2, 0x08,
      11,    0,   84,    2, 0x08,
      12,    0,   85,    2, 0x08,
      13,    0,   86,    2, 0x08,
      14,    0,   87,    2, 0x08,
      15,    1,   88,    2, 0x08,
      17,    2,   91,    2, 0x08,
      21,    3,   96,    2, 0x08,
      24,    2,  103,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8, QMetaType::QString,    9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, 0x80000000 | 18, QMetaType::UInt,   19,   20,
    QMetaType::Void, 0x80000000 | 18, QMetaType::UInt, QMetaType::Int,   19,   22,   23,
    QMetaType::Void, 0x80000000 | 18, QMetaType::Int,   25,   22,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->readTcpData(); break;
        case 1: _t->Errore((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 2: _t->on_actionConnect_triggered(); break;
        case 3: _t->AppendMessageToQtextEdit((*reinterpret_cast< QTextEdit*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->on_SendBaseCase_clicked(); break;
        case 5: _t->on_pushButton_SendStructure_clicked(); break;
        case 6: _t->on_actionDeltaTau_PMAC_Geobrick_2_triggered(); break;
        case 7: _t->on_actionTest_LocalHost_triggered(); break;
        case 8: _t->HumanReadableError((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->DecodeErrors((*reinterpret_cast< std::vector<int>(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 10: _t->DecodeSum((*reinterpret_cast< std::vector<int>(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 11: _t->PartialDecoding((*reinterpret_cast< std::vector<int>(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QTextEdit* >(); break;
            }
            break;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
