#include <QtGui>
#include "qqibla.h"

Qqibla::Qqibla( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	path = QCoreApplication::applicationDirPath ();
	if (path.data()[path.size() - 1] != '/') path += "/";
	setupUi(this);
	setWindowIcon(QIcon(path+"images/mecque.png"));
	init();
}

void Qqibla::init()
{
	file = path+"data/qsalat.xml";
	parser.readFile(file);
	bool ok;
	latitude = parser.getElement(0,0).toDouble(&ok);
	longitude = parser.getElement(0,1).toDouble(&ok);
	qiblaAngle = getQibla();		
}

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
    painter.rotate(qiblaAngle); // l angle des minutes
    painter.drawConvexPolygon(minuteHand, 6);
    painter.restore();
    painter.setPen(minuteColor);
    label->setText("Qibla angle direction : "+QString::number(qiblaAngle)+"N");
}

void Qqibla::closeEvent(QCloseEvent *event)
{
	hide();
	event->ignore();
}
