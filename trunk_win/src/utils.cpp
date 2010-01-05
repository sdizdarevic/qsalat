/****************************************************************************
** Qsalat project V1.0
** utils.cpp
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

#include "utils.h"

void Utils::saveFile(QString fileName, QString data)
{
	QFile file(fileName);	
	if (file.open(QIODevice::WriteOnly|QIODevice::Text)) {
  		file.write(data.toUtf8());
 	}	
}

QString Utils::readFile(QString fileName)
{
	QFile file(fileName);	
	file.open(QIODevice::ReadOnly|QIODevice::Text);
	QString data = QString::fromUtf8(file.readAll());	
	return data;
}
