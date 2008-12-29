#ifndef QQibla_H
#define QQibla_H
//
#include <QDialog>
#include "ui_qibla.h"
#include "domparser.h"
//
class Qqibla : public QDialog, public Ui::Qibla
{
Q_OBJECT
public:
	Qqibla( QWidget * parent = 0, Qt::WFlags f = 0 );	
	void paintEvent(QPaintEvent *);
	void init();
	double getQibla();
	
protected:
	void closeEvent(QCloseEvent *);
	
private slots:

private:
	DomParser parser;
	QString file;
	double latitude;
	double longitude;	
	double qiblaAngle;
	QString path;
};
#endif



