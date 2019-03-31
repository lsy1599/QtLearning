#include "CameraDeviceForm.h"
#include "ui_CameraDeviceForm.h"
#include <QDebug>

CameraDeviceForm::CameraDeviceForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CameraDeviceForm)
{
    ui->setupUi(this);
    connect(this, &CameraDeviceForm::ImageReadly, this, &CameraDeviceForm::ShowImage);
}

CameraDeviceForm::~CameraDeviceForm()
{
    _cameraThreadFlag = false;
    _cameraThreadSrc.waitForFinished();
    delete ui;
}

void CameraDeviceForm::SelectCameraThread(CameraDeviceForm *cls)
{
    cls->_cameraThreadFlag = true;
    while(cls->_cameraThreadFlag)
    {
        QImage* image = new QImage;
        cls->_CameraUseLock.lock();
        cls->_cameraDevice->GetOneImage(*image);
        cls->_CameraUseLock.unlock();
        emit cls->ImageReadly(image);
        QThread::sleep(1);
    }

}

bool CameraDeviceForm::InitCamera(CameraBasePlugin *camera)
{
    if(!_isCameraAvailable)
    {
        _CameraUseLock.lock();
        _cameraDevice = camera;
        _isCameraAvailable  = true;
        _CameraUseLock.unlock();
        qDebug()<<__func__;
        return true;
    }else {
        return false;
    }
}

bool CameraDeviceForm::ExitCamera()
{
    if(_isCameraAvailable)
    {
        _CameraUseLock.lock();
        _cameraDevice = nullptr;
        _CameraUseLock.unlock();
        _isCameraAvailable = false;
        return true;
    }else{
        return false;
    }
}

bool CameraDeviceForm::Start()
{
    if(_isCameraAvailable)
    {
        _cameraDevice->Open();
        _cameraDevice->Stop();
        _cameraThreadSrc = QtConcurrent::run(SelectCameraThread, this);
        qDebug()<<__FUNCTION__;
    }
    return true;
}

bool CameraDeviceForm::Stop()
{
    if(_isCameraAvailable)
    {
        _cameraThreadFlag = false;
        _cameraThreadSrc.waitForFinished();
        _cameraDevice->Stop();
        _cameraDevice->Close();
    }
    return true;
}

void CameraDeviceForm::ShowImage(QImage *img)
{
    ui->Image->setPixmap(QPixmap::fromImage(*img));
    qDebug()<<img->size();

    delete img;
    qDebug()<<__FUNCTION__;
}

void CameraDeviceForm::resizeEvent(QResizeEvent *size)
{
   // ui->Image->resize(this->width()-100, this->height()-20);
   // ui->verticalLayout->setGeometry(QRect(this->width()+40, 0, 100,this->height()));

}

void CameraDeviceForm::on_toolButton_clicked()
{
    Start();
    qDebug()<<__FUNCTION__;
}
