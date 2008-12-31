#ifndef __QHIJRIDATE_H__
#define __QHIJRIDATE_H__

#include <QtGui>
#include "ui_hijri.h"
#include "qhijri.h"
#include "domparser.h"

class Qhijridate : public QDialog, public Ui::Hijri
{
Q_OBJECT
public:
	Qhijridate( QWidget * parent = 0, Qt::WFlags f = 0 );	
	void init();
	
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
	 QString path;
	 DomParser parser;
	 QString file;
};

#endif // __QHIJRIDATE_H__
