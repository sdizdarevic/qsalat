TEMPLATE = app
QT = gui core network
CONFIG += qt warn_on console release
DESTDIR = bin
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
FORMS = ui/salat.ui \
 ui/qibla.ui \
 ui/hijri.ui \
 ui/athan.ui \
 ui/worldtime.ui
HEADERS = src/qsalat.h src/qpray.h qhijri.h
SOURCES = src/qsalat.cpp src/main.cpp src/qpray.cpp qhijri.cpp
RESOURCES += salat.qrc
