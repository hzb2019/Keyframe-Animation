/**
 * @file PictureFactory.cpp
 * @author Charles Owen
 */

#include "pch.h"
#include "PictureFactory.h"
#include "Picture.h"
#include "HaroldFactory.h"
#include "SpartyFactory.h"
#include "Actor.h"
#include "ImageDrawable.h"
#include "MachineDrawable.h"

using namespace std;

/**
 * Factory method to create a new picture.
 * @param imagesDir Directory that contains the images for this application
 * @return The created picture
 */
std::shared_ptr<Picture> PictureFactory::Create(std::wstring imagesDir)
{
    shared_ptr<Picture> picture = make_shared<Picture>();


    // Create the background and add it
    auto background = make_shared<Actor>(L"Background");
    background->SetClickable(false);
    background->SetPosition(wxPoint(0, 0));
    auto backgroundI =
            make_shared<ImageDrawable>(L"Background", imagesDir + L"/Background.jpg");
    background->AddDrawable(backgroundI);
    background->SetRoot(backgroundI);
    picture->AddActor(background);

    // Create and add type 1 machine
    auto machine1 = make_shared<Actor>(L"Machine1");
    auto machineDrawable1 = make_shared<MachineDrawable>(L"Machine1", imagesDir);
    // Set up the connection between the actor and drawable first so the drawable can properly use its functions
    machine1->SetRoot(machineDrawable1);
    machine1->AddDrawable(machineDrawable1);
    machineDrawable1->SetLocation(wxPoint(450, 600));

    // Create and add type 2 machine
    auto machine2 = make_shared<Actor>(L"Machine2");
    auto machineDrawable2 = make_shared<MachineDrawable>(L"Machine2", imagesDir);
    // Set up the connection between the actor and drawable first so the drawable can properly use its functions
    machine2->SetRoot(machineDrawable2);
    machine2->AddDrawable(machineDrawable2);
    machineDrawable2->SetLocation(wxPoint(800, 400));
    machineDrawable2->SetMachineNumber(2);


    picture->AddActor(machine2);

    picture->AddActor(machine1);


    // Create and add Harold
    HaroldFactory haroldFactory;
    auto harold = haroldFactory.Create(imagesDir);

    // This is where Harold will start out.
    harold->SetPosition(wxPoint(300, 500));
    picture->AddActor(harold);

    // Create and add Sparty
    SpartyFactory spartyFactory;
    auto sparty = spartyFactory.Create(imagesDir);

    sparty->SetPosition(wxPoint(550, 520));
    picture->AddActor(sparty);

    return picture;
}

