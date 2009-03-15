/****************************************************************************
** Qsalat project V1.0
** qmonthly.cpp
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

#include "qmonthly.h"

//
Qmonthly::Qmonthly( QWidget * parent, Qt::WFlags f) 
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
	setMethods();
#ifdef Q_WS_WIN
	file = path+"data/qsalat.xml";
#else 
	file = QDir::homePath ()+"/.qsalat/config/qsalat.xml";
#endif	
	parser.readFile(file);
	date = QDate::currentDate();
	prayers = new Qpray();
	init();
	setActions();
}

//
void Qmonthly::closeEvent(QCloseEvent *event)
{
	hide();
	event->ignore();
}

//
void Qmonthly::init()
{
	yearBox->setValue(date.year());
	calcMethod = parser.getElement(2,0).toInt();
	asrMethod = parser.getElement(2,2).toInt();
	duhrMinutes = parser.getElement(2,1).toInt();
}

//
void Qmonthly::setActions()
{
	connect(selectButton, SIGNAL(clicked()), this, SLOT(load()));
	connect(generateButton, SIGNAL(clicked()), this, SLOT(generate()));
}

//
void Qmonthly::setUI()
{
	setWindowIcon(QIcon(path+"images/mecque.png"));
	selectButton->setIcon(style()->standardIcon(QStyle::SP_DialogOpenButton));
	generateButton->setIcon(style()->standardIcon(QStyle::SP_DialogApplyButton));
}

//
void Qmonthly::setMethods()
{
	QStringList list;	
	list << "January"<<"February"<<"March"<<"April"<<"May"<<"June"<<"July"<<"August"<<"September"
		 <<"October"<<"November"<<"December";
	monthBox->addItems(list);	
}

//load loaction to save html file
void Qmonthly::load()
{
	pathEdit->setText(QFileDialog::getExistingDirectory(this, tr("Select Directory"),"/home",QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks));
}

//generate monthly prayer times
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
		QString text = utils.readFile(path+"data/part1");
		text += months[monthBox->currentIndex()]+" "+QString::number(yearBox->value());
		text += utils.readFile(path+"data/part2");
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
		QString slash = "";
		if (pathEdit->text().data()[pathEdit->text().size() - 1] != '/') slash = "/";		
		utils.saveFile(pathEdit->text()+slash+"monthly.html", text);
	 	QDesktopServices::openUrl(QUrl::fromLocalFile(pathEdit->text()+slash+"monthly.html"));
	}
}
