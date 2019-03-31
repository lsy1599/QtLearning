#include "TestCameraPlugin.h"
#include <QDir>
#include <QDebug>
#include <QImage>
#include <QPixmap>



#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(TestCamera, GenericPlugin)
#endif // QT_VERSION < 0x050000

TestCamera::TestCamera()
{

}

TestCamera::~TestCamera()
{

}

bool TestCamera::GetCameraList(QList<CameraBasePlugin::TCameraDevice *> &camerasList)
{
    TCameraDevice *CameraDevice= new TCameraDevice;
    CameraDevice->Type="Test";
    CameraDevice->ModelName    = "TestCamera";
    CameraDevice->SerialNumber = "TestCamera";
    CameraDevice->VendorName   = "TestCamera";
    CameraDevice->CameraIndex  = 0;
    camerasList.append(CameraDevice);
    return true;
}

bool TestCamera::Open()
{
    _Dir = new QDir("./image");
    QStringList nameFilters;
    nameFilters <<"*.jpg" <<"*.png";
    _files = _Dir->entryList(nameFilters, QDir::Files | QDir::Readable, QDir::Name);

    foreach(auto file, _files)
    {
        qDebug()<<file;
    }
    _it = _files.begin();
    return true;
}

bool TestCamera::Close()
{
    _files.clear();
    return true;
}

bool TestCamera::Start()
{

    return true;
}

bool TestCamera::Stop()
{

    return true;
}

bool TestCamera::CameraList()
{

    return true;
}

bool TestCamera::GetOneImage(QImage &img)
{
    if(_it != _files.end())
    {
        img.load("image/"+*_it);
        _it++;
        return true;
    }else{
        _it = _files.begin();
        if(_it == _files.end())
                return false;
        else{
                img.load("image/"+*_it);
                _it++;
                return true;
        }
    }
}

bool TestCamera::GetOneImage(QPixmap &img)
{
        if(_it != _files.end())
        {
                img.load(*_it);
                qDebug()<<*_it<<img.size();
                _it++;
        }else
                _it = _files.begin();
        return true;
}

