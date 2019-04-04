#ifndef CAMERAINFOFORM_H
#define CAMERAINFOFORM_H

#include <QWidget>
#include <CameraBusManager.h>
#include <CameraBasePlugin.h>
#include <CameraDeviceForm.h>
#include <QList>
#include <QTreeWidgetItem>
#include <QAbstractTableModel>

#include <QVariant>

namespace Ui {
class CameraInfoForm;
}
class CameraInfoFormTableWidgetModel;

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
//    CameraInfoFormTableWidgetModel *_tableModel;
};


class CameraInfoFormTableWidgetModel: public QAbstractTableModel
{
    Q_OBJECT
public:
    CameraInfoFormTableWidgetModel(QObject* parent = nullptr);

    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;

private:

};






#endif // CAMERAINFOFORM_H

