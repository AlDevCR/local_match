#-------------------------------------------------
#
# Project created by QtCreator 2018-12-03T08:58:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LocalMatch
TEMPLATE = app


SOURCES += main.cpp\
    sources/mainwindow.cpp \
    sources/signup.cpp \
    sources/homewindow.cpp \
    sources/functionsevent.cpp \
    sources/classevent.cpp

HEADERS  += \
    headers/mainwindow.h \
    headers/signup.h \
    headers/homewindow.h \
    headers/functionsevent.h \
    headers/classevent.h

FORMS    += \
    forms/mainwindow.ui \
    forms/signup.ui \
    forms/homewindow.ui

RESOURCES += \
    resources/resources.qrc

DISTFILES += \
    resources/images/eventExample.svg \
    resources/images/logo.svg \
    resources/images/user.svg
