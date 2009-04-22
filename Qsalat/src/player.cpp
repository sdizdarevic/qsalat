/****************************************************************************
** Qsalat project V1.0
** player.cpp
**
** Copyright (C) 2008 Skander Jabouzi (Skander Software Solutions).
** Contact: skander@skanderjabouzi.com or jabouzi@gmail.com
**
** This file is part of the Player open source software.
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

#include "player.h"
//
Player::Player( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	path = QCoreApplication::applicationDirPath ();
	if (path.data()[path.size() - 1] != '/') path += "/";
	setupUi(this);
	audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
	mediaObject = new Phonon::MediaObject(this);
	Phonon::createPath(mediaObject, audioOutput);
	mediaObject->setTickInterval(1000);   
	setUI();
	setActions();
	timeLabel->installEventFilter(this);
	volumeLabel->installEventFilter(this);
	timeLeft = false;	
	init();
	adjustWindow();
	setWindowFlags(Qt::WindowStaysOnTopHint);
	this->setGeometry(screenWidth - width - 10,screenHeight - height - 10,screenWidth, screenHeight);	
}

void Player::init()
{
	index = 0;
	playing = 0;
	stopped = false;
	playButton->setEnabled(false);
	stopButton->setEnabled(false);
	newLoad = true;
}

// adjust window position to center of the screen
void Player::adjustWindow()
{
	QDesktopWidget *desktop = QApplication::desktop();
	int x, y;
	QSize windowSize;	 
	screenWidth = desktop->width(); 
	screenHeight = desktop->height();
	windowSize = size(); 
	width = windowSize.width(); 
	height = windowSize.height();	
	x = (screenWidth - width) / 2;
	y = (screenHeight - height) / 2;
}

void Player::closeEvent(QCloseEvent *event)
{
	stop();
	close();
}

// set player label text
void Player::setLabel(QString title)
{
	label->setText(title);	
	this->setWindowTitle(title);
}

void Player::setAudio(QStringList list)
{
	init();	
	for (int i = 0; i < list.size(); i++){			
		Phonon::MediaSource source(list.at(i));
		sources.insert(i,source);			
	}	
	playButton->setEnabled(true);	
	stopButton->setEnabled(true);	
	mediaObject->setCurrentSource(getAudio());
}

// get the audio source file
Phonon::MediaSource Player::getAudio()
{
	if (playing == 1)
		index++;			
	if (playing == 2)
		index--;	
	return sources.at(index);	
}

// actions
void Player::setActions(){
	connect(playButton, SIGNAL(clicked()), this, SLOT(play()));
	connect(stopButton, SIGNAL(clicked()), this, SLOT(stop()));
	connect(mediaObject, SIGNAL(finished()), this, SLOT(finished()));
	connect(audioOutput, SIGNAL(volumeChanged ( qreal )), this, SLOT(setVolume()));
	connect(mediaObject, SIGNAL(totalTimeChanged(qint64)), this, SLOT(updateTime()));
	connect(mediaObject, SIGNAL(tick(qint64)), this, SLOT(updateTime()));	
	connect(mediaObject, SIGNAL(stateChanged(Phonon::State, Phonon::State)), this, SLOT(stateChanged(Phonon::State, Phonon::State)));
}

// set the player UI : buttons icons and sliders
void Player::setUI(){
	QColor *c = new QColor ( 238, 238, 157, 255 );	
	QPalette * p = new QPalette();
	p->setColor(QPalette::ToolTipBase,*c);
	QFont *f = new QFont ( "sans", 10, -1, false );	
	QToolTip::setFont ( *f );
	QToolTip::setPalette(*p);	
	setWindowIcon(QIcon(path+"images/audio.png"));
    playButton->setIcon(QIcon(path+"images/play.png"));
    playButton->setToolTip("Play");
    stopButton->setIcon(QIcon(path+"images/stop.png"));
    stopButton->setToolTip("Stop");
    volumeLabel->setPixmap(QPixmap::fromImage(QImage(path+"images/volume.png")));
    seekSlider = new Phonon::SeekSlider(this);   
    seekSlider->setMediaObject(mediaObject);    
    QHBoxLayout *seekerLayout = new QHBoxLayout;
    seekerLayout->addWidget(seekSlider);  
    playerFrame->setLayout(seekerLayout);    
    volumeSlider = new Phonon::VolumeSlider(this);   
    volumeSlider->setAudioOutput(audioOutput);
    volumeSlider->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum); 
    QSize *size = new QSize(0,0);
    volumeSlider->setIconSize(*size);   
    QHBoxLayout *volumeLayout = new QHBoxLayout;
    volumeLayout->addWidget(volumeSlider);  
    volumeFrame->setLayout(volumeLayout);
}

// play audio file
void Player::play()
{ 
	if (mediaObject->state() == Phonon::PlayingState)
		mediaObject->pause();
	else if (mediaObject->state() == Phonon::PausedState || mediaObject->state() == Phonon::LoadingState || mediaObject->state() == Phonon::StoppedState)
		mediaObject->play();
}

// show playing time (left or elapsed just click on the label to switch)
void Player::updateTime()
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
        QString timeFormat = "mm:ss";
        //if (hour > 0)
            //timeFormat = "hh:mm:ss";        
        timeString = playTime.toString(timeFormat);
        if (len)
           sign += timeString;        
    }
    timeLabel->setText(sign);
}

// stop playing
void Player::stop()
{
	mediaObject->stop();	
	updateTime();
}

// change the volume
void Player::setVolume()
{
	if (audioOutput->volume () == 0.0) volumeLabel->setPixmap(QPixmap::fromImage(QImage(path+"images/mute.png")));
	else volumeLabel->setPixmap(QPixmap::fromImage(QImage(path+"images/volume.png")));
}

// when the audio source is finished
void Player::finished(){
	stop();
	if (index < sources.size() - 1)
		next();
}

// switch between time left or elapsed one
void Player::changeSign(){	
	timeLeft = !timeLeft;
}

// detect click on the time label
bool Player::eventFilter(QObject *o, QEvent *e)
{
    if (e->type() == QEvent::MouseButtonPress)
    {
        if (o == timeLabel)
        {
            changeSign();
            return TRUE;
        }
        if (o == volumeLabel)
        {        	
        	if (audioOutput->volume () == 0.0) {
    			audioOutput->setVolume(1.0);
    			volumeLabel->setPixmap(QPixmap::fromImage(QImage(path+"images/volume.png")));
			}
    		else {
    			audioOutput->setVolume(0.0);
    			volumeLabel->setPixmap(QPixmap::fromImage(QImage(path+"images/mute.png"))); 
			}    		     
       	}
    }

    return QWidget::eventFilter(o, e);
}

// forward
void Player::next()
{
	playing = 1;
	mediaObject->setCurrentSource(getAudio());
	play();
	
}

// load media files
void Player::load()
{	
	sources.clear();
	QStringList list = QFileDialog::getOpenFileNames(this,tr("Open one or more files"),".",tr("audios (*.mp3 *.wma *.ogg *.wave *.midi *.avi *.mpeg *.mpg *.wmv *.divx *.xvid *.mp4 *.flv *.ogv)"));
	if (list.size() > 0){
		init();	
		for (int i = 0; i < list.size(); i++){			
			Phonon::MediaSource source(list.at(i));
			sources.insert(i,source);			
		}	
		playButton->setEnabled(true);	
		stopButton->setEnabled(true);
		mediaObject->setCurrentSource(getAudio());
		play();
	}
}

// detect the phonon status
void Player::stateChanged(Phonon::State newstate, Phonon::State oldstate)
{
	if (oldstate == Phonon::LoadingState){	
		playIcon = style()->standardIcon(QStyle::SP_MediaPause);
		playButton->setIcon(QIcon(path+"images/pause.png"));
		playButton->setToolTip("Pause");
	}
	if( newstate == Phonon::StoppedState || newstate == Phonon::PausedState){		
		playButton->setIcon(QIcon(path+"images/play.png"));
		playButton->setToolTip("Play");
	}
	else if (newstate == Phonon::PlayingState) {
		playButton->setIcon(QIcon(path+"images/pause.png")); 
		playButton->setToolTip("Pause"); 
	}	
	else if (newstate == Phonon::ErrorState) {	
            QMessageBox::warning(this, "Phonon Mediaplayer", mediaObject->errorString(), QMessageBox::Close);
            if (mediaObject->errorType() == Phonon::FatalError) {
                init();
            } else {
                mediaObject->pause();
            }
     }
}
//
