#ifndef QQibla_H
#define QQibla_H
//
#include <QDialog>

#include "ui_qibla.h"
//
class Qqibla : public QDialog, public Ui::Qibla
{
Q_OBJECT
public:
	Qqibla( QWidget * parent = 0, Qt::WFlags f = 0 );	
	void paintEvent(QPaintEvent *);
	
protected:
	void closeEvent(QCloseEvent *);
	
private slots:
};
#endif



