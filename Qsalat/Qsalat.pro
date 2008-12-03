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
 ui/worldtime.ui \
 ui/location.ui \
 ui/audio.ui \
 ui/calculation.ui \
 ui/monthly.ui \
 ui/yearly.ui \
 ui/about.ui
HEADERS = src/qsalat.h \
 src/qpray.h \
 src/qhijri.h \
 src/qqibla.h \
 src/qlocation.h \
 src/qaudio.h \
 src/calculation.h \
 src/worldTime.h
SOURCES = src/qsalat.cpp \
 src/main.cpp \
 src/qpray.cpp \
 src/qhijri.cpp \
 src/qqibla.cpp \
 src/qlocation.cpp \
 src/qaudio.cpp \
 src/calculation.cpp \
 src/worldTime.cpp
RESOURCES += salat.qrc qibla.qrc worldtime.qrc
