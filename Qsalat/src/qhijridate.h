#ifndef __QHIJRIDATE_H__
#define __QHIJRIDATE_H__

#include <QtGui>
#include "ui_hijri.h"

class Qhijridate : public QDialog, public Ui::Hijri
{
Q_OBJECT
public:
	Qhijridate( QWidget * parent = 0, Qt::WFlags f = 0 );	
	
public slots:	

protected:
	void closeEvent(QCloseEvent *);
	
signals:	
	
private:
	 void setUI();
};

#endif // __QHIJRIDATE_H__
