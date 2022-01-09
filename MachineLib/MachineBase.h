/**
 * @file MachineBase.h
 * @author Henry Barton
 *
 * Class representing the base of a machine object
 */

#ifndef CANADIANEXPERIENCE_MACHINEBASE_H
#define CANADIANEXPERIENCE_MACHINEBASE_H

#include "Machine.h"

class MachineController;

class MachineBase final : public Machine{
private:
    /// The directory images will be loaded from
    std::wstring mImagesDir;

    /// The location in the frame the machine will be set at
    wxPoint mLocation;

    /// The current frame the entire machine is at
    int mFrame;

    /// The current speed the entire machine is running at
    double mSpeed;

    /// The framerate this will animate at
    int mFrameRate;

    /// The ID number of this machine
    int mMachineID;

    /// The current time of the machine
    double mTime;

    /// The controller for this machine
    std::shared_ptr<MachineController> mController;

public:
    MachineBase(const std::wstring& imagesDir);

    /// Copy constructor (disabled)
    MachineBase(const MachineBase &) = delete;
    
    /// Assignment operator
    void operator=(const MachineBase &) = delete;

    void SetMachineNumber(int number) override;
    void DrawMachine(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
    * Set the position for the root of the machine
    * @param location The x,y location to place the machine
    */
    void SetLocation(wxPoint location) override { mLocation = location; }

    /**
     * Get the location of the machine
     * @return Location x,y in pixels as a point
     */
    wxPoint GetLocation() override { return mLocation; }

    void SetMachineFrame(int frame) override;

    /**
     * Set the expected frame rate in frames per second
     * @param rate Frame rate in frames per second
     */
    void SetFrameRate(double rate) override { mFrameRate = rate; }

    /**
    * Set the speed for animating the machine
    * @param speed Speed from 0 to 1, where 1 is full speed
    */
    void SetSpeed(double speed) override { mSpeed = speed; }

    /**
     * Get the current machine number
     * @return Machine number integer
     */
    int GetMachineNumber() override { return mMachineID; }

    /**
     * Get the current machine time.
     * @return Machine time in seconds
     */
    double GetMachineTime() override;

};

#endif //CANADIANEXPERIENCE_MACHINEBASE_H
