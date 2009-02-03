/****************************************************************************
** Qsalat project V1.0
** playerimpl.cpp
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

#include "playerimpl.h"

//
PlayerImpl::PlayerImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	path = QCoreApplication::applicationDirPath ();
	if (path.data()[path.size() - 1] != '/') path += "/";
	setupUi(this);
	audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
	mediaObject = new Phonon::MediaObject(this);
	metaInformationResolver = new Phonon::MediaObject(this);
	mediaObject->setTickInterval(1000);   
	setUI();
	setActions();
	Phonon::createPath(mediaObject, audioOutput);
	adjustWindow();
	setWindowFlags(Qt::WindowStaysOnTopHint);
	rect = this->geometry();	
	region = QRegion::QRegion(rect);
	this->setGeometry(screenWidth - width - 10,screenHeight - height - 10,screenWidth, screenHeight);	
	timeLabel->installEventFilter(this);
	timeLeft = false;
	index = 0;
	//play2 = false;
}

//
void PlayerImpl::closeEvent(QCloseEvent *event)
{
	stop();
	hide();	
	event->ignore();
}

//
void PlayerImpl::adjustWindow(){
	QDesktopWidget *desktop = QApplication::desktop();
	int x, y;
	QSize windowSize;	 
	screenWidth = desktop->width(); 
	screenHeight = desktop->height();
	windowSize = size(); 
	width = windowSize.width(); 
	height = windowSize.height();	
	x = (screenWidth - width - 15);
	y = (screenHeight - height - 50);
}

//
void PlayerImpl::setAudio(QStringList files)
{
	audioSource = files;
}

//
void PlayerImpl::setLabel(QString label_)
{
	label->setText(label_);
}

//
void PlayerImpl::autoPlay()
{	
	playButton->animateClick(100);		
}

//
QString PlayerImpl::getAudio()
{
	return audioSource.at(index++);;
}

//
void PlayerImpl::setActions(){
	connect(playButton, SIGNAL(clicked()), this, SLOT(play()));
	connect(stopButton, SIGNAL(clicked()), this, SLOT(stop()));
	connect(mediaObject, SIGNAL(finished()), this, SLOT(finished()));
	connect(audioOutput, SIGNAL(volumeChanged ( qreal )), this, SLOT(setVolume()));
	connect(mediaObject, SIGNAL(totalTimeChanged(qint64)), this, SLOT(updateTime()));
	connect(mediaObject, SIGNAL(tick(qint64)), this, SLOT(updateTime()));		
}

//
void PlayerImpl::setUI(){
	setWindowIcon(QIcon(path+"images/mecque.png"));
    playIcon = style()->standardIcon(QStyle::SP_MediaPlay);
    playButton->setIcon(playIcon);
    stopIcon = style()->standardIcon(QStyle::SP_MediaStop);
    stopButton->setIcon(stopIcon);
    volumeIcon = style()->standardPixmap(QStyle::SP_MediaVolume);
    mutedIcon = style()->standardPixmap(QStyle::SP_MediaVolumeMuted);
    volumeLabel->setPixmap(volumeIcon);
    seekSlider = new Phonon::SeekSlider(this);   
    seekSlider->setMediaObject(mediaObject);    
    QHBoxLayout *seekerLayout = new QHBoxLayout;
    seekerLayout->addWidget(seekSlider);  
    playerFrame->setLayout(seekerLayout);     
    
    volumeSlider = new Phonon::VolumeSlider(this);
    volumeSlider->setAudioOutput(audioOutput);
    volumeSlider->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);    
    QHBoxLayout *volumeLayout = new QHBoxLayout;
    volumeLayout->addWidget(volumeSlider);  
    volumeFrame->setLayout(volumeLayout);
}

//
void PlayerImpl::play()
{         
	if (mediaObject->state() == Phonon::LoadingState || mediaObject->state() == Phonon::StoppedState){      
	Phonon::MediaSource source(getAudio());
	mediaObject->setCurrentSource(source);
	metaInformationResolver->setCurrentSource(source);
	mediaObject->play();
	playIcon = style()->standardIcon(QStyle::SP_MediaPause);
	playButton->setIcon(playIcon);
	}
	else if (mediaObject->state() == Phonon::PlayingState) {
		mediaObject->pause();           
		playIcon = style()->standardIcon(QStyle::SP_MediaPlay);
		playButton->setIcon(playIcon);  
	}
	else if (mediaObject->state() == Phonon::PausedState) {
		mediaObject->play();
		playIcon = style()->standardIcon(QStyle::SP_MediaPause);
		playButton->setIcon(playIcon);
	}
}

//
void PlayerImpl::stop()
{
	mediaObject->stop();
	playIcon = style()->standardIcon(QStyle::SP_MediaPlay);
	playButton->setIcon(playIcon);
	updateTime();
}

//
void PlayerImpl::setVolume()
{
    if (audioOutput->volume () == 0.0) volumeLabel->setPixmap(mutedIcon);
    else volumeLabel->setPixmap(volumeIcon);       
}

//
void PlayerImpl::finished()
{
	stop();	
	if (play2 && index < audioSource.size())
		autoPlay();	
	else hide();
}

// show playing time (left or elapsed just click on the label to switch)
void PlayerImpl::updateTime()
{
	QString sign = "";
    long len = mediaObject->totalTime();
    long pos = mediaObject->currentTime();
    if (timeLeft == true) {
    	pos = len -pos;
    	sign = "-";    	
	}
    QString timeString;    
    if (pos || len)
    {
        int sec = pos/1000;
        int min = sec/60;
        int hour = min/60;
        int msec = pos;

        QTime playTime(hour%60, min%60, sec%60, msec%1000);
        sec = len / 1000;
        min = sec / 60;
        hour = min / 60;
        msec = len;

        QTime stopTime(hour%60, min%60, sec%60, msec%1000);
        QString timeFormat = "m:ss";
        if (hour > 0)
            timeFormat = "h:mm:ss";        
        timeString = playTime.toString(timeFormat);
        if (len)
           sign += timeString;         
    }
    timeLabel->setText(sign);
}

// switch between time left or elapsed one
void PlayerImpl::changeSign(){	
	timeLeft = !timeLeft;
}

// detect click on the time label
bool PlayerImpl::eventFilter(QObject *o, QEvent *e)
{
    if (e->type() == QEvent::MouseButtonPress)
    {
        if (o == timeLabel)
        {
            changeSign();
            return TRUE;
        }
    }

    return QWidget::eventFilter(o, e);
}

void PlayerImpl::setPlay2(bool play2_)
{
	play2 = play2_;
}
//
