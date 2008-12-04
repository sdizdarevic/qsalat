#include "qaudio.h"

Qaudio::Qaudio( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);	
	setUI();
}

void Qaudio::closeEvent(QCloseEvent *event)
{
	hide();
	event->ignore();
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
