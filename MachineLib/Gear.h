/**
 * @file Gear.h
 * @author Henry Barton
 *
 * Class that handles the creation of Gear objects and their connections
 */

#ifndef CANADIANEXPERIENCE_GEAR_H
#define CANADIANEXPERIENCE_GEAR_H

#include "Component.h"
#include "RotationSource.h"
#include "RotationSink.h"

class Gear : public Component {
private:
    /// The number of teeth for this Gear
    int mTeeth;

    /// The RotationSource that controls rotation for things connected to this Gear
    RotationSource mSource;

    /// The RotationSink that controls the rotation for this Gear
    RotationSink mSink;

public:
    /// Default constructor (disabled)
    Gear() = delete;

    /// Copy constructor (disabled)
    Gear(const Gear &) = delete;

    /// Assignment operator
    void operator=(const Gear &) = delete;

    Gear(int teeth);

    void SetRotation(double rotation) override;

    void Drive(std::shared_ptr<Gear> gear, double phase);

    /**
     * Gets the RotationSink that controls this class
     * @return mSink Pointer to the RotationSink
     */
    RotationSink* GetSink() { return &mSink; }

    /**
     * Gets the RotationSource that this class controls
     * @return mSink Pointer to the RotationSource
     */
    RotationSource* GetSource() { return &mSource; }
};

#endif //CANADIANEXPERIENCE_GEAR_H
