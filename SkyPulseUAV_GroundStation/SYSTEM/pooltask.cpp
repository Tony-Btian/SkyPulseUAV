#include "pooltask.h"  // Include the declaration for the PoolTask class


/**
 * @brief Constructor for the PoolTask class.
 * @param func A std::function object encapsulating the task to be executed by this pool task.
 */
PoolTask::PoolTask(std::function<void()> func)
    : taskFunction(std::move(func))  // Initialize the taskFunction member variable by moving the func parameter.
{}


/**
 * @brief Executes the task encapsulated by this PoolTask object.
 *
 * This method checks if a task function exists and executes it. Upon completion, it signals that the task is done.
 */
void PoolTask::run()
{
    if(taskFunction){  // Check if the task function is not empty
        taskFunction();  // Execute the task function if it is valid
    }
    // Uncomment the following lines to introduce a task loop if necessary
    // while(!_stop.loadRelaxed()){
    //     // Execute task's main logic here
    // }
    emit isDone();  // Emit a signal to indicate that the task is completed
}


/**
 * @brief Signals the PoolTask to stop execution.
 *
 * This method sets a flag that can be used to exit the task's main loop (if uncommented in the run method).
 */
void PoolTask::stop()
{
    _stop.storeRelease(true);  // Atomically set the _stop flag to true, indicating the task should cease operation.
}
