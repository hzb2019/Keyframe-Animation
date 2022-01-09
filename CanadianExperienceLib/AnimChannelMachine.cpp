/**
 * @file AnimChannelMachine.cpp
 * @author Henry Barton
 */

#include "pch.h"
#include "AnimChannelMachine.h"

#include "MachineDrawable.h"

/**
 * Saves the relevant machine information to an XML node and returns it
 * @return XML node containing machine position values and start time
 */
wxXmlNode* AnimChannelMachine::XmlSave(wxXmlNode* node)
{
    auto itemNode = new wxXmlNode(wxXML_ELEMENT_NODE, L"channel");
    node->AddChild(itemNode);

    itemNode->AddAttribute(L"name", GetName());
    itemNode->AddAttribute(L"position_x", wxString::Format(wxT("%d"), mPosition.x));
    itemNode->AddAttribute(L"position_y", wxString::Format(wxT("%d"), mPosition.y));
    itemNode->AddAttribute(L"start_time", wxString::Format(wxT("%f"), mStartTime));
    return itemNode;
}

/**
 * Loads the relevant machine information from the saved file
 */
void AnimChannelMachine::XmlLoad(wxXmlNode* node)
{
    int posX = wxAtoi(node->GetAttribute(L"position_x", L"0"));
    int posY = wxAtoi(node->GetAttribute(L"position_y", L"0"));

    wxString start = node->GetAttribute(L"start_time", L"0");
    double value;

    if (!start.ToDouble(&value))
    {
        value = 0;
    }

    mDrawable->SetLocation(wxPoint(posX, posY));
    mDrawable->SetStartTime(value);
}

/**
 * Would load a keyframe if this class used them, does nothing
 * @param node XML node to load
 */
void AnimChannelMachine::XmlLoadKeyframe(wxXmlNode* node) {}

/**
 * Would tween if this class did tweening, but it doesn't so this does nothing
 * @param n Time or something
 */
void AnimChannelMachine::Tween(double n) {}