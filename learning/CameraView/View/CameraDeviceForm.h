#ifndef CAMERADEVICEFORM_H
#define CAMERADEVICEFORM_H

#include <QWidget>
#include <QQueue>
#include <QtConcurrent/QtConcurrent>
#include <QMutex>

#include "CameraBasePlugin.h"

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

    bool InitCamera(CameraBasePlugin* camera);
    bool ExitCamera();


    bool Start();
    bool Stop();


signals:
    void ImageReadly(QImage *img);

public slots:
    void ShowImage(QImage* img);

protected:
    void resizeEvent(QResizeEvent* size);


private slots:
    void on_toolButton_clicked();

private:
    Ui::CameraDeviceForm *ui;
    QQueue<QImage*> _ImageQueue;

    //相机线程
    QFuture<void> _cameraThreadSrc;
    bool         _cameraThreadFlag = false;

    //相机资源
    CameraBasePlugin* _cameraDevice = nullptr;
    bool              _isCameraAvailable = false;
    QMutex            _CameraUseLock;
};

#endif // CAMERADEVICEFORM_H
