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
	videoPlayer->mediaObject()->setTickInterval(1000);		
	volumeSlider->setRange(0,100);
	load();
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
	connect(playButton, SIGNAL(clicked()), this, SLOT(play()));
	connect(stopButton, SIGNAL(clicked()), this, SLOT(stop()));
	connect(saveButton, SIGNAL(clicked()), this, SLOT(apply()));
	connect(okButton, SIGNAL(clicked()), this, SLOT(save()));
	connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));
	connect(videoPlayer->mediaObject(), SIGNAL(finished()), this, SLOT(finished()));
	connect(timeSlider, SIGNAL(sliderReleased()),this, SLOT(seekFile()));
    connect(volumeSlider, SIGNAL(sliderReleased()),this, SLOT(changeVolume()));
    connect(videoPlayer->mediaObject(), SIGNAL(tick(qint64)), this, SLOT(updateTime())); 
    connect(videoPlayer->mediaObject(), SIGNAL(stateChanged(Phonon::State, Phonon::State)), this, SLOT(stateChanged(Phonon::State, Phonon::State)));
    //connect(videoPlayer->mediaObject(), SIGNAL(metaDataChanged()), this, SLOT(updateInfo()));
    //connect(videoPlayer->mediaObject(), SIGNAL(totalTimeChanged(qint64)), this, SLOT(updateTime()));
	//connect(audioOutput, SIGNAL(volumeChanged ( qreal )), this, SLOT(setVolume()));
	connect(salatCheckBox,SIGNAL(stateChanged(int)), this, SLOT(checkChanged()));
	connect(regularRadioButton,SIGNAL(clicked()), this, SLOT(changeSourceAthan()));
	connect(fajrRadioButton,SIGNAL(clicked()), this, SLOT(changeSourceFajr()));
	connect(duaRadioButton,SIGNAL(clicked()), this, SLOT(changeSourceDua()));
}

//
void Qaudio::setUI()
{
    setWindowIcon(QIcon(path+"images/mecque.png"));
    playIcon = style()->standardIcon(QStyle::SP_MediaPlay);
    playButton->setIcon(playIcon);
    stopIcon = style()->standardIcon(QStyle::SP_MediaStop);
    stopButton->setIcon(stopIcon);
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

void Qaudio::load()
{    
    sources.clear();
    if ("" != prayerLineEdit->text())
    {
    	Phonon::MediaSource source(fajrLineEdit->text());
    	sources.insert(0,source);
   	}
   	if ("" != fajrLineEdit->text())
    {
    	Phonon::MediaSource source(fajrLineEdit->text());
    	sources.insert(1,source);
   	}
   	if ("" != duaLineEdit->text())
    {
    	Phonon::MediaSource source(fajrLineEdit->text());
    	sources.insert(2,source);
   	}
    	
}

//
void Qaudio::play()
{       
	if (videoPlayer->mediaObject()->state() == Phonon::PlayingState)
        videoPlayer->pause();
    else if (videoPlayer->mediaObject()->state() == Phonon::PausedState || videoPlayer->mediaObject()->state() == Phonon::LoadingState || videoPlayer->mediaObject()->state() == Phonon::StoppedState)
        videoPlayer->play();   		
}

void Qaudio::seekFile()
{
	videoPlayer->seek(timeSlider->value());
}

//
void Qaudio::stop()
{
        videoPlayer->mediaObject()->stop();
        playIcon = style()->standardIcon(QStyle::SP_MediaPlay);
        playButton->setIcon(playIcon);
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
	load();
}

//
void Qaudio::save()
{
        apply();
        stop();
        close();
}

//
void Qaudio::cancel()
{
		videoPlayer->mediaObject()->stop();
        close();
}

//
void Qaudio::finished()
{
	stop();
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

void Qaudio::updateTime()
{
    long pos = videoPlayer->mediaObject()->currentTime();
    timeSlider->setValue(pos);
}

void Qaudio::changeVolume()
{
	float volume = float(volumeSlider->value())/100.0;
	videoPlayer->setVolume(volume);
}

void Qaudio::stateChanged(Phonon::State newstate, Phonon::State oldstate)
{
    if (oldstate == Phonon::LoadingState){    
        playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
        playButton->setToolTip("Pause");
    }
    if( newstate == Phonon::StoppedState || newstate == Phonon::PausedState){        
        playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
        playButton->setToolTip("Play");
    }
    else if (newstate == Phonon::PlayingState) {
        playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause)); 
        playButton->setToolTip("Pause"); 
    }    
    else if (newstate == Phonon::ErrorState) {    
            //QMessageBox::warning(this, "Phonon Mediaplayer", videoPlayer->mediaObject()->errorString(), QMessageBox::Close);
            if (videoPlayer->mediaObject()->errorType() == Phonon::FatalError) {
                //init2();
                //this->close();
            } else {
                videoPlayer->mediaObject()->pause();
            }
     }
}

void Qaudio::changeSourceAthan()
{
	videoPlayer->mediaObject()->setCurrentSource(sources.at(0)); 
	volumeSlider->setValue(videoPlayer->volume()*100);  
   	timeSlider->setRange(0,videoPlayer->mediaObject()->totalTime());
    qDebug(QString::number(videoPlayer->mediaObject()->totalTime()).toLatin1().data());        
	
}

void Qaudio::changeSourceFajr()
{
	 videoPlayer->mediaObject()->setCurrentSource(sources.at(1)); 
	 volumeSlider->setValue(videoPlayer->volume()*100);  
   	 timeSlider->setRange(0,videoPlayer->mediaObject()->totalTime());
     qDebug(QString::number(videoPlayer->mediaObject()->totalTime()).toLatin1().data()); 
}
	
void Qaudio::changeSourceDua()
{
	videoPlayer->mediaObject()->setCurrentSource(sources.at(2)); 
	volumeSlider->setValue(videoPlayer->volume()*100);  
   	timeSlider->setRange(0,videoPlayer->mediaObject()->totalTime());
    qDebug(QString::number(videoPlayer->mediaObject()->totalTime()).toLatin1().data()); 
}
