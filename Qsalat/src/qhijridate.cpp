#include "qhijridate.h"

Qhijridate::Qhijridate( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);	
	setUI();
}

void Qhijridate::closeEvent(QCloseEvent *event)
{
	hide();
	event->ignore();
}

void Qhijridate::setUI()
{
	setWindowIcon(QIcon("images/mecque.png"));
	convertButton->setIcon(style()->standardIcon(QStyle::SP_DialogApplyButton));
}

