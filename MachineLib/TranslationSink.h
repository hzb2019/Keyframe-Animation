/**
 * @file TranslationSink.h
 * @author Henry Barton
 *
 * Class which represents a sink for Translation movement
 */

#ifndef CANADIANEXPERIENCE_TRANSLATIONSINK_H
#define CANADIANEXPERIENCE_TRANSLATIONSINK_H

class Component;

class TranslationSink {
private:
    /// The class that owns this TranslationSink
    Component* mOwner;
public:
    TranslationSink();

    /// Copy constructor (disabled)
    TranslationSink(const TranslationSink &) = delete;

    /// Assignment operator
    void operator=(const TranslationSink &) = delete;

    void Update(wxPoint position);

    /**
     * Sets the component that owns this TranslationSink so it updates the correct component
     * @param component The component that owns this TranslationSink
     */
    void SetOwner(Component* owner) { mOwner = owner; }
};

#endif //CANADIANEXPERIENCE_TRANSLATIONSINK_H
