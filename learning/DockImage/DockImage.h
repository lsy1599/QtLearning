#ifndef DOCKIMAGE_H
#define DOCKIMAGE_H

#include <QWidget>
#include <QDockWidget>

class DockImage : public QWidget
{
    Q_OBJECT

public:
    DockImage(QWidget *parent = 0);
    ~DockImage();
    void paintEvent(QPaintEvent* e);
};

#endif // DOCKIMAGE_H
