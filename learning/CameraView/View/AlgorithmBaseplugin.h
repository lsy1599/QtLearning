#ifndef ALGORITHMBASEPLUGIN_H
#define ALGORITHMBASEPLUGIN_H

#include <QtPlugin>
#include <QObject>


class AlgorithmBasePlugin{

public:
    virtual QString Name() = 0;
    virtual void Run() = 0;

    virtual void SetInputParameter(QString Key, QString Value) = 0;
    virtual void GetInputParameter(QString Key, QString &Value) = 0;
    virtual void SetOutputParameter(QString Key, QString Value) = 0;
    virtual void GetOutputParameter(QString Key, QString &Value) = 0;

    //QVariant




};


#define AlgorithmBasePlugin_IID "zestroly.plugin.com.algorithm"
Q_DECLARE_INTERFACE(AlgorithmBasePlugin, AlgorithmBasePlugin_IID)


#endif // ALGORITHMBASEPLUGIN_H
