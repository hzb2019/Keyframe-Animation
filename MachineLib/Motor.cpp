/**
 * @file Motor.cpp
 * @author Henry Barton
 */

#include "pch.h"
#include "Motor.h"

using namespace std;

/// Default constructor
Motor::Motor()
{
}

/**
 * Draw the motor based on the machine location and its position offset
 * @param graphics Graphics object to render to
 * @param x The x position of the machine this component is a part of
 * @param y The y position of the machine this component is a part of
 */
void Motor::Draw(shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    auto loc = GetLocation();
    mBody->DrawPolygon(graphics, loc.x + x, loc.y + y);
    Component::Draw(graphics, x, y);
}

/**
 * Sets the time for the motor
 * @param time The current time
 */
void Motor::SetTime(double time)
{
    if(mIsOn)
    {
        SetRotation(mMotorSpeed * time);
    }
    mSource.UpdateSinks(GetRotation());
}