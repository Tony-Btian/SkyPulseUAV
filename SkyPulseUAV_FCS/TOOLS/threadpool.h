#ifndef THREADPOOL_H  // Prevents the header file from being included multiple times in the same compilation unit
#define THREADPOOL_H


#include <QObject>        // Includes the QObject class which is the base class for all Qt objects
#include <QRunnable>      // Includes the QRunnable interface for creating runnable objects
#include <QDebug>         // Includes the QDebug class for debugging messages
#include <functional>     // Includes the std::function utilities from the C++ Standard Library


/**
 * @class ThreadPool
 * @brief Manages a single task in a thread pool environment.
 * 
 * This class is designed to run a specific task in a thread pool. It uses std::function to allow any callable to be 
 * executed in a separate thread. It extends both QObject and QRunnable to integrate with Qt's signal-slot mechanism
 * and thread pool management respectively.
 */
class ThreadPool : public QObject, public QRunnable {
    Q_OBJECT  // Macro that allows the class to include signals and slots

public:
    /**
     * @brief Constructs a ThreadPool with a specific task.
     * @param func A std::function representing the task to be run.
     */
    explicit ThreadPool(std::function<void()> func);

    /**
     * @brief The overridden run method from QRunnable that executes the task.
     */
    void run() override;

signals:
    /**
     * @brief Signal that is emitted when the task is done executing.
     */
    void isDone();

private:
    std::function<void()> taskFunction;  // Function to be executed by the thread pool
};


#endif // THREADPOOL_H  // Ends the preprocessor conditional started at the top of the file

