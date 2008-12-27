/****************************************************************************
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

#include "qsalat.h"
//
Qsalat::Qsalat( QWidget * parent, Qt::WFlags f) 
	: QMainWindow(parent, f)
{
	setupUi(this);	
	adjustWindow();	
	prayers = new Qpray();
	hijri = new Qhijri();	
	trayIcon = new QSystemTrayIcon(this);
	trayIconMenu = new QMenu(this);		
	createActions();	
	setVisible(true);
	Gfirst = true;
	locationFirst = true;	 
	init();  	
	getSalats();
	getHijri();
	initTimer();
	createTrayIcon();
}

void Qsalat::init()
{
	//QMessageBox::warning(this, tr("My Application"),parser.getElement(0,2),QMessageBox::Ok);
	date = QDate::currentDate();	
	year = date.year();;
	month = date.month();
	day = date.day();		
	file = "data/qsalat.xml";
	parser.readFile(file);
	//bool ok;
	latitude = parser.getElement(0,0).toDouble();
	longitude = parser.getElement(0,1).toDouble();	
	country = parser.getElement(0,2);
	city = parser.getElement(0,3);
	timezone = parser.getElement(0,4).toDouble();
	prayerAudio = parser.getElement(1,0);
	fajraAudio = parser.getElement(1,1);
	duaAudio = parser.getElement(1,2);	
	playAthan = parser.getElement(1,3);
	playDua = parser.getElement(1,4);
	calcMethod = parser.getElement(2,0).toInt();
	asrMethod = parser.getElement(2,2).toInt();
	duhrMinutes = parser.getElement(2,1).toInt();
	QTime time = QTime::currentTime();   		
    QString strTime = time.toString("HH");    
    worldtime.setImage(worldtime.getImage(strTime.toInt(),timezone));    
}

void Qsalat::initTimer()
{
	timer = startTimer(1000);
	QTimerEvent * e = new QTimerEvent(timer);
	QCoreApplication::postEvent(this,e);	
}

void Qsalat::adjustWindow(){
	QDesktopWidget *desktop = QApplication::desktop();
	int screenWidth, width; 
	int screenHeight, height;
	int x, y;
	QSize windowSize;	 
	screenWidth = desktop->width(); // get width of screen
	screenHeight = desktop->height(); // get height of screen	 
	windowSize = size(); // size of our application window
	width = windowSize.width(); 
	height = windowSize.height();	 
	// little computations
	x = (screenWidth - width) / 2;
	y = (screenHeight - height) / 2;
	y -= 50;	 
	// move window to desired coordinates
	move ( x, y );	
	//screenx = x;
	//screeny = y;
}

void Qsalat::getSalats(){			
	QString *times = new QString[7];
	prayers->setCalcMethod(calcMethod);
	prayers->setAsrMethod(asrMethod);
	prayers->setDhuhrMinutes(duhrMinutes);
	times = prayers->getDatePrayerTimes(year,month,day,latitude,longitude,timezone);
	label_fajr->setText(times[0]);
	label_duhr->setText(times[2]);
	label_asr->setText(times[3]);
	label_maghreb->setText(times[5]);
	label_isha->setText(times[6]);
	//QNetworkAddressEntry *host =  new QNetworkAddressEntry();//host->ip().toString()
	label_location->setText(city+", "+country);	
}

void Qsalat::getHijri(){
	QString *dates = new QString[4];
	dates = hijri->isToString(year, month, day);
	QString text = dates[0]+" "+dates[1]+" "+dates[3];	
	label_hijri->setText(QString::fromUtf8(dates[2].toLatin1().data()));
	label_hijri_3->setText(dates[3]);
	label_hijri_4->setText(dates[0]);
	label_hijri_2->setText(text);
}

void Qsalat::createTrayIcon()
{
	setWindowIcon(QIcon("images/mecque.png"));
	QColor *c = new QColor ( 238, 238, 157, 255 );	
	QPalette * p = new QPalette();
	p->setColor(QPalette::ToolTipBase,*c);
	QFont *f = new QFont ( "sans", 10, -1, false );	
	QToolTip::setFont ( *f );
	QToolTip::setPalette(*p);	
    trayIconMenu->addAction(minimizeAction);
    trayIconMenu->addAction(restoreAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(quitAction);    
    trayIcon->setContextMenu(trayIconMenu);
    trayIcon->setIcon(QIcon("images/mecque.png"));
	QString ttmessage = "Prayer times for : "+city+", "+country+"\nFajr :"+label_fajr->text()+"\nDuhr : "	+label_duhr->text()+"\nAsr : "+label_asr->text()+"\nMaghreb : "+label_maghreb->text()+"\nIsha : "+label_isha->text();
    trayIcon->setToolTip("Qsalat Islamic cross-platform prayers time V0.1");
    trayIcon->setToolTip(ttmessage);
	trayIcon->show();	
}

void Qsalat::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
	switch (reason) {
	case QSystemTrayIcon::Trigger:    
	case QSystemTrayIcon::MiddleClick:
		showNormal();
		break;
	default:
		;
	}
}

void Qsalat::setVisible(bool visible)
{
    minimizeAction->setEnabled(visible);
    //maximizeAction->setEnabled(!isMaximized());
    restoreAction->setEnabled(!visible);
    QMainWindow::setVisible(visible);
}

void Qsalat::closeEvent(QCloseEvent *event)
{
	//QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(1);
	//if (Gfirst == true){
		//trayIcon->showMessage("Information about this application", "Qsalat application is still runing", icon,10000);
		//Gfirst = false;
	//}		
	hide();
	event->ignore();
	qibla.hide();
	location.hide();
	audio.hide();
	calculation.hide();
	worldtime.hide();
	monthly.hide();
	yearly.hide();
	hijridate.hide();
}

void Qsalat::createActions()
{
	connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason))); 
    minimizeAction = new QAction(tr("Mi&nimize"), this);
    connect(minimizeAction, SIGNAL(triggered()), this, SLOT(_hide()));
    restoreAction = new QAction(tr("&Restore"), this);
    connect(restoreAction, SIGNAL(triggered()), this, SLOT(_showNormal()));
    quitAction = new QAction(tr("&Quit"), this);
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));    
    connect(actionLocation, SIGNAL(triggered()), this, SLOT(showLocation()));    
    connect(actionQibla_direction, SIGNAL(triggered()), this, SLOT(showQibla()));     
    connect(actionAudio, SIGNAL(triggered()), this, SLOT(showAudio()));     
    connect(actionCalculation_options, SIGNAL(triggered()), this, SLOT(showCalculation()));    
	connect(actionWorldtime, SIGNAL(triggered()), this, SLOT(showWorldtime()));
	connect(actionGenerate_monthly_prayer_times, SIGNAL(triggered()), this, SLOT(showMonthly()));
	connect(actionGenerate_yearly_prayer_times, SIGNAL(triggered()), this, SLOT(showYearly())); 
	connect(actionHijri_date, SIGNAL(triggered()), this, SLOT(showHijridate())); 
	actionQuit->setShortcut(tr("Ctrl+Q"));    
    connect(actionQuit, SIGNAL(triggered()), qApp, SLOT(quit()));    
    connect(actionAbout_QT, SIGNAL(triggered()), qApp, SLOT(aboutQt()));     
    actionHide->setShortcut(tr("Ctrl+H"));
    connect(actionHide, SIGNAL(triggered()), this, SLOT(hide()));    
    connect(actionAbout_Qsalat, SIGNAL(triggered()), this, SLOT(_about()));    
}

// Private Slots

void Qsalat::showLocation(){
	if (location.isHidden()){
		location.show();	
	}
	else{		
		location.activateWindow();
		location.raise();		
	}
	
}

void Qsalat::showQibla(){	
	if (qibla.isHidden()){		
		qibla.show();		
	}	
	else{
		//QMessageBox msgBox;
 		//msgBox.setText("YES");
 		//msgBox.exec();
 		qibla.activateWindow();
 		qibla.raise();	
	}	
}

void Qsalat::showAudio(){	
	if (audio.isHidden()){		
		audio.show();	
	}	
	else{		
		audio.activateWindow();
		audio.raise();		
	}	
}

void Qsalat::showCalculation(){		
	if (calculation.isHidden()){		
		calculation.show();
	}	
	else{		
		calculation.activateWindow();
		calculation.raise();		
	}	
}

void Qsalat::showWorldtime(){	
	if (worldtime.isHidden()){		
		worldtime.show();
	}	
	else{		
		worldtime.activateWindow();
		worldtime.raise();		
	}	
}

void Qsalat::showMonthly(){	
	if (monthly.isHidden()){		
		monthly.show();
	}	
	else{		
		monthly.activateWindow();
		monthly.raise();		
	}	
}

void Qsalat::showYearly(){	
	if (yearly.isHidden()){		
		yearly.show();
	}	
	else{		
		yearly.activateWindow();
		yearly.raise();		
	}	
}

void Qsalat::showHijridate(){	
	if (hijridate.isHidden()){		
		hijridate.show();
	}	
	else{		
		hijridate.activateWindow();
		hijridate.raise();		
	}	
}

void Qsalat::_about()
{
    QMessageBox::about(this, tr("About Qsalat"),
             tr("<b> Qsalat V0.1</b> Copyright (c) 2008 Skander Jabouzi skander@skanderjabouzi.com<br>"             
             	" This is a free software distributed under the terms of the GNU General Public License version 3\n(http://www.gnu.org/licenses/gpl-3.0.html)"));     
} 

void::Qsalat::_hide()
{
	hide();	
	if (!qibla.isHidden()){		
		qibla.hide();
	}
	if (!location.isHidden()){		
		location.hide();
	}
	if (!audio.isHidden()){		
		audio.hide();
	}	
	if (!calculation.isHidden()){		
		calculation.hide();
	}	
	if (!worldtime.isHidden()){		
		worldtime.hide();
	}	
	if (!monthly.isHidden()){		
		monthly.hide();
	}	
	if (!yearly.isHidden()){		
		yearly.hide();
	}	
	if (!hijridate.isHidden()){		
		hijridate.hide();
	}	
}

void Qsalat::_showNormal()
{
	showNormal();
}

void Qsalat::timerEvent(QTimerEvent *e)
{
	if (!e) return;
  	if (e->timerId() == timer){
  		if (DomParser::changed) {
  			init();  	
			getSalats();
			getHijri();
			createTrayIcon();	
			qibla.init();
  			DomParser::changed = false;
		}		
  		QTime time = QTime::currentTime();   		
    	QString strTime = time.toString("HH:mm:ss");
    	if ("00:00:00" == strTime){
    		init();  	
			getSalats();
			getHijri();
			createTrayIcon();	
			worldtime.setImage(worldtime.getImage(0,timezone));
   		}
   		else if ("01:00:00" == strTime){    		
			worldtime.setImage(worldtime.getImage(1,timezone));
   		}
   		else if ("02:00:00" == strTime){    		
			worldtime.setImage(worldtime.getImage(2,timezone));
   		}
   		else if ("03:00:00" == strTime){    		
			worldtime.setImage(worldtime.getImage(3,timezone));
   		}
   		else if ("04:00:00" == strTime){    		
			worldtime.setImage(worldtime.getImage(4,timezone));
   		}
   		else if ("05:00:00" == strTime){    		
			worldtime.setImage(worldtime.getImage(5,timezone));
   		}
   		else if ("06:00:00" == strTime){    		
			worldtime.setImage(worldtime.getImage(6,timezone));
   		}
   		else if ("07:00:00" == strTime){    		
			worldtime.setImage(worldtime.getImage(7,timezone));
   		}
   		else if ("08:00:00" == strTime){    		
			worldtime.setImage(worldtime.getImage(8,timezone));
   		}
   		else if ("09:00:00" == strTime){    		
			worldtime.setImage(worldtime.getImage(9,timezone));
   		}
   		else if ("10:00:00" == strTime){    		
			worldtime.setImage(worldtime.getImage(10,timezone));
   		}
   		else if ("11:00:00" == strTime){    		
			worldtime.setImage(worldtime.getImage(11,timezone));
   		}
   		else if ("12:00:00" == strTime){    		
			worldtime.setImage(worldtime.getImage(12,timezone));
   		}
   		else if ("13:00:00" == strTime){    		
			worldtime.setImage(worldtime.getImage(13,timezone));
   		}
   		else if ("14:00:00" == strTime){    		
			worldtime.setImage(worldtime.getImage(14,timezone));
   		}
   		else if ("15:00:00" == strTime){    		
			worldtime.setImage(worldtime.getImage(15,timezone));
   		}
   		else if ("16:00:00" == strTime){    		
			worldtime.setImage(worldtime.getImage(16,timezone));
   		}
   		else if ("17:00:00" == strTime){    		
			worldtime.setImage(worldtime.getImage(17,timezone));
   		}
   		else if ("18:00:00" == strTime){    		
			worldtime.setImage(worldtime.getImage(18,timezone));
   		}
   		else if ("19:00:00" == strTime){    		
   			worldtime.setImage(worldtime.getImage(19,timezone));
   		}
   		else if ("20:00:00" == strTime){    		
			worldtime.setImage(worldtime.getImage(20,timezone));
   		}
   		else if ("21:00:00" == strTime){    		
			worldtime.setImage(worldtime.getImage(21,timezone));
   		}
   		else if ("22:00:00" == strTime){    		
			worldtime.setImage(worldtime.getImage(22,timezone));
   		}
   		else if ("23:00:00" == strTime){    		
			worldtime.setImage(worldtime.getImage(23,timezone));
   		}
   		if (playAthan == "1"){
		   	if (label_fajr->text()+":00" == strTime){
		   		audioList << fajraAudio << QString::fromUtf8("Fajr prayer صلاة الفجر");
		   		QProcess::execute ("player/Player.exe", audioList );
		   		audioList.clear();
		   		if (playDua == "1"){
			   		audioList << duaAudio << "Fajr prayer صلاة الفجر";
			   		QProcess::execute ("player/Player.exe", audioList );
		   		}
		  	}
   			else if (label_duhr->text()+":00" == strTime){
		  		audioList <<  prayerAudio << "Duhr prayer";
		   		QProcess::execute ("player/Player.exe", audioList );	
		   		audioList.clear();
		   		if (playDua == "1"){
			   		audioList << duaAudio << "Duhr prayer";
			   		QProcess::execute ("player/Player.exe", audioList );
		   		}	   			
		  	}
   			else if (label_asr->text()+":00" == strTime){
		   		audioList << prayerAudio << "Asr prayer";
		   		QProcess::execute ("player/Player.exe", audioList );	
		   		audioList.clear();
		   		if (playDua == "1"){
			   		audioList << duaAudio << "Asr prayer";
			   		QProcess::execute ("player/Player.exe", audioList );
		   		}
		  	}
	  		else if (label_maghreb->text()+":00" == strTime){
	  			audioList << prayerAudio << "Maghreb prayer";
		   		QProcess::execute ("player/Player.exe", audioList );
		   		audioList.clear();
		   		if (playDua == "1"){
			   		audioList << duaAudio << "Maghreb prayer";
			   		QProcess::execute ("player/Player.exe", audioList );
		   		}		   			
	  		}
	  		else if (label_isha->text()+":00" == strTime){
	  			audioList << prayerAudio << "Isha prayer";
		   		QProcess::execute ("player/Player.exe", audioList );
		   		audioList.clear();
		   		if (playDua == "1"){
			   		audioList << duaAudio << "Isha prayer";
			   		QProcess::execute ("player/Player.exe", audioList );
		   		}		   			
	  		}
  		}    		
 	}	
}
//
