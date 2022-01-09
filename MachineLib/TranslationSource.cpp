/**
 * @file TranslationSource.cpp
 * @author Henry Barton
 */

#include "pch.h"
#include "TranslationSource.h"

#include "TranslationSink.h"

/// Default constructor
TranslationSource::TranslationSource()
{
}

/**
 * Updates the sinks this class controls based on the new position passed
 * @param position The new position to update sinks with
 */
void TranslationSource::Update(wxPoint position)
{
    for(auto sink : mSinks)
    {
        sink->Update(position);
    }
}