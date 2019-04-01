TEMPLATE = subdirs

CONFIG += LINUX_ARM64

LINUX_ARM64 {
    SUBDIRS += Dahua
    message("compile for linux arm")
}

LINUX_X86_X64 {
    message("compile for linux x86")
}

WINDOWS_X86_X64 {
    message("compile for Windows x86")
}

SUBDIRS += \
    TestCamera

