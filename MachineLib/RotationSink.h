/**
 * @file RotationSink.h
 * @author Henry Barton
 *
 * RotationSink class, connects RotationSources to the components they rotate
 */

#ifndef CANADIANEXPERIENCE_ROTATIONSINK_H
#define CANADIANEXPERIENCE_ROTATIONSINK_H

class RotationSource;
class Component;

class RotationSink {
private:
    /// Ratio that allows sinks to rotate faster or slower than their sources
    double mSpeedRatio = 1;
    /// Phase offset so gears mesh properly when turning
    double mPhase = 0;

    /// The Component that owns this RotationSink
    Component* mOwner;

public:

    RotationSink();

    /// Copy constructor (disabled)
    RotationSink(const RotationSink &) = delete;

    /// Assignment operator
    void operator=(const RotationSink &) = delete;

    void Update(double rotation);

    void SetPhase(double phase);

    /**
     * Sets the component that owns this RotationSink so it updates the correct component
     * @param component The component that owns this RotationSink
     */
    void SetOwner(Component* component) { mOwner = component; }

    /**
     * Sets the speed ratio value for this component
     * @param speed The speed ratio value
     */
    void SetSpeed(double speed) { mSpeedRatio = speed; }
};

#endif //CANADIANEXPERIENCE_ROTATIONSINK_H
