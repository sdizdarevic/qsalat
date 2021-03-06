#############################################################################
# Makefile for building: Qsalat
# Generated by qmake (2.01a) (Qt 4.6.0) on: Tue Jan 5 23:31:09 2010
# Project:  Qsalat.pro
# Template: app
# Command: /usr/local/Trolltech/Qt-4.6.0/bin/qmake -unix -o Makefile Qsalat.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_WEBKIT_LIB -DQT_PHONON_LIB -DQT_XML_LIB -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/local/Trolltech/Qt-4.6.0/mkspecs/linux-g++ -I. -I/usr/local/Trolltech/Qt-4.6.0/include/QtCore -I/usr/local/Trolltech/Qt-4.6.0/include/QtNetwork -I/usr/local/Trolltech/Qt-4.6.0/include/QtGui -I/usr/local/Trolltech/Qt-4.6.0/include/QtXml -I/usr/local/Trolltech/Qt-4.6.0/include/phonon -I/usr/local/Trolltech/Qt-4.6.0/include/QtWebKit -I/usr/local/Trolltech/Qt-4.6.0/include -I/usr/local/Trolltech/Qt-4.6.0/include/phonon_compat/phonon -I/usr/local/Trolltech/Qt-4.6.0/include/phonon_compat -I/usr/local/Trolltech/Qt-4.6.0/include/phonon/Phonon -Ibuild -Ibuild
LINK          = g++
LFLAGS        = -Wl,-O1 -Wl,-rpath,/usr/local/Trolltech/Qt-4.6.0/lib
LIBS          = $(SUBLIBS)  -L/usr/local/Trolltech/Qt-4.6.0/lib -lQtWebKit -L/usr/local/Trolltech/Qt-4.6.0/lib -L/usr/X11R6/lib -lQtXmlPatterns -lphonon -lQtXml -lQtGui -lQtNetwork -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/local/Trolltech/Qt-4.6.0/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -sf
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = build/

####### Files

SOURCES       = src/qsalat.cpp \
		src/utils.cpp \
		src/main.cpp \
		src/qpray.cpp \
		src/qhijri.cpp \
		src/qqibla.cpp \
		src/qlocation.cpp \
		src/qaudio.cpp \
		src/qmonthly.cpp \
		src/qyearly.cpp \
		src/qcalculation.cpp \
		src/qworldTime.cpp \
		src/qhijridate.cpp \
		src/dsingleapplication.cpp \
		src/domparser.cpp \
		src/player.cpp build/moc_qsalat.cpp \
		build/moc_qqibla.cpp \
		build/moc_qlocation.cpp \
		build/moc_qaudio.cpp \
		build/moc_qmonthly.cpp \
		build/moc_qyearly.cpp \
		build/moc_qworldTime.cpp \
		build/moc_qcalculation.cpp \
		build/moc_qhijridate.cpp \
		build/moc_dsingleapplication.cpp \
		build/moc_player.cpp \
		qrc_salat.cpp \
		qrc_qibla.cpp \
		qrc_worldtime.cpp
OBJECTS       = build/qsalat.o \
		build/utils.o \
		build/main.o \
		build/qpray.o \
		build/qhijri.o \
		build/qqibla.o \
		build/qlocation.o \
		build/qaudio.o \
		build/qmonthly.o \
		build/qyearly.o \
		build/qcalculation.o \
		build/qworldTime.o \
		build/qhijridate.o \
		build/dsingleapplication.o \
		build/domparser.o \
		build/player.o \
		build/moc_qsalat.o \
		build/moc_qqibla.o \
		build/moc_qlocation.o \
		build/moc_qaudio.o \
		build/moc_qmonthly.o \
		build/moc_qyearly.o \
		build/moc_qworldTime.o \
		build/moc_qcalculation.o \
		build/moc_qhijridate.o \
		build/moc_dsingleapplication.o \
		build/moc_player.o \
		build/qrc_salat.o \
		build/qrc_qibla.o \
		build/qrc_worldtime.o
