#ifndef MAHONY_PLOT_H
#define MAHONY_PLOT_H

#include <QObject>
#include <QFutureWatcher>
// #include <QMutex>
#include "qcustomplot.h"

class Mahony_Plot : public QObject
{
    Q_OBJECT

public:
    explicit Mahony_Plot(QObject *parent = nullptr);
    ~Mahony_Plot();

private:
    QFutureWatcher<void> watcher;
    QAtomicInt _stop;
    void plotThreadParameterInitial(); // 线程参数初始化

public slots:
    void plotThreadDataReceiver(uint, uint, uint);
    void startPlotting();
    void stopPlotting();

signals:
    void finishedPlotting();
    void requestData(uint x, uint y, uint z); // 修改信号，携带绘图数据

};

#endif // MAHONY_PLOT_H
