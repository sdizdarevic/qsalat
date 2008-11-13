/********************************************************************************
** Form generated from reading ui file 'salat.ui'
**
** Created: Wed Nov 12 16:35:55 2008
**      by: Qt User Interface Compiler version 4.4.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_SALAT_H
#define UI_SALAT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Salat
{
public:
    QAction *actionQuit;
    QAction *actionHide;
    QAction *actionHijri_date;
    QAction *actionQibla_direction;
    QAction *actionLocation;
    QAction *actionAudio;
    QAction *actionCustom_option;
    QAction *actionWorld_time;
    QAction *actionAbout_Qsalat;
    QAction *actionAbout_QT;
    QAction *actionCalculation_methods;
    QAction *actionWorld_time_2;
    QWidget *centralwidget;
    QWidget *widget;
    QLabel *label_fajr;
    QLabel *label_asr;
    QLabel *label_isha;
    QLabel *label_duhr;
    QLabel *label_maghreb;
    QLabel *label_location;
    QLabel *label_hijri;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuTools;
    QMenu *menuExtra;
    QMenu *menuAbout;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Salat)
    {
    if (Salat->objectName().isEmpty())
        Salat->setObjectName(QString::fromUtf8("Salat"));
    Salat->resize(300, 461);
    Salat->setMinimumSize(QSize(300, 461));
    Salat->setMaximumSize(QSize(300, 461));
    Salat->setStyleSheet(QString::fromUtf8(""));
    actionQuit = new QAction(Salat);
    actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
    actionHide = new QAction(Salat);
    actionHide->setObjectName(QString::fromUtf8("actionHide"));
    actionHijri_date = new QAction(Salat);
    actionHijri_date->setObjectName(QString::fromUtf8("actionHijri_date"));
    actionQibla_direction = new QAction(Salat);
    actionQibla_direction->setObjectName(QString::fromUtf8("actionQibla_direction"));
    actionLocation = new QAction(Salat);
    actionLocation->setObjectName(QString::fromUtf8("actionLocation"));
    actionAudio = new QAction(Salat);
    actionAudio->setObjectName(QString::fromUtf8("actionAudio"));
    actionCustom_option = new QAction(Salat);
    actionCustom_option->setObjectName(QString::fromUtf8("actionCustom_option"));
    actionWorld_time = new QAction(Salat);
    actionWorld_time->setObjectName(QString::fromUtf8("actionWorld_time"));
    actionAbout_Qsalat = new QAction(Salat);
    actionAbout_Qsalat->setObjectName(QString::fromUtf8("actionAbout_Qsalat"));
    actionAbout_QT = new QAction(Salat);
    actionAbout_QT->setObjectName(QString::fromUtf8("actionAbout_QT"));
    actionCalculation_methods = new QAction(Salat);
    actionCalculation_methods->setObjectName(QString::fromUtf8("actionCalculation_methods"));
    actionWorld_time_2 = new QAction(Salat);
    actionWorld_time_2->setObjectName(QString::fromUtf8("actionWorld_time_2"));
    centralwidget = new QWidget(Salat);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    widget = new QWidget(centralwidget);
    widget->setObjectName(QString::fromUtf8("widget"));
    widget->setGeometry(QRect(0, 0, 300, 400));
    widget->setStyleSheet(QString::fromUtf8("background-image: url(:/images/qsalat.png);"));
    label_fajr = new QLabel(widget);
    label_fajr->setObjectName(QString::fromUtf8("label_fajr"));
    label_fajr->setGeometry(QRect(120, 100, 75, 41));
    QFont font;
    font.setFamily(QString::fromUtf8("Arial Black"));
    font.setPointSize(19);
    font.setBold(true);
    font.setWeight(75);
    label_fajr->setFont(font);
    label_fajr->setStyleSheet(QString::fromUtf8("color:white;\n"
"opacity:1.0;\n"
"background-image: url(:/images/slider3.png);"));
    label_fajr->setAlignment(Qt::AlignCenter);
    label_asr = new QLabel(widget);
    label_asr->setObjectName(QString::fromUtf8("label_asr"));
    label_asr->setGeometry(QRect(120, 190, 75, 41));
    label_asr->setFont(font);
    label_asr->setStyleSheet(QString::fromUtf8("color:white;\n"
"opacity:1.0;\n"
"background-image: url(:/images/slider3.png);"));
    label_asr->setAlignment(Qt::AlignCenter);
    label_isha = new QLabel(widget);
    label_isha->setObjectName(QString::fromUtf8("label_isha"));
    label_isha->setGeometry(QRect(120, 280, 75, 41));
    label_isha->setFont(font);
    label_isha->setStyleSheet(QString::fromUtf8("color:white;\n"
"opacity:1.0;\n"
"background-image: url(:/images/slider3.png);"));
    label_isha->setAlignment(Qt::AlignCenter);
    label_duhr = new QLabel(widget);
    label_duhr->setObjectName(QString::fromUtf8("label_duhr"));
    label_duhr->setGeometry(QRect(120, 145, 75, 41));
    label_duhr->setFont(font);
    label_duhr->setStyleSheet(QString::fromUtf8("color:white;\n"
"opacity:1.0;\n"
"background-image: url(:/images/slider3.png);"));
    label_duhr->setAlignment(Qt::AlignCenter);
    label_maghreb = new QLabel(widget);
    label_maghreb->setObjectName(QString::fromUtf8("label_maghreb"));
    label_maghreb->setGeometry(QRect(120, 235, 75, 41));
    label_maghreb->setFont(font);
    label_maghreb->setStyleSheet(QString::fromUtf8("color:white;\n"
"opacity:1.0;\n"
"background-image: url(:/images/slider3.png);"));
    label_maghreb->setAlignment(Qt::AlignCenter);
    label_location = new QLabel(widget);
    label_location->setObjectName(QString::fromUtf8("label_location"));
    label_location->setGeometry(QRect(20, 340, 261, 41));
    label_location->setStyleSheet(QString::fromUtf8("background-image: url(:/images/slider3.png);\n"
"color:white;"));
    label_location->setAlignment(Qt::AlignCenter);
    label_hijri = new QLabel(widget);
    label_hijri->setObjectName(QString::fromUtf8("label_hijri"));
    label_hijri->setGeometry(QRect(130, 20, 161, 61));
    QFont font1;
    font1.setFamily(QString::fromUtf8("Arab"));
    font1.setPointSize(11);
    font1.setBold(true);
    font1.setItalic(false);
    font1.setWeight(75);
    label_hijri->setFont(font1);
    label_hijri->setStyleSheet(QString::fromUtf8("background-image: url(:/images/slider3.png);\n"
"color:white;\n"
""));
    label_hijri->setAlignment(Qt::AlignCenter);
    Salat->setCentralWidget(centralwidget);
    menubar = new QMenuBar(Salat);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 300, 25));
    menuFile = new QMenu(menubar);
    menuFile->setObjectName(QString::fromUtf8("menuFile"));
    menuTools = new QMenu(menubar);
    menuTools->setObjectName(QString::fromUtf8("menuTools"));
    menuExtra = new QMenu(menubar);
    menuExtra->setObjectName(QString::fromUtf8("menuExtra"));
    menuAbout = new QMenu(menubar);
    menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
    Salat->setMenuBar(menubar);
    statusbar = new QStatusBar(Salat);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    Salat->setStatusBar(statusbar);
    toolBar = new QToolBar(Salat);
    toolBar->setObjectName(QString::fromUtf8("toolBar"));
    Salat->addToolBar(Qt::TopToolBarArea, toolBar);

    menubar->addAction(menuFile->menuAction());
    menubar->addAction(menuTools->menuAction());
    menubar->addAction(menuExtra->menuAction());
    menubar->addAction(menuAbout->menuAction());
    menuFile->addAction(actionQuit);
    menuFile->addAction(actionHide);
    menuTools->addSeparator();
    menuTools->addAction(actionHijri_date);
    menuTools->addAction(actionQibla_direction);
    menuTools->addAction(actionLocation);
    menuTools->addAction(actionAudio);
    menuTools->addAction(actionCalculation_methods);
    menuExtra->addAction(actionWorld_time_2);
    menuAbout->addSeparator();
    menuAbout->addAction(actionAbout_Qsalat);
    menuAbout->addAction(actionAbout_QT);

    retranslateUi(Salat);

    QMetaObject::connectSlotsByName(Salat);
    } // setupUi

    void retranslateUi(QMainWindow *Salat)
    {
    Salat->setWindowTitle(QApplication::translate("Salat", "MainWindow", 0, QApplication::UnicodeUTF8));
    actionQuit->setText(QApplication::translate("Salat", "Hide", 0, QApplication::UnicodeUTF8));
    actionHide->setText(QApplication::translate("Salat", "Quit", 0, QApplication::UnicodeUTF8));
    actionHijri_date->setText(QApplication::translate("Salat", "Hijri date", 0, QApplication::UnicodeUTF8));
    actionQibla_direction->setText(QApplication::translate("Salat", "Qibla direction", 0, QApplication::UnicodeUTF8));
    actionLocation->setText(QApplication::translate("Salat", "Location", 0, QApplication::UnicodeUTF8));
    actionAudio->setText(QApplication::translate("Salat", "Audio", 0, QApplication::UnicodeUTF8));
    actionCustom_option->setText(QApplication::translate("Salat", "Custom option", 0, QApplication::UnicodeUTF8));
    actionWorld_time->setText(QApplication::translate("Salat", "World time", 0, QApplication::UnicodeUTF8));
    actionAbout_Qsalat->setText(QApplication::translate("Salat", "About Qsalat", 0, QApplication::UnicodeUTF8));
    actionAbout_QT->setText(QApplication::translate("Salat", "About QT", 0, QApplication::UnicodeUTF8));
    actionCalculation_methods->setText(QApplication::translate("Salat", "Calculation methods", 0, QApplication::UnicodeUTF8));
    actionWorld_time_2->setText(QApplication::translate("Salat", "World time", 0, QApplication::UnicodeUTF8));
    label_fajr->setText(QApplication::translate("Salat", "06:00", 0, QApplication::UnicodeUTF8));
    label_asr->setText(QApplication::translate("Salat", "00:00", 0, QApplication::UnicodeUTF8));
    label_isha->setText(QApplication::translate("Salat", "00:00", 0, QApplication::UnicodeUTF8));
    label_duhr->setText(QApplication::translate("Salat", "06:00", 0, QApplication::UnicodeUTF8));
    label_maghreb->setText(QApplication::translate("Salat", "06:00", 0, QApplication::UnicodeUTF8));
    label_location->setText(QApplication::translate("Salat", "TextLabel", 0, QApplication::UnicodeUTF8));
    label_hijri->setText(QApplication::translate("Salat", "00 Jumada al-Thani 0000", 0, QApplication::UnicodeUTF8));
    menuFile->setTitle(QApplication::translate("Salat", "File", 0, QApplication::UnicodeUTF8));
    menuTools->setTitle(QApplication::translate("Salat", "Tools", 0, QApplication::UnicodeUTF8));
    menuExtra->setTitle(QApplication::translate("Salat", "Extra", 0, QApplication::UnicodeUTF8));
    menuAbout->setTitle(QApplication::translate("Salat", "About", 0, QApplication::UnicodeUTF8));
    toolBar->setWindowTitle(QApplication::translate("Salat", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Salat: public Ui_Salat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALAT_H
