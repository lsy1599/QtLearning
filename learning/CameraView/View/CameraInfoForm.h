#ifndef CAMERAINFOFORM_H
#define CAMERAINFOFORM_H

#include <QWidget>
#include <CameraBusManager.h>
#include <CameraBasePlugin.h>
#include <CameraDeviceForm.h>
#include <QList>
#include <QTreeWidgetItem>
#include <QAbstractTableModel>
#include <QItemDelegate>
#include <QModelIndex>

#include <QVariant>

namespace Ui {
class CameraInfoForm;
}
class CameraInfoFormTableWidgetModel;
class ComBoxDelegate;

class CameraInfoForm : public QWidget
{
    Q_OBJECT

public:
    explicit CameraInfoForm(QList<CameraDeviceForm*> & CameraWorkDocker,
                            CameraBusManager & CameraBusManager,
                            QWidget *parent = nullptr);
    ~CameraInfoForm();
    void InitCamerasList();


    void InitCameraTableWidget();


public slots:
    void on_TreeWidgetDoubleClicked(QTreeWidgetItem* item,int index);

    void DisplayCameraChange(const QString &text);



private:
    Ui::CameraInfoForm *ui;

    QList<CameraDeviceForm*> &_cameraDeviceForm;
    CameraBusManager &_busManager;
    int  _CurrentCamera = -1;
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


class ComBoxDelegate: public QItemDelegate
{
    Q_OBJECT
public:
    ComBoxDelegate(QObject* parent = nullptr);
    void setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index)const;



};





#endif // CAMERAINFOFORM_H

