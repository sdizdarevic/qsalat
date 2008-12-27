#ifndef __QMONTHLY_H__
#define __QMONTHLY_H__

#include <QtGui>
#include <QString>
#include "ui_monthly.h"
#include "utils.h"
#include "qpray.h"
#include "domparser.h"

class Qmonthly : public QDialog, public Ui::Monthly
{
Q_OBJECT
public:
	Qmonthly( QWidget * parent = 0, Qt::WFlags f = 0 );	
	
protected:
	void closeEvent(QCloseEvent *);
	
private slots:
	 void generate();
	 void load();
		
private:
	 void setUI();
	 void setMethods();
	 void init();
	 void setActions();
	 QDate date;
	 Qpray *prayers;
	 DomParser parser;
	 QString file;
	 int calcMethod;
	 int asrMethod;
	 int duhrMinutes;
	
};


#endif // __QMONTHLY_H__
