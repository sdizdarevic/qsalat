#ifndef __CALCULATION_H__
#define __CALCULATION_H__

#include <QtGui>
#include <QString>
#include "ui_calculation.h"
#include "domparser.h"

class Qcalculation : public QDialog, public Ui::Calculation
{
Q_OBJECT
public:
	Qcalculation( QWidget * parent = 0, Qt::WFlags f = 0 );	
	
protected:
	void closeEvent(QCloseEvent *);
	
private slots:	
	void save();
	void cancel();
	void apply();
	
private:
	 void setUI();
	 void init();
	 void setActions();
	 DomParser parser;
	 QString file;
	 QStringList list;		
};

#endif // __CALCULATION_H__
