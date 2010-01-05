/****************************************************************************
** Qsalat project V1.0
** qhijri.h
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
#ifndef __HIJRI_H__
#define __HIJRI_H__

#include <cmath>
#include <stdlib.h>
#include <QString>
class Qhijri{
public:
	Qhijri();
	~Qhijri();
	int intPart(int);
	int* chrToIsl(int, int, int, int);
	int* islToChr(int, int, int, int);
	QString* isToString(int, int, int, int);
	QString* chrToString(int, int, int, int);
};
#endif // __HIJRI_H__
