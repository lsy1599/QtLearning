#ifndef CAMERABASEPLUGIN_H
#define CAMERABASEPLUGIN_H
#include <QtPlugin>
#include <QObject>
#include <QList>
#include <QImage>
#include <QPixmap>

class CameraDevice{
public:
    virtual bool Start() {return false;}
    virtual bool Stop() {return false;}
    virtual bool Open() {return false;}
    virtual bool Close() {return false;}

    virtual bool SetParameter(QString Key, QString Value){(void)Key;(void)Value;return false;}

    virtual bool GetOneImage(QImage &img){img.load("://res/no-image.jpg"); return false;}

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
