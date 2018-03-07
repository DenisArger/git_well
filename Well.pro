#-------------------------------------------------
#
# Project created by QtCreator 2017-12-27T15:16:19
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Well
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    global.h \
    Model/heirqsqlquerymodel.h \
    Model/servicecardquerymodel.h \
    Model/serviceqsqlquerymodel.h \
    Gui/editinstrumentsdialog.h \
    DataBase/database.h \
    Gui/primewindow.h \
    Gui/clientswindows.h \
    Gui/cardclientwindows.h \
    Gui/stockwindow.h \
    Gui/serviceclientswindow.h \
    Gui/cardservicewindows.h \
    Gui/logindialog.h \
    Gui/busysplashwidget.h \
    Gui/addinstruments.h \
    config.h

SOURCES += \
    global.cpp \
    main.cpp \
    Model/heirqsqlquerymodel.cpp \
    Model/servicecardquerymodel.cpp \
    Model/serviceqsqlquerymodel.cpp \
    Gui/editinstrumentsdialog.cpp \
    DataBase/database.cpp \
    Gui/primewindow.cpp \
    Gui/clientswindows.cpp \
    Gui/cardclientwindows.cpp \
    Gui/stockwindow.cpp \
    Gui/serviceclientswindow.cpp \
    Gui/cardservicewindows.cpp \
    Gui/logindialog.cpp \
    Gui/busysplashwidget.cpp \
    Gui/addinstruments.cpp

FORMS += \
    Gui/editinstrumentsdialog.ui \
    Gui/primewindow.ui \
    Gui/clientswindows.ui \
    Gui/cardclientwindows.ui \
    Gui/stockwindow.ui \
    Gui/serviceclientswindow.ui \
    Gui/cardservicewindows.ui \
    Gui/logindialog.ui \
    Gui/addinstruments.ui




