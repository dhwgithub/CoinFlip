#-------------------------------------------------
#
# Project created by QtCreator 2023-07-03T22:33:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Learn01
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    teacher.cpp \
    student.cpp

HEADERS  += mainwindow.h \
    teacher.h \
    student.h

FORMS    += mainwindow.ui
CONFIG   += C++11
