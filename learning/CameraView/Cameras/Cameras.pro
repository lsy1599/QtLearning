TEMPLATE = subdirs
SUBDIRS +=Dahua

if(contains(DEFINES,ARM)){
    message("compile for arm")
}else{
    message("compile for x86")
}
