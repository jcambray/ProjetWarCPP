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
    player.cpp \
    tmxviewer.cpp \
    glossary.cpp \
    lexiquewindow.cpp \
    power.cpp \
    nation.cpp \
    selectnationpowerwindows.cpp \
    selectplayerwindows.cpp \
    area.cpp \
    mapwindow.cpp \
    displayendgame.cpp


HEADERS  += mainwindow.h \
    game.h \
    gamemap.h \
    mapitem.h \
    player.h \
    tmxviewer.h \
    glossary.h \
    lexiquewindow.h \
    power.h \
    nation.h \
    selectnationpowerwindows.h \
    selectplayerwindows.h \
    area.h \
    mapwindow.h \
    displayendgame.h

FORMS    += mainwindow.ui \
    selectnationpowerwindows.ui \
    selectplayerwindows.ui \
	lexique.ui \
    mapwindow.ui \
    Lexique.ui \
    displayendgame.ui

OTHER_FILES += \
        images/fondAcceuil.jpg \
    images/area \
    images/rules \
    images/power \
    images/nation \
    images/token \
    images/area/0.jpg \
    images/area/1.jpg \
    images/area/2.jpg \
    images/area/3.jpg \
    images/area/4.jpg \
    images/area/5.jpg \
    images/area/6.jpg \
    images/nation/0.jpg \
    images/nation/1.jpg \
    images/nation/2.jpg \
    images/nation/3.jpg \
    images/power/0.jpg \
    images/power/1.jpg \
    images/power/2.jpg \
    images/power/3.jpg \
    images/rules/font.jpg \
    lexique.xml \
    images/fond.jpg \
    images/fond_parchemin.png \
    map/map.jpg \
    map/map.tmx

RESOURCES += \
    res.qrc
