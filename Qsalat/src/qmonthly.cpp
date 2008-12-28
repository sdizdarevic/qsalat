#include "qmonthly.h"

Qmonthly::Qmonthly( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);	
	setUI();
	setMethods();
	file = "data/qsalat.xml";
	parser.readFile(file);
	date = QDate::currentDate();
	prayers = new Qpray();
	init();
	setActions();
}

void Qmonthly::closeEvent(QCloseEvent *event)
{
	hide();
	event->ignore();
}

void Qmonthly::init()
{
	yearBox->setValue(date.year());
	calcMethod = parser.getElement(2,0).toInt();
	asrMethod = parser.getElement(2,2).toInt();
	duhrMinutes = parser.getElement(2,1).toInt();
}

void Qmonthly::setActions()
{
	connect(selectButton, SIGNAL(clicked()), this, SLOT(load()));
	connect(generateButton, SIGNAL(clicked()), this, SLOT(generate()));
}

void Qmonthly::setUI()
{
	setWindowIcon(QIcon("images/mecque.png"));
	selectButton->setIcon(style()->standardIcon(QStyle::SP_DialogOpenButton));
	generateButton->setIcon(style()->standardIcon(QStyle::SP_DialogApplyButton));
}

void Qmonthly::setMethods()
{
	QStringList list;	
	list << "January"<<"February"<<"March"<<"April"<<"May"<<"June"<<"July"<<"August"<<"September"
		 <<"October"<<"November"<<"December";
	monthBox->addItems(list);	
}

void Qmonthly::load()
{
	pathEdit->setText(QFileDialog::getExistingDirectory(this, tr("Select Directory"),"/home",QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks));
}

void Qmonthly::generate()
{
	if (pathEdit->text().length() == 0) QMessageBox::warning(this, tr("My Application"),"No folder selected",QMessageBox::Ok);
	else{
		QString *times = new QString[7];	
		Utils utils;
		int february;
		prayers->setCalcMethod(calcMethod);
		prayers->setAsrMethod(asrMethod);
		prayers->setDhuhrMinutes(duhrMinutes);
		QString months[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
		if (QDate::isLeapYear ( yearBox->value() )) february = 29;
		else february = 28;
		int days[] = {31,february,31,30,31,30,31,31,30,31,30,31};
		QString text = utils.readFile("data/part1");
		text += months[monthBox->currentIndex()]+" "+QString::number(yearBox->value());
		text += utils.readFile("data/part2");
		int index[] = {0,2,3,5,6};
		for (int i = 1; i <= days[monthBox->currentIndex()]; i++){
			text += "<tr><td id=\"\" width=\"25\">"+QString::number(i)+"</td>\n";
			times = prayers->getDatePrayerTimes(date.year(),date.month(),i,parser.getElement(0,0).toDouble(),parser.getElement(0,1).toDouble(),parser.getElement(0,4).toDouble());
			for (int j = 0; j < 5; j++){
				text += "<td id=\"\" width=\"40\">"+times[index[j]]+"</td>\n";
			}
			text += "</tr>\n";
		}
		text += "</tbody></table></body></html>";
	 	utils.saveFile(pathEdit->text()+"monthly.html", text);
	 	QUrl url;
	 	url.setUrl(pathEdit->text()+"monthly.html");
		QDesktopServices::openUrl(url);
	}
}

