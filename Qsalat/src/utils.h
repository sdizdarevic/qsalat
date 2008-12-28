#ifndef UTILS_H
#define UTILS_H
#include <QString>
#include <QFile>

class Utils{
	
public:
 void saveFile(QString fileName, QString data);	

 QString readFile(QString fileName);	
	
};

#endif // UTILS_H