DIST          = /usr/local/Trolltech/Qt-4.6.0/mkspecs/common/g++.conf \
		/usr/local/Trolltech/Qt-4.6.0/mkspecs/common/unix.conf \
		/usr/local/Trolltech/Qt-4.6.0/mkspecs/common/linux.conf \
		/usr/local/Trolltech/Qt-4.6.0/mkspecs/qconfig.pri \
		/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/qt_functions.prf \
		/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/qt_config.prf \
		/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/exclusive_builds.prf \
		/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/default_pre.prf \
		/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/release.prf \
		/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/default_post.prf \
		/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/warn_on.prf \
		/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/qt.prf \
		/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/unix/thread.prf \
		/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/moc.prf \
		/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/resources.prf \
		/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/uic.prf \
		/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/yacc.prf \
		/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/lex.prf \
		Qsalat.pro
QMAKE_TARGET  = Qsalat
DESTDIR       = 
TARGET        = Qsalat

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): build/ui_salat.h build/ui_qibla.h build/ui_hijri.h build/ui_worldtime.h build/ui_location.h build/ui_audio.h build/ui_calculation.h build/ui_monthly.h build/ui_yearly.h build/ui_player.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: Qsalat.pro  /usr/local/Trolltech/Qt-4.6.0/mkspecs/linux-g++/qmake.conf /usr/local/Trolltech/Qt-4.6.0/mkspecs/common/g++.conf \
		/usr/local/Trolltech/Qt-4.6.0/mkspecs/common/unix.conf \
		/usr/local/Trolltech/Qt-4.6.0/mkspecs/common/linux.conf \
		/usr/local/Trolltech/Qt-4.6.0/mkspecs/qconfig.pri \
		/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/qt_functions.prf \
		/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/qt_config.prf \
		/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/exclusive_builds.prf \
		/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/default_pre.prf \
		/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/release.prf \
		/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/default_post.prf \
		/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/warn_on.prf \
		/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/qt.prf \
		/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/unix/thread.prf \
		/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/moc.prf \
		/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/resources.prf \
		/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/uic.prf \
		/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/yacc.prf \
		/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/lex.prf \
		/usr/local/Trolltech/Qt-4.6.0/lib/libQtWebKit.prl \
		/usr/local/Trolltech/Qt-4.6.0/lib/libphonon.prl \
		/usr/local/Trolltech/Qt-4.6.0/lib/libQtGui.prl \
		/usr/local/Trolltech/Qt-4.6.0/lib/libQtCore.prl \
		/usr/local/Trolltech/Qt-4.6.0/lib/libQtXmlPatterns.prl \
		/usr/local/Trolltech/Qt-4.6.0/lib/libQtNetwork.prl \
		/usr/local/Trolltech/Qt-4.6.0/lib/libQtXml.prl
	$(QMAKE) -unix -o Makefile Qsalat.pro
/usr/local/Trolltech/Qt-4.6.0/mkspecs/common/g++.conf:
/usr/local/Trolltech/Qt-4.6.0/mkspecs/common/unix.conf:
/usr/local/Trolltech/Qt-4.6.0/mkspecs/common/linux.conf:
/usr/local/Trolltech/Qt-4.6.0/mkspecs/qconfig.pri:
/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/qt_functions.prf:
/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/qt_config.prf:
/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/exclusive_builds.prf:
/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/default_pre.prf:
/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/release.prf:
/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/default_post.prf:
/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/warn_on.prf:
/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/qt.prf:
/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/unix/thread.prf:
/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/moc.prf:
/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/resources.prf:
/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/uic.prf:
/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/yacc.prf:
/usr/local/Trolltech/Qt-4.6.0/mkspecs/features/lex.prf:
/usr/local/Trolltech/Qt-4.6.0/lib/libQtWebKit.prl:
/usr/local/Trolltech/Qt-4.6.0/lib/libphonon.prl:
/usr/local/Trolltech/Qt-4.6.0/lib/libQtGui.prl:
/usr/local/Trolltech/Qt-4.6.0/lib/libQtCore.prl:
/usr/local/Trolltech/Qt-4.6.0/lib/libQtXmlPatterns.prl:
/usr/local/Trolltech/Qt-4.6.0/lib/libQtNetwork.prl:
/usr/local/Trolltech/Qt-4.6.0/lib/libQtXml.prl:
qmake:  FORCE
	@$(QMAKE) -unix -o Makefile Qsalat.pro

