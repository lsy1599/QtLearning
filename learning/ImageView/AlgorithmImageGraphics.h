#ifndef ALGORITHMIMAGEGRAPHICS_H
#define ALGORITHMIMAGEGRAPHICS_H

#include <QWidget>
#include <QAction>
#include <QToolBar>
#include "AlgorithmImageGraphicsScene.h"
#include "AlgorithmImageGraphicsView.h"

class AlgorithmImageGraphics : public QWidget
{
    Q_OBJECT
public:
    explicit AlgorithmImageGraphics(QWidget *parent = nullptr);

    void initToolBar();

protected:
    bool eventFilter(QObject *watched, QEvent *event);
signals:

public slots:
    void setShape(QAction *act);
    void openPixmap(const QString &path = QString());

private:
    AlgorithmImageGraphicsView*  GraphicsView;
    AlgorithmImageGraphicsScene* GraphicsScene;
    QToolBar *ToolBar = Q_NULLPTR;

};

#endif // ALGORITHMIMAGEGRAPHICS_H
