/**
 * @file RodSink.h
 * @author Henry Barton
 *
 * Sink for Rod movement, passes a rod pointer to its owner so it can properly find a solution
 */

#ifndef CANADIANEXPERIENCE_RODSINK_H
#define CANADIANEXPERIENCE_RODSINK_H

class RodNegotiator;
class Component;
class Rod;

class RodSink {
private:
    /// The class that owns this RodSink
    RodNegotiator* mNegOwner;

public:
    /// Default constructor (disabled)
    RodSink() = delete;

    /// Copy constructor (disabled)
    RodSink(const RodSink &) = delete;

    /// Assignment operator
    void operator=(const RodSink &) = delete;

    RodSink(RodNegotiator* neg);

    void Negotiate(Rod* rod);
};

#endif //CANADIANEXPERIENCE_RODSINK_H
