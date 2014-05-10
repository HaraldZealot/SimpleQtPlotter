#include "datagenerator.h"
#include <QtGlobal>

DataGenerator::DataGenerator(QObject *parent) :
    QThread(parent)
{
}

void DataGenerator::run()
{
    while(true)
    {
        usleep(1000);
        int arg = qrand();
        int amp = qrand() % 2001 - 1000;
        double ampF = amp / 2000.0;
        emit sendPoint(QPointF(100.0 * (ampF + 1.0) * cos(arg), 100.0 * (ampF + 1.0) * sin(arg)));
    }
}
