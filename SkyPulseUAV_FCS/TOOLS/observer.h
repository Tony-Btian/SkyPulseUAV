#ifndef OBSERVER_H  // Prevents the header file from being included multiple times in the same compilation unit
#define OBSERVER_H

/**
 * @class Observer
 * @brief Abstract base class for all observers that need to receive updates from observables.
 *
 * This class defines the interface for all observers that are interested in receiving
 * updates from an Observable object whenever certain changes occur.
 */
class Observer {
public:
    /**
     * @brief Virtual destructor for the Observer class.
     *
     * A virtual destructor ensures that the destructor of any derived class is called 
     * when an object is deleted through a pointer of the base class type. This is crucial
     * to prevent resource leaks.
     */
    virtual ~Observer() {}

    /**
     * @brief Pure virtual function to be implemented by concrete observers for handling updates.
     *
     * This method will be called by the Observable whenever there is an update that the
     * observer needs to know about.
     * @param isInitialised A boolean flag that indicates whether the update is an initialisation-type update.
     */
    virtual void onUpdate(bool isInitialised) = 0;
};

#endif // OBSERVER_H  // Ends the preprocessor conditional started at the beginning of the file

