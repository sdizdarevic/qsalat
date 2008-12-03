/********************************************************************************
** Form generated from reading ui file 'worldtime.ui'
**
** Created: Tue Dec 2 22:21:37 2008
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_WORLDTIME_H
#define UI_WORLDTIME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>

QT_BEGIN_NAMESPACE

class Ui_WorldTime
{
public:

    void setupUi(QDialog *WorldTime)
    {
    if (WorldTime->objectName().isEmpty())
        WorldTime->setObjectName(QString::fromUtf8("WorldTime"));
    WorldTime->resize(640, 320);
    WorldTime->setMinimumSize(QSize(640, 320));
    WorldTime->setMaximumSize(QSize(640, 320));
    WorldTime->setStyleSheet(QString::fromUtf8("background-image: url(:/images/worldtime/img0.jpg);"));

    retranslateUi(WorldTime);

    QMetaObject::connectSlotsByName(WorldTime);
    } // setupUi

    void retranslateUi(QDialog *WorldTime)
    {
    WorldTime->setWindowTitle(QApplication::translate("WorldTime", "Qsalat - world time", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(WorldTime);
    } // retranslateUi

};

namespace Ui {
    class WorldTime: public Ui_WorldTime {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORLDTIME_H
