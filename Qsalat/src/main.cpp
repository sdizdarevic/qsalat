#include <QApplication>
#include "qsalat.h"
//
int main(int argc, char ** argv)
{
	//path = QCoreApplication::applicationDirPath ();
	QApplication app( argc, argv );
	QPixmap pixmap("images/splash.png");
	QSplashScreen splash(pixmap);
	splash.show();
	//app.processEvents();
	Qsalat win;
	win.show(); 
	splash.finish(&win);
	app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
	return app.exec();
}
