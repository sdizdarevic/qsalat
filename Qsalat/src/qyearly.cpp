#include "qyearly.h"

Qyearly::Qyearly( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);	
	setUI();
}

void Qyearly::closeEvent(QCloseEvent *event)
{
	hide();
	event->ignore();
}

void Qyearly::setUI()
{
	setWindowIcon(QIcon("images/mecque.png"));
	selectButton->setIcon(style()->standardIcon(QStyle::SP_DialogOpenButton));
}
