#include "qhijridate.h"

Qhijridate::Qhijridate( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);	
	setUI();
	setActions();	
	hijri = new Qhijri();
	init();	
}

void Qhijridate::closeEvent(QCloseEvent *event)
{
	hide();
	event->ignore();
}

void Qhijridate::init(){
	QDate date = QDate::currentDate(); 
	QString *dates = new QString[4];
	dates = hijri->isToString(date.year(), date.month(), date.day());	
	hyearBox->setValue(dates[3].toInt());
	jyearBox->setValue(date.year());
}

void Qhijridate::setUI()
{
	setWindowIcon(QIcon("images/mecque.png"));
	convertButton->setIcon(style()->standardIcon(QStyle::SP_DialogApplyButton));
	glist << "January"<<"February"<<"March"<<"April"<<"May"<<"June"<<"July"<<"August"<<"September"<<"October"<<"November"<<"December";	
	jmonthBox->addItems(glist);
	hlist <<"Muharram"<<"Safar"<<"Rabi-al Awwal"<<"Rabi-al Thani"<<"Jumada al-Ula"<<"Jumada al-Thani"<<"Rajab"<<"Sha\'ban"<<"Ramadhan"<<"Shawwal"<<"Dhul Qa\'dah"<<"Dhul Hijjah";
	hmonthBox->addItems(hlist);
}

void Qhijridate::setActions(){
    connect(convertButton,SIGNAL(clicked()),this,SLOT(convert()));  
    connect(georgianButton,SIGNAL(clicked()),this,SLOT(update()));
    connect(hijriButton,SIGNAL(clicked()),this,SLOT(update()));    
}

void Qhijridate::convert()
{
	QString *dates = new QString[4];
	QString text = "";	
	if (hijriButton->isChecked()){
		dates = hijri->chrToString(hyearBox->value(),hmonthBox->currentIndex()+1,hdayBox->value());
		text = dates[0]+" "+dates[1]+" "+dates[2];	
		QMessageBox::information(this, tr("My Application"),text,QMessageBox::Ok);
	}
	else{
		dates = hijri->isToString(jyearBox->value(),jmonthBox->currentIndex()+1,jdayBox->value());
		text = dates[0]+" "+dates[1]+" "+dates[3];	
		QMessageBox::information(this, tr("My Application"),text,QMessageBox::Ok);
	}
}

void Qhijridate::update()
{
	//QPixmap pixmap("/home/skander/Developpement/Qsalat/images/boussole.png");
	//QSplashScreen splash(pixmap);
	//splash.show();
	if (hijriButton->isChecked()){
		hyearBox->setEnabled(true);
		hmonthBox->setEnabled(true);
		hdayBox->setEnabled(true);
		jyearBox->setEnabled(false);
		jmonthBox->setEnabled(false);
		jdayBox->setEnabled(false);
	}
	else{
		jyearBox->setEnabled(true);
		jmonthBox->setEnabled(true);
		jdayBox->setEnabled(true);
		hyearBox->setEnabled(false);
		hmonthBox->setEnabled(false);
		hdayBox->setEnabled(false);
	}
}
