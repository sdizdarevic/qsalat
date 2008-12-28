#include "qyearly.h"

Qyearly::Qyearly( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);	
	setUI();
	file = "data/qsalat.xml";
	parser.readFile(file);
	date = QDate::currentDate();
	prayers = new Qpray();
	init();
	setActions();
}

void Qyearly::closeEvent(QCloseEvent *event)
{
	hide();
	event->ignore();
}

void Qyearly::init()
{
	yearBox->setValue(date.year());
	calcMethod = parser.getElement(2,0).toInt();
	asrMethod = parser.getElement(2,2).toInt();
	duhrMinutes = parser.getElement(2,1).toInt();
}

void Qyearly::setActions()
{
	connect(selectButton, SIGNAL(clicked()), this, SLOT(load()));
	connect(generateButton, SIGNAL(clicked()), this, SLOT(generate()));
}

void Qyearly::setUI()
{
	setWindowIcon(QIcon("images/mecque.png"));
	selectButton->setIcon(style()->standardIcon(QStyle::SP_DialogOpenButton));
	generateButton->setIcon(style()->standardIcon(QStyle::SP_DialogApplyButton));
}

void Qyearly::load()
{
	pathEdit->setText(QFileDialog::getExistingDirectory(this, tr("Select Directory"),"/home",QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks));
}

void Qyearly::generate()
{
	if (pathEdit->text().length() == 0) QMessageBox::warning(this, tr("My Application"),"No folder selected",QMessageBox::Ok);
	else{
		QString *times = new QString[7];	
		Utils utils;
		int february;
		prayers->setCalcMethod(calcMethod);
		prayers->setAsrMethod(asrMethod);
		prayers->setDhuhrMinutes(duhrMinutes);
		QString months[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
		if (QDate::isLeapYear ( yearBox->value() )) february = 29;
		else february = 28;
		int days[] = {31,february,31,30,31,30,31,31,30,31,30,31};
		QString text = utils.readFile("data/part4");
		text += QString::number(yearBox->value());
		text += utils.readFile("data/part3");
		int index[] = {0,2,3,5,6};
		for (int k = 0; k < 12; k++){
			for (int i = 1; i <= days[k]; i++){
				text += "<tr><td id=\"\" width=\"25\">"+months[k]+" "+QString::number(i)+"</td>\n";
				times = prayers->getDatePrayerTimes(date.year(),date.month(),i,parser.getElement(0,0).toDouble(),parser.getElement(0,1).toDouble(),parser.getElement(0,4).toDouble());
				for (int j = 0; j < 5; j++){
					text += "<td id=\"\" width=\"40\">"+times[index[j]]+"</td>\n";
				}
				text += "</tr>\n";
			}
		}
		text += "</tbody></table></body></html>";
	 	utils.saveFile(pathEdit->text()+"yearly.html", text);
	 	QUrl url;
	 	url.setUrl(pathEdit->text()+"yearly.html");
		QDesktopServices::openUrl(url);
	}
}
