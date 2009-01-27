/****************************************************************************
** Qsalat project V1.0
** playerimpl.h
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
	void updateTime();
	void changeSign();
	
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
	QString path;
	bool eventFilter(QObject *, QEvent *);
	bool timeLeft;

private slots:
	void setVolume();
	void finished();
};
#endif




