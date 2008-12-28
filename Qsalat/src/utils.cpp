#include "utils.h"

void Utils::saveFile(QString fileName, QString data)
{
	QFile file(fileName);	
	if (file.open(QIODevice::WriteOnly|QIODevice::Text)) {
  		file.write(data.toUtf8());
 	}	
}

QString Utils::readFile(QString fileName)
{
	QFile file(fileName);	
	file.open(QIODevice::ReadOnly|QIODevice::Text);
	QString data = QString::fromUtf8(file.readAll());	
	return data;
}
