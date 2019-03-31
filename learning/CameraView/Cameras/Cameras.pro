TEMPLATE = subdirs

if(contains(DEFINES,LINUX_ARM)){
    SUBDIRS += DaHua
    message("compile for linux arm")
}

if(contains(DEFINES,LINUX_X86)){
    message("compile for linux x86")
}

if(contains(DEFINES,Windows_X86)){
    message("compile for Windows x86")
}

SUBDIRS += \
    TestCamera

