/**
 * @file TranslationSink.cpp
 * @author Henry Barton
 */

#include "pch.h"
#include "TranslationSink.h"

#include "Component.h"

/// Default constructor
TranslationSink::TranslationSink()
{
}

void TranslationSink::Update(wxPoint position)
{
    mOwner->SetLocation(position);
}