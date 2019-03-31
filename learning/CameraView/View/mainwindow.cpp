#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <QString>
#include <QPluginLoader>
#include <QDebug>
#include <QTextCodec>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("CameraView"));
    setWindowIcon(QIcon("://res/factory_128px.ico"));
    setMinimumSize(QSize(800, 600)); //窗口最小尺寸
    setCentralWidget(ui->tabWidgetMain); //设置为主窗口的中心窗口，会填充MainWindow的窗口

    QFile qssfile(":/qss/themeSun/mainTabWidget.qss");
    qssfile.open(QFile::ReadOnly);
    ui->tabWidgetMain->setStyleSheet(qssfile.readAll());


    QWidget* homeWidget = new QWidget(this);
    ui->tabWidgetMain->addTab(homeWidget,tr("Home"));

    QWidget* cameraWidget = new QWidget(this);
    ui->tabWidgetMain->addTab(cameraWidget,tr("Camera"));
    showMaximized();


    qDebug()<<ui->tabWidgetMain->widget(0)->size();
    QGridLayout *gridlayout = new QGridLayout(ui->tabWidgetMain->widget(0));

    CameraDeviceForm* cameraDeviceForm;
    int cameraDeviceNumber = 4;
    int cameraDeviceCols =  (cameraDeviceNumber + 1)/2;
    if(cameraDeviceNumber >=3)
    {
        for(int i = 0, j = 0, k = 0 ; i < cameraDeviceNumber ; i++, j++)
        {
            if(i == cameraDeviceCols)
            {
                j = 0;
                k++;
            }
            cameraDeviceForm = new  CameraDeviceForm(this);
            gridlayout->addWidget(cameraDeviceForm, k, j);
            _cameraDeviceForm.append(cameraDeviceForm);
        }
    }else{
        if( cameraDeviceNumber >= 1){
            cameraDeviceForm = new  CameraDeviceForm(this);
            gridlayout->addWidget(cameraDeviceForm, 0, 0);
            _cameraDeviceForm.append(cameraDeviceForm);
        }
        if( cameraDeviceNumber == 2){
            cameraDeviceForm = new  CameraDeviceForm(this);
            gridlayout->addWidget(cameraDeviceForm, 0, 1);
            _cameraDeviceForm.append(cameraDeviceForm);
        }
    }

    loadCameraPlugin();


    _cameraDeviceForm[0]->InitCamera(_Camera);



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
            _Camera = camera;
        }
    }
}
