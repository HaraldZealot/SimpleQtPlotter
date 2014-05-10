#ifndef PLOTSCREEN_H
#define PLOTSCREEN_H

#include <QWidget>

class PlotScreen : public QWidget
{
    Q_OBJECT
public:
    explicit PlotScreen(QWidget *parent = 0);

signals:

public slots:
    void receive(QPointF);

protected:
    void wheelEvent(QWheelEvent *event)override;
    void paintEvent(QPaintEvent *)override;
private:
    double scale;
    QVector<QPointF> points;
};

#endif // PLOTSCREEN_H
