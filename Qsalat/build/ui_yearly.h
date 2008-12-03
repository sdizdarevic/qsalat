/********************************************************************************
** Form generated from reading ui file 'yearly.ui'
**
** Created: Tue Dec 2 22:32:14 2008
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_YEARLY_H
#define UI_YEARLY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Yearly
{
public:
    QGroupBox *groupBox;
    QLabel *label_3;
    QComboBox *yearBox;
    QPushButton *generateButton;
    QGroupBox *groupBox_2;
    QPushButton *selectButton;
    QLineEdit *pathEdit;
    QLabel *label;

    void setupUi(QDialog *Yearly)
    {
    if (Yearly->objectName().isEmpty())
        Yearly->setObjectName(QString::fromUtf8("Yearly"));
    Yearly->resize(352, 266);
    Yearly->setMinimumSize(QSize(352, 266));
    Yearly->setMaximumSize(QSize(352, 266));
    groupBox = new QGroupBox(Yearly);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    groupBox->setGeometry(QRect(10, 119, 331, 81));
    label_3 = new QLabel(groupBox);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setGeometry(QRect(10, 30, 91, 31));
    yearBox = new QComboBox(groupBox);
    yearBox->setObjectName(QString::fromUtf8("yearBox"));
    yearBox->setGeometry(QRect(190, 30, 131, 27));
    generateButton = new QPushButton(Yearly);
    generateButton->setObjectName(QString::fromUtf8("generateButton"));
    generateButton->setGeometry(QRect(260, 220, 80, 28));
    groupBox_2 = new QGroupBox(Yearly);
    groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
    groupBox_2->setGeometry(QRect(10, 20, 331, 80));
    selectButton = new QPushButton(groupBox_2);
    selectButton->setObjectName(QString::fromUtf8("selectButton"));
    selectButton->setGeometry(QRect(249, 30, 71, 28));
    pathEdit = new QLineEdit(groupBox_2);
    pathEdit->setObjectName(QString::fromUtf8("pathEdit"));
    pathEdit->setGeometry(QRect(92, 30, 141, 28));
    label = new QLabel(groupBox_2);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(10, 30, 81, 31));

    retranslateUi(Yearly);

    QMetaObject::connectSlotsByName(Yearly);
    } // setupUi

    void retranslateUi(QDialog *Yearly)
    {
    Yearly->setWindowTitle(QApplication::translate("Yearly", "Qsalat - yearly prayer times", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("Yearly", "Yearly generation", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("Yearly", "Select a year", 0, QApplication::UnicodeUTF8));
    generateButton->setText(QApplication::translate("Yearly", "Generate", 0, QApplication::UnicodeUTF8));
    groupBox_2->setTitle(QApplication::translate("Yearly", "Folder", 0, QApplication::UnicodeUTF8));
    selectButton->setText(QString());
    label->setText(QApplication::translate("Yearly", "Select folder", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Yearly);
    } // retranslateUi

};

namespace Ui {
    class Yearly: public Ui_Yearly {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YEARLY_H
