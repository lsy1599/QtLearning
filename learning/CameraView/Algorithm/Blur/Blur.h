#ifndef BLUR_H
#define BLUR_H

#include <../../View/AlgorithmBaseplugin.h>


//均值滤波
class Blur : public QObject, public AlgorithmBasePlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QGenericPluginFactoryInterface" FILE "Blur.json")
    Q_INTERFACES(AlgorithmBasePlugin)

public:
    QString Name();
    void Run();

    void SetInputParameter(QString Key, QString Value);
    void GetInputParameter(QString Key, QString &Value);
    void SetOutputParameter(QString Key, QString Value);
    void GetOutputParameter(QString Key, QString &Value);

    uint8_t *imageSrc;

};

#endif // BLUR_H
