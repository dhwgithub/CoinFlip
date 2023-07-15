#-------------------------------------------------
#
# Project created by QtCreator 2023-07-10T10:17:18
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CoinFlip
TEMPLATE = app


SOURCES += main.cpp\
        mainscene.cpp \
    mypushbuttom.cpp \
    chooselevelscene.cpp \
    playscene.cpp \
    mycoin.cpp \
    dataconfig.cpp

HEADERS  += mainscene.h \
    mypushbuttom.h \
    chooselevelscene.h \
    playscene.h \
    mycoin.h \
    dataconfig.h

FORMS    += mainscene.ui \
    chooselevelscene.ui

RESOURCES += \
    res.qrc
CONFIG += C++11
