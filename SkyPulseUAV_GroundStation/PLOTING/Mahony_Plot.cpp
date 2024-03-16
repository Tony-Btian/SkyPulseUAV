#include "Mahony_Plot.h"
#include <QDebug>
#include <QtConcurrent>

Mahony_Plot::Mahony_Plot(QObject *parent) : QObject(parent), _stop(0)
{
    connect(&watcher, &QFutureWatcher<void>::finished, this, &Mahony_Plot::plotThreadParameterInitial);
}

Mahony_Plot::~Mahony_Plot()
{
    if (watcher.isRunning()) {
        watcher.waitForFinished();
    }
}

void Mahony_Plot::startPlotting()
{
    _stop.storeRelease(0); // 设置_stop为0，表示开始运行
    auto future = QtConcurrent::run([this]() {
        int i = 0;
        while (_stop.loadAcquire() == 0) {
            ++i;
            QThread::msleep(100); // 模拟耗时操作
            qDebug() << "Print: " << i << "Task running in thread" << QThread::currentThread();
            // 适当的任务代码
        }
    });
    watcher.setFuture(future);
}

void Mahony_Plot::stopPlotting()
{
    _stop.storeRelease(1);
}

void Mahony_Plot::plotThreadParameterInitial()
{
    // 进行线程内的初始化，例如设置绘图参数
}

void Mahony_Plot::plotThreadDataReceiver(uint x, uint y, uint z)
{

}


