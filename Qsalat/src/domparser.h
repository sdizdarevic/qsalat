#ifndef DOMPARSER_H
#define DOMPARSER_H

#include <QtGui>
#include <QtXml>
#include <QTextStream>

class DomParser
{
public:
    DomParser();

    bool readFile(const QString &fileName);
	void changeElement(QString text, int index1, int index2);
	void saveData();
	QString params[4][5];  
	
private:
    void parseBookindexElement(const QDomElement &element);
    void parseEntryElement(const QDomElement &element);
    QString parsePageElement(const QDomElement &element);  	  
};

#endif
