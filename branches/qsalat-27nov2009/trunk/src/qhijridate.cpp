/****************************************************************************
** Qsalat project V1.0
** qhijridate.cpp
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

#include "qhijridate.h"

//
Qhijridate::Qhijridate( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
#ifdef Q_WS_WIN
	path = QCoreApplication::applicationDirPath ();
#else 
	path = "/usr/share/qsalat/";
#endif
	if (path.data()[path.size() - 1] != '/') path += "/";
	setupUi(this);	
	setUI();
	setActions();	
	hijri = new Qhijri();
	init();	
}

//
void Qhijridate::closeEvent(QCloseEvent *event)
{
	hide();
	event->ignore();
}

//
void Qhijridate::init(){
#ifdef Q_WS_WIN
	file = path+"data/qsalat.xml";
#else 
	file = QDir::homePath ()+"/.qsalat/config/qsalat.xml";
#endif	
	parser.readFile(file);	
	QDate date = QDate::currentDate(); 
	QString *dates = new QString[4];
	dates = hijri->isToString(date.year(), date.month(), date.day(),parser.getElement(2,3).toInt());	
	hyearBox->setValue(dates[3].toInt());
	jyearBox->setValue(date.year());
}

//
void Qhijridate::setUI()
{
	setWindowIcon(QIcon(path+"images/mecque.png"));
	convertButton->setIcon(style()->standardIcon(QStyle::SP_DialogApplyButton));
	glist << "January"<<"February"<<"March"<<"April"<<"May"<<"June"<<"July"<<"August"<<"September"<<"October"<<"November"<<"December";	
	jmonthBox->addItems(glist);
	hlist <<"Muharram"<<"Safar"<<"Rabi-al Awwal"<<"Rabi-al Thani"<<"Jumada al-Ula"<<"Jumada al-Thani"<<"Rajab"<<"Sha\'ban"<<"Ramadhan"<<"Shawwal"<<"Dhul Qa\'dah"<<"Dhul Hijjah";
	hmonthBox->addItems(hlist);
}

//
void Qhijridate::setActions(){
    connect(convertButton,SIGNAL(clicked()),this,SLOT(convert()));  
    connect(georgianButton,SIGNAL(clicked()),this,SLOT(update()));
    connect(hijriButton,SIGNAL(clicked()),this,SLOT(update()));    
}

//convert from/to hijri and georgian calendars
void Qhijridate::convert()
{
	QString *dates = new QString[4];
	QString text = "";	
	if (hijriButton->isChecked()){
		dates = hijri->chrToString(hyearBox->value(),hmonthBox->currentIndex()+1,hdayBox->value(),parser.getElement(2,3).toInt());
		text = dates[0]+" "+dates[1]+" "+dates[2];	
		QMessageBox::information(this, tr("My Application"),text,QMessageBox::Ok);
	}
	else{
		dates = hijri->isToString(jyearBox->value(),jmonthBox->currentIndex()+1,jdayBox->value(),parser.getElement(2,3).toInt());
		text = dates[0]+" "+dates[1]+" "+dates[3];	
		QMessageBox::information(this, tr("My Application"),text,QMessageBox::Ok);
	}
}

//
void Qhijridate::update()
{
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