dist: 
	@$(CHK_DIR_EXISTS) build/Qsalat1.0.0 || $(MKDIR) build/Qsalat1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) build/Qsalat1.0.0/ && $(COPY_FILE) --parents src/qsalat.h src/utils.h src/qpray.h src/qhijri.h src/qqibla.h src/qlocation.h src/qaudio.h src/qmonthly.h src/qyearly.h src/qworldTime.h src/qcalculation.h src/qhijridate.h src/dsingleapplication.h src/domparser.h src/player.h build/Qsalat1.0.0/ && $(COPY_FILE) --parents salat.qrc qibla.qrc worldtime.qrc build/Qsalat1.0.0/ && $(COPY_FILE) --parents src/qsalat.cpp src/utils.cpp src/main.cpp src/qpray.cpp src/qhijri.cpp src/qqibla.cpp src/qlocation.cpp src/qaudio.cpp src/qmonthly.cpp src/qyearly.cpp src/qcalculation.cpp src/qworldTime.cpp src/qhijridate.cpp src/dsingleapplication.cpp src/domparser.cpp src/player.cpp build/Qsalat1.0.0/ && $(COPY_FILE) --parents ui/salat.ui ui/qibla.ui ui/hijri.ui ui/worldtime.ui ui/location.ui ui/audio.ui ui/calculation.ui ui/monthly.ui ui/yearly.ui ui/player.ui build/Qsalat1.0.0/ && $(COPY_FILE) --parents qsalat_en.ts qsalat_fr.ts build/Qsalat1.0.0/ && (cd `dirname build/Qsalat1.0.0` && $(TAR) Qsalat1.0.0.tar Qsalat1.0.0 && $(COMPRESS) Qsalat1.0.0.tar) && $(MOVE) `dirname build/Qsalat1.0.0`/Qsalat1.0.0.tar.gz . && $(DEL_FILE) -r build/Qsalat1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: build/moc_qsalat.cpp build/moc_qqibla.cpp build/moc_qlocation.cpp build/moc_qaudio.cpp build/moc_qmonthly.cpp build/moc_qyearly.cpp build/moc_qworldTime.cpp build/moc_qcalculation.cpp build/moc_qhijridate.cpp build/moc_dsingleapplication.cpp build/moc_player.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) build/moc_qsalat.cpp build/moc_qqibla.cpp build/moc_qlocation.cpp build/moc_qaudio.cpp build/moc_qmonthly.cpp build/moc_qyearly.cpp build/moc_qworldTime.cpp build/moc_qcalculation.cpp build/moc_qhijridate.cpp build/moc_dsingleapplication.cpp build/moc_player.cpp
build/moc_qsalat.cpp: build/ui_salat.h \
		src/qpray.h \
		src/qhijri.h \
		src/qlocation.h \
		build/ui_location.h \
		src/domparser.h \
		src/qcalculation.h \
		build/ui_calculation.h \
		src/qqibla.h \
		build/ui_qibla.h \
		src/qaudio.h \
		build/ui_audio.h \
		src/qworldTime.h \
		build/ui_worldtime.h \
		src/qmonthly.h \
		build/ui_monthly.h \
		src/utils.h \
		src/qyearly.h \
		build/ui_yearly.h \
		src/qhijridate.h \
		build/ui_hijri.h \
		src/player.h \
		build/ui_player.h \
		src/qsalat.h
	/usr/local/Trolltech/Qt-4.6.0/bin/moc $(DEFINES) $(INCPATH) src/qsalat.h -o build/moc_qsalat.cpp

build/moc_qqibla.cpp: build/ui_qibla.h \
		src/domparser.h \
		src/qqibla.h
	/usr/local/Trolltech/Qt-4.6.0/bin/moc $(DEFINES) $(INCPATH) src/qqibla.h -o build/moc_qqibla.cpp

build/moc_qlocation.cpp: build/ui_location.h \
		src/domparser.h \
		src/qcalculation.h \
		build/ui_calculation.h \
		src/qpray.h \
		src/qlocation.h
	/usr/local/Trolltech/Qt-4.6.0/bin/moc $(DEFINES) $(INCPATH) src/qlocation.h -o build/moc_qlocation.cpp

build/moc_qaudio.cpp: build/ui_audio.h \
		src/domparser.h \
		src/qaudio.h
	/usr/local/Trolltech/Qt-4.6.0/bin/moc $(DEFINES) $(INCPATH) src/qaudio.h -o build/moc_qaudio.cpp

