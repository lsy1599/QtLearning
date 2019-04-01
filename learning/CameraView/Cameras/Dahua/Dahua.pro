#-------------------------------------------------
#
# Project created by QtCreator 2019-03-21T09:46:41
#
#-------------------------------------------------

QT       += core gui

TARGET = Dahua
TEMPLATE = lib
CONFIG += plugin

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
        DahuaPlugin.cpp

HEADERS += \
        DahuaPlugin.h
DISTFILES += Dahua.json 


DaHuaLibs = \
                            -lMVSDK \
                            -lrt \
                            -llog4cpp \
                            -lGCBase_gcc485_v3_0 \
                            -lNodeMapData_gcc485_v3_0 \
                            -lGenApi_gcc485_v3_0 \
                            -lLog_gcc485_v3_0 \
                            -lXmlParser_gcc485_v3_0 \
                            -lImageConvert \
                            -lMathParser_gcc485_v3_0 \
                            -llog4cpp_gcc485_v3_0 \

LIBS += -L$$PWD/MVviewer/lib/ $${DaHuaLibs}

INCLUDEPATH += $$PWD/MVviewer/include
DEPENDPATH += $$PWD/MVviewer/include


DESTDIR =../../build/CameraPlugin/

unix{
        MYLIBS.path=/root/CameraPlugin/lib/
        MYLIBDIR=$${PWD}/MVviewer/lib/
        MYLIBS.files+= $${MYLIBDIR}/libMVSDK.so \
            $${MYLIBDIR}/liblog4cpp.so.5 \
            $${MYLIBDIR}/libGCBase_gcc485_v3_0.so \
            $${MYLIBDIR}/libNodeMapData_gcc485_v3_0.so \
            $${MYLIBDIR}/libGenApi_gcc485_v3_0.so \
            $${MYLIBDIR}/libLog_gcc485_v3_0.so \
            $${MYLIBDIR}/libXmlParser_gcc485_v3_0.so \
            $${MYLIBDIR}/libImageConvert.so \
            $${MYLIBDIR}/libMathParser_gcc485_v3_0.so \
            $${MYLIBDIR}/liblog4cpp_gcc485_v3_0.so
        INSTALLS +=MYLIBS

        target.path = /root/CameraPlugin
        INSTALLS += target
}
