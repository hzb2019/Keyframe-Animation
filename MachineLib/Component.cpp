/**
 * @file Component.cpp
 * @author Henry Barton
 */

#include "pch.h"
#include "Component.h"

/// Default constructor
Component::Component()
{
}

/**
 * Draw the component based on the machine location and its position offset
 * @param graphics Graphics object to render to
 * @param x The x position of the machine this component is a part of
 * @param y The y position of the machine this component is a part of
 */
void Component::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    DrawPolygon(graphics, mPosition.x + x, mPosition.y + y);
}

