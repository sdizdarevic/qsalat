#ifndef QSALAT_H
#define QSALAT_H
//
#include <QMainWindow>
#include <QtGui>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QProcess>
//#include <QNetworkAddressEntry>
//#include <QHostAddress>
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
//
class Qsalat : public QMainWindow, public Ui::Salat
{
Q_OBJECT
public:
	Qsalat( QWidget * parent = 0, Qt::WFlags f = 0 );	
	void getSalats();
	void getHijri();		
	Qpray *prayers;
	Qhijri *hijri;
	Qlocation location;
	Qqibla qibla;
	QDate date;
	Qaudio audio;
	Qcalculation calculation;
	Qworldtime worldtime;
	Qmonthly monthly;
	Qyearly yearly;
	Qhijridate hijridate;
	
protected:
	int year;
	int month;
	int day;
	double latitude;
	double longitude;
	double timezone;
	QString country;
	QString city;
	void closeEvent(QCloseEvent *);
	void adjustWindow();
	
private:    
    QAction *minimizeAction;
    QAction *restoreAction;
    QAction *quitAction;
    //QAction *action_Close;
    //QAction *action_Hide;
	QSystemTrayIcon *trayIcon;
	QMenu *trayIconMenu;
	void createActions();
	void createTrayIcon();
	void setVisible(bool);	
	void timerEvent(QTimerEvent *e);
	void init();	
	void initTimer();
	bool Gfirst; 
	bool locationFirst;
	//int screenx;
	//int screeny;
	DomParser parser;
	QString file;	
	int timer;	
	QStringList audioList;
	
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




