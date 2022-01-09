/**
 * @file Shape.cpp
 * @author Henry Barton
 */

#include "pch.h"
#include "Shape.h"

/// Default constructor
Shape::Shape()
{
    mSink.SetOwner(this);
}