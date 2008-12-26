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

void Qworldtime::closeEvent(QCloseEvent *event)
{
	hide();
	event->ignore();
}

void Qworldtime::setUI()
{
	setWindowIcon(QIcon("images/mecque.png"));	
}
