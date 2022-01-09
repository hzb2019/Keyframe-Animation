/**
 * @file CustomMachineFactory.cpp
 * @author Henry Barton
 */

#include "pch.h"
#include "CustomMachineFactory.h"

#include "MachineController.h"
#include "Shape.h"
#include "Motor.h"
#include "Gear.h"
#include "Arm.h"
#include "Rod.h"
#include "Lever.h"
#include "Piston.h"

using namespace std;

/// Coefficient to change arm1.png images from drawn length to the length we pass to the object
const double armOneRatio = 92.0/120.0;
/// Coefficient to change lever.png images from drawn length to the length we pass to the object
const double leverRatio = 240.0/256.0;
/// Coefficient to change rod.png images from drawn length to the length we pass to the object
const double rodRatio = 0.9;

/**
 * Constructor for our type 1 machine factory
 * @param imagesDir The directory of our image files
 */
CustomMachineFactory::CustomMachineFactory(wstring imagesDir) : mImagesDir(imagesDir)
{
}

/**
 * Creates a type 1 machine
 * @return Pointer to the newly created machine
 */
shared_ptr<MachineController> CustomMachineFactory::CreateMachine()
{
    // The actual machine object
    shared_ptr<MachineController> machine = make_shared<MachineController>();

    // Base component
    auto base = make_shared<Shape>();
    int wid = 550;
    base->Rectangle(-wid/2, -1, wid, 40);
    base->SetImage(mImagesDir + L"/base.png");

    // Motor object
    auto motor = make_shared<Motor>();

    wid = 100;
    // Body of the motor
    auto body = make_shared<Shape>();
    body->SetColor(*wxBLACK);
    body->CenteredSquare(wid);
    // Connect the motor body to the motor
    motor->SetLength(100);
    motor->SetWidth(100);
    motor->SetBody(body);

    // Set up the moving part of the motor
    wid = 25;
    motor->CenteredSquare(wid);
    motor->SetImage(mImagesDir + L"/shaft.png");
    motor->SetLocation(wxPoint(102, -90));

    // Gear that is driven by the motor
    auto motorGear = make_shared<Gear>(7);
    motorGear->SetColor(*wxRED);
    motorGear->SetLocation(wxPoint(102,-90));
    motor->GetSource()->AddSink(motorGear->GetSink());

    // Gear connected to the gear driven by the motor
    auto gear = make_shared<Gear>(35);
    gear->SetColor(*wxBLUE);
    gear->SetLocation(wxPoint(100, -155));
    motorGear->Drive(gear, 0.25);

    // Arm driven by the previous gear
    wid = 120;
    auto arm = make_shared<Arm>();
    arm->SetImage(mImagesDir + L"/arm1.png");
    arm->Rectangle(-wid/2, -1, wid, 14);
    arm->SetOrigin(wxPoint(100, -155));
    arm->SetLength(wid * armOneRatio);
    arm->SetWidth(14);
    gear->GetSource()->AddSink(arm->GetSink());

    // Rod connecting the previous arm with the lever that is created next
    wid = 200;
    auto rod = make_shared<Rod>();
    rod->SetColor(*wxRED);
    rod->Rectangle(-wid/2, -1, wid, 10);
    rod->SetLength(wid * rodRatio);
    rod->SetWidth(10);
    arm->GetSource()->AddSink(rod->GetSink());

    // Lever controlled by the previous rod
    wid = 512;
    auto lever = make_shared<Lever>();
    lever->Rectangle(-wid/2, -1, wid, 48);
    lever->SetImage(mImagesDir + L"/lever.png");
    lever->SetLength(wid * leverRatio);
    lever->SetWidth(48);
    lever->SetLocation(wxPoint(-150, -250));
    rod->GetSource()->AddSink(lever->GetSink());

    // Prop controlled by the lever, shows lever operates as a rotation source
    wid = 63;
    auto leverProp = make_shared<Shape>();
    leverProp->Rectangle(-wid/2, -1, wid, 150);
    leverProp->SetImage(mImagesDir + L"/flag.png");
    leverProp->SetLocation(lever->GetLocation());
    lever->GetRotationSource()->AddSink(leverProp->GetSink());

    // Rod connecting the lever with a piston
    wid = 75;
    auto leverRod = make_shared<Rod>();
    leverRod->SetColor(*wxRED);
    leverRod->Rectangle(-wid/2, -1, wid, 10);
    leverRod->SetLength(wid * rodRatio);
    leverRod->SetWidth(10);
    lever->GetTranslationSource()->AddSink(leverRod->GetSink());

    // Piston driven by the lever
    wid = 50;
    auto leverPiston = make_shared<Piston>();
    // Create the body graphic for the piston
    auto leverPistonBody = make_shared<Shape>();
    leverPistonBody->SetColor(*wxBLACK);
    leverPistonBody->Rectangle(-wid/2, -1, wid, wid);
    leverPiston->SetBody(leverPistonBody);
    leverPiston->SetBodyLength(wid);
    leverPiston->SetBodyWidth(wid);
    // Create the arm graphic of the piston
    leverPiston->Rectangle(-wid/2, -1, wid * 2, 14);
    leverPiston->SetLocation(wxPoint(-350, -50));
    leverPiston->SetLength(wid * 2 * armOneRatio);
    leverPiston->SetWidth(14);
    leverPiston->SetImage(mImagesDir + L"/arm1.png");
    leverPiston->SetRotation(0.75);
    leverRod->GetSource()->AddSink(leverPiston->GetSink());

    // Pillar to hold the lever up
    wid = 25;
    auto pillar = make_shared<Shape>();
    pillar->Rectangle(-wid/2, -1, wid, 260);
    pillar->SetLocation(wxPoint(-150, -30));
    pillar->SetImage(mImagesDir + L"/column.png");

    // Set the machine to it's initial state
    machine->SetCurrentTime(machine->GetStartTime());

    // Add all the components of the machine
    machine->AddComponent(pillar);
    machine->AddComponent(base);
    machine->AddMotor(motor);
    machine->AddComponent(motorGear);
    machine->AddComponent(gear);
    machine->AddComponent(rod);
    machine->AddComponent(arm);
    machine->AddComponent(leverProp);
    machine->AddComponent(leverRod);
    machine->AddComponent(lever);
    machine->AddComponent(leverPiston);

    return machine;
}
