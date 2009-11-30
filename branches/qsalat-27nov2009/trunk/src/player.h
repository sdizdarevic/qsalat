/****************************************************************************
** Qsalat project V1.0
** player.h
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

#ifndef PLAYER_H
#define PLAYER_H
//
#include <QDialog>
#include <QtGui>
#include <QString>
#include <phonon>
#include "ui_player.h"
//
class Player : public QDialog, public Ui::Player
{
Q_OBJECT
public:
	Player( QWidget * parent = 0, Qt::WFlags f = 0 );
	void setLabel(QString);
	void setAudio(QStringList);
	
public slots:
	void play();
	
private:
	QIcon playIcon;
    QIcon pauseIcon;
    QIcon stopIcon;
    QIcon nextIcon;
    QIcon prevIcon;
    QPixmap volumeIcon;
    QPixmap mutedIcon;
    Phonon::SeekSlider *seekSlider;
    Phonon::MediaObject *mediaObject;
    Phonon::VolumeSlider *volumeSlider;
    Phonon::AudioOutput *audioOutput;
    Phonon::VideoWidget *videoWidget;
    QList<Phonon::MediaSource> sources;
    void setActions();
    void setUI();
    bool isplay;
    QStringList audioSource;
    QString audioLabel;
    void adjustWindow();
    int screenx;
	int screeny;
	bool eventFilter(QObject *, QEvent *);
	bool timeLeft;
	QString path;
	int index;
	bool stopped;
	int playing;
	bool newLoad;
	void init();
	void closeEvent(QCloseEvent *);	
	Phonon::MediaSource getAudio();	
	QRect rect;
	QRegion region;
	int screenWidth; 
	int screenHeight;
	int width; 
	int height;

private slots:
	void setVolume();
	void finished();
	void next();
	void load();
	void stop();
	void updateTime();
	void changeSign();
	void stateChanged ( Phonon::State, Phonon::State );
};
#endif




