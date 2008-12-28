#ifndef __QYEARLY_H__
#define __QYEARLY_H__

#include <QtGui>
#include "ui_yearly.h"
#include "utils.h"
#include "qpray.h"
#include "domparser.h"

class Qyearly : public QDialog, public Ui::Yearly
{
Q_OBJECT
public:
	Qyearly( QWidget * parent = 0, Qt::WFlags f = 0 );	
	
private slots:
	 void generate();
	 void load();

protected:
	void closeEvent(QCloseEvent *);
	
private:
	 void setUI();
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


#endif // __QYEARLY_H__