build/moc_qmonthly.cpp: build/ui_monthly.h \
		src/utils.h \
		src/qpray.h \
		src/domparser.h \
		src/qmonthly.h
	/usr/local/Trolltech/Qt-4.6.0/bin/moc $(DEFINES) $(INCPATH) src/qmonthly.h -o build/moc_qmonthly.cpp

build/moc_qyearly.cpp: build/ui_yearly.h \
		src/utils.h \
		src/qpray.h \
		src/domparser.h \
		src/qyearly.h
	/usr/local/Trolltech/Qt-4.6.0/bin/moc $(DEFINES) $(INCPATH) src/qyearly.h -o build/moc_qyearly.cpp

build/moc_qworldTime.cpp: build/ui_worldtime.h \
		src/qworldTime.h
	/usr/local/Trolltech/Qt-4.6.0/bin/moc $(DEFINES) $(INCPATH) src/qworldTime.h -o build/moc_qworldTime.cpp

build/moc_qcalculation.cpp: build/ui_calculation.h \
		src/domparser.h \
		src/qpray.h \
		src/qcalculation.h
	/usr/local/Trolltech/Qt-4.6.0/bin/moc $(DEFINES) $(INCPATH) src/qcalculation.h -o build/moc_qcalculation.cpp

build/moc_qhijridate.cpp: build/ui_hijri.h \
		src/qhijri.h \
		src/domparser.h \
		src/qhijridate.h
	/usr/local/Trolltech/Qt-4.6.0/bin/moc $(DEFINES) $(INCPATH) src/qhijridate.h -o build/moc_qhijridate.cpp

build/moc_dsingleapplication.cpp: src/dsingleapplication.h
	/usr/local/Trolltech/Qt-4.6.0/bin/moc $(DEFINES) $(INCPATH) src/dsingleapplication.h -o build/moc_dsingleapplication.cpp

build/moc_player.cpp: build/ui_player.h \
		src/player.h
	/usr/local/Trolltech/Qt-4.6.0/bin/moc $(DEFINES) $(INCPATH) src/player.h -o build/moc_player.cpp

compiler_rcc_make_all: qrc_salat.cpp qrc_qibla.cpp qrc_worldtime.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_salat.cpp qrc_qibla.cpp qrc_worldtime.cpp
qrc_salat.cpp: salat.qrc \
		/usr/share/qsalat/images/hide.png \
		/usr/share/qsalat/images/boussole.png \
		/usr/share/qsalat/images/0396.png \
		/usr/share/qsalat/images/qsalat.png \
		/usr/share/qsalat/images/exit.png \
		/usr/share/qsalat/images/qibla.png \
		/usr/share/qsalat/images/0442.png \
		/usr/share/qsalat/images/mp3.png \
		/usr/share/qsalat/images/year.png \
		/usr/share/qsalat/images/Qt.png \
		/usr/share/qsalat/images/hijri.png \
		/usr/share/qsalat/images/month.png \
		/usr/share/qsalat/images/mecque.png \
		/usr/share/qsalat/images/world.png
	/usr/local/Trolltech/Qt-4.6.0/bin/rcc -name salat salat.qrc -o qrc_salat.cpp

qrc_qibla.cpp: qibla.qrc \
		/usr/share/qsalat/images/boussole.png
	/usr/local/Trolltech/Qt-4.6.0/bin/rcc -name qibla qibla.qrc -o qrc_qibla.cpp

