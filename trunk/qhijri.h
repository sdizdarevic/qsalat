#ifndef __HIJRI_H__
#define __HIJRI_H__

#include <cmath>
#include <stdlib.h>
#include <QString>
class Qhijri{
public:
	Qhijri();
	~Qhijri();
	int intPart(int);
	int* chrToIsl(int, int, int);
	int* islToChr(int, int, int);
	QString* isToString(int, int, int);
};
#endif // __HIJRI_H__
