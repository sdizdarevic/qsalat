
#include <iostream>

using namespace std;

#include "domparser.h"

DomParser::DomParser()
{    
}

bool DomParser::changed = false; 

bool DomParser::readFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        std::cerr << "Error: Cannot read file " << qPrintable(fileName)
                  << ": " << qPrintable(file.errorString())
                  << std::endl;
        return false;
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
        std::cerr << "Error: Not a bookindex file" << std::endl;
        return false;
    }

    parseBookindexElement(root);
    return true;
}

void DomParser::parseBookindexElement(const QDomElement &element)
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
        else if (child.toElement().tagName() == "city") {
            params[0][2] = parsePageElement(child.toElement());
        }
        else if (child.toElement().tagName() == "country") {
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
        else if (child.toElement().tagName() == "fajr") {
            params[3][0] =  parsePageElement(child.toElement());
        }
        else if (child.toElement().tagName() == "duhr") {
            params[3][1] =  parsePageElement(child.toElement());
        }
        else if (child.toElement().tagName() == "asr") {
            params[3][2] =  parsePageElement(child.toElement());
        }
        else if (child.toElement().tagName() == "maghreb") {
            params[3][3] =  parsePageElement(child.toElement());
        }
        else if (child.toElement().tagName() == "isha") {
            params[3][4] =  parsePageElement(child.toElement());
        }       
        child = child.nextSibling();
    }
}

QString DomParser::parsePageElement(const QDomElement &element)
{
    QString page = element.text();    
    //cout << page.toLatin1().data() << endl;
    return page;
}

void DomParser::changeElement(QString text, int index1, int index2){
	//cout << "avant : " << params[index1][index2].toLatin1().data() << endl;
	params[index1][index2] = text;
	//cout << "apres : " << params[index1][index2].toLatin1().data() << endl;	
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
		    << "		<city>" << Qt::escape(params[0][2]) << "</city>\n"
			<< "		<country>" << Qt::escape(params[0][3]) << "</country>\n"
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
			<< "	<prayers>\n"
			<< "		<fajr>" << Qt::escape(params[3][0]) << "</fajr>\n"
			<< "		<duhr>" << Qt::escape(params[3][1]) << "</duhr>\n"
			<< "		<asr>" << Qt::escape(params[3][2]) << "</asr>\n"
			<< "		<maghreb>" << Qt::escape(params[3][3]) << "</maghreb>\n"
			<< "		<isha>" << Qt::escape(params[3][4]) << "</isha>\n"
			<< "	</prayers>\n"
			<< "</qsalat>\n";
	 }
}
