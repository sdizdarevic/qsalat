/****************************************************************************
** Qsalat project V1.0
** qqibla.cpp
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

#include <QtGui>
#include "qqibla.h"

//
Qqibla::Qqibla( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
#ifdef Q_WS_WIN
	path = QCoreApplication::applicationDirPath ();
#else 
	path = "/usr/share/qsalat/";
#endif
	if (path.data()[path.size() - 1] != '/') path += "/";
	setupUi(this);
	setWindowIcon(QIcon(path+"images/mecque.png"));
	init();
}

// 
void Qqibla::init()
{
#ifdef Q_WS_WIN
	file = path+"data/qsalat.xml";
#else 
	file = QDir::homePath ()+"/.qsalat/config/qsalat.xml";
#endif	
	parser.readFile(file);
	bool ok;
	latitude = parser.getElement(0,0).toDouble(&ok);
	longitude = parser.getElement(0,1).toDouble(&ok);
	qiblaAngle = getQibla();		
}

//Qibla calculation
double Qqibla::getQibla(){	
	const double MLONG = 39.823333;
	const double MLAT = 21.42333;	
	const double Pi = 4.0*atan(1.0);
	
	double x1 = sin((-longitude+MLONG)*Pi/180);
	double y1 = cos(latitude*Pi/180) * tan(MLAT*Pi/180);
	double y2 = sin(latitude*Pi/180) *	cos((-longitude+MLONG)*Pi/180);
	double Result = atan(x1/(y1-y2))*180/Pi;
	if (Result < 0) Result = 360.0 + Result;
	
	if ((longitude < MLONG) && (longitude > MLONG-180)) {
		if (Result > 180)	Result = Result - 180;
	}
	if (Result > 360) Result =	Result - 360;	
	return Result;		
}

//Qibla direction 
void Qqibla::paintEvent(QPaintEvent *)
{
	static const QPoint minuteHand[6] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -70),
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, 40)        
    };
    
    QColor minuteColor(0, 0, 0, 191);

    int side = qMin(width(), height());    
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
    painter.scale(side / 200.0, side / 200.0);
    painter.setPen(Qt::NoPen);
    painter.setBrush(minuteColor);

    painter.save();
    painter.rotate(qiblaAngle); // minutes angle
    painter.drawConvexPolygon(minuteHand, 6);
    painter.restore();
    painter.setPen(minuteColor);
    label->setText("Qibla angle direction : "+QString::number(qiblaAngle)+"N");
}

//
void Qqibla::closeEvent(QCloseEvent *event)
{
	hide();
	event->ignore();
}
