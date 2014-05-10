#ifndef DATAGENERATOR_H
#define DATAGENERATOR_H

#include <QThread>
#include <QPoint>

class DataGenerator : public QThread
{
    Q_OBJECT
public:
    explicit DataGenerator(QObject *parent = 0);

signals:
    void sendPoint(QPointF point);
protected:
    void run()override;

};

#endif // DATAGENERATOR_H
