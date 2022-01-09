/**
 * @file Gear.cpp
 * @author Henry Barton
 */

#include "pch.h"
#include "Gear.h"

const double ToothDepth = 5;     ///< Depth of a tooth in pixels
const double ToothWidth = 0.33;  ///< Width of a tooth at the top as fraction of tooth pitch
const double ToothSlope = 0.1;   ///< Fraction of pitch where the tooth slopes up or down
const double PI2 = M_PI * 2;     ///< PI * 2 constant

/**
 * Constructor, needs to know how many teeth this gear has
 * @param teeth The number of teeth on this gear
 */
Gear::Gear(int teeth) : mTeeth(teeth)
{
    mSink.SetOwner(this);

    double radius = teeth * 1.66;

    // Where the tooth starts in the arc
    double toothStart = 1.0 - ToothWidth - ToothSlope * 2;
    double innerRadius = radius - ToothDepth;

    for (int t = 0; t < mTeeth; t++)
    {
        double angle1 = double(t) / double(mTeeth) * PI2;
        double angle2 = double(t + toothStart) / double(mTeeth) * PI2;
        double angle3 = double(t + toothStart + ToothSlope) / double(mTeeth) * PI2;
        double angle4 = double(t + toothStart + ToothSlope + ToothWidth) / double(mTeeth) * PI2;
        double angle5 = double(t + toothStart + ToothSlope * 2 + ToothWidth) / double(mTeeth) * PI2;

        AddPoint(innerRadius * cos(angle1), innerRadius * sin(angle1));
        AddPoint(innerRadius * cos(angle2), innerRadius * sin(angle2));
        AddPoint(radius * cos(angle3), radius * sin(angle3));
        AddPoint(radius * cos(angle4), radius * sin(angle4));
        AddPoint(innerRadius * cos(angle5), innerRadius * sin(angle5));
    }
}

/**
 * Set the rotation of the gear
 * @param rotation Rotation in turns, where 0-1 is one revolution.
 */
void Gear::SetRotation(double rotation)
{
    mSource.UpdateSinks(rotation);
    Polygon::SetRotation(rotation);
}

/**
* Makes this gear act as a source for another gear
*/
void Gear::Drive(std::shared_ptr<Gear> gear, double phase)
{
    auto sink = gear->GetSink();

    mSource.AddSink(sink);
    sink->SetSpeed(-(double)mTeeth / (double)gear->mTeeth);
    sink->SetPhase(phase);
}