#include "pooltask.h"

PoolTask::PoolTask(std::function<void()> func)
    : taskFunction(std::move(func))
{}

void PoolTask::run()
{
    if(taskFunction){
        taskFunction();
    }
    // while(!_stop.loadRelaxed()){
    //     // 执行任务的主要逻辑
    // }
    emit isDone();
}

void PoolTask::stop()
{
    _stop.storeRelease(true);
}
