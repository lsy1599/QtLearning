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
            QList<CameraBasePlugin::TCameraDevice*> CameraDeviceList;
            CameraBasePlugin *camera = qobject_cast<CameraBasePlugin*>(plugin);
            camera->GetCameraList(CameraDeviceList);
        }

    }





}
