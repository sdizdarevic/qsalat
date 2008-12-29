#include "qcalculation.h"

Qcalculation::Qcalculation( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	path = QCoreApplication::applicationDirPath ();
	if (path.data()[path.size() - 1] != '/') path += "/";
	setupUi(this);	
	setUI();
	file = path+"data/qsalat.xml";
	parser.readFile(file);
	setActions();
	init();
}

void Qcalculation::closeEvent(QCloseEvent *event)
{
	hide();
	event->ignore();
}

void Qcalculation::init()
{
	bool ok;
	list << "Ithna Ashari"<<"University of Islamic Sciences, Karachi"<<"Islamic Society of North America (ISNA)"
		 <<"Muslim World League (MWL)"<<"Umm al-Qura, Makkah"<<"Egyptian General Authority of Survey";
		 //<<"Custom settings";	
	calcList->addItems(list);
	calcList->setCurrentIndex(parser.getElement(2,0).toInt(&ok));
	duhrBox->setValue(parser.getElement(2,1).toInt(&ok));
	if (parser.getElement(2,2).toInt(&ok) == 0) shafiiButton->setChecked(true);
	else hanafiButton->setChecked(true);
	hijriBox->setValue(parser.getElement(2,3).toInt(&ok));	
	if (parser.getElement(2,4).toInt(&ok) == 1) highLatBox->setChecked(true);
}

void Qcalculation::setUI()
{
	setWindowIcon(QIcon(path+"images/mecque.png"));
	okButton->setIcon(style()->standardIcon(QStyle::SP_DialogOkButton));
	saveButton->setIcon(style()->standardIcon(QStyle::SP_DialogApplyButton));
	cancelButton->setIcon(style()->standardIcon(QStyle::SP_DialogCancelButton));
}

void Qcalculation::setActions(){   
    connect(saveButton,SIGNAL(clicked()),this,SLOT(apply()));
    connect(okButton,SIGNAL(clicked()),this,SLOT(save()));
    connect(cancelButton,SIGNAL(clicked()),this,SLOT(cancel()));   
}

void Qcalculation::apply()
{
	int asrChecked = 0;
	int highChecked = 0;
	parser.changeElement(QString::number(calcList->currentIndex()),2,0);
	parser.changeElement(QString::number(duhrBox->value()),2,1);
	if (hanafiButton->isChecked()) asrChecked = 1;	
	parser.changeElement(QString::number(asrChecked),2,2);
	parser.changeElement(QString::number(hijriBox->value()),2,3);
	if (highLatBox->isChecked()) highChecked = 1;		
	parser.changeElement(QString::number(highChecked),2,4);
	parser.saveData(file);
	DomParser::changed = true; 
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

