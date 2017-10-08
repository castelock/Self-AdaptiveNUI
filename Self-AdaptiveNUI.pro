#-------------------------------------------------
#
# Project created by QtCreator 2017-09-13T13:24:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Self-AdaptiveNUI
TEMPLATE = app

# Include OPenCV library
INCLUDEPATH += /usr/local/include/opencv
LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_videoio -lopencv_imgproc -lopencv_bgsegm -lopencv_video

# Inclide dlib library
INCLUDEPATH += /usr/local/include/dlib
LIBS += -pthread
CONFIG += link_pkgconfig
PKGCONFIG += x11

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
