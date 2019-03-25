#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionZoonIn_triggered();

    void on_actionZoonOut_triggered();

    void on_actionRotate_triggered();

private:
    Ui::MainWindow *ui;
    QImage img;
    qreal m_zoonin = 1.0;
    qreal m_zoonout =1.0;
    int   m_rotale = 0;
};

#endif // MAINWINDOW_H
