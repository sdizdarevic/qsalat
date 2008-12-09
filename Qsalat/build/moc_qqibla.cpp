/****************************************************************************
** Meta object code from reading C++ file 'qqibla.h'
**
** Created: Tue Dec 9 13:20:33 2008
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/qqibla.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qqibla.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Qqibla[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets

       0        // eod
};

static const char qt_meta_stringdata_Qqibla[] = {
    "Qqibla\0"
};

const QMetaObject Qqibla::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Qqibla,
      qt_meta_data_Qqibla, 0 }
};

const QMetaObject *Qqibla::metaObject() const
{
    return &staticMetaObject;
}

void *Qqibla::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Qqibla))
        return static_cast<void*>(const_cast< Qqibla*>(this));
    if (!strcmp(_clname, "Ui::Qibla"))
        return static_cast< Ui::Qibla*>(const_cast< Qqibla*>(this));
    return QDialog::qt_metacast(_clname);
}

int Qqibla::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
