/**
 * @file Shape.h
 * @author Henry Barton
 *
 * Class for generic shape components
 */

#ifndef CANADIANEXPERIENCE_SHAPE_H
#define CANADIANEXPERIENCE_SHAPE_H

#include "Component.h"
#include "RotationSink.h"

class Shape : public Component {
private:
    /// The RotationSink that controls the rotation for this Shape
    RotationSink mSink;

public:

    Shape();

    /// Copy constructor (disabled)
    Shape(const Shape &) = delete;

    /// Assignment operator
    void operator=(const Shape &) = delete;

    /**
     * Gets the RotationSink that controls this class
     * @return mSink Pointer to the RotationSink
     */
    RotationSink* GetSink() { return &mSink; }
};

#endif //CANADIANEXPERIENCE_SHAPE_H
