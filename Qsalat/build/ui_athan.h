/********************************************************************************
** Form generated from reading ui file 'athan.ui'
**
** Created: Tue Dec 2 14:55:43 2008
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_ATHAN_H
#define UI_ATHAN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>

QT_BEGIN_NAMESPACE

class Ui_Audio
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_8;
    QLineEdit *lineEdit_4;
    QLabel *label_4;
    QGroupBox *groupBox_2;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QGroupBox *groupBox_3;
    QSlider *horizontalSlider_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QSlider *horizontalSlider_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QDialog *Audio)
    {
    if (Audio->objectName().isEmpty())
        Audio->setObjectName(QString::fromUtf8("Audio"));
    Audio->resize(484, 392);
    groupBox = new QGroupBox(Audio);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    groupBox->setGeometry(QRect(10, 10, 461, 141));
    pushButton_5 = new QPushButton(groupBox);
    pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
    pushButton_5->setGeometry(QRect(360, 20, 80, 28));
    pushButton_6 = new QPushButton(groupBox);
    pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
    pushButton_6->setGeometry(QRect(360, 60, 80, 28));
    lineEdit = new QLineEdit(groupBox);
    lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
    lineEdit->setGeometry(QRect(120, 20, 231, 28));
    lineEdit_2 = new QLineEdit(groupBox);
    lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
    lineEdit_2->setGeometry(QRect(120, 60, 231, 28));
    label = new QLabel(groupBox);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(10, 17, 101, 31));
    label_2 = new QLabel(groupBox);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(10, 60, 101, 31));
    pushButton_8 = new QPushButton(groupBox);
    pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
    pushButton_8->setGeometry(QRect(360, 100, 80, 28));
    lineEdit_4 = new QLineEdit(groupBox);
    lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
    lineEdit_4->setGeometry(QRect(120, 100, 231, 28));
    label_4 = new QLabel(groupBox);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setGeometry(QRect(10, 97, 101, 31));
    groupBox_2 = new QGroupBox(Audio);
    groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
    groupBox_2->setGeometry(QRect(10, 160, 461, 51));
    checkBox = new QCheckBox(groupBox_2);
    checkBox->setObjectName(QString::fromUtf8("checkBox"));
    checkBox->setGeometry(QRect(20, 20, 191, 24));
    checkBox_2 = new QCheckBox(groupBox_2);
    checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
    checkBox_2->setGeometry(QRect(280, 20, 171, 24));
    groupBox_3 = new QGroupBox(Audio);
    groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
    groupBox_3->setGeometry(QRect(10, 220, 461, 111));
    horizontalSlider_3 = new QSlider(groupBox_3);
    horizontalSlider_3->setObjectName(QString::fromUtf8("horizontalSlider_3"));
    horizontalSlider_3->setGeometry(QRect(20, 30, 421, 20));
    horizontalSlider_3->setOrientation(Qt::Horizontal);
    pushButton_2 = new QPushButton(groupBox_3);
    pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
    pushButton_2->setGeometry(QRect(20, 60, 41, 28));
    pushButton = new QPushButton(groupBox_3);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));
    pushButton->setGeometry(QRect(80, 60, 41, 28));
    horizontalSlider_2 = new QSlider(groupBox_3);
    horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
    horizontalSlider_2->setGeometry(QRect(320, 70, 121, 16));
    horizontalSlider_2->setOrientation(Qt::Horizontal);
    pushButton_3 = new QPushButton(Audio);
    pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
    pushButton_3->setGeometry(QRect(390, 350, 80, 28));
    pushButton_4 = new QPushButton(Audio);
    pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
    pushButton_4->setGeometry(QRect(290, 350, 80, 28));

    retranslateUi(Audio);

    QMetaObject::connectSlotsByName(Audio);
    } // setupUi

    void retranslateUi(QDialog *Audio)
    {
    Audio->setWindowTitle(QApplication::translate("Audio", "Qsalat - audio", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("Audio", "Audio option", 0, QApplication::UnicodeUTF8));
    pushButton_5->setText(QApplication::translate("Audio", "Select", 0, QApplication::UnicodeUTF8));
    pushButton_6->setText(QApplication::translate("Audio", "Select", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("Audio", "Regular prayer", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("Audio", "Fajr prayer", 0, QApplication::UnicodeUTF8));
    pushButton_8->setText(QApplication::translate("Audio", "Select", 0, QApplication::UnicodeUTF8));
    lineEdit_4->setText(QString());
    label_4->setText(QApplication::translate("Audio", "Dua", 0, QApplication::UnicodeUTF8));
    groupBox_2->setTitle(QApplication::translate("Audio", "Play options", 0, QApplication::UnicodeUTF8));
    checkBox->setText(QApplication::translate("Audio", "Play athan audio", 0, QApplication::UnicodeUTF8));
    checkBox_2->setText(QApplication::translate("Audio", "Play dua audio", 0, QApplication::UnicodeUTF8));
    groupBox_3->setTitle(QApplication::translate("Audio", "Player", 0, QApplication::UnicodeUTF8));
    pushButton_2->setText(QString());
    pushButton->setText(QString());
    pushButton_3->setText(QApplication::translate("Audio", "Cancel", 0, QApplication::UnicodeUTF8));
    pushButton_4->setText(QApplication::translate("Audio", "Save", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Audio);
    } // retranslateUi

};

namespace Ui {
    class Audio: public Ui_Audio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATHAN_H
