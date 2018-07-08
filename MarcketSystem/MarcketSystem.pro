#-------------------------------------------------
#
# Project created by QtCreator 2018-06-28T10:05:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MarcketSystem
TEMPLATE = app

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
    addthings.cpp \
    cutom1.cpp \
    query.cpp \
    manager1.cpp \
    manager2.cpp \
    count.cpp \
    edit.cpp \
    food2.cpp \
    cosmetic2.cpp \
    good2.cpp \
    drink2.cpp \
    food1.cpp \
    drink1.cpp \
    cosmetic1.cpp \
    good1.cpp

HEADERS += \
    mainwindow.h \
    addthings.h \
    cutom1.h \
    query.h \
    manager1.h \
    manager2.h \
    manager2.h \
    count.h \
    edit.h \
    food2.h \
    cosmetic2.h \
    good2.h \
    drink2.h \
    food1.h \
    drink1.h \
    cosmetic1.h \
    good1.h

FORMS += \
   mainwindow.ui \
    addthings.ui \
    cutom1.ui \
    query.ui \
    manager1.ui \
    manager2.ui \
    count.ui \
    edit.ui \
    food2.ui \
    cosmetic2.ui \
    good2.ui \
    drink2.ui \
    food1.ui \
    drink1.ui \
    cosmetic1.ui \
    good1.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    picture.qrc

DISTFILES += \
    resource/589c38401867b.jpg \
    resource/timg (1).jpg \
    resource/timg.jpg \
    resource/1.png \
    resource/111.png \
    resource/按钮1.png \
    resource/按钮2.png \
    resource/按钮3.png \
    resource/按钮4.png \
    resource/按钮5.png