qrc_worldtime.cpp: worldtime.qrc \
		/usr/share/qsalat/images/worldtime/img6.jpg \
		/usr/share/qsalat/images/worldtime/img2.jpg \
		/usr/share/qsalat/images/worldtime/img19.jpg \
		/usr/share/qsalat/images/worldtime/img15.jpg \
		/usr/share/qsalat/images/worldtime/img11.jpg \
		/usr/share/qsalat/images/worldtime/img22.jpg \
		/usr/share/qsalat/images/worldtime/img7.jpg \
		/usr/share/qsalat/images/worldtime/img3.jpg \
		/usr/share/qsalat/images/worldtime/img16.jpg \
		/usr/share/qsalat/images/worldtime/img12.jpg \
		/usr/share/qsalat/images/worldtime/img23.jpg \
		/usr/share/qsalat/images/worldtime/img8.jpg \
		/usr/share/qsalat/images/worldtime/img4.jpg \
		/usr/share/qsalat/images/worldtime/img0.jpg \
		/usr/share/qsalat/images/worldtime/img17.jpg \
		/usr/share/qsalat/images/worldtime/img13.jpg \
		/usr/share/qsalat/images/worldtime/img9.jpg \
		/usr/share/qsalat/images/worldtime/img20.jpg \
		/usr/share/qsalat/images/worldtime/img5.jpg \
		/usr/share/qsalat/images/worldtime/img1.jpg \
		/usr/share/qsalat/images/worldtime/img18.jpg \
		/usr/share/qsalat/images/worldtime/img14.jpg \
		/usr/share/qsalat/images/worldtime/img10.jpg \
		/usr/share/qsalat/images/worldtime/img21.jpg
	/usr/local/Trolltech/Qt-4.6.0/bin/rcc -name worldtime worldtime.qrc -o qrc_worldtime.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: build/ui_salat.h build/ui_qibla.h build/ui_hijri.h build/ui_worldtime.h build/ui_location.h build/ui_audio.h build/ui_calculation.h build/ui_monthly.h build/ui_yearly.h build/ui_player.h
compiler_uic_clean:
	-$(DEL_FILE) build/ui_salat.h build/ui_qibla.h build/ui_hijri.h build/ui_worldtime.h build/ui_location.h build/ui_audio.h build/ui_calculation.h build/ui_monthly.h build/ui_yearly.h build/ui_player.h
build/ui_salat.h: ui/salat.ui
	/usr/local/Trolltech/Qt-4.6.0/bin/uic ui/salat.ui -o build/ui_salat.h

build/ui_qibla.h: ui/qibla.ui
	/usr/local/Trolltech/Qt-4.6.0/bin/uic ui/qibla.ui -o build/ui_qibla.h

build/ui_hijri.h: ui/hijri.ui
	/usr/local/Trolltech/Qt-4.6.0/bin/uic ui/hijri.ui -o build/ui_hijri.h

build/ui_worldtime.h: ui/worldtime.ui
	/usr/local/Trolltech/Qt-4.6.0/bin/uic ui/worldtime.ui -o build/ui_worldtime.h

build/ui_location.h: ui/location.ui
	/usr/local/Trolltech/Qt-4.6.0/bin/uic ui/location.ui -o build/ui_location.h

build/ui_audio.h: ui/audio.ui
	/usr/local/Trolltech/Qt-4.6.0/bin/uic ui/audio.ui -o build/ui_audio.h

build/ui_calculation.h: ui/calculation.ui
	/usr/local/Trolltech/Qt-4.6.0/bin/uic ui/calculation.ui -o build/ui_calculation.h

build/ui_monthly.h: ui/monthly.ui
	/usr/local/Trolltech/Qt-4.6.0/bin/uic ui/monthly.ui -o build/ui_monthly.h

build/ui_yearly.h: ui/yearly.ui
	/usr/local/Trolltech/Qt-4.6.0/bin/uic ui/yearly.ui -o build/ui_yearly.h

build/ui_player.h: ui/player.ui
	/usr/local/Trolltech/Qt-4.6.0/bin/uic ui/player.ui -o build/ui_player.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

build/qsalat.o: src/qsalat.cpp src/qsalat.h \
		build/ui_salat.h \
		src/qpray.h \
		src/qhijri.h \
		src/qlocation.h \
		build/ui_location.h \
		src/domparser.h \
		src/qcalculation.h \
		build/ui_calculation.h \
		src/qqibla.h \
		build/ui_qibla.h \
		src/qaudio.h \
		build/ui_audio.h \
		src/qworldTime.h \
		build/ui_worldtime.h \
		src/qmonthly.h \
		build/ui_monthly.h \
		src/utils.h \
		src/qyearly.h \
		build/ui_yearly.h \
		src/qhijridate.h \
		build/ui_hijri.h \
		src/player.h \
		build/ui_player.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/qsalat.o src/qsalat.cpp

build/utils.o: src/utils.cpp src/utils.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/utils.o src/utils.cpp

