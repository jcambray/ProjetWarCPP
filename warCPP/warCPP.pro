#-------------------------------------------------
#
# Project created by QtCreator 2014-05-15T18:00:50
#
#-------------------------------------------------

QT       += core gui
QT += xml

include(libtiled\libtiled.pro)

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
    lexiquewindow.cpp \
    power.cpp \
    nation.cpp \
    selectnationpowerwindows.cpp

HEADERS  += mainwindow.h \
    game.h \
    gamemap.h \
    mapitem.h \
    partie.h \
    player.h \
    tmxviewer.h \
    glossary.h \
    lexiquewindow.h \
    power.h \
    nation.h \
    selectnationpowerwindows.h

FORMS    += mainwindow.ui \
    Lexique.ui \
    selectnationpowerwindows.ui

OTHER_FILES += \
    images/fondAcceuil.jpg \
        images/area \
        images/Rules \
        images/Power \
        images/Nation/1 \
        images/Nation/2 \
    lexique.xml \
    images/fond.jpg \
    images/Nation/1.jpg \
    images/Nation/2.jpg \
    images/fond_parchemin.png

RESOURCES += \
    res.qrc
