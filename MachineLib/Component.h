/**
 * @file Component.h
 * @author Henry Barton
 *
 * Base class for the components in the machine
 */

#ifndef CANADIANEXPERIENCE_COMPONENT_H
#define CANADIANEXPERIENCE_COMPONENT_H

#include "Polygon.h"

class Component : public Polygon {
private:
    /// The position where the component will be drawn in the graphics context
    wxPoint mPosition;

    /// The origin of the graphics for this component, used for rotations
    wxPoint mOrigin = wxPoint(0,0);

    /// The length of the Component
    int mLength = 0;

    /// The width of the Component
    int mWidth = 0;
public:
    Component();

    /// Copy constructor (disabled)
    Component(const Component &) = delete;

    /// Assignment operator
    void operator=(const Component &) = delete;

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics, int x, int y);

    /**
     * Set the location for this component (location related to the parent machine)
     * @param point The location point
     */
    virtual void SetLocation(const wxPoint point) { mPosition = point; }

    /**
     * Get the location of this component (location related to parent machine)
     * @return The location point
     */
     wxPoint GetLocation() { return mPosition; }

    /**
     * Set the origin for this component
     * @param point The origin point
     */
    virtual void SetOrigin(const wxPoint point) { mOrigin = point; }

    /**
     * Get the origin of this component
     * @return The origin point
     */
    wxPoint GetOrigin() { return mOrigin; }

    /**
     * Sets the length of the Component, in pixels
     * @param length The length of the Rod
     */
    void SetLength(int length) { mLength = length; }

    /**
     * Gets the length of the Component, in pixels
     * @return The length of the Rod
     */
    int GetLength() const { return mLength; }

    /**
     * Sets the width of the Component, in pixels
     * @param width The width of the Rod
     */
    void SetWidth(int width) { mWidth = width; }

    /**
    * Gets the width of the Component, in pixels
    * @return The width of the Rod
    */
    int GetWidth() const { return mWidth; }

};

#endif //CANADIANEXPERIENCE_COMPONENT_H
