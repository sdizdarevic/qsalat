/********************************************************************************
** Form generated from reading ui file 'hijri.ui'
**
** Created: Fri Dec 5 11:15:41 2008
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_HIJRI_H
#define UI_HIJRI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_Hijri
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QComboBox *hyearBox;
    QComboBox *hmonthBox;
    QComboBox *hdayBox;
    QGroupBox *groupBox_2;
    QComboBox *jdayBox;
    QComboBox *jmonthBox;
    QLabel *label_4;
    QComboBox *jyearBox;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *convertButton;
    QGroupBox *groupBox_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;

    void setupUi(QDialog *Hijri)
    {
    if (Hijri->objectName().isEmpty())
        Hijri->setObjectName(QString::fromUtf8("Hijri"));
    Hijri->resize(300, 400);
    Hijri->setMinimumSize(QSize(300, 400));
    Hijri->setMaximumSize(QSize(300, 400));
    groupBox = new QGroupBox(Hijri);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    groupBox->setGeometry(QRect(10, 10, 281, 111));
    label = new QLabel(groupBox);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(210, 30, 54, 18));
    label_2 = new QLabel(groupBox);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(120, 30, 54, 18));
    label_3 = new QLabel(groupBox);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setGeometry(QRect(30, 30, 54, 18));
    hyearBox = new QComboBox(groupBox);
    hyearBox->setObjectName(QString::fromUtf8("hyearBox"));
    hyearBox->setGeometry(QRect(20, 60, 75, 27));
    hmonthBox = new QComboBox(groupBox);
    hmonthBox->setObjectName(QString::fromUtf8("hmonthBox"));
    hmonthBox->setEnabled(true);
    hmonthBox->setGeometry(QRect(110, 60, 75, 27));
    hdayBox = new QComboBox(groupBox);
    hdayBox->setObjectName(QString::fromUtf8("hdayBox"));
    hdayBox->setEnabled(false);
    hdayBox->setGeometry(QRect(200, 60, 75, 27));
    groupBox_2 = new QGroupBox(Hijri);
    groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
    groupBox_2->setGeometry(QRect(10, 130, 281, 111));
    jdayBox = new QComboBox(groupBox_2);
    jdayBox->setObjectName(QString::fromUtf8("jdayBox"));
    jdayBox->setEnabled(false);
    jdayBox->setGeometry(QRect(200, 60, 75, 27));
    jmonthBox = new QComboBox(groupBox_2);
    jmonthBox->setObjectName(QString::fromUtf8("jmonthBox"));
    jmonthBox->setEnabled(false);
    jmonthBox->setGeometry(QRect(110, 60, 75, 27));
    label_4 = new QLabel(groupBox_2);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setGeometry(QRect(30, 30, 54, 18));
    jyearBox = new QComboBox(groupBox_2);
    jyearBox->setObjectName(QString::fromUtf8("jyearBox"));
    jyearBox->setEnabled(false);
    jyearBox->setGeometry(QRect(20, 60, 75, 27));
    label_5 = new QLabel(groupBox_2);
    label_5->setObjectName(QString::fromUtf8("label_5"));
    label_5->setGeometry(QRect(120, 30, 54, 18));
    label_6 = new QLabel(groupBox_2);
    label_6->setObjectName(QString::fromUtf8("label_6"));
    label_6->setGeometry(QRect(210, 30, 54, 18));
    convertButton = new QPushButton(Hijri);
    convertButton->setObjectName(QString::fromUtf8("convertButton"));
    convertButton->setGeometry(QRect(210, 360, 80, 28));
    groupBox_3 = new QGroupBox(Hijri);
    groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
    groupBox_3->setGeometry(QRect(10, 250, 281, 80));
    radioButton = new QRadioButton(groupBox_3);
    radioButton->setObjectName(QString::fromUtf8("radioButton"));
    radioButton->setGeometry(QRect(20, 30, 91, 24));
    radioButton->setChecked(true);
    radioButton_2 = new QRadioButton(groupBox_3);
    radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
    radioButton_2->setGeometry(QRect(150, 30, 91, 24));
    radioButton_2->setChecked(false);

    retranslateUi(Hijri);

    QMetaObject::connectSlotsByName(Hijri);
    } // setupUi

    void retranslateUi(QDialog *Hijri)
    {
    Hijri->setWindowTitle(QApplication::translate("Hijri", "Qsalat - date conversion", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("Hijri", "Hijri", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("Hijri", "Day", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("Hijri", "Month", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("Hijri", "Year", 0, QApplication::UnicodeUTF8));
    groupBox_2->setTitle(QApplication::translate("Hijri", "Julian", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("Hijri", "Year", 0, QApplication::UnicodeUTF8));
    label_5->setText(QApplication::translate("Hijri", "Month", 0, QApplication::UnicodeUTF8));
    label_6->setText(QApplication::translate("Hijri", "Day", 0, QApplication::UnicodeUTF8));
    convertButton->setText(QApplication::translate("Hijri", "Convert", 0, QApplication::UnicodeUTF8));
    groupBox_3->setTitle(QApplication::translate("Hijri", "Convertion", 0, QApplication::UnicodeUTF8));
    radioButton->setText(QApplication::translate("Hijri", "Hijri to julian", 0, QApplication::UnicodeUTF8));
    radioButton_2->setText(QApplication::translate("Hijri", "Julian to hijri", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Hijri);
    } // retranslateUi

};

namespace Ui {
    class Hijri: public Ui_Hijri {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HIJRI_H
