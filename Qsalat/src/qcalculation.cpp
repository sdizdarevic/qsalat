#include "qcalculation.h"

Qcalculation::Qcalculation( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);	
	setUI();
	setMethods();
	init();
}

void Qcalculation::closeEvent(QCloseEvent *event)
{
	hide();
	event->ignore();
}

void Qcalculation::init()
{
	
}

void Qcalculation::setUI()
{
	setWindowIcon(QIcon("images/mecque.png"));
	okButton->setIcon(style()->standardIcon(QStyle::SP_DialogOkButton));
	saveButton->setIcon(style()->standardIcon(QStyle::SP_DialogApplyButton));
	cancelButton->setIcon(style()->standardIcon(QStyle::SP_DialogCancelButton));
}

void Qcalculation::setMethods()
{
	QStringList list;	
	list << "Ithna Ashari"<<"University of Islamic Sciences, Karachi"<<"Islamic Society of North America (ISNA)"
		 <<"Muslim World League (MWL)"<<"Umm al-Qura, Makkah"<<"Egyptian General Authority of Survey";
		 //<<"Custom settings";	
	calcBox->addItems(list);
}

void Qcalculation::apply()
{
	//int prayerChecked = 0;
	//int duaChecked = 0;
	//parser.changeElement(prayerLineEdit->text(),1,0);
	//parser.changeElement(fajrLineEdit->text(),1,1);
	//parser.changeElement(duaLineEdit->text(),1,2);
	//if (salatCheckBox->isChecked()) prayerChecked = 1;
	//if (duaCheckBox->isChecked()) duaChecked = 1;
	//parser.changeElement(QString::number(prayerChecked),1,3);	
	//parser.changeElement(QString::number(duaChecked),1,4);
	//parser.saveData(file);
	//DomParser::changed = true; 
}


void Qcalculation::save()
{
	apply();
	close();
}

void Qcalculation::cancel()
{
	close();
}

