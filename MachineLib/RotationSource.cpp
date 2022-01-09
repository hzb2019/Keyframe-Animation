/**
 * @file RotationSource.cpp
 * @author Henry Barton
 */

#include "pch.h"
#include "RotationSource.h"

#include "RotationSink.h"

RotationSource::RotationSource()
{
}

/**
 * Adds a sink to the collection this RotationSource controls
 * @param sink Pointer to the RotationSink object to add
 */
void RotationSource::AddSink(RotationSink* sink)
{
    mSinks.push_back(sink);
}

/**
 * Updates all the sinks associated with this Rotation Source
 * @param rotation The rotation value to use for updating
 */
void RotationSource::UpdateSinks(double rotation)
{
    for(auto sink : mSinks)
    {
        sink->Update(rotation);
    }
}
