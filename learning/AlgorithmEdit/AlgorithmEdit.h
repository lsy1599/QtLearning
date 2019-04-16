#ifndef ALGORITHMEDIT_H
#define ALGORITHMEDIT_H

#include <QWidget>
#include <QToolBar>
#include <QAction>
#include "GraphicsScene.h"
#include "GraphicsView.h"

namespace ZAlgorithm {



class AlgorithmEdit : public QWidget
{
    Q_OBJECT

public:
    AlgorithmEdit(QWidget *parent = 0);
    ~AlgorithmEdit();

    void InitToolBar();


private:
    QToolBar* ToolBar = Q_NULLPTR;
    GraphicsView*  View = Q_NULLPTR;
    GraphicsScene* Scene = Q_NULLPTR;

public slots:
    void setShape(QAction *act);

};

}

#endif // ALGORITHMEDIT_H
