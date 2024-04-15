#ifndef OBSERVABLE_H  // Prevents the header file from being included multiple times in a single compilation unit, which can lead to redefinition errors
#define OBSERVABLE_H

#include <list>         // Includes the standard list container from the C++ Standard Library
#include "observer.h"   // Include the Observer class definition



/**
 * @class Observable
 * @brief Class that can be observed by other objects (observers).
 *
 * This class maintains a list of observer objects and notifies them of changes.
 */
class Observable
{
public:
    /**
     * @brief Adds an observer to the notification list.
     * @param observer Pointer to the observer object to be added.
     */
    void addObserver(Observer *observer);

    /**
     * @brief Removes an observer from the notification list.
     * @param observer Pointer to the observer object to be removed.
     */
    void removeObserver(Observer *observer);

protected:
    /**
     * @brief Notifies all registered observers about an event.
     * @param isInitialised Boolean flag indicating if the notification is about initialization.
     */
    void notifyObservers(bool isInitialised);

private:
    std::list<Observer*> observers;  // List of pointers to Observer objects
};

#endif // OBSERVABLE_H  // Ends the preprocessor conditional that began at the top of the file

