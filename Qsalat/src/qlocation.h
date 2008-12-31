#ifndef QLOCATION_H
#define QLOCATION_H
//
#include <QDialog>
#include <QtGui>
#include <QWebView>
#include <QWebFrame>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QMessageBox>
#include <QVariant>
#include <QHttp>
#include "ui_location.h"
#include "domparser.h"
//
class Qlocation : public QDialog, public Ui::Location
{
Q_OBJECT
public:
	Qlocation( QWidget * parent = 0, Qt::WFlags f = 0 );
	void init(int);
	
private slots:
	void loadAddress(QString);
	void loadCoordinates(float,float);
	void showItem();
	void updateLatLng();
	void apply();
	void save();
	void cancel();
	void update();

protected:
	void closeEvent(QCloseEvent *);
	
signals:
	void reloadMap();
	void updateMap();
	
private:
	QNetworkAccessManager *manager;
	QList<QPointF> coordinates;
	DomParser parser;
	QString file;	
	float latitude;
	float longitude;
	QString country;
	QString city;
	int timezone;
	int pendingRequests;	
	void setActions();
	void setUI();	
	
	QString path;
};
#endif




