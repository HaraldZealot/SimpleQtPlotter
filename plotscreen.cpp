#include "plotscreen.h"
#include <QTransform>
#include <QPainter>
#include <QWheelEvent>
#include <QDebug>

PlotScreen::PlotScreen(QWidget *parent) :
    QWidget(parent),
    scale(1.0)
{
    points.reserve(300000);
}

void PlotScreen::receive(QPointF point)
{
    points.push_back(point);
    update();
}

void PlotScreen::wheelEvent(QWheelEvent *event)
{
    int delta = 0;

    QPoint numPixels = event->pixelDelta();
    QPoint numAngles = event->angleDelta();

    if (!numPixels.isNull())
        delta = numPixels.y();
    else if (!numAngles.isNull())
        delta = numAngles.y();

    if(delta > 0)
        scale *= 1.015625;
    else
        scale /= 1.015625;
}

void PlotScreen::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.setTransform(QTransform(1, 0, 0, -1, width() / 2, height() / 2));

    QPen paintpen(Qt::black);
    paintpen.setWidth(2);
    painter.setPen(paintpen);

    for(auto it = points.begin(), end = points.end(); it != end; ++it)
        painter.drawPoint(scale * (*it));
}
