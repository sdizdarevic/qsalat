TEMPLATE = app
QT = gui core network webkit
CONFIG += qt warn_on console release
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
FORMS = ui/salat.ui \
 ui/qibla.ui \
 ui/hijri.ui \
 ui/athan.ui \
 ui/worldtime.ui \
 ui/message.ui \
 ui/location.ui
HEADERS = src/qsalat.h \
 src/qpray.h \
 src/qhijri.h \
 src/qlocation.h \
 src/qqibla.h
SOURCES = src/qsalat.cpp \
 src/main.cpp \
 src/qpray.cpp \
 src/qhijri.cpp \
 src/qlocation.cpp \
 src/qqibla.cpp
RESOURCES += salat.qrc qibla.qrc
