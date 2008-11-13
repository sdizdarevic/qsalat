#include <QtGui>
#include "qqibla.h"

Qqibla::Qqibla( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
	setWindowIcon(QIcon("images/mecque.png"));
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
    painter.rotate(57); // l angle des minutes
    painter.drawConvexPolygon(minuteHand, 6);
    painter.restore();
    painter.setPen(minuteColor);
}

void Qqibla::closeEvent(QCloseEvent *event)
{
	hide();
	event->ignore();
}
