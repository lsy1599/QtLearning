#ifndef DAHUAPLUGIN_H
#define DAHUAPLUGIN_H

#include "../../View/CameraBasePlugin.h"
#include "../../View/CameraBusManager.h"
#include "GenICam/System.h"
#include "GenICam/Camera.h"
#include "GenICam/StreamSource.h"
#include "GenICam/GigE/GigECamera.h"
#include "GenICam/GigE/GigEInterface.h"
#include "Infra/PrintLog.h"
#include "Memory/SharedPtr.h"
#include <arpa/inet.h>
#include <QImage>
#include <QList>


using namespace Dahua::GenICam;
using namespace Dahua::Infra;

class DahuaPlugin :  public QObject, public CameraBasePlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QGenericPluginFactoryInterface" CameraBase_IID FILE "Dahua.json")
    Q_INTERFACES(CameraBasePlugin)

public:
    class CameraDahua: public CameraDevice
    {
        public:
            CameraDahua(CSystem &systemObj, ICameraPtr& cameraSptr);
            bool Start();
            bool Stop();
            bool Open();
            bool Close();
            bool GetOneImage(QImage &img, int timeout = 1000);

            bool SetParameter(const QString Key, const QString Value);
            bool GetParameter(const QString Key, QString &Value);
        private:
            ICameraPtr _cameraSptr;//camera handler
            IStreamSourcePtr _streamPtr;
            CSystem &_systemObj;
    };

    DahuaPlugin();
    ~DahuaPlugin();

    CameraDevice *operator[](int index);
    int CameraNumber();
    bool Discover();

    bool Refresh();

    ICameraPtr m_cameraSptr;
    CSystem &m_systemObj;
    TVector<ICameraPtr> m_vCameraPtrList;
    IStreamSourcePtr m_streamPtr;

    QList<CameraDevice*> _Cameras;
};

#endif // DAHUAPLUGIN_H
