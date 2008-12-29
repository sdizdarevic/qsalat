#include "qworldTime.h"

Qworldtime::Qworldtime( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	path = QCoreApplication::applicationDirPath ();
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
	int number = hour - int(timezone);
	if (number >= 24) number = number -24;
	else if (number < 0) number = 24 - timezone;
	return path+"images/worldtime/img"+QString::number(number)+".jpg";
}

void Qworldtime::closeEvent(QCloseEvent *event)
{
	hide();
	event->ignore();
}

void Qworldtime::setUI()
{
	setWindowIcon(QIcon(path+"images/mecque.png"));	
}


