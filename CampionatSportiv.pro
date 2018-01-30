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
    addparticipantdialog.cpp \
    controller.cpp \
    agecategory.cpp \
    addagecategorydialog.cpp \
    controlleragecategory.cpp \
    weightcategory.cpp \
    experiencecategory.cpp \
    organisation.cpp

HEADERS  += mainwindow.h \
    participants.h \
    addparticipantdialog.h \
    controller.h \
    agecategory.h \
    addagecategorydialog.h \
    controlleragecategory.h \
    weightcategory.h \
    experiencecategory.h \
    organisation.h

FORMS    += mainwindow.ui \
    addparticipantdialog.ui \
    addagecategorydialog.ui

    participantdialog.ui

win32: LIBS += -LC:/Qt/5.10.0/msvc2017_64/plugins/sqldrivers/psql/lib/ -llibpq

INCLUDEPATH += C:/Qt/5.10.0/msvc2017_64/plugins/sqldrivers/psql
DEPENDPATH += C:/Qt/5.10.0/msvc2017_64/plugins/sqldrivers/psql
