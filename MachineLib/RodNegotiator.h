/**
 * @file RodNegotiator.h
 * @author Henry Barton
 *
 * Negotiator interface for rod/piston and rod/lever negotiations
 */

#ifndef CANADIANEXPERIENCE_RODNEGOTIATOR_H
#define CANADIANEXPERIENCE_RODNEGOTIATOR_H

class Rod;

class RodNegotiator
{
public:
    /**
     * Negotiate with a rod to come up with a mutual rotation solution
     * @param rod
     */
    virtual void Negotiate(Rod* rod) = 0;
};

#endif //CANADIANEXPERIENCE_RODNEGOTIATOR_H
