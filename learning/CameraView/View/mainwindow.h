#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "CameraBasePlugin.h"
#include <QTabWidget>
#include <QAction>
#include <QList>
#include <CameraDeviceForm.h>
#include <CameraBusManager.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void discoverCamera();

    void InitHomeWidget();
    void InitCameraWidget();
    void InitLogWidget();
    void InitAlgorithmEditWidget();

    void AutoBridgeConnectionCamera();
    void     BridgeConnectionCamera();

private:
    Ui::MainWindow *ui;

    QList<CameraDeviceForm*> _cameraDeviceForm;
    CameraBusManager _busManager;


};
#endif // MAINWINDOW_H
