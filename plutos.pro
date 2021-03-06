#-------------------------------------------------
#
# Project created by QtCreator 2018-06-06T10:02:24
#
#-------------------------------------------------

QT       += core gui sql charts


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = plutos
TEMPLATE = app
RC_FILE = app.rc
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    additemsform.cpp \
    bdsettings.cpp \
    viewform.cpp \
    pcore.cpp \
    sellform.cpp \
    delegates.cpp \
    zvit.cpp \
    actionform.cpp \
    infoform.cpp

HEADERS += \
        mainwindow.h \
    additemsform.h \
    bdsettings.h \
    viewform.h \
    pcore.h \
    sellform.h \
    yascompleter.h \
    delegates.h \
    zvit.h \
    actionform.h \
    infoform.h

FORMS += \
        mainwindow.ui \
    additemsform.ui \
    bdsettings.ui \
    viewform.ui \
    sellform.ui \
    zvit.ui \
    actionform.ui \
    infoform.ui

RESOURCES += \
    res.qrc
