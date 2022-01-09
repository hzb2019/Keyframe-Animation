/**
 * @file Rod.h
 * @author Henry Barton
 *
 * Class that creates and handles Rod objects and their connections
 */

#ifndef CANADIANEXPERIENCE_ROD_H
#define CANADIANEXPERIENCE_ROD_H

#include "Component.h"
#include "TranslationSink.h"
#include "RodSource.h"

class Lever;

class Rod : public Component{
private:
    /// The TranslationSink class that updates the position of this Rod
    TranslationSink mSink;

    /// The RodSource class this class controls and updates sinks for
    RodSource mSource;

    /// Whether or not this Rod is currently negotiating
    bool mNegotiating = false;
public:
    Rod();

    /// Copy constructor (disabled)
    Rod(const Rod &) = delete;

    /// Assignment operator
    void operator=(const Rod &) = delete;

    void SetLocation(wxPoint position) override;

    /**
     * Gets the TranslationSink that controls this class
     * @return Pointer to the TranslationSink
     */
    TranslationSink* GetSink() { return &mSink; }

    /**
     * Gets the RodSource that class controls
     * @return Pointer to the RotationSource
     */
    RodSource* GetSource() { return &mSource; }

    /**
     * Sets the Negotiation flag so the class knows when a SetLocation function call
     * is coming from a Negotiation call or not preventing a function call loop
     * @param negotiation True if the class is currently Negotiating, false otherwise
     */
     void SetNegotiation(bool negotiation) { mNegotiating = negotiation; }
};

#endif //CANADIANEXPERIENCE_ROD_H
