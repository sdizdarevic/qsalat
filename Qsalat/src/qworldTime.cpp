#include "qworldTime.h"

Qworldtime::Qworldtime( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);	
	setUI();	
}

void Qworldtime::setImage(QString img)
{
	QImage image(img);	
	label->setPixmap(QPixmap::fromImage(image));
}

QString Qworldtime::getImage(int hour, int timezone)
{
	return "images/worldtime/img"+QString::number(abs(24 - (hour - int(timezone))))+".jpg";
}

void Qworldtime::closeEvent(QCloseEvent *event)
{
	hide();
	event->ignore();
}

void Qworldtime::setUI()
{
	setWindowIcon(QIcon("images/mecque.png"));	
}


