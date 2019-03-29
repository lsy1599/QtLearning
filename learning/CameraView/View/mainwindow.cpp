#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QString>
#include <QPluginLoader>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadCameraPlugin();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadCameraPlugin()
{
    QDir CameraPluginDir("./");
    CameraPluginDir.cd("CameraPlugin");

    foreach(QString fileName, CameraPluginDir.entryList(QDir::Files))
    {
        QPluginLoader loader(CameraPluginDir.absoluteFilePath(fileName));
        QObject *plugin =loader.instance();
        if(plugin)
        {
            QList<CameraBasePlugin::TCameraDevice*> CameraDeviceList;
            CameraBasePlugin *camera = qobject_cast<CameraBasePlugin*>(plugin);
            camera->GetCameraList(CameraDeviceList);
            foreach(auto CameraDevice, CameraDeviceList)
            {
                qDebug()<<CameraDevice->Type
                       <<CameraDevice->ModelName
                      <<CameraDevice->Ipaddress
                     <<CameraDevice->VendorName
                    <<CameraDevice->SerialNumber;
            }

        }

    }
}
