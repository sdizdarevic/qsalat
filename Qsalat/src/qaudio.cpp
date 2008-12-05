#include "qaudio.h"

Qaudio::Qaudio( QWidget * parent, Qt::WFlags f)
	: QDialog(parent, f)
{
	setupUi(this);
	setUI();
	setActions();
}

void Qaudio::closeEvent(QCloseEvent *event)
{
	hide();
	event->ignore();
}

void Qaudio::setActions(){
	connect(prayerButton, SIGNAL(clicked()), this, SLOT(load1(prayerLineEdit)));
	connect(fajrButton, SIGNAL(clicked()), this, SLOT(load2()));
	connect(duaButton, SIGNAL(clicked()), this, SLOT(load3()));
	//connect(playButton, SIGNAL(clicked()), this, SLOT(play()));
	//connect(stopButton, SIGNAL(clicked()), this, SLOT(stop()));
	//connect(saveButton, SIGNAL(clicked()), this, SLOT(save()));
	//connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));
}


void Qaudio::setUI(){
	setWindowIcon(QIcon("images/mecque.png"));
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
    saveButton->setIcon(style()->standardIcon(QStyle::SP_DialogSaveButton));
    cancelButton->setIcon(style()->standardIcon(QStyle::SP_DialogCancelButton));
}

void Qaudio::load1(QLineEdit* lineEdit)
{
	lineEdit->setText(QFileDialog::getOpenFileName(this,tr("Open File"),".",tr("audios (*.mp3 *.wma *.ogg *.wave *.midi)")));
}

void Qaudio::load2()
{
	fajrLineEdit->setText(QFileDialog::getOpenFileName(this,tr("Open File"),".",tr("audios (*.mp3 *.wma *.ogg *.wave *.midi)")));
}

void Qaudio::load3()
{
	duaLineEdit->setText(QFileDialog::getOpenFileName(this,tr("Open File"),".",tr("audios (*.mp3 *.wma *.ogg *.wave *.midi)")));
}
