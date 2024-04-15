#include "observable.h"  // Include the declaration for the Observable class


/**
 * @brief Adds a new observer to the list of observers.
 * @param observer Pointer to the observer to be added.
 */
void Observable::addObserver(Observer *observer)
{
    observers.push_back(observer);  // Add the observer to the end of the observer list
}


/**
 * @brief Removes an observer from the list of observers.
 * @param observer Pointer to the observer to be removed.
 */
void Observable::removeObserver(Observer *observer)
{
    observers.remove(observer);  // Remove the observer from the list
}


/**
 * @brief Notifies all registered observers of a change.
 * @param isInitialised A boolean flag indicating whether the notification is due to initialisation.
 */
void Observable::notifyObservers(bool isInitialised)
{
    for(Observer *observer : observers){  // Loop through each observer in the list
        observer->onUpdate(isInitialised);  // Call the onUpdate method of each observer with the isInitialised flag
    }
}

