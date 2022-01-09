/**
 * @file Lever.h
 * @author Henry Barton
 *
 * Class that creates and handles Lever objects and their connections
 */

#ifndef CANADIANEXPERIENCE_LEVER_H
#define CANADIANEXPERIENCE_LEVER_H

#include "Component.h"
#include "RodSink.h"
#include "RotationSource.h"
#include "TranslationSource.h"
#include "RodNegotiator.h"

class Lever : public Component, public RodNegotiator{
private:
    /// The RodSink that controls the rotation for this Lever
    RodSink mSink = RodSink(this);

    /// The RotationSource that this class controls
    RotationSource mRotationSource;

    /// The TranslationSource that this class controls
    TranslationSource mTranslationSource;
public:
    Lever();

    /// Copy constructor (disabled)
    Lever(const Lever &) = delete;

    /// Assignment operator
    void operator=(const Lever &) = delete;

    void Negotiate(Rod* rod) override;

    /**
     * Gets the RodSink that controls this class
     * @return Pointer to the RotationSink
     */
    RodSink* GetSink() { return &mSink; }

    /**
     * Gets the RotationSource that this class controls
     * @return Pointer to the source
     */
    RotationSource* GetRotationSource() { return &mRotationSource; }

    /**
     * Gets the TranslationSource that this class controls
     * @return Pointer to the source
     */
     TranslationSource* GetTranslationSource() { return &mTranslationSource; }
};

#endif //CANADIANEXPERIENCE_LEVER_H
