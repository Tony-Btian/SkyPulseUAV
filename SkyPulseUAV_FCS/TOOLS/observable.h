#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <list>
#include "observer.h"

class Observable
{
public:
    void addObserver(Observer *observer);
    void removeObserver(Observer *observer);

protected:
    void notifyObservers(bool isInitialised);

private:
    std::list<Observer*> observers;
};

#endif // OBSERVABLE_H
