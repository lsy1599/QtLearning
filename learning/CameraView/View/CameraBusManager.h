#ifndef CAMERABUSMANAGER_H
#define CAMERABUSMANAGER_H

#include <QObject>
#include <QImage>
#include <QList>

#include "CameraBasePlugin.h"


class CameraBusManager : public QObject
{
    Q_OBJECT
public:
    explicit CameraBusManager(QObject *parent = nullptr);
    ~CameraBusManager();

    void loadCameraPlugin();



    int  CameraNumber();
    CameraDevice *operator[](int index);
signals:

public slots:

private:
    QList<CameraDevice*> _cameraDevices;
};

#endif // CAMERABUSMANAGER_H
