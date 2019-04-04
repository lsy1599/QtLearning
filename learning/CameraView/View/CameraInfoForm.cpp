#include "CameraInfoForm.h"
#include "ui_CameraInfoForm.h"


CameraInfoForm::CameraInfoForm(QList<CameraDeviceForm *> &CameraWorkDocker, CameraBusManager &CameraBusManager, QWidget *parent):
    QWidget(parent),
    ui(new Ui::CameraInfoForm),
    _cameraDeviceForm(CameraWorkDocker),
    _busManager(CameraBusManager)

{

    ui->setupUi(this);
    InitCamerasList();

}





CameraInfoForm::~CameraInfoForm()
{
    delete ui;
}


static void removeListSame(QStringList& list)
{
    for(int i = 0; i < list.count(); i++)
    {
        for(int k = i + 1;  k < list.count(); k++)
        {
            if(list.at(i) == list.at(k))
            {
                list.removeAt(k);
                k--;
            }
        }
    }
}

void CameraInfoForm::InitCamerasList()
{

    ui->treeWidget->setColumnCount(5);

    QStringList headers;
    headers<<"Index"<<"Vendor"<<"Model"<<"S/N"<<"Ip address";
    ui->treeWidget->setHeaderLabels(headers);
    ui->treeWidget->header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->treeWidget->clear();

    QStringList treeNodeList;
    for(int i = 0; i < _busManager.CameraNumber(); i++)
    {
        treeNodeList << _busManager[i]->Type;
    }
    removeListSame(treeNodeList);
    for(int i = 0; i < treeNodeList.count(); i++)
    {
        QTreeWidgetItem *NodeItem =  new QTreeWidgetItem(ui->treeWidget);
        NodeItem->setText(0, treeNodeList[i]);
    }

    qDebug()<<_busManager.CameraNumber();
    for(int i = 0; i < _busManager.CameraNumber(); i++)
    {
     //   QTreeWidgetItem* widgetItem = new QTreeWidgetItem(ui->treeWidget);
      //  widgetItem->setText(0, _busManager[i]->Type);
        QStringList TextList;
        TextList
                 << QString::number(i)
                 << _busManager[i]->VendorName
                 << _busManager[i]->ModelName
                 << _busManager[i]->SerialNumber
                 << _busManager[i]->Ipaddress ;

        for(int j = 0; j < ui->treeWidget->topLevelItemCount(); j++)
        {

            if(ui->treeWidget->topLevelItem(j)->text(0) == _busManager[i]->Type)
                new QTreeWidgetItem( ui->treeWidget->topLevelItem(j), TextList);
        }

    }

    ui->treeWidget->expandAll();
    connect(ui->treeWidget, &QTreeWidget::itemDoubleClicked, this, &CameraInfoForm::on_TreeWidgetDoubleClicked);



}

void CameraInfoForm::on_TreeWidgetDoubleClicked(QTreeWidgetItem *item, int index)
{
    bool ok;
    int clickCamera = item->text(0).toInt(&ok);
    if(!ok)
        return;

    qDebug()<<clickCamera ;
}
