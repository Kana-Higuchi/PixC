#-------------------------------------------------
#
# Project created by QtCreator 2013-09-05T17:03:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PixC
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    custumlist.cpp \
    scene.cpp \
    view.cpp

HEADERS  += mainwindow.h \
    custumlist.h \
    scene.h \
    view.h

FORMS    += mainwindow.ui
EPENDPATH += /opt/local/include
INCLUDEPATH += /opt/local/include
LIBS += -L/opt/local/lib/ \
     -lopencv_core \
     -lopencv_imgproc \
     -lopencv_highgui

OTHER_FILES += \
    kasa_y_03.png \
    kasa_migi_03.png \
    kasa_m_07.png \
    kasa_kansei_02.png \
    kasa_h_03.png \
    kasa_06.png \
    a.jpg

RESOURCES +=
