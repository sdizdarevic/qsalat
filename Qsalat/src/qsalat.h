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
	QStringList audioList;
	QString prayerAudio;
	QString fajrAudio;
	QString duaAudio;
	QString playAthan;
	QString playDua;
	int calcMethod;
	int asrMethod;
	int duhrMinutes;
	int hijriDays;
	QString path;	
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
	void setPlayer(QString,QString);
	
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




