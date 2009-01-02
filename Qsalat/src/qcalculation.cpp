#include "qcalculation.h"
#include "qpray.h"

Qcalculation::Qcalculation( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	path = QCoreApplication::applicationDirPath ();
	if (path.data()[path.size() - 1] != '/') path += "/";
	setupUi(this);	
	setUI();	
	setActions();
	date = QDate::currentDate();
	prayers = new Qpray();
	init(0);		
}

void Qcalculation::closeEvent(QCloseEvent *event)
{
	hide();
	event->ignore();
}

void Qcalculation::init(int flag = 0)
{
	
	file = path+"data/qsalat.xml";
	parser.readFile(file);
	calcMethod = parser.getElement(2,0).toInt();
	asrMethod = parser.getElement(2,2).toInt();
	prayers->setAsrMethod(asrMethod);
	//duhrMinutes = parser.getElement(2,1).toInt();
	QString *times = new QString[7];
	//QMessageBox msgBox;
 	//msgBox.setText(QString::number(date.year())+" "+QString::number(date.month())+" "+QString::number(date.day()));
 	//msgBox.exec();
	times = prayers->getDatePrayerTimes(date.year(),date.month(),date.day(),parser.getElement(0,0).toDouble(),parser.getElement(0,1).toDouble(),parser.getElement(0,4).toDouble());	
	duhrBox->setMaximum(calcTime(times[2],times[3]));	
	if (0 == flag){
		list << "Ithna Ashari"<<"University of Islamic Sciences, Karachi"<<"Islamic Society of North America (ISNA)"
			 <<"Muslim World League (MWL)"<<"Umm al-Qura, Makkah"<<"Egyptian General Authority of Survey";
			 //<<"Custom settings";	
		calcList->addItems(list);
		calcList->setCurrentIndex(parser.getElement(2,0).toInt());
		duhrBox->setValue(getDuhrMinutes());
		if (parser.getElement(2,2).toInt() == 0) shafiiButton->setChecked(true);
		else hanafiButton->setChecked(true);
		hijriBox->setValue(parser.getElement(2,3).toInt());	
		if (parser.getElement(2,4).toInt() == 1) highLatBox->setChecked(true);			
	}
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
	int temp = setDuhrMinutes();	
	parser.changeElement(QString::number(temp),2,1);
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

int Qcalculation::calcTime(QString time1,QString time2){
	QStringList list1 = time1.split(":");
	QStringList list2 = time2.split(":");
	int hours = list2[0].toInt() - list1[0].toInt();
	int minutes = list2[1].toInt() - list1[1].toInt();
	return (hours * 60) + minutes;
}

int Qcalculation::getDuhrMinutes(){
	return duhrBox->maximum() - parser.getElement(2,1).toInt();
}

int Qcalculation::setDuhrMinutes(){
	int result = duhrBox->maximum() - duhrBox->value();
	if (result < 0) return 0;
	else return result;
}

