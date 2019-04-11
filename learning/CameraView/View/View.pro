#-------------------------------------------------
#
# Project created by QtCreator 2019-03-21T09:43:29
#
#-------------------------------------------------

QT       += core gui concurrent
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = View
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

include(../opencv.pri)

#opencvbuild.target=post_build_cmds
#CONFIG(debug, debug|release): opencvbuild.commands = xcopy  $${OPENCVPATH}/lib/opencv_world401d.dll $${OUT_PWD}/../build/
#CONFIG(release, debug|release): opencvbuild.commands  = xcopy  $${OPENCVPATH}/lib/opencv_world401.dll $${OUT_PWD}/../build/

QMAKE_EXTRA_TARGETS += opencvbuild
POST_TARGETDEPS += post_build_cmds



#message($${QMAKE_POST_LINK})
#error($${QMAKE_POST_LINK})



SOURCES += \
        main.cpp \
        mainwindow.cpp \
    CameraDeviceForm.cpp \
    CameraBusManager.cpp \
    CameraInfoForm.cpp \
    WidgetLogForm.cpp \
    UIConfig.cpp

HEADERS += \
        mainwindow.h \
    CameraBasePlugin.h \
    CameraDeviceForm.h \
    CameraBusManager.h \
    CameraInfoForm.h \
    WidgetLogForm.h \
    UIConfig.h \
    AlgorithmBaseplugin.h

FORMS += \
        mainwindow.ui \
    CameraDeviceForm.ui \
    CameraInfoForm.ui \
    WidgetLogForm.ui

DESTDIR =../build

# Default rules for deployment.
target.path = /root
INSTALLS += target

RESOURCES += \
    res.qrc
