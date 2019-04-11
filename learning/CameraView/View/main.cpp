#include "mainwindow.h"
#include <QApplication>

#include <QTextCodec>
#include <CameraDeviceForm.h>

#include <opencv2/highgui/highgui.hpp>


void showOpencv()
{
    cv::Mat img = cv::imread("./1.jpg");
    cv::imshow("shole", img);
    cv::waitKey(0);

}

int main(int argc, char *argv[])
{
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForLocale(codec);
    QApplication a(argc, argv);
   // QApplication::setOverrideCursor(Qt::BlankCursor);//不显示鼠标
   // CameraDeviceForm w;
    MainWindow w;
    w.show();



    return a.exec();
}
