#ifndef __QMONTHLY_H__
#define __QMONTHLY_H__

#include <QtGui>
#include <QString>
#include "ui_monthly.h"

class Qmonthly : public QDialog, public Ui::Monthly
{
Q_OBJECT
public:
	Qmonthly( QWidget * parent = 0, Qt::WFlags f = 0 );	
	
public slots:	

protected:
	void closeEvent(QCloseEvent *);
	
signals:	
	
private:
	 void setUI();
	 void setMethods();
};


#endif // __QMONTHLY_H__
