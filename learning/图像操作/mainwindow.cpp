#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    img.load("hello.jpeg");
    ui->setupUi(this);
    ui->imagelabel->setPixmap(QPixmap::fromImage(img));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionZoonIn_triggered()
{
    if(img.isNull())
        return;

    m_zoonin *= 1.2;

    QMatrix martix;
    martix.scale(m_zoonin, m_zoonin);//放大
    QImage imgpix = img.transformed(martix);

    ui->imagelabel->setPixmap(QPixmap::fromImage(imgpix));
}

void MainWindow::on_actionZoonOut_triggered()
{
    if(img.isNull())
        return;

    m_zoonout /= 0.8;
    QMatrix martix;
    martix.scale(m_zoonout,m_zoonout); //缩小
    QImage imgpix = img.transformed(martix);

    ui->imagelabel->setPixmap(QPixmap::fromImage(imgpix));
}

void MainWindow::on_actionRotate_triggered()
{
    if(img.isNull())
        return;

    if(m_rotale <= 180)
        m_rotale +=90;
    else {
        m_rotale = 0;
    }

    QMatrix martix;
    martix.rotate(m_rotale);
    QImage imgpix = img.transformed(martix); //旋转
    //img.mirrored(true,true);镜像

    ui->imagelabel->setPixmap(QPixmap::fromImage(imgpix));

}
