/********************************************************************************
** Form generated from reading ui file 'calculation.ui'
**
** Created: Tue Dec 2 22:38:03 2008
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CALCULATION_H
#define UI_CALCULATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Calculation
{
public:
    QGroupBox *groupBox;
    QComboBox *calcBox;
    QGroupBox *groupBox_2;
    QRadioButton *shafiiButton;
    QRadioButton *hanafiButton;
    QGroupBox *groupBox_3;
    QSpinBox *duhrBox;
    QGroupBox *groupBox_4;
    QCheckBox *highLatBox;
    QPushButton *cancelButton;
    QPushButton *saveButton;
    QGroupBox *groupBox_5;
    QSpinBox *hijriBox;

    void setupUi(QDialog *Calculation)
    {
    if (Calculation->objectName().isEmpty())
        Calculation->setObjectName(QString::fromUtf8("Calculation"));
    Calculation->resize(363, 280);
    Calculation->setMinimumSize(QSize(363, 280));
    Calculation->setMaximumSize(QSize(363, 280));
    groupBox = new QGroupBox(Calculation);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    groupBox->setGeometry(QRect(10, 10, 171, 81));
    calcBox = new QComboBox(groupBox);
    calcBox->setObjectName(QString::fromUtf8("calcBox"));
    calcBox->setGeometry(QRect(20, 30, 131, 31));
    calcBox->setEditable(false);
    calcBox->setMaxVisibleItems(7);
    calcBox->setMaxCount(7);
    groupBox_2 = new QGroupBox(Calculation);
    groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
    groupBox_2->setGeometry(QRect(190, 10, 161, 80));
    shafiiButton = new QRadioButton(groupBox_2);
    shafiiButton->setObjectName(QString::fromUtf8("shafiiButton"));
    shafiiButton->setGeometry(QRect(20, 30, 91, 24));
    shafiiButton->setChecked(true);
    hanafiButton = new QRadioButton(groupBox_2);
    hanafiButton->setObjectName(QString::fromUtf8("hanafiButton"));
    hanafiButton->setGeometry(QRect(90, 30, 91, 24));
    groupBox_3 = new QGroupBox(Calculation);
    groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
    groupBox_3->setGeometry(QRect(10, 100, 171, 80));
    duhrBox = new QSpinBox(groupBox_3);
    duhrBox->setObjectName(QString::fromUtf8("duhrBox"));
    duhrBox->setGeometry(QRect(20, 30, 121, 28));
    duhrBox->setMaximum(60);
    groupBox_4 = new QGroupBox(Calculation);
    groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
    groupBox_4->setGeometry(QRect(190, 100, 161, 80));
    highLatBox = new QCheckBox(groupBox_4);
    highLatBox->setObjectName(QString::fromUtf8("highLatBox"));
    highLatBox->setGeometry(QRect(20, 30, 141, 24));
    cancelButton = new QPushButton(Calculation);
    cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
    cancelButton->setGeometry(QRect(280, 220, 71, 28));
    saveButton = new QPushButton(Calculation);
    saveButton->setObjectName(QString::fromUtf8("saveButton"));
    saveButton->setGeometry(QRect(200, 220, 71, 28));
    groupBox_5 = new QGroupBox(Calculation);
    groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
    groupBox_5->setGeometry(QRect(10, 190, 171, 80));
    hijriBox = new QSpinBox(groupBox_5);
    hijriBox->setObjectName(QString::fromUtf8("hijriBox"));
    hijriBox->setGeometry(QRect(20, 30, 121, 28));
    hijriBox->setMinimum(-2);
    hijriBox->setMaximum(2);

    retranslateUi(Calculation);

    calcBox->setCurrentIndex(-1);


    QMetaObject::connectSlotsByName(Calculation);
    } // setupUi

    void retranslateUi(QDialog *Calculation)
    {
    Calculation->setWindowTitle(QApplication::translate("Calculation", "Qsalat - calculation options", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("Calculation", "Calculation methods", 0, QApplication::UnicodeUTF8));
    groupBox_2->setTitle(QApplication::translate("Calculation", "Asr options", 0, QApplication::UnicodeUTF8));
    shafiiButton->setText(QApplication::translate("Calculation", "Shafii", 0, QApplication::UnicodeUTF8));
    hanafiButton->setText(QApplication::translate("Calculation", "Hanafi", 0, QApplication::UnicodeUTF8));
    groupBox_3->setTitle(QApplication::translate("Calculation", "Duhr added minutes", 0, QApplication::UnicodeUTF8));
    groupBox_4->setTitle(QApplication::translate("Calculation", "Higher Latitudes option", 0, QApplication::UnicodeUTF8));
    highLatBox->setText(QApplication::translate("Calculation", "Higher Latitudes", 0, QApplication::UnicodeUTF8));
    cancelButton->setText(QApplication::translate("Calculation", "Cancel", 0, QApplication::UnicodeUTF8));
    saveButton->setText(QApplication::translate("Calculation", "Save", 0, QApplication::UnicodeUTF8));
    groupBox_5->setTitle(QApplication::translate("Calculation", "Hijri date adjustment", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Calculation);
    } // retranslateUi

};

namespace Ui {
    class Calculation: public Ui_Calculation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATION_H
