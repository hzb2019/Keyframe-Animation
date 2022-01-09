/**
 * @file Arm.cpp
 * @author Henry Barton
 */

#include "pch.h"
#include "Arm.h"

/// Default constructor
Arm::Arm()
{
    mSink.SetOwner(this);
}

void Arm::SetRotation(double rotation)
{
    Polygon::SetRotation(rotation);

    auto origin = GetOrigin();

    double rotationValue = rotation * M_PI * 2;

    double x = GetLength() * cos(rotationValue) / 2;
    x -= GetWidth() * sin(rotationValue) / 2;
    x += origin.x;
    double y = GetLength() * sin(rotationValue) / 2;
    y += GetWidth() * cos(rotationValue) / 2;
    y += origin.y;

    SetLocation(wxPoint(x,y));

    x = origin.x + GetLength() * cos(rotationValue);
    y = origin.y + GetLength() * sin(rotationValue);

    mSource.Update(wxPoint(x, y));
}
