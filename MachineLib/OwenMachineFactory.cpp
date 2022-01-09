/**
 * @file OwenMachineFactory.cpp
 * @author Henry Barton
 */

#include "pch.h"
#include "OwenMachineFactory.h"

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
 * Constructor for our type 2 machine factory
 * @param imagesDir The directory of our image files
 */
OwenMachineFactory::OwenMachineFactory(wstring imagesDir) : mImagesDir(imagesDir)
{
}

/**
 * Creates a type 2 machine
 * @return Pointer to the newly created machine
 */
shared_ptr<MachineController> OwenMachineFactory::CreateMachine()
{
    // The actual machine object
    shared_ptr<MachineController> machine = make_shared<MachineController>();

    // Base component of the Machine
    auto base = make_shared<Shape>();
    int wid = 300;
    base->Rectangle(-wid/2, -1, wid, 300);
    base->SetImage(mImagesDir + L"/motor-frame.png");

    // Motor object
    auto motor = make_shared<Motor>();
    machine->AddMotor(motor);

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
    wid = 75;
    motor->CenteredSquare(wid);
    motor->SetImage(mImagesDir + L"/shaft.png");
    motor->SetLocation(wxPoint(-50, -60));

    // Arm driven by the motor
    wid = 50;
    auto arm = make_shared<Arm>();
    arm->SetImage(mImagesDir + L"/arm1.png");
    arm->Rectangle(-wid/2, -1, wid, 14);
    arm->SetOrigin(wxPoint(-50, -60));
    arm->SetLength(wid * armOneRatio);
    arm->SetWidth(14);
    motor->GetSource()->AddSink(arm->GetSink());

    // Lever driven by the motor
    wid = 256;
    auto lever = make_shared<Lever>();
    lever->Rectangle(-wid/2, -1, wid, 24);
    lever->SetImage(mImagesDir + L"/lever.png");
    lever->SetLength(wid * leverRatio);
    lever->SetWidth(24);
    lever->SetLocation(wxPoint(-100, -213));

    // Lever column base
    wid = 24;
    auto leverColumn = make_shared<Shape>();
    leverColumn->Rectangle(-wid/2, -1, wid, 113);
    leverColumn->SetImage(mImagesDir + L"/column.png");
    leverColumn->SetLocation(wxPoint(-100, -120));

    // Rod connecting the leverGear arm to the lever
    wid = 200;
    auto armRod = make_shared<Rod>();
    armRod->SetColor(*wxRED);
    armRod->Rectangle(-wid/2, -1, wid, 10);
    armRod->SetLength(wid * rodRatio);
    armRod->SetWidth(10);

    // Create the connections using the rod
    arm->GetSource()->AddSink(armRod->GetSink());
    armRod->GetSource()->AddSink(lever->GetSink());

    // Create a Gear connected to the first lever
    auto leverGear = make_shared<Gear>(25);
    leverGear->SetColor(*wxBLUE);
    leverGear->SetLocation(wxPoint(-100, -225));
    lever->GetRotationSource()->AddSink(leverGear->GetSink());

    // Create a Gear to connect the lever gear and an arm
    auto leverGear2 = make_shared<Gear>(25);
    leverGear2->SetColor(*wxGREEN);
    leverGear2->SetLocation(wxPoint(-100, -304));
    leverGear->Drive(leverGear2, 0.0);

    // Creates the arm that is driven by the lever gear
    wid = 120;
    auto arm2 = make_shared<Arm>();
    arm2->SetImage(mImagesDir + L"/arm1.png");
    arm2->Rectangle(-wid/2, -1, wid, 14);
    arm2->SetOrigin(wxPoint(-100, -304));
    arm2->SetLength(wid * armOneRatio);
    arm2->SetWidth(14);
    arm2->GetSink()->SetPhase(0.5);
    leverGear->GetSource()->AddSink(arm2->GetSink());

    // Lever column 2 base
    wid = 24;
    auto leverColumn2 = make_shared<Shape>();
    leverColumn2->Rectangle(-wid/2, -1, wid, 350);
    leverColumn2->SetImage(mImagesDir + L"/column.png");
    leverColumn2->SetLocation(wxPoint(-300, 0));

    // Lever 2
    wid = 256;
    auto lever2 = make_shared<Lever>();
    lever2->Rectangle(-wid/2, -1, wid, 24);
    lever2->SetImage(mImagesDir + L"/lever.png");
    lever2->SetLength(wid * leverRatio);
    lever2->SetWidth(24);
    lever2->SetLocation(wxPoint(-300, -300));

    // Rod to connect lever 2 to the lever gear arm
    wid = 25;
    auto leverGearRod = make_shared<Rod>();
    leverGearRod->SetColor(*wxRED);
    leverGearRod->Rectangle(-wid/2, -1, wid, 10);
    leverGearRod->SetLength(wid * rodRatio);
    leverGearRod->SetWidth(10);

    // Connect the rod to the lever and arm
    arm2->GetSource()->AddSink(leverGearRod->GetSink());
    leverGearRod->GetSource()->AddSink(lever2->GetSink());

    // Piston that is the final component of this side of the machine
    wid = 100;
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
    leverPiston->SetLocation(wxPoint(-423, -100));
    leverPiston->SetLength(wid * 2 * armOneRatio);
    leverPiston->SetWidth(14);
    leverPiston->SetImage(mImagesDir + L"/arm1.png");
    leverPiston->SetRotation(0.75);

    // Rod to connect lever 2 to the piston
    wid = 25;
    auto leverPistonRod = make_shared<Rod>();
    leverPistonRod->SetColor(*wxRED);
    leverPistonRod->Rectangle(-wid/2, -1, wid, 10);
    leverPistonRod->SetLength(wid * rodRatio);
    leverPistonRod->SetWidth(10);

    // Connect the rod with the lever and piston
    lever2->GetTranslationSource()->AddSink(leverPistonRod->GetSink());
    leverPistonRod->GetSource()->AddSink(leverPiston->GetSink());


    // Another motor object
    auto motor2 = make_shared<Motor>();
    machine->AddMotor(motor2);

    wid = 100;
    // Body of the second motor
    auto body2 = make_shared<Shape>();
    body2->SetColor(*wxBLACK);
    body2->CenteredSquare(wid);
    // Connect the second motor body to the second motor
    motor2->SetLength(100);
    motor2->SetWidth(100);
    motor2->SetBody(body2);

    // Set up the moving part of the second motor
    wid = 50;
    motor2->CenteredSquare(wid);
    motor2->SetImage(mImagesDir + L"/shaft.png");
    motor2->SetLocation(wxPoint(50, -60));

    // Set up a leverGear to connect to the second motor
    auto motorGear = make_shared<Gear>(20);
    motorGear->SetColor(*wxBLUE);
    motorGear->SetLocation(wxPoint(50, -60));
    motor2->GetSource()->AddSink(motorGear->GetSink());

    // Gear that connects to second motor leverGear
    auto motorGearConnect = make_shared<Gear>(40);
    motorGearConnect->SetColor(*wxGREEN);
    motorGearConnect->SetLocation(wxPoint(122, -122));
    motorGear->Drive(motorGearConnect, 0.0022);

    // Final leverGear in the second motor connection
    auto propGear = make_shared<Gear>(15);
    propGear->SetColor(*wxBLUE);
    propGear->SetLocation(wxPoint(191, -173));
    motorGearConnect->Drive(propGear, 0.0002);

    // Prop driven by the previous leverGear
    wid = 34;
    auto gearProp = make_shared<Shape>();
    gearProp->Rectangle(-wid/2, -1, wid, 75);
    gearProp->SetImage(mImagesDir + L"/flag.png");
    gearProp->SetLocation(wxPoint(191, -173));
    propGear->GetSource()->AddSink(gearProp->GetSink());

    // Column holding up the flag leverGear
    wid = 20;
    auto propColumn = make_shared<Shape>();
    propColumn->Rectangle(-wid/2, -1, wid, 190);
    propColumn->SetImage(mImagesDir + L"/column.png");
    propColumn->SetLocation(wxPoint(191, 0));

    machine->AddComponent(motor);
    machine->AddComponent(arm);
    machine->AddComponent(leverGear2);
    machine->AddComponent(arm2);
    machine->AddComponent(motor2);
    machine->AddComponent(base);
    machine->AddComponent(leverGear);
    machine->AddComponent(leverColumn);
    machine->AddComponent(lever);
    machine->AddComponent(armRod);
    machine->AddComponent(motorGear);
    machine->AddComponent(propColumn);
    machine->AddComponent(motorGearConnect);
    machine->AddComponent(propGear);
    machine->AddComponent(gearProp);
    machine->AddComponent(leverColumn2);
    machine->AddComponent(lever2);
    machine->AddComponent(leverGearRod);
    machine->AddComponent(leverPiston);
    machine->AddComponent(leverPistonRod);

    machine->SetCurrentTime(machine->GetStartTime());

    return machine;
}
