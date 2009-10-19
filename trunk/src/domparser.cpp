/****************************************************************************
** Qsalat project V1.0
** domparser.cpp
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

#include <iostream>

using namespace std;

#include "domparser.h"

DomParser::DomParser()
{    
	QDir dir;
#ifdef Q_WS_X11
	if (!dir.exists(QDir::homePath ()+"/.qsalat/")) dir.mkdir(QDir::homePath ()+"/.qsalat/");
	if (!dir.exists(QDir::homePath ()+"/.qsalat/config/")) dir.mkdir(QDir::homePath ()+"/.qsalat/config/");	
#endif	
	
}

bool DomParser::changed = false; 

bool DomParser::readFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        saveDefault();
    }

    QString errorStr;
    int errorLine;
    int errorColumn;

    QDomDocument doc;
    if (!doc.setContent(&file, false, &errorStr, &errorLine,
                        &errorColumn)) {
        std::cerr << "Error: Parse error at line " << errorLine << ", "
                  << "column " << errorColumn << ": "
                  << qPrintable(errorStr) << std::endl;
        return false;
    }

    QDomElement root = doc.documentElement();
    if (root.tagName() != "qsalat") {
        std::cerr << "Error: Not a qsalat file" << std::endl;
        return false;
    }

    parseindexElement(root);
    return true;
}

void DomParser::parseindexElement(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {
        if (child.toElement().tagName() == "location")
            parseEntryElement(child.toElement());
        else if (child.toElement().tagName() == "audio")
            parseEntryElement(child.toElement());
        else if (child.toElement().tagName() == "calculation")
            parseEntryElement(child.toElement());
        else if (child.toElement().tagName() == "prayers")
            parseEntryElement(child.toElement());
        child = child.nextSibling();
    }
}

void DomParser::parseEntryElement(const QDomElement &element)
{
    QDomNode child = element.firstChild();
    while (!child.isNull()) {        
        if (child.toElement().tagName() == "latitude") {
            params[0][0] = parsePageElement(child.toElement());
        }
        else if (child.toElement().tagName() == "longitude") {
            params[0][1] = parsePageElement(child.toElement());
        }
        else if (child.toElement().tagName() == "country") {
            params[0][2] = parsePageElement(child.toElement());
        }
        else if (child.toElement().tagName() == "city") {
            params[0][3] = parsePageElement(child.toElement());
        }
        else if (child.toElement().tagName() == "timezone") {
            params[0][4] = parsePageElement(child.toElement());
        }
        else if (child.toElement().tagName() == "prayer") {
            params[1][0] = parsePageElement(child.toElement());
        }
        else if (child.toElement().tagName() == "fajrPrayer") {
            params[1][1] = parsePageElement(child.toElement());
        }
        else if (child.toElement().tagName() == "dua") {
            params[1][2] = parsePageElement(child.toElement());
        }
        else if (child.toElement().tagName() == "playAthan") {
            params[1][3] = parsePageElement(child.toElement());
        }
        else if (child.toElement().tagName() == "playDua") {
            params[1][4] = parsePageElement(child.toElement());
        }
        else if (child.toElement().tagName() == "method") {
            params[2][0] =  parsePageElement(child.toElement());
        }
        else if (child.toElement().tagName() == "duhr") {
            params[2][1] =  parsePageElement(child.toElement());
        }
        else if (child.toElement().tagName() == "asr") {
            params[2][2] =  parsePageElement(child.toElement());
        }
        else if (child.toElement().tagName() == "hijri") {
            params[2][3] =  parsePageElement(child.toElement());
        }
        else if (child.toElement().tagName() == "higherLat") {
            params[2][4] =  parsePageElement(child.toElement());
        }        
        child = child.nextSibling();
    }
}

QString DomParser::parsePageElement(const QDomElement &element)
{
    QString page = element.text();  
    return page;
}

void DomParser::changeElement(QString text, int index1, int index2)
{	
	params[index1][index2] = text;
}

QString DomParser::getElement( int index1, int index2)
{
	return params[index1][index2];
}

void DomParser::saveData(QString file){
	QFile data(file);
	 if (data.open(QFile::WriteOnly | QFile::Truncate)) {
		 QTextStream out(&data);
		 out.setCodec("UTF-8");
		 out << "<?xml version=\"1.0\" ?>\n"
			<< "<qsalat>\n"
			<< "	<location>\n"
			<< "		<latitude>" << Qt::escape(params[0][0]) << "</latitude>\n"
			<< "		<longitude>" << Qt::escape(params[0][1]) << "</longitude>\n"
			<< "		<country>" << Qt::escape(params[0][2]) << "</country>\n"
		    << "		<city>" << Qt::escape(params[0][3]) << "</city>\n"
			<< "		<timezone>" << Qt::escape(params[0][4]) << "</timezone>\n"
			<< "	</location>\n"
			<< "	<audio>\n"
			<< "		<prayer>" << Qt::escape(params[1][0]) << "</prayer>\n"
			<< "		<fajrPrayer>" << Qt::escape(params[1][1]) << "</fajrPrayer>\n"
			<< "		<dua>" << Qt::escape(params[1][2]) << "</dua>\n"
			<< "		<playAthan>" << Qt::escape(params[1][3]) << "</playAthan>\n"
			<< "		<playDua>" << Qt::escape(params[1][4]) << "</playDua>\n"
			<< "	</audio>\n"
			<< "	<calculation>\n"
			<< "		<method>" << Qt::escape(params[2][0]) << "</method>	\n"	
			<< "		<duhr>" << Qt::escape(params[2][1]) << "</duhr>\n"
			<< "		<asr>" << Qt::escape(params[2][2]) << "</asr>\n"
			<< "		<hijri>" << Qt::escape(params[2][3]) << "</hijri>\n"
			<< "		<higherLat>" << Qt::escape(params[2][4]) << "</higherLat>\n"
			<< "	</calculation>\n"
			<< "</qsalat>\n";
	 }
 }
	 
void DomParser::saveDefault(){
	QString file;
	QString path;	
#ifdef Q_WS_WIN	
	path = QCoreApplication::applicationDirPath ();
	file = path+"data/qsalat.xml";
#else 
	path = "/usr/share/qsalat/";
	file = QDir::homePath ()+"/.qsalat/config/qsalat.xml";	
#endif	
	if (path.data()[path.size() - 1] != '/') path += "/";
	QFile data(file);
	 if (data.open(QFile::WriteOnly | QFile::Truncate)) {
		 QTextStream out(&data);
		 out.setCodec("UTF-8");
		 out << "<?xml version=\"1.0\" ?>\n"
			<< "<qsalat>\n"
			<< "	<location>\n"
			<< "		<latitude>45.545447</latitude>\n"
			<< "		<longitude>-73.639076</longitude>\n"
			<< "		<country>Canada</country>\n"
		    << "		<city>Montreal</city>\n"
			<< "		<timezone>-5</timezone>\n"
			<< "	</location>\n"
			<< "	<audio>\n"
			<< "		<prayer>" << path+"audio/athan.mp3" << "</prayer>\n"
			<< "		<fajrPrayer>" << path+"audio/athanFajr.mp3" << "</fajrPrayer>\n"
			<< "		<dua>" << path+"audio/dua.mp3" << "</dua>\n"
			<< "		<playAthan>1</playAthan>\n"
			<< "		<playDua>1</playDua>\n"
			<< "	</audio>\n"
			<< "	<calculation>\n"
			<< "		<method>3</method>	\n"	
			<< "		<duhr>0</duhr>\n"
			<< "		<asr>0</asr>\n"
			<< "		<hijri>0</hijri>\n"
			<< "		<higherLat>0</higherLat>\n"
			<< "	</calculation>\n"
			<< "</qsalat>\n";
	 }
}
