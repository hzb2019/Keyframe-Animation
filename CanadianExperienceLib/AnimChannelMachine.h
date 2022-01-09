/**
 * @file AnimChannelMachine.h
 * @author Henry Barton
 *
 * Animation channel for machines, used to handle saving and loading to XML
 */

#ifndef CANADIANEXPERIENCE_ANIMCHANNELMACHINE_H
#define CANADIANEXPERIENCE_ANIMCHANNELMACHINE_H

#include "AnimChannel.h"

class MachineDrawable;

class AnimChannelMachine : public AnimChannel{
private:
    /// The position of the Machine
    wxPoint mPosition = wxPoint(0,0);

    /// The start time of the Machine
    double mStartTime = 0;

    /// The drawable that owns this channel
    MachineDrawable* mDrawable;
public:

    wxXmlNode* XmlSave(wxXmlNode* node) override;
    void XmlLoad(wxXmlNode* node);

    void XmlLoadKeyframe(wxXmlNode *) override;
    void Tween(double) override;

    /**
     * Sets the position for the channel to use
     * @param position The position to use
     */
    void SetPosition(wxPoint position) { mPosition = position; }

    /**
     * Sets the start time for the channel to use
     * @param time The start time to use
     */
     void SetStartTime(double time) { mStartTime = time; }

     /**
      * Sets the drawable that owns this channel
      * @param Pointer to the Drawable
      */
      void SetDrawable(MachineDrawable* drawable) { mDrawable = drawable; }
};

#endif //CANADIANEXPERIENCE_ANIMCHANNELMACHINE_H
