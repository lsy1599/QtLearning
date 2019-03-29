#include "DahuaPlugin.h"
#include <QDebug>

#include "GenICam/System.h"
#include "GenICam/Camera.h"
#include "GenICam/StreamSource.h"
#include "GenICam/GigE/GigECamera.h"
#include "GenICam/GigE/GigEInterface.h"
#include "Infra/PrintLog.h"
#include "Memory/SharedPtr.h"
#include <arpa/inet.h>



DahuaPlugin::DahuaPlugin():m_systemObj(CSystem::getInstance())
{
    qDebug()<<__FUNCTION__;

}

DahuaPlugin::~DahuaPlugin()
{
    qDebug()<<__FUNCTION__;
}

bool DahuaPlugin::GetCameraList(QList<CameraBasePlugin::TCameraDevice*> &CameraDeviceList)
{
    ICameraPtr cameraSptr;
    if(RefreshCameraList(m_vCameraPtrList))
    {
        for(size_t index = 0; index < m_vCameraPtrList.size(); index++)
        {
            TCameraDevice* CameraDevice = new TCameraDevice;
            cameraSptr = m_vCameraPtrList[index];
            CameraDevice->CameraIndex  = static_cast<int>(index);
            CameraDevice->VendorName   = cameraSptr->getVendorName();
            CameraDevice->ModelName    = cameraSptr->getModelName();
            CameraDevice->SerialNumber = cameraSptr->getSerialNumber();

            switch (cameraSptr->getType())
            {
            case ICamera::typeGige:
            {
                CameraDevice->Type = "Gige";
                IGigECameraPtr gigeCameraPtr = IGigECamera::getInstance(cameraSptr);
                if (nullptr != gigeCameraPtr.get())
                {
                    CameraDevice->Ipaddress = gigeCameraPtr->getIpAddress().c_str();
                }
                break;
            }
            case ICamera::typeU3v:
                CameraDevice->Type = "U3V";
                break;
            case ICamera::typeCL:
                CameraDevice->Type = "CL";
                break;
            case ICamera::typePCIe:
                CameraDevice->Type = "PCIe";
                break;
            default:
                CameraDevice->Type = "Unknow";
                break;
            }
            CameraDeviceList.append(CameraDevice);
        }
    }
    return true;
}


bool DahuaPlugin::RefreshCameraList(TVector<ICameraPtr> &vCameraPtrList)
{
    bool isDiscoverySuccess = m_systemObj.discovery(vCameraPtrList);
    if(!isDiscoverySuccess)
    {
        qDebug()<<"Discovery Device Fail.\n";
        return false;
    }

    if(m_vCameraPtrList.size() == 0)
    {
        qDebug()<<"No Device.\n";
        return false;
    }
    return true;
}

bool DahuaPlugin::Open()
{
    qDebug()<<__FUNCTION__;
    return true;
}

bool DahuaPlugin::Close()
{
    qDebug()<<__FUNCTION__;
    return true;
}

bool DahuaPlugin::Start()
{
    return true;
}

bool DahuaPlugin::Stop()
{
    return true;
}
