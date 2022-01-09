/**
 * @file MachineDrawable.h
 * @author Henry Barton
 *
 * Describes a Machine Drawable object to display in the frame
 */

#ifndef CANADIANEXPERIENCE_MACHINEDRAWABLE_H
#define CANADIANEXPERIENCE_MACHINEDRAWABLE_H

#include <machine-api.h>
#include "Drawable.h"
#include "AnimChannelMachine.h"

class MachineDrawable : public Drawable{
private:
    /// The machine that this class draws
    std::shared_ptr<Machine> mMachine;

    /// The start time of the machine, in frames
    double mStartTime = 1;

    /// The machine animation channel for helping save and load from XML
    AnimChannelMachine mChannel;
public:
    /// Default constructor (disabled)
    MachineDrawable() = delete;

    /// Copy constructor (disabled)
    MachineDrawable(const MachineDrawable &) = delete;

    /// Assignment operator
    void operator=(const MachineDrawable &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext>) override;
    bool HitTest(wxPoint) override;
    void SetTimeline(Timeline *timeline) override;

    MachineDrawable(const std::wstring &name, const std::wstring &imagesDir);

    void SetStartTime(double time);

    /// Lets ViewEdit know we can do something when we are double clicked on
    void OnDoubleClick() override;

    /**
     * Sets the type of machine used
     * @param number 1 is the first machine design, 2 is the second design
     */
    void SetMachineNumber(int number) { mMachine->SetMachineNumber(number); };

    /**
     * Sets the location of the machine in the frame
     * @param position The position the machine will be set to
     */
    void SetLocation(wxPoint position);

    /**
     * The machine save channel
     * @return Pointer to machine save channel
     */
     AnimChannelMachine* GetMachineChannel() { return &mChannel; }
};

#endif //CANADIANEXPERIENCE_MACHINEDRAWABLE_H
