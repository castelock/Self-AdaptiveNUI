#-------------------------------------------------
#
# Project created by QtCreator 2017-09-13T13:24:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Self-AdaptiveNUI
TEMPLATE = app

INCLUDEPATH += /usr/local/include/opencv
LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui
<<<<<<< HEAD

=======
>>>>>>> 69bc4931274e91427a4fdd41fa03af6ac07e3148

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
