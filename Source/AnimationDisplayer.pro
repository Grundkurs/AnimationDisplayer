TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt


SOURCES += main.cpp \
    tinyxml2.cpp \
    Program.cpp \
    ConfigLoader.cpp \
    Animation.cpp


HEADERS += \
    tinyxml2.h \
    Program.h \
    ConfigLoader.h \
    Animation.h


win32:INCLUDEPATH += C:\SFMLMinGW\include
win32:DEPENDPATH += C:\SFMLMinGW\include
win32:LIBS += -LC:\SFMLMinGW\lib

#CONFIG ( release, debug | release ) {

LIBS += -lsfml-audio -lsfml-network -lsfml-graphics -lsfml-window -lsfml-system
win32: LIBS += -lsfml-main

#}

#CONFIG ( debug, debug | release ) {

#LIBS += -lsfml-audio-d -lsfml-network-d -lsfml-graphics-d -lsfml-window-d -lsfml-system-d
#win32: LIBS += -lsfml-main

#}

QMAKE_CXXFLAGS += -std=c++11

OTHER_FILES += \
    test.txt \
    AnimationDisplayer.pro.user
