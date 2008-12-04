#include "qmonthly.h"

Qmonthly::Qmonthly( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);	
	setUI();
	setMethods();
}

void Qmonthly::closeEvent(QCloseEvent *event)
{
	hide();
	event->ignore();
}

void Qmonthly::setUI()
{
	setWindowIcon(QIcon("images/mecque.png"));
	selectButton->setIcon(style()->standardIcon(QStyle::SP_DialogOpenButton));
}

void Qmonthly::setMethods()
{
	QStringList list;	
	list << "January"<<"February"<<"March"<<"April"<<"May"<<"June"<<"July"<<"August"<<"September"
		 <<"October"<<"November"<<"December";
		 //<<"Custom settings";	
	monthBox->addItems(list);	
}

