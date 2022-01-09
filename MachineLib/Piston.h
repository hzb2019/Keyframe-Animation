/**
 * @file Piston.h
 * @author Henry Barton
 *
 * Class that handles the creation of Piston objects and their connections
 */

#ifndef CANADIANEXPERIENCE_PISTON_H
#define CANADIANEXPERIENCE_PISTON_H

#include "Component.h"
#include "RodNegotiator.h"
#include "RodSink.h"

class Rod;

class Piston : public Component, public RodNegotiator {
private:
    /// The RodSink that negotiates with this object
    RodSink mSink = RodSink(this);

    /// The body of the piston
    std::shared_ptr<Polygon> mBody;

    /// The length dimension of the body
    double mBodyLength;

    /// The width dimension of the body
    double mBodyWidth;

public:

    Piston();

    /// Copy constructor (disabled)
    Piston(const Piston &) = delete;

    /// Assignment operator
    void operator=(const Piston &) = delete;

    void Negotiate(Rod* rod) override;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y) override;

    /**
     * Sets the shape of the body for the motor
     * @param body
     */
    void SetBody(std::shared_ptr<Polygon> body) { mBody = body; }

    /**
     * Sets the position of the body of the motor
     * @param point The position of the body
     */
    void SetBodyPosition(wxPoint point);

    /**
     * Gets the RodSink that controls this class
     * @return Pointer to the RodSink
     */
    RodSink* GetSink() { return &mSink; }

    /**
     * Sets the length dimension of the body of the piston
     * @param length The length of the piston body
     */
     void SetBodyLength(double length) { mBodyLength = length; }

     /**
      * Sets the width dimension of the body of the piston
      * @param width The width of the piston body
      */
      void SetBodyWidth(double width) { mBodyWidth = width; }
};

#endif //CANADIANEXPERIENCE_PISTON_H
