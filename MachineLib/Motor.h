/**
 * @file Motor.h
 * @author Henry Barton
 *
 * Motor component class. Drives the motion of the entire machine, is composed of a static
 * body Polygon and a moving shaft.
 */

#ifndef CANADIANEXPERIENCE_MOTOR_H
#define CANADIANEXPERIENCE_MOTOR_H

#include "Component.h"
#include "RotationSource.h"

class Motor : public Component{
private:
    /// Whether or not this motor is turned on
    bool mIsOn = true;

    /// The speed this motor is currently running at
    double mMotorSpeed = 1;

    /// The immobile body of the motor
    std::shared_ptr<Polygon> mBody;

    /// The RotationSource object for this class
    RotationSource mSource;

public:
    Motor();

    /// Copy constructor (disabled)
    Motor(const Motor &) = delete;

    /// Assignment operator
    void operator=(const Motor &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) override;

    void SetTime(double time);

    /**
     * Sets the shape of the body for the motor
     * @param body
     */
    void SetBody(std::shared_ptr<Polygon> body) { mBody = body; }

    /**
     * Sets the position of the body of the motor
     * @param point The position of the body
     */
     //void SetBodyPosition(wxPoint point) { mBodyPos = point; }

     /**
      * Gets pointer to the RotationSource object
      * @return The RotationSource object owned by this motor
      */
      RotationSource* GetSource() { return &mSource; }
};

#endif //CANADIANEXPERIENCE_MOTOR_H
