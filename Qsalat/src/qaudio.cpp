#include "qaudio.h"

Qaudio::Qaudio( QWidget * parent, Qt::WFlags f) : QDialog(parent, f )
{
	//setWindowFlags(Qt::WindowMinimizeButtonHint);
	path = QCoreApplication::applicationDirPath ();
	setupUi(this);
	audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory, this);
	mediaObject = new Phonon::MediaObject(this);
	metaInformationResolver = new Phonon::MediaObject(this);
	mediaObject->setTickInterval(1000);   
	setUI();
	setActions();
	Phonon::createPath(mediaObject, audioOutput);
	isplay = true;
	file = path+"data/qsalat.xml";
	parser.readFile(file);	
	init();
}

void Qaudio::init()
{
	bool ok;
	prayerLineEdit->setText(parser.getElement(1,0));
    fajrLineEdit->setText(parser.getElement(1,1));
    duaLineEdit->setText(parser.getElement(1,2));
    if (0 == parser.getElement(1,3).toInt(&ok)) {
		salatCheckBox->setChecked(false); 		
	}
	else{
		salatCheckBox->setChecked(true);
	}
	if (0 == parser.getElement(1,4).toInt(&ok)) {
		duaCheckBox->setChecked(false); 		
	}
	else{
		duaCheckBox->setChecked(true);
	}
    
}

void Qaudio::closeEvent(QCloseEvent *event)
{
	hide();
	event->ignore();
}

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
	connect(mediaObject, SIGNAL(finished()), this, SLOT(finished()));
	connect(audioOutput, SIGNAL(volumeChanged ( qreal )), this, SLOT(setVolume()));
}


void Qaudio::setUI()
{
    setWindowIcon(QIcon(path+"images/mecque.png"));
    playIcon = style()->standardIcon(QStyle::SP_MediaPlay);
    playButton->setIcon(playIcon);
    stopIcon = style()->standardIcon(QStyle::SP_MediaStop);
    stopButton->setIcon(stopIcon);
    volumeIcon = style()->standardPixmap(QStyle::SP_MediaVolume);
    mutedIcon = style()->standardPixmap(QStyle::SP_MediaVolumeMuted);
    volumeLabel->setPixmap(volumeIcon);
    prayerButton->setIcon(style()->standardIcon(QStyle::SP_DialogOpenButton));
    fajrButton->setIcon(style()->standardIcon(QStyle::SP_DialogOpenButton));
    duaButton->setIcon(style()->standardIcon(QStyle::SP_DialogOpenButton));
    okButton->setIcon(style()->standardIcon(QStyle::SP_DialogOkButton));
    saveButton->setIcon(style()->standardIcon(QStyle::SP_DialogApplyButton));
    cancelButton->setIcon(style()->standardIcon(QStyle::SP_DialogCancelButton));
    
    seekSlider = new Phonon::SeekSlider(this);   
    seekSlider->setMediaObject(mediaObject);    
    QHBoxLayout *seekerLayout = new QHBoxLayout;
    seekerLayout->addWidget(seekSlider);  
    playerFrame->setLayout(seekerLayout);
     
    
    volumeSlider = new Phonon::VolumeSlider(this);
    //volumeSlider->setMuteVisible(true);
    volumeSlider->setAudioOutput(audioOutput);
    volumeSlider->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);    
    QHBoxLayout *volumeLayout = new QHBoxLayout;
    volumeLayout->addWidget(volumeSlider);  
    volumeFrame->setLayout(volumeLayout);
}

void Qaudio::loadPrayer()
{
        prayerLineEdit->setText(QFileDialog::getOpenFileName(this,tr("Open File"),".",tr("audios (*.mp3 *.wma *.ogg *.wave *.midi *.rm *.ram)")));
}

void Qaudio::loadFajr()
{
        fajrLineEdit->setText(QFileDialog::getOpenFileName(this,tr("Open File"),".",tr("audios (*.mp3 *.wma *.ogg *.wave *.midi *.rm *.ram)")));
}

void Qaudio::loadDua()
{
        duaLineEdit->setText(QFileDialog::getOpenFileName(this,tr("Open File"),".",tr("audios (*.mp3 *.wma *.ogg *.wave *.midi *.rm *.ram)")));
}

void Qaudio::play()
{       
        //if (isplay){  
        //QMessageBox::warning(this, tr("My Application"),QString::number(mediaObject->state()),QMessageBox::Ok);       
		QString audioFile = "";		
		if (regularRadioButton->isChecked()) audioFile = prayerLineEdit->text();
		else if (fajrRadioButton->isChecked()) audioFile = fajrLineEdit->text(); 
		else audioFile = duaLineEdit->text();   
        if (mediaObject->state() == Phonon::LoadingState || mediaObject->state() == Phonon::StoppedState){      
                Phonon::MediaSource source(audioFile);
                mediaObject->setCurrentSource(source);
                metaInformationResolver->setCurrentSource(source);
                mediaObject->play();
                //isplay = false;
                playIcon = style()->standardIcon(QStyle::SP_MediaPause);
                playButton->setIcon(playIcon);
        }
        else if (mediaObject->state() == Phonon::PlayingState) {
                mediaObject->pause();           
                playIcon = style()->standardIcon(QStyle::SP_MediaPlay);
                playButton->setIcon(playIcon);  
                //isplay = false;       
        }
        else if (mediaObject->state() == Phonon::PausedState) {
                mediaObject->play();
                playIcon = style()->standardIcon(QStyle::SP_MediaPause);
                playButton->setIcon(playIcon);
        }
}

void Qaudio::stop()
{
        mediaObject->stop();
        playIcon = style()->standardIcon(QStyle::SP_MediaPlay);
        playButton->setIcon(playIcon);
}

void Qaudio::setVolume()
{
    if (audioOutput->volume () == 0.0) volumeLabel->setPixmap(mutedIcon);
    else volumeLabel->setPixmap(volumeIcon);       
}

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


void Qaudio::save()
{
        apply();
        stop();
        close();
}

void Qaudio::cancel()
{
		mediaObject->stop();
        close();
}

void Qaudio::finished()
{
	stop();
}