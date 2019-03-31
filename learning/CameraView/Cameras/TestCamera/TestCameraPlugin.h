#ifndef GENERICPLUGIN_H
#define GENERICPLUGIN_H

#include <QGenericPlugin>
#include "../../View/CameraBasePlugin.h"
#include <QDir>



class TestCamera :  public QObject, public CameraBasePlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QGenericPluginFactoryInterface" CameraBase_IID FILE "TestCamera.json")
    Q_INTERFACES(CameraBasePlugin)
public:
    TestCamera();
    ~TestCamera();

    bool GetCameraList(QList<TCameraDevice*> &camerasList);

    bool Open();
    bool Close();
    bool Start();
    bool Stop();
    bool CameraList();

    bool GetOneImage(QImage &img);
    bool GetOneImage(QPixmap &img);
    bool isAvailable = true;
private:
    QDir *_Dir;
    QStringList _files;
    QStringList::iterator _it;

};
#endif // GENERICPLUGIN_H
