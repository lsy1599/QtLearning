
```
#include "mainwindow.h"
#include <QApplication>

#include <QPixmap>
#include <QThread>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPixmap pixmap(":/root/images/splash.jpg");
    QSplashScreen splash(pixmap);
    splash.show();
    a.processEvents(); //试程序在启动时仍然能响应鼠标等其他事件
    MainWindow w;
    splash.finish(&w);//在w初始化完成后结束启动画面

    w.show();
    return a.exec();
}
```
