#include "Mahony_Plot.h"
// #include "pooltask.h"
#include <QDebug>

Mahony_Plot::Mahony_Plot(QObject *parent) : QObject(parent)
{
    pool.setMaxThreadCount(5);
}

Mahony_Plot::~Mahony_Plot()
{

}

void Mahony_Plot::run()
{
    for(int i = 0; i < 10; i++)
    {
        qDebug() << "plot:" << i << ", current ThreadID: " << QThread::currentThreadId();
        // QThread::sleep(1);
    }
    // qDebug() << "Mahony 线程: " << QThread::currentThreadId();
    // connect(task, &PoolTask::isDone, task, &QObject::deleteLater, Qt::QueuedConnection);
}

void Mahony_Plot::startPlotting()
{
    run();
}

void Mahony_Plot::stopPlotting()
{

}

void Mahony_Plot::plotThreadParameterInitial()
{
    // 进行线程内的初始化，例如设置绘图参数
}

void Mahony_Plot::plotThreadDataReceiver(uint x, uint y, uint z)
{

}