build/main.o: src/main.cpp src/qsalat.h \
		build/ui_salat.h \
		src/qpray.h \
		src/qhijri.h \
		src/qlocation.h \
		build/ui_location.h \
		src/domparser.h \
		src/qcalculation.h \
		build/ui_calculation.h \
		src/qqibla.h \
		build/ui_qibla.h \
		src/qaudio.h \
		build/ui_audio.h \
		src/qworldTime.h \
		build/ui_worldtime.h \
		src/qmonthly.h \
		build/ui_monthly.h \
		src/utils.h \
		src/qyearly.h \
		build/ui_yearly.h \
		src/qhijridate.h \
		build/ui_hijri.h \
		src/player.h \
		build/ui_player.h \
		src/dsingleapplication.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/main.o src/main.cpp

build/qpray.o: src/qpray.cpp src/qpray.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/qpray.o src/qpray.cpp

build/qhijri.o: src/qhijri.cpp src/qhijri.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/qhijri.o src/qhijri.cpp

build/qqibla.o: src/qqibla.cpp src/qqibla.h \
		build/ui_qibla.h \
		src/domparser.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/qqibla.o src/qqibla.cpp

build/qlocation.o: src/qlocation.cpp src/qlocation.h \
		build/ui_location.h \
		src/domparser.h \
		src/qcalculation.h \
		build/ui_calculation.h \
		src/qpray.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/qlocation.o src/qlocation.cpp

build/qaudio.o: src/qaudio.cpp src/qaudio.h \
		build/ui_audio.h \
		src/domparser.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/qaudio.o src/qaudio.cpp

build/qmonthly.o: src/qmonthly.cpp src/qmonthly.h \
		build/ui_monthly.h \
		src/utils.h \
		src/qpray.h \
		src/domparser.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/qmonthly.o src/qmonthly.cpp

build/qyearly.o: src/qyearly.cpp src/qyearly.h \
		build/ui_yearly.h \
		src/utils.h \
		src/qpray.h \
		src/domparser.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/qyearly.o src/qyearly.cpp

build/qcalculation.o: src/qcalculation.cpp src/qcalculation.h \
		build/ui_calculation.h \
		src/domparser.h \
		src/qpray.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/qcalculation.o src/qcalculation.cpp

build/qworldTime.o: src/qworldTime.cpp src/qworldTime.h \
		build/ui_worldtime.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/qworldTime.o src/qworldTime.cpp

build/qhijridate.o: src/qhijridate.cpp src/qhijridate.h \
		build/ui_hijri.h \
		src/qhijri.h \
		src/domparser.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/qhijridate.o src/qhijridate.cpp

build/dsingleapplication.o: src/dsingleapplication.cpp src/dsingleapplication.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/dsingleapplication.o src/dsingleapplication.cpp

build/domparser.o: src/domparser.cpp src/domparser.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/domparser.o src/domparser.cpp

build/player.o: src/player.cpp src/player.h \
		build/ui_player.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/player.o src/player.cpp

build/moc_qsalat.o: build/moc_qsalat.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_qsalat.o build/moc_qsalat.cpp

build/moc_qqibla.o: build/moc_qqibla.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_qqibla.o build/moc_qqibla.cpp

build/moc_qlocation.o: build/moc_qlocation.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_qlocation.o build/moc_qlocation.cpp

build/moc_qaudio.o: build/moc_qaudio.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_qaudio.o build/moc_qaudio.cpp

build/moc_qmonthly.o: build/moc_qmonthly.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_qmonthly.o build/moc_qmonthly.cpp

build/moc_qyearly.o: build/moc_qyearly.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_qyearly.o build/moc_qyearly.cpp

build/moc_qworldTime.o: build/moc_qworldTime.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_qworldTime.o build/moc_qworldTime.cpp

build/moc_qcalculation.o: build/moc_qcalculation.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_qcalculation.o build/moc_qcalculation.cpp

build/moc_qhijridate.o: build/moc_qhijridate.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_qhijridate.o build/moc_qhijridate.cpp

build/moc_dsingleapplication.o: build/moc_dsingleapplication.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_dsingleapplication.o build/moc_dsingleapplication.cpp

build/moc_player.o: build/moc_player.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_player.o build/moc_player.cpp

build/qrc_salat.o: qrc_salat.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/qrc_salat.o qrc_salat.cpp

build/qrc_qibla.o: qrc_qibla.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/qrc_qibla.o qrc_qibla.cpp

build/qrc_worldtime.o: qrc_worldtime.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/qrc_worldtime.o qrc_worldtime.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

