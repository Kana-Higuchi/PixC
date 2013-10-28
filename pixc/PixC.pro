#-------------------------------------------------
#
# Project created by QtCreator 2013-09-05T17:03:16
#
#
# To System team
#
# 実行するには以下のファイルを書き換えて下さい。
# ※主に画像のpathです。後々改善できたらいいね。
# その際には他の人のpathは消さずにコメントアウトで。
#
#  PixC.pro
#  view.h
#  custumlist.cpp (void CustumList::startDrag())
#  mainwindow.cpp
#  scene.cpp
#
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

#-----ver.Novelist-----

#EPENDPATH += /opt/local/include
#INCLUDEPATH += /opt/local/include
#LIBS += -L/opt/local/lib/ \
#     -lopencv_core \
#     -lopencv_imgproc \
#     -lopencv_highgui

#----------------------

#-----ver.Kana.H-----

INCLUDEPATH += /usr/local/Cellar/opencv/2.4.5/include/
DEPENDPATH += /usr/local/Cellar/opencv/2.4.5/include/

LIBS += -L/usr/local/Cellar/opencv/2.4.5/lib/ \
    -lopencv_core \
    -lopencv_imgproc \
    -lopencv_highgui

#-------------------

OTHER_FILES += \
    kasa_y_03.png \
    kasa_migi_03.png \
    kasa_m_07.png \
    kasa_kansei_02.png \
    kasa_h_03.png \
    kasa_06.png \
    a.jpg

RESOURCES +=
