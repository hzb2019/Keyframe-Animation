/**
 * @file MachineController.cpp
 * @author Henry Barton
 */

#include "pch.h"
#include "MachineController.h"

#include "MachineBase.h"
#include "Component.h"
#include "Motor.h"

/// Default constructor
MachineController::MachineController()
{
}

/**
 * Adds a component to this MachineController
 * @param component Pointer to the component to add
 */
void MachineController::AddComponent(std::shared_ptr<Component> component)
{
    mComponents.push_back(component);
}

/**
 * Adds a motor to this MachineController
 * @param component Pointer to the motor to add
 */
void MachineController::AddMotor(std::shared_ptr<Motor> motor)
{
    mMotors.push_back(motor);
    mComponents.push_back(motor);
}

/**
 * Draws all the components in the machine this controls
 * @param graphics The graphics context within which to draw the components
 */
void MachineController::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    wxPoint machinePosition = mMachineBase->GetLocation();
    for(auto component : mComponents)
    {
        component->Draw(graphics, machinePosition.x, machinePosition.y);
    }
}

/**
 * Updates the time for all the components
 * @param currentTime The current time
 */
void MachineController::SetCurrentTime(double currentTime)
{
    if (currentTime >= mStartTime)
    {
        currentTime -= mStartTime;
        for(auto motor : mMotors)
        {
            motor->SetTime(currentTime);
        }
    }

}


