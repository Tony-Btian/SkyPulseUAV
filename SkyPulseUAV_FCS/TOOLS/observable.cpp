#include "observable.h"

void Observable::addObserver(Observer *observer)
{
    observers.push_back(observer);
}

void Observable::removeObserver(Observer *observer)
{
    observers.remove(observer);
}

void Observable::notifyObservers(bool isInitialised)
{
    for(Observer *observer : observers){
        observer->onUpdate(isInitialised);
    }
}
