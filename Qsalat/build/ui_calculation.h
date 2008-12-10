/********************************************************************************
** Form generated from reading ui file 'calculation.ui'
**
** Created: Tue Dec 9 22:11:35 2008
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
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Calculation
{
public:
    QGroupBox *groupBox;
    QComboBox *calcBox;
    QLabel *label;
    QGroupBox *groupBox_2;
    QRadioButton *shafiiButton;
    QRadioButton *hanafiButton;
    QLabel *label_2;
    QGroupBox *groupBox_3;
    QSpinBox *duhrBox;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QGroupBox *groupBox_4;
    QCheckBox *highLatBox;
    QLabel *label_10;
    QPushButton *cancelButton;
    QPushButton *saveButton;
    QGroupBox *groupBox_5;
    QSpinBox *hijriBox;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_7;
    QPushButton *okButton;

    void setupUi(QDialog *Calculation)
    {
    if (Calculation->objectName().isEmpty())
        Calculation->setObjectName(QString::fromUtf8("Calculation"));
    Calculation->resize(363, 450);
    Calculation->setMinimumSize(QSize(363, 450));
    Calculation->setMaximumSize(QSize(363, 450));
    groupBox = new QGroupBox(Calculation);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    groupBox->setGeometry(QRect(10, 40, 341, 111));
    calcBox = new QComboBox(groupBox);
    calcBox->setObjectName(QString::fromUtf8("calcBox"));
    calcBox->setGeometry(QRect(20, 60, 311, 31));
    calcBox->setEditable(false);
    calcBox->setMaxVisibleItems(7);
    calcBox->setMaxCount(7);
    label = new QLabel(groupBox);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(20, 30, 301, 18));
    groupBox_2 = new QGroupBox(Calculation);
    groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
    groupBox_2->setGeometry(QRect(190, 160, 161, 111));
    shafiiButton = new QRadioButton(groupBox_2);
    shafiiButton->setObjectName(QString::fromUtf8("shafiiButton"));
    shafiiButton->setGeometry(QRect(20, 60, 91, 24));
    shafiiButton->setChecked(true);
    hanafiButton = new QRadioButton(groupBox_2);
    hanafiButton->setObjectName(QString::fromUtf8("hanafiButton"));
    hanafiButton->setGeometry(QRect(90, 60, 91, 24));
    label_2 = new QLabel(groupBox_2);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(10, 30, 141, 18));
    groupBox_3 = new QGroupBox(Calculation);
    groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
    groupBox_3->setGeometry(QRect(10, 160, 171, 111));
    duhrBox = new QSpinBox(groupBox_3);
    duhrBox->setObjectName(QString::fromUtf8("duhrBox"));
    duhrBox->setGeometry(QRect(40, 60, 61, 28));
    duhrBox->setMaximum(60);
    label_3 = new QLabel(groupBox_3);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setGeometry(QRect(10, 30, 141, 18));
    label_4 = new QLabel(groupBox_3);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setGeometry(QRect(10, 59, 41, 31));
    label_5 = new QLabel(groupBox_3);
    label_5->setObjectName(QString::fromUtf8("label_5"));
    label_5->setGeometry(QRect(110, 60, 51, 31));
    groupBox_4 = new QGroupBox(Calculation);
    groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
    groupBox_4->setGeometry(QRect(190, 280, 161, 111));
    highLatBox = new QCheckBox(groupBox_4);
    highLatBox->setObjectName(QString::fromUtf8("highLatBox"));
    highLatBox->setGeometry(QRect(20, 60, 141, 24));
    label_10 = new QLabel(groupBox_4);
    label_10->setObjectName(QString::fromUtf8("label_10"));
    label_10->setGeometry(QRect(10, 30, 141, 18));
    cancelButton = new QPushButton(Calculation);
    cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
    cancelButton->setGeometry(QRect(280, 410, 71, 28));
    saveButton = new QPushButton(Calculation);
    saveButton->setObjectName(QString::fromUtf8("saveButton"));
    saveButton->setGeometry(QRect(200, 410, 71, 28));
    groupBox_5 = new QGroupBox(Calculation);
    groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
    groupBox_5->setGeometry(QRect(10, 280, 171, 111));
    hijriBox = new QSpinBox(groupBox_5);
    hijriBox->setObjectName(QString::fromUtf8("hijriBox"));
    hijriBox->setGeometry(QRect(40, 60, 61, 28));
    hijriBox->setMinimum(-2);
    hijriBox->setMaximum(2);
    label_6 = new QLabel(groupBox_5);
    label_6->setObjectName(QString::fromUtf8("label_6"));
    label_6->setGeometry(QRect(10, 30, 141, 18));
    label_8 = new QLabel(groupBox_5);
    label_8->setObjectName(QString::fromUtf8("label_8"));
    label_8->setGeometry(QRect(10, 60, 41, 31));
    label_9 = new QLabel(groupBox_5);
    label_9->setObjectName(QString::fromUtf8("label_9"));
    label_9->setGeometry(QRect(110, 60, 51, 31));
    label_7 = new QLabel(Calculation);
    label_7->setObjectName(QString::fromUtf8("label_7"));
    label_7->setGeometry(QRect(10, 10, 341, 21));
    QFont font;
    font.setPointSize(11);
    font.setBold(true);
    font.setWeight(75);
    label_7->setFont(font);
    label_7->setAlignment(Qt::AlignCenter);
    okButton = new QPushButton(Calculation);
    okButton->setObjectName(QString::fromUtf8("okButton"));
    okButton->setGeometry(QRect(120, 410, 71, 28));

    retranslateUi(Calculation);

    calcBox->setCurrentIndex(-1);


    QMetaObject::connectSlotsByName(Calculation);
    } // setupUi

    void retranslateUi(QDialog *Calculation)
    {
    Calculation->setWindowTitle(QApplication::translate("Calculation", "Qsalat - calculation options", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("Calculation", "Calculation methods", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("Calculation", "Select calculation method for fajr, maghreb and isha", 0, QApplication::UnicodeUTF8));
    groupBox_2->setTitle(QApplication::translate("Calculation", "Asr options", 0, QApplication::UnicodeUTF8));
    shafiiButton->setText(QApplication::translate("Calculation", "Shafii", 0, QApplication::UnicodeUTF8));
    hanafiButton->setText(QApplication::translate("Calculation", "Hanafi", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("Calculation", "Select asr method", 0, QApplication::UnicodeUTF8));
    groupBox_3->setTitle(QApplication::translate("Calculation", "Duhr added minutes", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("Calculation", "Set duhr custom time", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("Calculation", "Add", 0, QApplication::UnicodeUTF8));
    label_5->setText(QApplication::translate("Calculation", "minutes", 0, QApplication::UnicodeUTF8));
    groupBox_4->setTitle(QApplication::translate("Calculation", "Higher Latitudes option", 0, QApplication::UnicodeUTF8));
    highLatBox->setText(QApplication::translate("Calculation", "Higher Latitudes", 0, QApplication::UnicodeUTF8));
    label_10->setText(QApplication::translate("Calculation", "Set high Latitudes option", 0, QApplication::UnicodeUTF8));
    cancelButton->setText(QApplication::translate("Calculation", "Cancel", 0, QApplication::UnicodeUTF8));
    saveButton->setText(QApplication::translate("Calculation", "Save", 0, QApplication::UnicodeUTF8));
    groupBox_5->setTitle(QApplication::translate("Calculation", "Hijri date adjustment", 0, QApplication::UnicodeUTF8));
    label_6->setText(QApplication::translate("Calculation", "Set hijri custom date", 0, QApplication::UnicodeUTF8));
    label_8->setText(QApplication::translate("Calculation", "Add", 0, QApplication::UnicodeUTF8));
    label_9->setText(QApplication::translate("Calculation", "days", 0, QApplication::UnicodeUTF8));
    label_7->setText(QApplication::translate("Calculation", "Prayer calculation options", 0, QApplication::UnicodeUTF8));
    okButton->setText(QApplication::translate("Calculation", "OK", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Calculation);
    } // retranslateUi

};

namespace Ui {
    class Calculation: public Ui_Calculation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATION_H
