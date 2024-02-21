#include "Mahony_Plot.h"


Mahony_Plot::Mahony_Plot(QObject *parent) : QObject(parent)
    , MahonyPlotThread(nullptr){}

Mahony_Plot::~Mahony_Plot()
{
    stopPlotting(); // 确保线程被正确删除
}

void Mahony_Plot::startPlotting()
{
    createThread(); // 创建并启动线程
    qDebug() << "Mahony 线程: " << QThread::currentThreadId();
}

void Mahony_Plot::stopPlotting()
{
    // if (MahonyPlotThread != nullptr) {
    //     MahonyPlotThread->quit();
    //     MahonyPlotThread->wait();
    //     MahonyPlotThread->deleteLater();
    //     MahonyPlotThread = nullptr; // 重置指针，确保后续可以重新创建线程
    // }

    if (MahonyPlotThread != nullptr && MahonyPlotThread->isRunning()) {
        // 请求线程退出
        QMetaObject::invokeMethod(MahonyPlotThread, "quit", Qt::QueuedConnection);

        // 等待线程安全退出
        if (!MahonyPlotThread->wait(3000)) { // 等待最多3秒
            qWarning() << "Thread did not finish in time, forcing termination";
            MahonyPlotThread->terminate(); // 不推荐使用，除非没有其他选择
            MahonyPlotThread->wait(); // 再次等待
        }

        MahonyPlotThread->deleteLater();
        MahonyPlotThread = nullptr;
    }
    qDebug() << "Mahony 线程Close: ";
}

void Mahony_Plot::createThread()
{
    if (MahonyPlotThread == nullptr) {
        MahonyPlotThread = new QThread(this);
        this->moveToThread(MahonyPlotThread);
        connect(MahonyPlotThread, &QThread::started, this, &Mahony_Plot::plotThreadParameterInitial);
        MahonyPlotThread->start();
    }
}

void Mahony_Plot::plotThreadParameterInitial()
{
    // 进行线程内的初始化，例如设置绘图参数
}

void Mahony_Plot::plotThreadDataReceiver(uint x, uint y, uint z)
{
    if (MahonyPlotThread && MahonyPlotThread->isRunning()) {
        emit requestData(x, y, z); // 发送数据到绘图线程
    }
}


