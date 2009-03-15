/****************************************************************************
** Qsalat project V1.0
** qworldtime.cpp
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

#include "qworldTime.h"

//
Qworldtime::Qworldtime( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
#ifdef Q_WS_WIN
	path = QCoreApplication::applicationDirPath ();
#else 
	path = "/usr/share/qsalat/";
#endif
	if (path.data()[path.size() - 1] != '/') path += "/";
	setupUi(this);	
	setUI();	
}

//set background image
void Qworldtime::setImage(QString img)
{
	QImage image(img);	
	label->setPixmap(QPixmap::fromImage(image));
}

//get background image
QString Qworldtime::getImage(int hour, int timezone)
{
	int number = hour - int(timezone);
	if (number >= 24) number = number -24;
	else if (number < 0) number = 24 - timezone;
	return path+"images/worldtime/img"+QString::number(number)+".jpg";
}

//
void Qworldtime::closeEvent(QCloseEvent *event)
{
	hide();
	event->ignore();
}

//
void Qworldtime::setUI()
{
	setWindowIcon(QIcon(path+"images/mecque.png"));	
}


