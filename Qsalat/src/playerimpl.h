#ifndef PLAYERIMPL_H
#define PLAYERIMPL_H
//
#include <QDialog>
#include <QtGui>
#include <QString>
#include <phonon>
#include "ui_player.h"
//
class PlayerImpl : public QDialog, public Ui::Player
{
Q_OBJECT
public:
	PlayerImpl( QWidget * parent = 0, Qt::WFlags f = 0 );
	
public slots:
	void play();
	void stop();
	void setAudio(QString);
	QString getAudio();
	void setLabel(QString);
	QString getLabel();
	void autoPlay();
	
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
    QString audioSource;
    QString audioLabel;
    QString audioLabel_2;
    void adjustWindow();
    int screenx;
	int screeny;
	QRect rect;
	QRegion region;
	int screenWidth; 
	int screenHeight;
	int width; 
	int height;
	void closeEvent(QCloseEvent *);

private slots:
	void setVolume();
	void finished();
};
#endif




