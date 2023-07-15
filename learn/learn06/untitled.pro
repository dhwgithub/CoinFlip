#-------------------------------------------------
#
# Project created by QtCreator 2023-07-08T10:33:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    smallwidget.cpp

HEADERS  += mainwindow.h \
    smallwidget.h

FORMS    += mainwindow.ui \
    smallwidget.ui
CONFIG += C++11
