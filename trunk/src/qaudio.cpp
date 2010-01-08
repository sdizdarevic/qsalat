/****************************************************************************
** Qsalat project V1.0
** qaudio.cpp
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

#include "qaudio.h"

//
Qaudio::Qaudio( QWidget * parent, Qt::WFlags f) : QDialog(parent, f )
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
	init(0);
}

//
void Qaudio::init(int flag = 0)
{
#ifdef Q_WS_WIN
	file = path+"data/qsalat.xml";
#else 
	file = QDir::homePath ()+"/.qsalat/config/qsalat.xml";
#endif	
	parser.readFile(file);	
	if (0 == flag){
		prayerLineEdit->setText(parser.getElement(1,0));
	    fajrLineEdit->setText(parser.getElement(1,1));
	    duaLineEdit->setText(parser.getElement(1,2));
	    if (0 == parser.getElement(1,3).toInt()) {
			salatCheckBox->setChecked(false); 
			duaCheckBox->setChecked(false);
			duaCheckBox->setEnabled(false);		
		}
		else{
			salatCheckBox->setChecked(true);
			if (0 == parser.getElement(1,4).toInt()) {
				duaCheckBox->setChecked(false); 		
			}
			else{
				duaCheckBox->setChecked(true);
			}	
		}				
	}    
}

//
void Qaudio::closeEvent(QCloseEvent *event)
{
	hide();
	event->ignore();
}

//
void Qaudio::setActions()
{
	connect(prayerButton, SIGNAL(clicked()), this, SLOT(loadPrayer()));
	connect(fajrButton, SIGNAL(clicked()), this, SLOT(loadFajr()));
	connect(duaButton, SIGNAL(clicked()), this, SLOT(loadDua()));
	connect(saveButton, SIGNAL(clicked()), this, SLOT(apply()));
	connect(okButton, SIGNAL(clicked()), this, SLOT(save()));
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));
	connect(previewButton,SIGNAL(clicked()), this, SLOT(preview()));	
}

//
void Qaudio::setUI()
{
    setWindowIcon(QIcon(path+"images/mecque.png"));
    prayerButton->setIcon(style()->standardIcon(QStyle::SP_DialogOpenButton));
    fajrButton->setIcon(style()->standardIcon(QStyle::SP_DialogOpenButton));
    duaButton->setIcon(style()->standardIcon(QStyle::SP_DialogOpenButton));
    okButton->setIcon(style()->standardIcon(QStyle::SP_DialogOkButton));
    saveButton->setIcon(style()->standardIcon(QStyle::SP_DialogApplyButton));
    cancelButton->setIcon(style()->standardIcon(QStyle::SP_DialogCancelButton));   
}

// load athan file
void Qaudio::loadPrayer()
{
        prayerLineEdit->setText(QFileDialog::getOpenFileName(this,tr("Open File"),".",tr("audios et videos (*.mp3 *.wma *.ogg *.wave *.midi *.mp4 *.flv *.ogv *.mpeg *.mpg *.avi *.divx *.wmv *.mov)")));
}

// load fajr file
void Qaudio::loadFajr()
{
        fajrLineEdit->setText(QFileDialog::getOpenFileName(this,tr("Open File"),".",tr("audios et videos (*.mp3 *.wma *.ogg *.wave *.midi *.mp4 *.flv *.ogv *.mpeg *.mpg *.avi *.divx *.wmv *.mov)")));
}

// load dua file
void Qaudio::loadDua()
{
        duaLineEdit->setText(QFileDialog::getOpenFileName(this,tr("Open File"),".",tr("audios et videos (*.mp3 *.wma *.ogg *.wave *.midi *.mp4 *.flv *.ogv *.mpeg *.mpg *.avi *.divx *.wmv *.mov)")));
}

//
void Qaudio::preview()
{       
	QStringList audioFile;         
	audioFile.clear();
    if (regularRadioButton->isChecked()) audioFile << prayerLineEdit->text() << "Athan preview";
    else if (fajrRadioButton->isChecked()) audioFile << fajrLineEdit->text() << "Athan fajr preview"; 
    else audioFile << duaLineEdit->text() << "Dua fajr preview";   
    QString program = "salatPlayer";
    QProcess *myProcess = new QProcess(this);
    myProcess->start(program, audioFile);
}

//
void Qaudio::apply()
{
	int prayerChecked = 0;
	int duaChecked = 0;
	parser.changeElement(prayerLineEdit->text(),1,0);
	parser.changeElement(fajrLineEdit->text(),1,1);
	parser.changeElement(duaLineEdit->text(),1,2);
	if (salatCheckBox->isChecked()) prayerChecked = 1;
	if (duaCheckBox->isChecked()) duaChecked = 1;
	parser.changeElement(QString::number(prayerChecked),1,3);	
	parser.changeElement(QString::number(duaChecked),1,4);
	parser.saveData(file);
	DomParser::changed = true; 
}

//
void Qaudio::save()
{
        apply();
        close();
}

//
void Qaudio::cancel()
{
        close();
}

void Qaudio::checkChanged()
{
	if (salatCheckBox->isChecked() == false){
		duaCheckBox->setChecked(false);
		duaCheckBox->setEnabled(false);
	}
	else{
		duaCheckBox->setEnabled(true);
	}
}
