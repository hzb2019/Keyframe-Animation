/**
 * @file RotationSink.cpp
 * @author Henry Barton
 */

#include "pch.h"
#include "RotationSink.h"

#include "Component.h"

/// Default constructor
RotationSink::RotationSink()
{
}

/**
 * Updates the RotationSink object and its owner Component
 * @param rotation The rotation value to use for update calculations
 */
void RotationSink::Update(double rotation)
{
    mOwner->SetRotation(rotation * mSpeedRatio + mPhase);
}

/**
* Sets the phase offset so gears can have correct initial states
* @param phase The phase offset value to set
*/
void RotationSink::SetPhase(double phase)
{
    mPhase = phase;
    mOwner->SetRotation(mPhase);
}