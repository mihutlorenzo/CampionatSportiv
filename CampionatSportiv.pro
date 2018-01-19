#-------------------------------------------------
#
# Project created by QtCreator 2018-01-12T12:29:34
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CampionatSportiv
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    participants.cpp \
    addparticipantdialog.cpp

HEADERS  += mainwindow.h \
    participants.h \
    addparticipantdialog.h

FORMS    += mainwindow.ui \
    addparticipantdialog.ui

    participantdialog.ui
