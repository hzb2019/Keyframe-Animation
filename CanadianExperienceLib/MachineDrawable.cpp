/**
 * @file MachineDrawable.cpp
 * @author Henry Barton
 */

#include "pch.h"
#include "MachineDrawable.h"

#include "Actor.h"
#include "Picture.h"
#include "Timeline.h"

using namespace std;

/// Default constructor
MachineDrawable::MachineDrawable(const wstring &name, const wstring &imagesDir)
    : Drawable(name)
{
    MachineFactory factory = MachineFactory(imagesDir);

    mChannel.SetName(name + L":machine");
    mChannel.SetDrawable(this);
    mChannel.SetStartTime(mStartTime);

    mMachine = factory.CreateMachine();
    mMachine->SetMachineFrame(0);
    mMachine->SetSpeed(1);
}

void MachineDrawable::Draw(shared_ptr<wxGraphicsContext> graphics)
{
    auto timeline = GetActor()->GetPicture()->GetTimeline();

    int frameRate = timeline->GetFrameRate();
    mMachine->SetFrameRate(frameRate);

    int frame = timeline->GetCurrentFrame();
    if(frame > mStartTime)
    {
        mMachine->SetMachineFrame(frame - mStartTime*frameRate);
    }
    else
    {
        mMachine->SetMachineFrame(0);
    }

    double scale = 0.75f;

    wxPoint location = mMachine->GetLocation();

    graphics->PushState();
    graphics->Translate(location.x, location.y);
    graphics->Scale(scale, scale);
    mMachine->SetLocation(wxPoint(0, 0));
    mMachine->DrawMachine(graphics);
    graphics->PopState();

    mMachine->SetLocation(wxPoint(location.x, location.y));
}

/**
 * Checks if the Machine was clicked on
 * This only checks for a rectangular area around the base of the machine,
 * it should include the motors for the type2 machine and should be around the
 * center of the bricks for the type 1 machine.
 * @param point The clicked point to check at
 */
bool MachineDrawable::HitTest(wxPoint point)
{
    wxPoint loc = mMachine->GetLocation();

    bool xPos = loc.x + 75 - point.x > 0 && loc.x - 75 < point.x;
    bool yPos = loc.y - 100 < point.y && loc.y > point.y;

    if(xPos && yPos)
    {
        return true;
    }

    return false;
}

/**
 * Set the machine location
 * @param pos The new location position
 */
void MachineDrawable::SetLocation(wxPoint position)
{
    mMachine->SetLocation(position);
    mChannel.SetPosition(position);
}

/**
 * Sets the start time of the machine
 * @param time The time to set
 */
void MachineDrawable::SetStartTime(double time)
{
    mStartTime = time;
    mChannel.SetStartTime(time);
}

/**
 * Add the channels for this drawable to a timeline
 * @param timeline The timeline class.
 */
void MachineDrawable::SetTimeline(Timeline *timeline)
{
    timeline->AddChannel(&mChannel);
    Drawable::SetTimeline(timeline);
}

void MachineDrawable::OnDoubleClick()
{
    //auto mainFrame = GetActor()->
    //MachineDialog dlg(mainFrame, make_shared<Machine>(this));
}