#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "CameraBasePlugin.h"
#include <QTabWidget>
#include <QAction>
#include <QList>
#include <CameraDeviceForm.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void loadCameraPlugin();

private:
    Ui::MainWindow *ui;
    QList<CameraDeviceForm*> _cameraDeviceForm;
    CameraBasePlugin* _Camera;

};
#endif // MAINWINDOW_H
