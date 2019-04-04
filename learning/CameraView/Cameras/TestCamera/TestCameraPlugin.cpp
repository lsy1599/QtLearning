#include "TestCameraPlugin.h"
#include <QDir>
#include <QDebug>
#include <QImage>
#include <QPixmap>
#include <QThread>



#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(TestCamera, GenericPlugin)
#endif // QT_VERSION < 0x050000

TestCamera::CameraTest::CameraTest()
{
    CameraIndex = 0;
    VendorName = "TestCamera";
    ModelName    = "TestCamera";
    SerialNumber = "TestCamera";
    VendorName   = "TestCamera";
    Ipaddress   = "0.0.0.0";
    Type="Local";
}



bool TestCamera::CameraTest::Open()
{
    _Dir = new QDir(_DirPath);
    QStringList nameFilters;
    nameFilters <<"*.jpg" <<"*.png";
    _files = _Dir->entryList(nameFilters, QDir::Files | QDir::Readable, QDir::Name);
    foreach(auto file, _files)
    {
      //  qDebug()<<file;
    }
    _it = _files.begin();
    return true;
}

bool TestCamera::CameraTest::Start()
{
    return true;
}

bool TestCamera::CameraTest::Stop()
{
    return true;
}

bool TestCamera::CameraTest::Close()
{
    _files.clear();
    return true;
}

bool TestCamera::CameraTest::GetOneImage(QImage &img, int timeout)
{
    QThread::msleep(timeout);
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

bool TestCamera::CameraTest::SetParameter(const QString Key, const QString Value)
{
    if(Key == "DirPath")
    {
        _DirPath = Value;
        return true;
    }

    return false;
}

bool TestCamera::CameraTest::GetParameter(const QString Key, QString &Value)
{

    return false;
}

bool TestCamera::CameraTest::GetParameterList(QStringList &keys)
{


    return false;
}

CameraDevice *TestCamera::operator[](int index)
{
    if(index >=0 && index < _Cameras.size())
    {
        return _Cameras[index];
    }else{
        return nullptr;
    }
}

int TestCamera::CameraNumber()
{
    return _Cameras.size();
}

bool TestCamera::Discover()
{
    CameraDevice*  cameradev;
    cameradev =  new  CameraTest;
    cameradev->SetParameter("DirPath", "./image");
    _Cameras.append(cameradev);

    cameradev =  new  CameraTest;
    cameradev->SetParameter("DirPath", "./image");
    _Cameras.append(cameradev);
    return true;
}




