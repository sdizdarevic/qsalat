#include <QApplication>
#include "qsalat.h"
#include "dsingleapplication.h"
//
int main(int argc, char ** argv)
{
	//QString path = QCoreApplication::applicationDirPath ();
	//if (path.data()[path.size() - 1] != '/') path += "/";
	QApplication app( argc, argv );
	app.setApplicationName( "Qsalat" );
	//DSingleApplication instance( "Qsalat" );
  
	  //if ( instance.isRunning() ) {
	    //instance.sendMessage( "Hey, i'm the other instance" );
	    //return 0;
	  //}
	//QPixmap pixmap(":/images/splash.png");
	//QPixmap pixmap(path+"images/splash.png");
	//QSplashScreen splash(pixmap);
	//splash.show();
	//app.processEvents();
	Qsalat win;
	win.show(); 
	//splash.finish(&win);
	app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
	return app.exec();
}
