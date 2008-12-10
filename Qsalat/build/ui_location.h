/********************************************************************************
** Form generated from reading ui file 'location.ui'
**
** Created: Wed Dec 10 10:01:43 2008
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
    QLineEdit *locationLineEdit;
    QPushButton *searchButton;
    QWebView *webView;
    QLabel *latLabel;
    QLabel *lngLabel;
    QPushButton *cancelButton;
    QPushButton *applyButton;
    QPushButton *okButton;
    QLabel *label_2;

    void setupUi(QDialog *Location)
    {
    if (Location->objectName().isEmpty())
        Location->setObjectName(QString::fromUtf8("Location"));
    Location->resize(301, 450);
    Location->setMinimumSize(QSize(301, 450));
    Location->setMaximumSize(QSize(301, 450));
    label = new QLabel(Location);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(10, 40, 54, 31));
    locationLineEdit = new QLineEdit(Location);
    locationLineEdit->setObjectName(QString::fromUtf8("locationLineEdit"));
    locationLineEdit->setGeometry(QRect(60, 40, 181, 28));
    searchButton = new QPushButton(Location);
    searchButton->setObjectName(QString::fromUtf8("searchButton"));
    searchButton->setGeometry(QRect(250, 40, 41, 28));
    webView = new QWebView(Location);
    webView->setObjectName(QString::fromUtf8("webView"));
    webView->setGeometry(QRect(10, 79, 281, 281));
    webView->setUrl(QUrl("http://www.skanderjabouzi.com/qpray/"));
    latLabel = new QLabel(Location);
    latLabel->setObjectName(QString::fromUtf8("latLabel"));
    latLabel->setGeometry(QRect(10, 380, 141, 20));
    lngLabel = new QLabel(Location);
    lngLabel->setObjectName(QString::fromUtf8("lngLabel"));
    lngLabel->setGeometry(QRect(160, 380, 131, 20));
    cancelButton = new QPushButton(Location);
    cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
    cancelButton->setGeometry(QRect(219, 410, 71, 28));
    applyButton = new QPushButton(Location);
    applyButton->setObjectName(QString::fromUtf8("applyButton"));
    applyButton->setGeometry(QRect(150, 410, 61, 28));
    okButton = new QPushButton(Location);
    okButton->setObjectName(QString::fromUtf8("okButton"));
    okButton->setGeometry(QRect(80, 410, 61, 28));
    label_2 = new QLabel(Location);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(10, 10, 281, 21));
    QFont font;
    font.setPointSize(11);
    font.setBold(true);
    font.setWeight(75);
    label_2->setFont(font);
    label_2->setAlignment(Qt::AlignCenter);

    retranslateUi(Location);

    QMetaObject::connectSlotsByName(Location);
    } // setupUi

    void retranslateUi(QDialog *Location)
    {
    Location->setWindowTitle(QApplication::translate("Location", "Qsalat - location", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("Location", "Location", 0, QApplication::UnicodeUTF8));
    searchButton->setText(QApplication::translate("Location", "Search", 0, QApplication::UnicodeUTF8));
    latLabel->setText(QApplication::translate("Location", "0.0", 0, QApplication::UnicodeUTF8));

#ifndef QT_NO_STATUSTIP
    lngLabel->setStatusTip(QApplication::translate("Location", "Longitude", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP

    lngLabel->setText(QApplication::translate("Location", "0.0", 0, QApplication::UnicodeUTF8));
    cancelButton->setText(QApplication::translate("Location", "Cancel", 0, QApplication::UnicodeUTF8));
    applyButton->setText(QApplication::translate("Location", "Apply", 0, QApplication::UnicodeUTF8));
    okButton->setText(QApplication::translate("Location", "OK", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("Location", "Set your location", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Location);
    } // retranslateUi

};

namespace Ui {
    class Location: public Ui_Location {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOCATION_H
