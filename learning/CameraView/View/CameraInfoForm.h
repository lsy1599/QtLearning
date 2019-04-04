#ifndef CAMERAINFOFORM_H
#define CAMERAINFOFORM_H

#include <QWidget>
#include <CameraBusManager.h>
#include <CameraBasePlugin.h>
#include <CameraDeviceForm.h>
#include <QList>
#include <QTreeWidgetItem>

namespace Ui {
class CameraInfoForm;
}

class CameraInfoForm : public QWidget
{
    Q_OBJECT

public:
    explicit CameraInfoForm(QList<CameraDeviceForm*> & CameraWorkDocker,
                            CameraBusManager & CameraBusManager,
                            QWidget *parent = nullptr);
    ~CameraInfoForm();
    void InitCamerasList();

public slots:
    void on_TreeWidgetDoubleClicked(QTreeWidgetItem* item,int index);



private:
    Ui::CameraInfoForm *ui;

    QList<CameraDeviceForm*> &_cameraDeviceForm;
    CameraBusManager &_busManager;
};

#endif // CAMERAINFOFORM_H
