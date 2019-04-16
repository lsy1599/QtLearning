#include "AlgorithmEdit.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ZAlgorithm::AlgorithmEdit w;
    w.show();

    return a.exec();
}
