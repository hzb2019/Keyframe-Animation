/**
 * @file Rod.cpp
 * @author Henry Barton
 */

#include "pch.h"
#include "Rod.h"

/// Default constructor (disabled)
Rod::Rod()
{
    mSink.SetOwner(this);
}

/**
 * Sets the location of this Rod
 * @param position The new position of the end of the Source that controls this Rod
 */
void Rod::SetLocation(wxPoint position)
{
    if (!mNegotiating)
    {
        SetOrigin(position);
        mSource.Update(this);
    }
    else
    {
        Component::SetLocation(position);
    }
}
