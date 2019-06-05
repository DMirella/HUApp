#-------------------------------------------------
#
# Project created by QtCreator 2018-11-17T18:00:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HUApp
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

CONFIG += c++11

SOURCES += \
    hmi/main_window.cc \
    hmi/hmi_service.cc \
    main/main.cc \
    main/service_accessor.cc \
    radio/radio_service.cc \
    media/media_service.cc \
    hmi/radio/radio_screen.cc \
    hmi/media/media_screen.cc \
    hmi/phone/phone_screen.cc \
    hmi/settings/settings_screen.cc

HEADERS += \
    hmi/main_window.h \
    hmi/hmi_service.h \
    main/service_accessor.h \
    radio/radio_service.h \
    media/media_service.h \
    hmi/radio/radio_screen.h \
    hmi/media/media_screen.h \
    hmi/phone/phone_screen.h \
    hmi/settings/settings_screen.h \
    media/btmedialib.h

FORMS += \
    hmi/main_window.ui \
    hmi/radio/radio_screen.ui \
    hmi/media/media_screen.ui \
    hmi/phone/phone_screen.ui \
    hmi/settings/settings_screen.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
