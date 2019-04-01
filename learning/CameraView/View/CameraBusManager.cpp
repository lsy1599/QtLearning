#include "CameraBusManager.h"
#include "CameraBasePlugin.h"

#include <QDir>
#include <QPluginLoader>
#include <QList>
#include <QDebug>
#include <QString>

CameraBusManager::CameraBusManager(QObject *parent) : QObject(parent)
{

}

CameraBusManager::~CameraBusManager()
{

}

void CameraBusManager::loadCameraPlugin()
{
    QDir CameraPluginDir("./");
    CameraPluginDir.cd("CameraPlugin");

    foreach(QString fileName, CameraPluginDir.entryList(QDir::Files))
    {
        QPluginLoader loader(CameraPluginDir.absoluteFilePath(fileName));
        QObject *plugin =loader.instance();
        if(plugin)
        {
            CameraBasePlugin *cameraPlugin = qobject_cast<CameraBasePlugin*>(plugin);
            cameraPlugin->Discover(); //find camera
            qDebug()<<cameraPlugin->CameraNumber();
            for(int i =0; i < cameraPlugin->CameraNumber(); i++)
            {
                _cameraDevices.append((*cameraPlugin)[i]);
            }
        }
    }
}

int CameraBusManager::CameraNumber()
{
    return _cameraDevices.size();
}

CameraDevice *CameraBusManager::operator[](int index)
{
    if(index >=0 && index < CameraNumber())
    {
        return _cameraDevices[index];
    }else{
        return nullptr;
    }
}
