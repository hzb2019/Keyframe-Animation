/**
 * @file RodSink.cpp
 * @author Henry Barton
 */

#include "pch.h"
#include "RodSink.h"

#include "RodNegotiator.h"

/**
 * Constructor for the RodSink class
 * @param neg The class that owns this sink, as a RodNegotiator pointer
 * @param comp The class that owns this sink, as a Component pointer
 */
RodSink::RodSink(RodNegotiator* neg) : mNegOwner(neg)
{
}

/**
 * Passes the rod pointer to its owner so it can properly negotiate a position and rotation
 * solution
 * @param rod The rod pointer to use
 */
void RodSink::Negotiate(Rod* rod)
{
    if(mNegOwner != nullptr)
    {
        mNegOwner->Negotiate(rod);
    }
}