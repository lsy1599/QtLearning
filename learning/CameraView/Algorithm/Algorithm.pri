

include(../opencv.pri)

DESTDIR =../../build/AlgorithmPlugin/
TEMPLATE = lib
CONFIG += plugin
DEFINES += QT_DEPRECATED_WARNINGS

unix {
    target.path = /root/AlgorithmPlugin
    INSTALLS += target
}
