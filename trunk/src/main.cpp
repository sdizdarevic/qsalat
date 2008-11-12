#include <QApplication>
#include "qsalat.h"
//
int main(int argc, char ** argv)
{
	QApplication app( argc, argv );
	Qsalat win;
	win.show(); 
	app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
	return app.exec();
}
