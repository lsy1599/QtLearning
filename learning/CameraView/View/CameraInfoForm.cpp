#include "CameraInfoForm.h"
#include "ui_CameraInfoForm.h"

#include <QHeaderView>
#include <QScrollBar>
#include <QComboBox>

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

void CameraInfoForm::InitCameraTableWidget()
{

}

void CameraInfoForm::on_TreeWidgetDoubleClicked(QTreeWidgetItem *item, int Index)
{
    bool ok;
    int clickCamera = item->text(0).toInt(&ok);
    if(!ok)
        return;

    _CurrentCamera = clickCamera;
    //_tableModel =  new CameraInfoFormTableWidgetModel(this);
    //ui->tableWidget->setModel(_tableModel);
    ui->tableWidget->clear(); //清理所有数据，行还在
    ui->tableWidget->clearContents(); //清理表数据，不清理头
    ui->tableWidget->setRowCount(0); //清理行
    ui->tableWidget->setColumnCount(4);

    QStringList header;
    header <<tr("name")<<tr("value")<<tr("max")<<tr("min");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setShowGrid(true); //显示分割线

    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    //设置水平、垂直滚动栏样式
    ui->tableWidget->horizontalScrollBar()->setStyleSheet("QScrollBar{background:transparent; height:10px;}"
                                                          "QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
                                                          "QScrollBar::handle:hover{background:gray;}"
                                                          "QScrollBar::sub-line{background:transparent;}"
                                                          "QScrollBar::add-line{background:transparent;}");
    ui->tableWidget->verticalScrollBar()->setStyleSheet("QScrollBar{background:transparent; width: 10px;}"
                                                        "QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
                                                        "QScrollBar::handle:hover{background:gray;}"
                                                        "QScrollBar::sub-line{background:transparent;}"
                                                        "QScrollBar::add-line{background:transparent;}");

    QTableWidgetItem *cellitem = nullptr;
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
    ui->tableWidget->setItem(0,0,cellitem = new QTableWidgetItem("显示位置"));

    cellitem->setFlags(Qt::NoItemFlags);

    QComboBox *displayComBox  = new QComboBox(this);

    int displaycount = _cameraDeviceForm.length();

    displayComBox->addItem(QString("None"));
    int i;
    for(i = 0; i < displaycount; i++)
    {
       if( _cameraDeviceForm[i]->getBindCameraIndex() != -1)
       {
           if(clickCamera ==  _cameraDeviceForm[i]->getBindCameraIndex())
           {
                displayComBox->addItem(QString("%1").arg(i));
                displayComBox->setCurrentText(QString("%1").arg(i));
           }
           qDebug()<< QString("display:%1").arg(i)<<i<<"点击："<<clickCamera << _cameraDeviceForm[i]->getBindCameraIndex();
           continue;
       }

       qDebug()<< QString("display:%1 is idle").arg(i);
       displayComBox->addItem(QString("%1").arg(i));
    }

    ui->tableWidget->setCellWidget(0, 1, displayComBox);
    connect(displayComBox, &QComboBox::currentTextChanged, this, &CameraInfoForm::DisplayCameraChange);


}

void CameraInfoForm::DisplayCameraChange(const QString &text)
{
    bool ok;
    if(text == "None")
    {

        for(int i = 0; i < _cameraDeviceForm.length(); i++)
        {
            if(_cameraDeviceForm[i]->getBindCameraIndex() == _CurrentCamera)
                _cameraDeviceForm[i]->UnbindCamera();
        }
        return;
    }

    int displayFormIndex = text.toInt(&ok);
    if(!ok)
    {
        return;
    }

    _cameraDeviceForm[displayFormIndex]->BindCamera(_busManager[_CurrentCamera], _CurrentCamera);


}

CameraInfoFormTableWidgetModel::CameraInfoFormTableWidgetModel(QObject *parent):
    QAbstractTableModel(parent)
{


}

QVariant CameraInfoFormTableWidgetModel::data(const QModelIndex &index, int role) const
{

    return "";
}

int CameraInfoFormTableWidgetModel::rowCount(const QModelIndex &parent) const
{

    return 0;
}

int CameraInfoFormTableWidgetModel::columnCount(const QModelIndex &parent) const
{

    return 0;
}

ComBoxDelegate::ComBoxDelegate(QObject *parent)
{

}

void ComBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    qDebug()<<index<<model<<editor;

}
