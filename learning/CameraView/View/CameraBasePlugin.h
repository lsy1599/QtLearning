#ifndef CAMERABASEPLUGIN_H
#define CAMERABASEPLUGIN_H
#include <QtPlugin>
#include <QObject>
#include <QList>
#include <QImage>
#include <QPixmap>

class CameraBasePlugin
{
public:
    typedef struct {
        int CameraIndex = -1;
        QString VendorName;
        QString ModelName;
        QString SerialNumber;
        QString Type;
        QString Ipaddress;
    }TCameraDevice;

    virtual bool GetCameraList(QList<TCameraDevice*> &camerasList) = 0;
    virtual bool Open()  = 0;
    virtual bool Close() = 0;
    virtual bool Start() = 0;
    virtual bool Stop() = 0;
    virtual bool GetOneImage(QImage &img){return false;}
    virtual bool GetOneImage(QPixmap &img){return false;}

};

#define CameraBasePlugin_IID "zestroly.plugin.com.cameras"
Q_DECLARE_INTERFACE(CameraBasePlugin, CameraBasePlugin_IID)


#endif // CAMERABASEPLUGIN_H
