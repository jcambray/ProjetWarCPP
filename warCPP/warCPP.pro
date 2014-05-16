#-------------------------------------------------
#
# Project created by QtCreator 2014-05-15T18:00:50
#
#-------------------------------------------------

QT       += core gui
QT += xml

include(C:\Users\jerome\Documents\Qt Projects\warC++\libtiled.pro)

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = warCPP
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    game.cpp \
    gamemap.cpp \
    mapitem.cpp \
    partie.cpp \
    player.cpp \
    tmxviewer.cpp \
    glossary.cpp \
    lexiquewindow.cpp

HEADERS  += mainwindow.h \
    game.h \
    gamemap.h \
    mapitem.h \
    partie.h \
    player.h \
    tmxviewer.h \
    glossary.h \
    lexiquewindow.h

FORMS    += mainwindow.ui \
    Lexique.ui

RESOURCES += \
    res.qrc
