/****************************************************************************
** Qsalat project V1.0
** qyearly.h
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

#ifndef __QYEARLY_H__
#define __QYEARLY_H__

#include <QtGui>
#include "ui_yearly.h"
#include "utils.h"
#include "qpray.h"
#include "domparser.h"

class Qyearly : public QDialog, public Ui::Yearly
{
Q_OBJECT
public:
	Qyearly( QWidget * parent = 0, Qt::WFlags f = 0 );	
	
private slots:
	 void generate();
	 void load();

protected:
	void closeEvent(QCloseEvent *);
	
private:
	 void setUI();
	 void init();
	 void setActions();
	 QDate date;
	 Qpray *prayers;
	 DomParser parser;
	 QString file;
	 int calcMethod;
	 int asrMethod;
	 int duhrMinutes;
	 QString path;
};


#endif // __QYEARLY_H__
