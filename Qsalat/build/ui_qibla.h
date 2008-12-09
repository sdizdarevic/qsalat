/********************************************************************************
** Form generated from reading ui file 'qibla.ui'
**
** Created: Tue Dec 9 11:36:45 2008
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_QIBLA_H
#define UI_QIBLA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Qibla
{
public:

    void setupUi(QDialog *Qibla)
    {
    if (Qibla->objectName().isEmpty())
        Qibla->setObjectName(QString::fromUtf8("Qibla"));
    Qibla->resize(300, 400);
    Qibla->setMinimumSize(QSize(300, 400));
    Qibla->setMaximumSize(QSize(300, 400));
    Qibla->setStyleSheet(QString::fromUtf8("background-image: url(:/images/boussole.png);\n"
""));

    retranslateUi(Qibla);

    QMetaObject::connectSlotsByName(Qibla);
    } // setupUi

    void retranslateUi(QDialog *Qibla)
    {
    Qibla->setWindowTitle(QApplication::translate("Qibla", "Qsalat - qibla direction", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Qibla);
    } // retranslateUi

};

namespace Ui {
    class Qibla: public Ui_Qibla {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QIBLA_H
