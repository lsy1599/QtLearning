#ifndef DAHUAPLUGIN_H
#define DAHUAPLUGIN_H

#include "../../View/CameraBasePlugin.h"
#include "GenICam/System.h"
#include "GenICam/Camera.h"
#include "GenICam/StreamSource.h"
#include "GenICam/GigE/GigECamera.h"
#include "GenICam/GigE/GigEInterface.h"
#include "Infra/PrintLog.h"
#include "Memory/SharedPtr.h"
#include <arpa/inet.h>


using namespace Dahua::GenICam;
using namespace Dahua::Infra;

class DahuaPlugin :  public QObject, public CameraBasePlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QGenericPluginFactoryInterface" CameraBase_IID FILE "Dahua.json")
    Q_INTERFACES(CameraBasePlugin)
public:
    DahuaPlugin();
    ~DahuaPlugin();

    bool GetCameraList(QList<TCameraDevice*> &camerasList);
    bool RefreshCameraList(TVector<ICameraPtr> &vCameraPtrList);

    bool Open();
    bool Close();
    bool Start();
    bool Stop();
    bool CameraList();

    ICameraPtr m_cameraSptr;
    CSystem &m_systemObj;
    TVector<ICameraPtr> m_vCameraPtrList;
    IStreamSourcePtr m_streamPtr;


};

#endif // DAHUAPLUGIN_H
