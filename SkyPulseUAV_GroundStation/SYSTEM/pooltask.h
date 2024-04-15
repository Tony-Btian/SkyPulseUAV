#ifndef POOLTASK_H
#define POOLTASK_H

#include <QObject>
#include <QRunnable>
#include <QAtomicInt>
#include <functional>

class PoolTask : public QObject, public QRunnable
{
    Q_OBJECT

public:
    explicit PoolTask(std::function<void()> func);
    void run() override;
    void stop();

signals:
    void isDone();

private:
    std::function<void()> taskFunction;
    QAtomicInt _stop;
};

#endif // POOLTASK_H
