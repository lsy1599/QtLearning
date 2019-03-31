#ifndef CAMERABUSMANAGER_H
#define CAMERABUSMANAGER_H

#include <QObject>

class CameraBusManager : public QObject
{
    Q_OBJECT
public:
    explicit CameraBusManager(QObject *parent = nullptr);
    ~CameraBusManager();

    void loadCameraPlugin();

signals:

public slots:
};

#endif // CAMERABUSMANAGER_H
