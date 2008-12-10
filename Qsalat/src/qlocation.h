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
#include "ui_location.h"
//
class Qlocation : public QDialog, public Ui::Location
{
Q_OBJECT
public:
	Qlocation( QWidget * parent = 0, Qt::WFlags f = 0 );
	//double x, y;
	QString adress;
	void adjustWindow();
	
public slots:
	void replyFinished(QNetworkReply*);
	void loadCoordinates();
	void geoCode(const QString &address);
	void clearCoordinates();
	void showItem();
	void updateLatLng();

protected:
	void closeEvent(QCloseEvent *);
	
signals:
	void reloadMap();
	void updateMap();
	
private:
	QNetworkAccessManager *manager;
	QList<QPointF> coordinates;
	int pendingRequests;	
	void setActions();
	void setUI();
};
#endif




