/****************************************************************************
** Meta object code from reading C++ file 'qlocation.h'
**
** Created: Tue Dec 9 22:11:55 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/qlocation.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qlocation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Qlocation[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      23,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      35,   10,   10,   10, 0x0a,
      65,   10,   10,   10, 0x0a,
      91,   83,   10,   10, 0x0a,
     108,   10,   10,   10, 0x0a,
     127,   10,   10,   10, 0x0a,
     138,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Qlocation[] = {
    "Qlocation\0\0reloadMap()\0updateMap()\0"
    "replyFinished(QNetworkReply*)\0"
    "loadCoordinates()\0address\0geoCode(QString)\0"
    "clearCoordinates()\0showItem()\0"
    "updateLatLng()\0"
};

const QMetaObject Qlocation::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Qlocation,
      qt_meta_data_Qlocation, 0 }
};

const QMetaObject *Qlocation::metaObject() const
{
    return &staticMetaObject;
}

void *Qlocation::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Qlocation))
        return static_cast<void*>(const_cast< Qlocation*>(this));
    if (!strcmp(_clname, "Ui::Location"))
        return static_cast< Ui::Location*>(const_cast< Qlocation*>(this));
    return QDialog::qt_metacast(_clname);
}

int Qlocation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: reloadMap(); break;
        case 1: updateMap(); break;
        case 2: replyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 3: loadCoordinates(); break;
        case 4: geoCode((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: clearCoordinates(); break;
        case 6: showItem(); break;
        case 7: updateLatLng(); break;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Qlocation::reloadMap()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Qlocation::updateMap()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
