/**
 * @file Arm.h
 * @author Henry Barton
 *
 * Class that creates and handles Arm objects and their connections
 */

#ifndef CANADIANEXPERIENCE_ARM_H
#define CANADIANEXPERIENCE_ARM_H

#include "Component.h"
#include "RotationSink.h"
#include "TranslationSource.h"

class Arm : public Component {
private:
    /// The RotationSink that controls the rotation for this Arm
    RotationSink mSink;

    /// The TranslationSource that this class owns
    TranslationSource mSource;

public:
    /// Default constructor
    Arm();

    /// Copy constructor (disabled)
    Arm(const Arm &) = delete;

    /// Assignment operator
    void operator=(const Arm &) = delete;

    void SetRotation(double rotation) override;

    /**
     * Gets the RotationSink that controls this class
     * @return Pointer to the RotationSink
     */
    RotationSink* GetSink() { return &mSink; }

    /**
     * Gets the TranslationSource that this class controls
     * @return Pointer to the TranslationSource
     */
     TranslationSource* GetSource() { return &mSource; }

};

#endif //CANADIANEXPERIENCE_ARM_H
