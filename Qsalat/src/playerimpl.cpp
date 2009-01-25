#include "playerimpl.h"
//
PlayerImpl::PlayerImpl( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
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
}

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
	/*move (x, y);
	screenx = x;
	screeny = y;*/
}

void PlayerImpl::setAudio(QString file)
{
	audioSource = file;
}

void PlayerImpl::setLabel(QString label_)
{
	//audioLabel =  label;
	label->setText(label_);
}

QString PlayerImpl::getLabel()
{
	return audioLabel;	
}

void PlayerImpl::autoPlay()
{	
	playButton->animateClick(100);		
}

QString PlayerImpl::getAudio()
{
	return audioSource;
}

void PlayerImpl::setActions(){
	connect(playButton, SIGNAL(clicked()), this, SLOT(play()));
	connect(stopButton, SIGNAL(clicked()), this, SLOT(stop()));
	connect(mediaObject, SIGNAL(finished()), this, SLOT(finished()));
	connect(audioOutput, SIGNAL(volumeChanged ( qreal )), this, SLOT(setVolume()));
}


void PlayerImpl::setUI(){
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

void PlayerImpl::stop()
{
	mediaObject->stop();
	playIcon = style()->standardIcon(QStyle::SP_MediaPlay);
	playButton->setIcon(playIcon);
}

void PlayerImpl::setVolume()
{
    if (audioOutput->volume () == 0.0) volumeLabel->setPixmap(mutedIcon);
    else volumeLabel->setPixmap(volumeIcon);       
}

void PlayerImpl::finished()
{
	stop();
	hide();
}

void PlayerImpl::closeEvent(QCloseEvent *event)
{
	stop();
	hide();	
}
//
