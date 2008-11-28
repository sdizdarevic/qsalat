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
	date = QDate::currentDate();	
	year = date.year();;
	month = date.month();
	day = date.day();
	latitude = 45.5454;
	longitude = -73.6391;
	timezone = -5.0;
	getSalats();
	getHijri();
	createActions();
	createTrayIcon();	
	setVisible(true);
	Gfirst = true;
	locationFirst = true;
	connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
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
}

void Qsalat::getSalats(){	
	QString *times = new QString[7];
	prayers->setCalcMethod(3);
	times = prayers->getDatePrayerTimes(year,month,day,latitude,longitude,timezone);
	label_fajr->setText(times[0]);
	label_duhr->setText(times[2]);
	label_asr->setText(times[3]);
	label_maghreb->setText(times[5]);
	label_isha->setText(times[6]);
	//QNetworkAddressEntry *host =  new QNetworkAddressEntry();//host->ip().toString()
	label_location->setText("Montreal, Canada");
}

void Qsalat::getHijri(){
	QString *dates = new QString[3];
	dates = hijri->isToString(year, month, day);
	QString text = dates[0]+" "+dates[1]+" "+dates[2];
	label_hijri->setText(text);
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
	QString ttmessage = "Qsalat cross-platform Islamic prayer times V0.1\nFajr : "+label_fajr->text()+"\nDuhr : "
	+label_duhr->text()+"\nAsr : "+label_asr->text()+"\nMaghreb : "+label_maghreb->text()+"\nIsha : "+label_isha->text();
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
	QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::MessageIcon(1);
	if (Gfirst == true){
		trayIcon->showMessage("Information about this application", "Qsalat application is still runing", icon,10000);
		Gfirst = false;
	}		
	hide();
	event->ignore();
}

void Qsalat::createActions()
{
    minimizeAction = new QAction(tr("Mi&nimize"), this);
    connect(minimizeAction, SIGNAL(triggered()), this, SLOT(hide()));

    restoreAction = new QAction(tr("&Restore"), this);
    connect(restoreAction, SIGNAL(triggered()), this, SLOT(showNormal()));

    quitAction = new QAction(tr("&Quit"), this);
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));     
    
    connect(actionLocation, SIGNAL(triggered()), this, SLOT(editLocation()));  
    
    connect(actionQibla_direction, SIGNAL(triggered()), this, SLOT(showQibla()));     
    
    connect(actionQuit, SIGNAL(triggered()), qApp, SLOT(quit()));  
    
    //action_Close->setShortcut(tr("Ctrl+Q"));
    //connect(action_Close, SIGNAL(triggered()), qApp, SLOT(quit()));
    
    //action_Hide->setShortcut(tr("Ctrl+H"));
   // connect(action_Hide, SIGNAL(triggered()), this, SLOT(hide()));    
    
    //connect(action_About, SIGNAL(triggered()), this, SLOT(_about()));    
}

// Private Slots

void Qsalat::editLocation(){
	//Qlocation::Qlocation();
	location.setWindowOpacity(0.0);
	location.show();	
}

void Qsalat::showQibla(){	
	qibla.show();
}

//
