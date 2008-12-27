#ifndef __QHIJRIDATE_H__
#define __QHIJRIDATE_H__

#include <QtGui>
#include "ui_hijri.h"
#include "qhijri.h"

class Qhijridate : public QDialog, public Ui::Hijri
{
Q_OBJECT
public:
	Qhijridate( QWidget * parent = 0, Qt::WFlags f = 0 );	
	
protected:
	void closeEvent(QCloseEvent *);
	
private slots:
	void convert();
	void update();
	
private:
	 Qhijri *hijri;
	 void setUI();
	 void setActions();
	 QStringList glist;	
	 QStringList hlist;	
	 void init();
};

#endif // __QHIJRIDATE_H__
