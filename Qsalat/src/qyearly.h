#ifndef __QYEARLY_H__
#define __QYEARLY_H__

#include <QtGui>
#include "ui_yearly.h"

class Qyearly : public QDialog, public Ui::Yearly
{
Q_OBJECT
public:
	Qyearly( QWidget * parent = 0, Qt::WFlags f = 0 );	
	
public slots:	

protected:
	void closeEvent(QCloseEvent *);
	
signals:	
	
private:
	 void setUI();
};


#endif // __QYEARLY_H__
