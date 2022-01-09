/**
 * @file Lever.cpp
 * @author Henry Barton
 */

#include "pch.h"
#include "Lever.h"

#include "Rod.h"

/// Default constructor
Lever::Lever()
{
}

/**
 * Negotiate with a rod to come up with a mutual rotation/position solution
 * @param rod Pointer to the rod to negotiate with
 */
void Lever::Negotiate(Rod* rod)
{
    auto point1 = rod->GetOrigin();
    auto point2 = GetLocation();
    point2 = wxPoint(point2.x, point2.y - (GetWidth() / 2));

    int a = GetLength() / 2;
    int b = rod->GetLength();
    double c = sqrt(pow((point2.y - point1.y), 2) + pow((point2.x - point1.x), 2));

    double delta = atan2(-(point2.y - point1.y), point2.x - point1.x);
    double alpha = acos((pow(b, 2) + pow(c, 2) - pow(a, 2)) / (2 * b * c));
    double theta = delta - alpha;

    wxPoint point3 = wxPoint(point1.x + b * cos(-theta), point1.y + b * sin(-theta));

    double phi = atan2(point3.y - point2.y, point3.x - point2.x);

    rod->SetRotation(- (theta / M_PI / 2));
    rod->SetNegotiation(true);
    rod->SetLocation(wxPoint((rod->GetWidth() + point3.x + point1.x) / 2, (point3.y + point1.y) / 2));
    rod->SetNegotiation(false);

    double rotationValue = phi / M_PI / 2;

    SetRotation(rotationValue);
    mRotationSource.UpdateSinks(rotationValue);

    double x = point2.x - (point3.x - point2.x);
    double y = point2.y - (point3.y - point2.y);

    mTranslationSource.Update(wxPoint(x, y));
}