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
        ./src/lifemaker/core/LMController.cpp \
        ./src/lifemaker/core/Logger.cpp \
        ./src/lifemaker/objects/Dictionary.cpp \
        ./src/lifemaker/objects/Element.cpp \
        ./src/lifemaker/objects/Relation.cpp \
        ./src/lifemaker/objects/Relations.cpp \
        ./src/lifemaker/tools/StringTools.cpp

HEADERS += ./src/gui/MainWindow.h \
        ./src/lifemaker/core/Exception.h \
        ./src/lifemaker/core/LMController.h \
        ./src/lifemaker/core/Logger.h \
        ./src/lifemaker/objects/Dictionary.h \
        ./src/lifemaker/objects/Element.h \
        ./src/lifemaker/objects/Relation.h \
        ./src/lifemaker/objects/Relations.h \
        ./src/lifemaker/tools/StringTools.h

FORMS += ./src/gui/mainwindow.ui

CONFIG += mobility
MOBILITY = 

QMAKE_CXXFLAGS += -std=c++11
