/********************************************************************************
** Form generated from reading ui file 'location.ui'
**
** Created: Tue Dec 2 22:21:37 2008
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_LOCATION_H
#define UI_LOCATION_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_Location
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QWebView *webView;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Location)
    {
    if (Location->objectName().isEmpty())
        Location->setObjectName(QString::fromUtf8("Location"));
    Location->resize(301, 421);
    Location->setMinimumSize(QSize(301, 421));
    Location->setMaximumSize(QSize(301, 421));
    label = new QLabel(Location);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(10, 10, 54, 31));
    lineEdit = new QLineEdit(Location);
    lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
    lineEdit->setGeometry(QRect(60, 10, 181, 28));
    pushButton = new QPushButton(Location);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));
    pushButton->setGeometry(QRect(250, 10, 41, 28));
    webView = new QWebView(Location);
    webView->setObjectName(QString::fromUtf8("webView"));
    webView->setGeometry(QRect(10, 49, 281, 281));
    webView->setUrl(QUrl("http://www.skanderjabouzi.com/qpray/"));
    label_2 = new QLabel(Location);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(10, 350, 141, 20));
    label_3 = new QLabel(Location);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setGeometry(QRect(160, 350, 131, 20));
    pushButton_2 = new QPushButton(Location);
    pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
    pushButton_2->setGeometry(QRect(229, 390, 61, 28));

    retranslateUi(Location);

    QMetaObject::connectSlotsByName(Location);
    } // setupUi

    void retranslateUi(QDialog *Location)
    {
    Location->setWindowTitle(QApplication::translate("Location", "Qsalat - location", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("Location", "Search", 0, QApplication::UnicodeUTF8));
    pushButton->setText(QApplication::translate("Location", "Go", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("Location", "0.0", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("Location", "0.0", 0, QApplication::UnicodeUTF8));
    pushButton_2->setText(QApplication::translate("Location", "Apply", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Location);
    } // retranslateUi

};

namespace Ui {
    class Location: public Ui_Location {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOCATION_H
