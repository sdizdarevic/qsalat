#include "qcalculation.h"

Qcalculation::Qcalculation( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);	
	setUI();
	setMethods();
}

void Qcalculation::closeEvent(QCloseEvent *event)
{
	hide();
	event->ignore();
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

