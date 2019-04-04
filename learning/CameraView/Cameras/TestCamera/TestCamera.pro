#-------------------------------------------------
#
# Project created by QtCreator 2019-03-29T21:26:22
#
#-------------------------------------------------

QT       += core gui

TARGET = TestCamera
TEMPLATE = lib
CONFIG += plugin


# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    TestCameraPlugin.cpp

HEADERS += \
    TestCameraPlugin.h

DISTFILES += TestCamera.json 

message($$DISTFILES)

unix {
        target.path = /root/CameraPlugin
        INSTALLS += target
}

DESTDIR =../../build/CameraPlugin/

