#include "Blur.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

QString Blur::Name()
{

    return "Blur";
}

void Blur::Run()
{

    cv::Mat src, dst;
    cv::blur(src, dst, cv::Size(5,5), cv::Point(-1,-1));

}

void Blur::SetInputParameter(QString Key, QString Value)
{

}

void Blur::GetInputParameter(QString Key, QString &Value)
{

}

void Blur::SetOutputParameter(QString Key, QString Value)
{

}

void Blur::GetOutputParameter(QString Key, QString &Value)
{

}
