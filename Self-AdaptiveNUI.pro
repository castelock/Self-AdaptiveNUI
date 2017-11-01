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
LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_videoio -lopencv_imgproc -lopencv_bgsegm -lopencv_video -lopencv_xfeatures2d -lopencv_features2d -lopencv_objdetect -lopencv_tracking

# Include dlib library
#INCLUDEPATH += /usr/local/include
##LIBS += -pthread
#LIBS += -L/usr/local/lib -ldlib -lpng12 -llapack -lblas -lgif
#CONFIG += link_pkgconfig
#PKGCONFIG += x11

SOURCES += main.cpp\
        mainwindow.cpp \
    backgroundsubtraction.cpp \
    haarcascadehands.cpp \
    intelligentmodule.cpp

HEADERS  += mainwindow.h \
    backgroundsubtraction.h \
    haarcascadehands.h \
    intelligentmodule.h

FORMS    += mainwindow.ui
