/**
 * @file MachineController.h
 * @author Henry Barton
 *
 * Controls the components of the machine
 */

#ifndef CANADIANEXPERIENCE_MACHINECONTROLLER_H
#define CANADIANEXPERIENCE_MACHINECONTROLLER_H

class MachineBase;
class Component;
class Motor;

class MachineController {
private:
    /// The time in the animation where this machine will start operating
    double mStartTime = 0;

    /// The collection of Components that make up this machine
    std::vector<std::shared_ptr<Component>> mComponents;

    /// The collection of Motors in this machine
    std::vector<std::shared_ptr<Motor>> mMotors;

    /// Pointer to the MachineBase owner class
    MachineBase* mMachineBase;
public:
    /// Copy constructor (disabled)
    MachineController(const MachineController &) = delete;

    /// Assignment operator
    void operator=(const MachineController &) = delete;

    MachineController();
    void AddComponent(std::shared_ptr<Component> component);
    void AddMotor(std::shared_ptr<Motor> motor);
    void Draw(std::shared_ptr<wxGraphicsContext> graphics);
    void SetCurrentTime(double currentTime);

    /**
     * Sets the class that owns this Controller
     * @param owner The MachineBase that owns this Controller
     */
    void SetOwner(MachineBase* owner) { mMachineBase = owner; }

    /**
     * Sets the start time for this Controller
     * @param time The start time in seconds
     */
     void SetStartTime(double time) { mStartTime = time; }

     /**
      * Gets the start time for this Controller, helps when setting initial state for the machine
      * @return The start time in seconds
      */
      double GetStartTime() { return mStartTime; }
};

#endif //CANADIANEXPERIENCE_MACHINECONTROLLER_H
