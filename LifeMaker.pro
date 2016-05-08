#-------------------------------------------------
#
# Project created by QtCreator 2016-05-07T18:08:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LifeMaker
TEMPLATE = app

DEPENDPATH += $$PWD/src/
INCLUDEPATH += $$PWD/src/

SOURCES += ./src/applications/lifemaker.cpp \
        ./src/gui/MainWindow.cpp \
        ./src/lifemaker/core/Exception.cpp \
        ./src/lifemaker/core/Logger.cpp

HEADERS += ./src/gui/MainWindow.h \
        ./src/lifemaker/core/Exception.h \
        ./src/lifemaker/core/Logger.h

FORMS += ./src/gui/mainwindow.ui

CONFIG += mobility
MOBILITY = 

