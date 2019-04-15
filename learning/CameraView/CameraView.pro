TEMPLATE = subdirs


#DEFINES += Windows_X86


SUBDIRS += \
    View \
    Cameras \
    Algorithm


win32 {
    scriptDir=$$PWD/script/windows/install.bat
    UserDependOnFile.target=post_build_cmds
    CONFIG(debug, debug|release):UserDependOnFile.commands=echo \"..123..\"
    else:UserDependOnFile.commands=echo \"...123...\"

    QMAKE_EXTRA_TARGETS += UserDependOnFile
    POST_TARGETDEPS += post_build_cmds

}





