/**
 * @file MachineBase.cpp
 * @author Henry Barton
 */

#include "pch.h"
#include "MachineBase.h"

#include "MachineController.h"
#include "CustomMachineFactory.h"
#include "OwenMachineFactory.h"

/**
 * Default constructor for a MachineBase
 */
 MachineBase::MachineBase(const std::wstring& imagesDir) : mImagesDir(imagesDir)
{
     SetMachineNumber(1);
}

/**
 * Set the machine number and change the controller
 * @param number An integer number. Each number makes a different machine
 */
void MachineBase::SetMachineNumber(int number)
{
    mMachineID = number;
    if(number == 1)
    {
        CustomMachineFactory factory = CustomMachineFactory(mImagesDir);
        mController = factory.CreateMachine();
        mController->SetOwner(this);
    }
    else if(number == 2)
    {
        OwenMachineFactory factory = OwenMachineFactory(mImagesDir);
        mController = factory.CreateMachine();
        mController->SetOwner(this);
    }

}

/**
 * Draw the machine at the currently specified location
 * @param graphics Graphics object to render to
 */
void MachineBase::DrawMachine(std::shared_ptr<wxGraphicsContext> graphics)
{
    mController->Draw(graphics);
}

/**
 * Get the current machine time.
 * @return Machine time in seconds
 */
double MachineBase::GetMachineTime()
{
    mTime = (double)mFrame / mFrameRate;
    return mTime;
}

/**
* Set the current machine animation frame
* @param frame Frame number
*/
void MachineBase::SetMachineFrame(int frame)
{
    mFrame = frame;
    mTime = (double)frame / mFrameRate * mSpeed;
    mController->SetCurrentTime(mTime);
}


