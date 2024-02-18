#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <QObject>
#include <QRunnable>
#include <QDebug>
#include <functional>


class ThreadPool : public QObject, public QRunnable {
    Q_OBJECT

public:
    explicit ThreadPool(std::function<void()> func);
    void run() override;

signals:
    void isDone();

private:
    std::function<void()> taskFunction;
};

#endif // THREADPOOL_H
