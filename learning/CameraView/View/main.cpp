#include "mainwindow.h"
#include <QApplication>

#include <QTextCodec>
#include <CameraDeviceForm.h>

int main(int argc, char *argv[])
{
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForLocale(codec);

    QApplication a(argc, argv);
   // CameraDeviceForm w;
    MainWindow w;
    w.show();

    return a.exec();
}
