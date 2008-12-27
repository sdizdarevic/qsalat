#ifndef __WORLDTIME_H__
#define __WORLDTIME_H__

#include <QtGui>
#include "ui_worldtime.h"

class Qworldtime : public QDialog, public Ui::WorldTime
{
Q_OBJECT
public:
	Qworldtime( QWidget * parent = 0, Qt::WFlags f = 0 );	
	void setImage(QString);
	QString getImage(int,int);

protected:
	void closeEvent(QCloseEvent *);
	
private:
	 void setUI();	
};

#endif // __WORLDTIME_H__
