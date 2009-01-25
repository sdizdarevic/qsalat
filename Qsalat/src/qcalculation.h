#ifndef __CALCULATION_H__
#define __CALCULATION_H__

#include <QtGui>
#include <QString>
#include "ui_calculation.h"
#include "domparser.h"
#include "qpray.h"

class Qcalculation : public QDialog, public Ui::Calculation
{
Q_OBJECT
public:
	Qcalculation( QWidget * parent = 0, Qt::WFlags f = 0 );	
	void init(int);
	void apply_();

//signals:
//	void apply_();
	
protected:
	void closeEvent(QCloseEvent *);
	
private slots:	
	void save();
	void cancel();
	void apply();
	
private:
	 void setUI();	 
	 void setActions();
	 DomParser parser;
	 QString file;
	 QStringList list;	
	 QStringList hList;
	 QString path;
	 Qpray *prayers;
	 QDate date;
	 QString *times;
	 int calcMethod;
	 int asrMethod;
	 int duhrMinutes;
	 int calcTime(QString,QString);
	 int getDuhrMinutes();
	 int setDuhrMinutes();
	 int getAsrDiff(int,QString,QString);
	 int asrMinutes;
};

#endif // __CALCULATION_H__
