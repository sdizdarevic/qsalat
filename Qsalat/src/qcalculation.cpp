/****************************************************************************
** Qsalat project V1.0
** qcalculation.cpp
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

#include "qcalculation.h"
#include "qpray.h"

//
Qcalculation::Qcalculation( QWidget * parent, Qt::WFlags f) 
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
	date = QDate::currentDate();
	prayers = new Qpray();
	times = new QString[7];
	init(0);		
}

//
void Qcalculation::closeEvent(QCloseEvent *event)
{
	hide();
	event->ignore();
}

//
void Qcalculation::init(int flag = 0)
{
	
#ifdef Q_WS_WIN
	file = path+"data/qsalat.xml";
#else 
	file = QDir::homePath ()+"/.qsalat/config/qsalat.xml";
#endif	
	parser.readFile(file);
	calcMethod = parser.getElement(2,0).toInt();
	asrMethod = parser.getElement(2,2).toInt();
	prayers->setAsrMethod(asrMethod);		
	times = prayers->getDatePrayerTimes(date.year(),date.month(),date.day(),parser.getElement(0,0).toDouble(),parser.getElement(0,1).toDouble(),parser.getElement(0,4).toDouble());	
	duhrBox->setMaximum(calcTime(times[2],times[3]));	
	label_12->setText(" Max "+QString::number(duhrBox->maximum())+" min (5 min before asr)");

	if (0 == flag){
		list << "Ithna Ashari"<<"University of Islamic Sciences, Karachi"<<"Islamic Society of North America (ISNA)"
			<<"Muslim World League (MWL)"<<"Umm al-Qura, Makkah"<<"Egyptian General Authority of Survey"<<"Institute of Geophysics, University of Tehran";
			 //<<"Custom settings";	
		calcList->addItems(list);
		calcList->setCurrentIndex(parser.getElement(2,0).toInt());
		hList << "No adjustment"<<"middle of night"<<"1/7th of night"<<"angle/60th of night";
		highList->addItems(hList);
		highList->setCurrentIndex(parser.getElement(2,4).toInt());
		duhrBox->setValue(parser.getElement(2,1).toInt());
		if (parser.getElement(2,2).toInt() == 0) shafiiButton->setChecked(true);
		else hanafiButton->setChecked(true);
		hijriBox->setValue(parser.getElement(2,3).toInt());			
	}
	else{
		apply();
	}
}

//
void Qcalculation::setUI()
{
	setWindowIcon(QIcon(path+"images/mecque.png"));
	okButton->setIcon(style()->standardIcon(QStyle::SP_DialogOkButton));
	saveButton->setIcon(style()->standardIcon(QStyle::SP_DialogApplyButton));
	cancelButton->setIcon(style()->standardIcon(QStyle::SP_DialogCancelButton));
}

//
void Qcalculation::setActions(){   
    connect(saveButton,SIGNAL(clicked()),this,SLOT(apply()));
	connect(okButton,SIGNAL(clicked()),this,SLOT(save()));
    connect(cancelButton,SIGNAL(clicked()),this,SLOT(cancel()));   
}

//
void Qcalculation::apply()
{
	int asrChecked = 0;
	parser.changeElement(QString::number(calcList->currentIndex()),2,0);
	if (hanafiButton->isChecked()) asrChecked = 1;
	parser.changeElement(QString::number(asrChecked),2,2);
	parser.changeElement(QString::number(hijriBox->value()),2,3);
	parser.changeElement(QString::number(highList->currentIndex()),2,4);
	if (asrMethod != asrChecked){
		prayers->setAsrMethod(asrChecked);
		QString *times_ = new QString[7];
		times_ = prayers->getDatePrayerTimes(date.year(),date.month(),date.day(),parser.getElement(0,0).toDouble(),parser.getElement(0,1).toDouble(),parser.getElement(0,4).toDouble());	
		asrMinutes = calcTime(times[3],times_[3]);		
	}
	else{
		asrMinutes = 0;
	}
	//int temp = setDuhrMinutes() + asrMinutes;
	parser.changeElement(QString::number(duhrBox->value()),2,1);
	parser.saveData(file);
	DomParser::changed = true;
}

//
void Qcalculation::save()
{
	apply();
	close();
}

//
void Qcalculation::cancel()
{
	close();
}

//calculate time diffrence
int Qcalculation::calcTime(QString time1,QString time2){
	QStringList list1 = time1.split(":");
	QStringList list2 = time2.split(":");
	int hours = list2[0].toInt() - list1[0].toInt();
	int minutes = list2[1].toInt() - list1[1].toInt();
	return (hours * 60) + minutes - 5;
}

//
int Qcalculation::getDuhrMinutes(){
	return duhrBox->maximum() - parser.getElement(2,1).toInt();
}

//
int Qcalculation::setDuhrMinutes(){
	int result = duhrBox->maximum() - duhrBox->value();
	if (result < 0) return 0;
	else return result;
}

//calculate time diffrence between duhr and asr
int Qcalculation::getAsrDiff(int flag,QString time1,QString time2){
	if (0 == flag) return calcTime(time1,time2);
	else return -1 * calcTime(time1,time2);
}

