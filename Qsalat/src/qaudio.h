#ifndef __QAUDIO_H__
#define __QAUDIO_H__

#include <QtGui>
#include <phonon>
#include "ui_audio.h"
class Qaudio : public QDialog, public Ui::Audio
{
Q_OBJECT
public:
	Qaudio( QWidget * parent = 0, Qt::WFlags f = 0 );

public slots:

protected:
	void closeEvent(QCloseEvent *);

signals:

private:
	QIcon playIcon;
    QIcon pauseIcon;
    QIcon stopIcon;
    QPixmap volumeIcon;
    QPixmap mutedIcon;
    Phonon::SeekSlider *seekSlider;
    Phonon::MediaObject *mediaObject;
    Phonon::MediaObject *metaInformationResolver;
    Phonon::VolumeSlider *volumeSlider;
    Phonon::AudioOutput *audioOutput;
    void setActions();
    void setUI();
    bool isplay;    

private slots:
	void loadPrayer();
	void loadFajr();
	void loadDua();
	void play();
	void stop();
	void setVolume(int);
	void save();
	void cancel();
};

#endif // __QAUDIO_H__
