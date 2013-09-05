#-------------------------------------------------
#
# Project created by QtCreator 2013-09-04T10:11:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = helloworld
TEMPLATE = app


SOURCES += main.cpp\
        helloworld.cpp

HEADERS  += helloworld.h

FORMS    += helloworld.ui
DEPENDPATH += /opt/local/include
INCLUDEPATH += /opt/local/include
LIBS += -L/opt/local/lib/ \
     -lopencv_core \
     -lopencv_imgproc \
     -lopencv_highgui
