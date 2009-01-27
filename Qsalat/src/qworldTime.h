/****************************************************************************
** Qsalat project V1.0
** qworldtime.h
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

#ifndef __WORLDTIME_H__
#define __WORLDTIME_H__

#include <QtGui>
#include "ui_worldtime.h"

class Qworldtime : public QDialog, public Ui::WorldTime
{
Q_OBJECT
public:
	Qworldtime( QWidget * parent = 0, Qt::WFlags f = 0 );	
	void setImage(QString);
	QString getImage(int,int);

protected:
	void closeEvent(QCloseEvent *);
	
private:
	 void setUI();	
	 QString path;
};

#endif // __WORLDTIME_H__
