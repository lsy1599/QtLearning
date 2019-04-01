#include "CameraDeviceForm.h"
#include "ui_CameraDeviceForm.h"
#include <QDebug>

CameraDeviceForm::CameraDeviceForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CameraDeviceForm)
{
    ui->setupUi(this);
    ui->Run_Button->setEnabled(false);

    connect(this, &CameraDeviceForm::ImageReadly, this, &CameraDeviceForm::ShowImage);
    connect(this, &CameraDeviceForm::StatusMessageReadly, this, &CameraDeviceForm::ShowStatusMessage);
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
        if(cls->_cameraDev->GetOneImage(*image))
        {
            cls->_OK_Count++;
            emit cls->ImageReadly(image);
        }else{
            cls->_NG_Count++;
        }
        cls->_CameraUseLock.unlock();

    }

}

bool CameraDeviceForm::InitCamera(CameraDevice *cameraDev)
{
    if(cameraDev != nullptr)
    {
        _CameraUseLock.lock();
        _cameraDev = cameraDev;
        _CameraUseLock.unlock();
        ui->Run_Button->setEnabled(true);
    }
    return true;
}

bool CameraDeviceForm::ExitCamera()
{
    if(_cameraDev != nullptr)
    {
        _CameraUseLock.lock();
        _cameraDev = nullptr;
        _CameraUseLock.unlock();
        _isCameraAvailable = false;
        ui->Run_Button->setEnabled(false);
    }
    return true;
}

bool CameraDeviceForm::Start()
{
    _cameraDev->Open();
    _cameraDev->Start();
    _cameraThreadSrc = QtConcurrent::run(SelectCameraThread, this);
    return true;
}

bool CameraDeviceForm::Stop()
{
    _cameraThreadFlag = false;
    _cameraThreadSrc.waitForFinished();
    _cameraDev->Stop();
    _cameraDev->Close();
    return true;
}

void CameraDeviceForm::SetShowLabel(QString Item, QString text)
{
    if(Item == "Total") {
        ui->Total_Count->setText(text);
    }else if(Item == "OK") {
        ui->OK_Count->setText(text);
    }else if(Item == "NG") {
        ui->NG_Count->setText(text);
    }else if(Item == "Resolution") {

    }

}

void CameraDeviceForm::ShowImage(QImage *img)
{
    ui->Image->setPixmap(QPixmap::fromImage(*img));
    SetShowLabel("Total", QString::number(_Total_Count));
    SetShowLabel("OK", QString::number(_OK_Count));
    SetShowLabel("NG", QString::number(_NG_Count));
    SetShowLabel("Resolution", QString("%1x%2").arg(img->width()).arg(img->height()));
    // ShowStatusMessage(QString("%1x%2").arg(img->width()).arg(img->height()));
    delete img;
}

void CameraDeviceForm::ShowStatusMessage(QString message)
{

}

void CameraDeviceForm::resizeEvent(QResizeEvent *size)
{
    // ui->Image->resize(this->width()-100, this->height()-20);
    // ui->verticalLayout->setGeometry(QRect(this->width()+40, 0, 100,this->height()));

}


void CameraDeviceForm::on_Run_Button_clicked(bool checked)
{
    if(checked)
    {
        Start();
    }else{
        Stop();
    }

}
