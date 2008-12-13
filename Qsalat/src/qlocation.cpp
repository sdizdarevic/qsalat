#include "qlocation.h"
//
Qlocation::Qlocation( QWidget * parent, Qt::WFlags f) 
	: QDialog(parent, f)
{
	setupUi(this);
	setUI();
	manager = new QNetworkAccessManager(this);
	setActions();
}

void Qlocation::geoCode(const QString& address)
{
	adress = address;
	clearCoordinates();
	QString requestStr( tr("http://maps.google.com/maps/geo?q=%1&output=%2&key=%3")
		.arg(address)
		.arg("csv")
		.arg("ABQIAAAADK2Z-2Uhvnv0BtjasvfxpBQ9r-JX5Ew3YiWGH5u4o4FZAQdnQRRB9I6-zAG7Un8nsXxMTDtquMbY2A") );
	//QMessageBox::warning(this, tr("My Application"),requestStr,QMessageBox::Ok);
	manager->get( QNetworkRequest(requestStr) );
	++pendingRequests;    
}

void Qlocation::replyFinished(QNetworkReply *reply)
{
    QString replyStr( reply->readAll() );
    QStringList coordinateStrList = replyStr.split(",");

    if( coordinateStrList.size() == 4) {
        QPointF coordinate( coordinateStrList[2].toFloat(),coordinateStrList[3].toFloat() );
        coordinates << coordinate;        
    }

    --pendingRequests;
    //if( pendingRequests<1 )
        reloadMap();        
}

void Qlocation::loadCoordinates()
{
    QStringList scriptStr;    
    foreach( QPointF point, coordinates ) {
        latLineEdit->setText(QString::number(point.x()));
        lngLineEdit->setText(QString::number(point.y()));
    }   
   scriptStr << QString("http://www.skanderjabouzi.com/qpray/?adr=%1")                        
                             .arg(adress);
    
    QUrl url(scriptStr.join("\n"));
    this->webView->load(url);
    //scriptStr << "document.getElementById(\"lat\").value;";
    //scriptStr << "alert(123);";
    //QVariant vres = webView->page()->mainFrame()->evaluateJavaScript( scriptStr.join("\n") );
    //QString sres = vres.toString();
    //QMessageBox::warning(this, tr("My Application"),sres,QMessageBox::Ok);
}

void Qlocation::clearCoordinates()
{
    coordinates.clear();   
}

void Qlocation::showItem()
{
    geoCode( locationLineEdit->text() );    
}

void Qlocation::updateLatLng(){
	QStringList scriptStr1,scriptStr2; 
	scriptStr1 << "document.getElementById(\"lat\").value;";
	QVariant vres1 = webView->page()->mainFrame()->evaluateJavaScript( scriptStr1.join("\n") );
    QString sres1 = vres1.toString();
    scriptStr2 << "document.getElementById(\"lng\").value;";
	QVariant vres2 = webView->page()->mainFrame()->evaluateJavaScript( scriptStr2.join("\n") );
    QString sres2 = vres2.toString();
    latLineEdit->setText(sres1);
    lngLineEdit->setText(sres2);
    /*QHttp *qhttp = new QHttp();
    qhttp->setHost ( "http://ws.geonames.org/timezone?lat=36.75&lng=10.30", 80 );
    const QString url = "http://ws.geonames.org/timezone?lat=36.75&lng=10.30";
    QFile file("res.xml");
    int getRes = qhttp->get ( url, file);*/
    
    apply();
    //"http://ws.geonames.org/timezone?lat=36.75&lng=10.30";
    //QMessageBox::warning(this, tr("My Application"),sres1,QMessageBox::Ok);
}

void Qlocation::closeEvent(QCloseEvent *event)
{
	hide();
	event->ignore();
}

void Qlocation::setActions(){
	connect(manager, SIGNAL(finished(QNetworkReply*)),this, SLOT(replyFinished(QNetworkReply*)));
    //connect(this,SIGNAL(loadFinished(ok)),this,SLOT(updateLatLng()));
    connect(this,SIGNAL(reloadMap()),this,SLOT(loadCoordinates()));
    connect(searchButton,SIGNAL(clicked()),this,SLOT(showItem()));  
    connect(applyButton,SIGNAL(clicked()),this,SLOT(updateLatLng()));
    connect(this,SIGNAL(updateMap()),this,SLOT(updateLatLng())); 
}

void Qlocation::setUI(){
	setWindowIcon(QIcon("images/mecque.png"));
	okButton->setIcon(style()->standardIcon(QStyle::SP_DialogOkButton));
	applyButton->setIcon(style()->standardIcon(QStyle::SP_DialogApplyButton));
	cancelButton->setIcon(style()->standardIcon(QStyle::SP_DialogCancelButton));
}

void Qlocation::apply()
{
	QString file = "data/qsalat.xml";
	parser.readFile(file);
	parser.changeElement(latLineEdit->text(),0,0);
	parser.changeElement(lngLineEdit->text(),0,1);
	parser.saveData(file);
	DomParser::changed = true; 
}

void Qlocation::save()
{
	apply();
	close();
}

void Qlocation::cancel()
{
	close();
}

//
