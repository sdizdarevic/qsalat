/****************************************************************************
** Qsalat project V1.0
** qlocation.h
**
** Copyright (C) 2008 Skander Jabouzi (Skander Software Solutions).
** Contact: skander@skanderjabouzi.com or jabouzi@gmail.com
**
** This file is part of the Qsalat open source software.
**
** GNU General Public License Usage
** This file may be used under the terms of the GNU
** General Public License versions 2.0 or 3.0 as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file.  Please review the following information
** to ensure GNU General Public Licensing requirements will be met:
** http://www.fsf.org/licensing/licenses/info/GPLv2.html and
** http://www.gnu.org/copyleft/gpl.html.  In addition, as a special
** exception, Nokia gives you certain additional rights. These rights
** are described in the Nokia Qt GPL Exception version 1.3, included in
** the file GPL_EXCEPTION.txt in this package.
**
***************************************************************************/

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
#include "qcalculation.h"
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
	Qcalculation calculation;	
	QString path;
};
#endif




