#ifndef POOLTASK_H  // Protects the file from being included multiple times in a single compilation, which can cause compilation errors
#define POOLTASK_H


#include <QObject>        // Includes QObject to allow the PoolTask to emit signals and slot mechanism
#include <QRunnable>      // Includes QRunnable to handle execution in a separate thread
#include <QAtomicInt>     // Includes QAtomicInt for atomic operations on integers, used here to manage the stop signal
#include <functional>     // Includes std::function to use function objects, allows flexibility in the callback definition


/**
 * @class PoolTask
 * @brief A task runner class designed to be used in a thread pool with the ability to stop tasks asynchronously.
 *
 * PoolTask combines QObject and QRunnable to enable task execution in separate threads
 * and interaction with Qt's signal-slot mechanism for thread-safe communication.
 */
class PoolTask : public QObject, public QRunnable
{
    Q_OBJECT  // Enables use of Qt features like signals and slots in this class

public:
    /**
     * @brief Constructs a PoolTask with a specific task function.
     * @param func A std::function wrapping the callable task to be executed.
     */
    explicit PoolTask(std::function<void()> func);

    /**
     * @brief The main task execution method. Overrides QRunnable's run().
     */
    void run() override;

    /**
     * @brief Initiates a stop command for the task, which is checked asynchronously.
     */
    void stop();

signals:
    /**
     * @brief Signal emitted when the task has completed its execution.
     */
    void isDone();

private:
    std::function<void()> taskFunction;  // The function object to be executed by the task.
    QAtomicInt _stop;  // Atomic integer to safely signal the task to stop across threads
};


#endif // POOLTASK_H  // Ends the preprocessor conditional that began at the top of the file

