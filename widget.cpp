#include "widget.h"
#include <QVBoxLayout>
#include "datagenerator.h"
#include "plotscreen.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    DataGenerator *dataGenerator = new DataGenerator(this);

    setMinimumSize(500, 500);

    PlotScreen *plotScreen = new PlotScreen();
    QVBoxLayout *layout = new QVBoxLayout();
    setLayout(layout);
    layout->addWidget(plotScreen);

    connect(dataGenerator, &DataGenerator::sendPoint, plotScreen, &PlotScreen::receive);
    connect(dataGenerator, &DataGenerator::finished, dataGenerator, &QObject::deleteLater);
    dataGenerator->start();
}

Widget::~Widget()
{

}


