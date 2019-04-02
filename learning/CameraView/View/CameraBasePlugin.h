#ifndef CAMERABASEPLUGIN_H
#define CAMERABASEPLUGIN_H
#include <QtPlugin>
#include <QObject>
#include <QList>
#include <QImage>
#include <QPixmap>

class CameraDevice{
public:
    virtual bool Start() = 0;
    virtual bool Stop() = 0;
    virtual bool Open() = 0;
    virtual bool Close() = 0;

    virtual bool SetParameter(const QString Key, const QString Value) = 0;
    virtual bool GetParameter(const QString Key, QString &Value) = 0;

    virtual bool GetOneImage(QImage &img, int timeout = 1000)=0;

    int CameraIndex = -1;
    QString VendorName;
    QString ModelName;
    QString SerialNumber;
    QString Type;
    QString Ipaddress;
};


class CameraBasePlugin
{
public:
    virtual CameraDevice *operator[](int index) = 0;
    virtual int CameraNumber() = 0;
    virtual bool Discover() = 0;
};

#define CameraBasePlugin_IID "zestroly.plugin.com.cameras"
Q_DECLARE_INTERFACE(CameraBasePlugin, CameraBasePlugin_IID)


#endif // CAMERABASEPLUGIN_H
