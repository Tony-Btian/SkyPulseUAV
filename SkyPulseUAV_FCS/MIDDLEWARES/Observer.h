#ifndef OBSERVER_H
#define OBSERVER_H

class Observer {
public:
    virtual ~Observer() {}
    virtual void onUpdate(bool isInitialised) = 0;
};

#endif // OBSERVER_H
