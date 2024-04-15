#include "threadpool.h"  // Includes the definition for the ThreadPool class.


/**
 * @brief Constructor for the ThreadPool class.
 * @param func The function that will be executed by the thread pool.
 */
ThreadPool::ThreadPool(std::function<void()> func)
    : taskFunction(std::move(func))  // Initialize the taskFunction member variable with the function passed to the constructor.
{
}

/**
 * @brief Executes the task assigned to the ThreadPool.
 * 
 * This function checks if a task function exists and then executes it. After execution, it emits a signal indicating the task is done.
 */
void ThreadPool::run()
{
    if (taskFunction) {  // Check if the task function is not empty
        taskFunction();  // Execute the task function
    }
    emit isDone();  // Emit a signal indicating that the task is completed
}
