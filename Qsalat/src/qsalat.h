/****************************************************************************
** Qsalat project V1.0
** qsalat.h
**
** Copyright (C) 2008 Skander Jabouzi (Skander Software Solutions).
** Contact: skander@skanderjabouzi.com or jabouzi@gmail.com
**
** This file is part of the Qsalat open source software.
**
** GNU General Public License Usage
** This file may be used under the terms of the GNU
** General Public License versions 2.0 or 3.0 as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file.  Please review the following information
** to ensure GNU General Public Licensing requirements will be met:
** http://www.fsf.org/licensing/licenses/info/GPLv2.html and
** http://www.gnu.org/copyleft/gpl.html.  In addition, as a special
** exception, Nokia gives you certain additional rights. These rights
** are described in the Nokia Qt GPL Exception version 1.3, included in
** the file GPL_EXCEPTION.txt in this package.
**
***************************************************************************/

#ifndef QSALAT_H
#define QSALAT_H
//
#include <QMainWindow>
#include <QtGui>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QProcess>
#include <QPaintEvent>
#include "ui_salat.h"
#include "qpray.h"
#include "qhijri.h"
#include "qlocation.h"
#include "qqibla.h"
#include "qaudio.h"
#include "qcalculation.h"
#include "qworldTime.h"
#include "qmonthly.h"
#include "qyearly.h"
#include "qhijridate.h"
#include "domparser.h"
#include "playerimpl.h"
//
class Qsalat : public QMainWindow, public Ui::Salat
{
Q_OBJECT
public:
	Qsalat( QWidget * parent = 0, Qt::WFlags f = 0 );	
	
private:    
	// private members
	Qpray *prayers;
	Qhijri *hijri;
	QAction *minimizeAction;
    QAction *restoreAction;
    QAction *quitAction;
	QSystemTrayIcon *trayIcon;
	QMenu *trayIconMenu;
	int year;
	int month;
	int day;
	double latitude;
	double longitude;
	double timezone;
	QString country;
	QString city;		
	Qlocation location;
	Qqibla qibla;
	QDate date;
	Qaudio audio;
	Qcalculation calculation;
	Qworldtime worldtime;
	Qmonthly monthly;
	Qyearly yearly;
	Qhijridate hijridate; 
	DomParser parser;
	PlayerImpl player;
	QString file;	
	int timer;	
	QString prayerAudio;
	QString fajrAudio;
	QString duaAudio;
	QString playAthan;
	QString playDua;
	int calcMethod;
	int asrMethod;
	int duhrMinutes;
	int hijriDays;
	int highlatitude;
	QString path;	
	QStringList audioList;
	// private methods
	void init();	
	void initTimer();	 
	void adjustWindow();	
	void getSalats();
	void getHijri();
	void createTrayIcon();
	void setVisible(bool);	
	void closeEvent(QCloseEvent *);
	void createActions();
	void timerEvent(QTimerEvent *e);
	void setPlayer(QStringList,QString);
	
private slots:
	void iconActivated(QSystemTrayIcon::ActivationReason);
	void showLocation();
	void showQibla();
	void showAudio();
	void showCalculation();
	void showWorldtime();
	void showMonthly();
	void showYearly();
	void showHijridate();
	void _about();
	void _hide();
	void _showNormal();
};
#endif




