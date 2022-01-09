/**
 * @file Piston.cpp
 * @author Henry Barton
 */

#include "pch.h"
#include "Piston.h"

#include "Rod.h"

/// Default constructor
Piston::Piston()
{
}

/**
 * Draw the piston based on the machine location and its position offset
 * @param graphics Graphics object to render to
 * @param x The x position of the machine this component is a part of
 * @param y The y position of the machine this component is a part of
 */
void Piston::Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y)
{
    auto loc = GetLocation();

    Component::Draw(graphics, (GetWidth() / 2) + x, y);
    mBody->DrawPolygon(graphics, loc.x + x, loc.y + y + (mBodyLength / 2));
}

void Piston::Negotiate(Rod* rod)
{
    int a = rod->GetLength();
    auto point1 = rod->GetOrigin();

    auto point2 = GetLocation();

    double alpha = asin(((double)point2.x - point1.x) / a);
    double beta = (M_PI / 2) - alpha;

    rod->SetRotation((beta / M_PI / 2));

    double y = point1.y + a * cos(alpha / M_PI / 2);
    SetLocation(wxPoint(point2.x, y + GetLength()));

    rod->SetNegotiation(true);
    rod->SetLocation(wxPoint((point1.x + point2.x - rod->GetWidth()) / 2, (point1.y + y) / 2));
    rod->SetNegotiation(false);
}