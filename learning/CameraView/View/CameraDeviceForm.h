#ifndef CAMERADEVICEFORM_H
#define CAMERADEVICEFORM_H

#include <QWidget>
#include <QQueue>
#include <QtConcurrent/QtConcurrent>
#include <QMutex>
#include <QStatusBar>

#include "CameraBasePlugin.h"
#include <QTime>

namespace Ui {
class CameraDeviceForm;
}

class CameraDeviceForm : public QWidget
{
    Q_OBJECT

public:
    explicit CameraDeviceForm(QWidget *parent = nullptr);
    ~CameraDeviceForm();
    void setImage(QImage* img);

    bool enqueueImage(QImage* img); //图片入队列
    bool dequeueImage(QImage* img); //图片出队列

    static void SelectCameraThread(CameraDeviceForm* cls);

    bool InitCamera(CameraDevice* cameraDev);
    bool ExitCamera();

    bool Start();
    bool Stop();


    void SetShowLabel(QString Item, QString text);
signals:
    void ImageReadly(QImage *img);
    void StatusMessageReadly(QString message);

public slots:
    void ShowImage(QImage* img);
    void ShowStatusMessage(QString message);

protected:
    void resizeEvent(QResizeEvent* size);


private slots:
    void on_Run_Button_clicked(bool checked);

private:
    Ui::CameraDeviceForm *ui;
    QQueue<QImage*> _ImageQueue;

    //相机线程
    QFuture<void> _cameraThreadSrc;
    bool         _cameraThreadFlag = false;

    //相机资源
    CameraDevice*     _cameraDev         = nullptr;
    bool              _isCameraAvailable = false;
    QMutex            _CameraUseLock;


    QStatusBar* ui_statusBar;
    qint64 _Total_Count = 0;
    qint64 _OK_Count = 0;
    qint64 _NG_Count = 0;

    int    _FrameRate = 0;
    int    _FrameRateShow = 0;
    int    _TransSpeed = 0;
    int    _TransSpeedShow = 0;
    QTime  _timebuff = QTime::currentTime();

};

#endif // CAMERADEVICEFORM_H
