/**
 * @file NegotiationTest.cpp
 * @author Henry Barton
 */

#include "pch.h"
#include "gtest/gtest.h"

#include <Rod.h>
#include <Lever.h>
#include <Piston.h>
 
TEST(NegotiationTest, Construct)
{
    // Makes sure the classes construct and form associations properly
    Rod rod;
    Lever lever;

    Rod rod2;
    Piston piston;

    rod.GetSource()->AddSink(lever.GetSink());
    rod2.GetSource()->AddSink(piston.GetSink());
}

TEST(NegotiationTest, SetValues)
{
    // Makes sure the value getters and setters are working properly before calculation tests are performed
    Rod rod;
    Lever lever;
    Piston piston;

    rod.SetLength(150);
    ASSERT_EQ(rod.GetLength(), 150);

    lever.SetLocation(wxPoint(0, -232));
    lever.SetLength(370);
    ASSERT_EQ(lever.GetLocation(), wxPoint(0, -232));
    ASSERT_EQ(lever.GetLength(), 370);

    piston.SetLocation(wxPoint(10, 10));
    lever.SetWidth(200);
    lever.SetLength(50);
    ASSERT_EQ(piston.GetLocation(), wxPoint(10, 10));
}

TEST(NegotiationTest, NegotiateLever)
{
    // Tests to make sure the rod->lever negotiation gets the correct values
    Rod rod;
    Lever lever;

    rod.SetLength(150);

    lever.SetLocation(wxPoint(0, -232));
    lever.SetLength(370);

    rod.GetSource()->AddSink(lever.GetSink());

    rod.SetLocation(wxPoint(195, -58));

    ASSERT_NEAR(rod.GetRotation(), -0.2623, 0.0001);
    ASSERT_NEAR(lever.GetRotation(), 0.021, 0.001);
}

TEST(NegotiationTest, NegotiatePiston)
{
    // Tests to make sure the rod->piston negotiation gets the correct values
    Rod rod;
    Piston piston;

    rod.SetLength(50);

    rod.GetSource()->AddSink(piston.GetSink());

    piston.SetLocation(wxPoint(-175, 0));

    rod.SetLocation(wxPoint(-183, -256));

    ASSERT_NEAR(rod.GetRotation(), 0.2244, 0.0001);
    ASSERT_EQ(piston.GetLocation(), wxPoint(-175, -206));
}