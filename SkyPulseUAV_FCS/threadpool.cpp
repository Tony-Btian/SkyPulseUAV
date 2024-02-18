#include "threadpool.h"

ThreadPool::ThreadPool(std::function<void()> func)
    : taskFunction(std::move(func))
{

}

void ThreadPool::run() {
    if (taskFunction) {
        taskFunction();
    }
    emit isDone();
}
