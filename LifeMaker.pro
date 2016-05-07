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

SOURCES += ./src/applications/lifemaker.cpp\
        ./src/gui/MainWindow.cpp

HEADERS  += ./src/gui/MainWindow.h

FORMS    += ./src/gui/mainwindow.ui

CONFIG += mobility
MOBILITY = 

