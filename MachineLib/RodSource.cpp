/**
 * @file RodSource.cpp
 * @author Henry Barton
 */

#include "pch.h"
#include "RodSource.h"

#include "RodSink.h"

/// Default constructor
RodSource::RodSource()
{
}

/**
 * Updates the sinks this class controls based on the new state of the Rod
 * @param rod The rod to update sink states with
 */
void RodSource::Update(Rod* rod)
{
    for(auto sink : mSinks)
    {
        sink->Negotiate(rod);
    }
}