
include(share.pri)

LINUX_ARM64 {
}


LINUX_X86_X64 {
}

win32 {
        OPENCVPATH=$$PWD/rootfs/opencv4.0.1_windows_x64
        DEPENDPATH += $${OPENCVPATH}
        INCLUDEPATH += $${OPENCVPATH}/include
        Debug{
        }
        Release{
        }

        CONFIG(debug, debug|release):LIBS+= $${OPENCVPATH}/lib/opencv_world401d.lib
        CONFIG(release, debug|release):LIBS += $${OPENCVPATH}/lib/opencv_world401.lib

        CONFIG(debug, debug|release):opencv_src_file=$${OPENCVPATH}/lib/opencv_world401d.dll
        else:opencv_src_file=$${OPENCVPATH}/lib/opencv_world401.dll
}
