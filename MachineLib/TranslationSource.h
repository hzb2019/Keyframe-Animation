/**
 * @file TranslationSource.h
 * @author Henry Barton
 *
 * Class which represents a source for Translation movement events between components
 */

#ifndef CANADIANEXPERIENCE_TRANSLATIONSOURCE_H
#define CANADIANEXPERIENCE_TRANSLATIONSOURCE_H

class Component;
class TranslationSink;

class TranslationSource {
private:
    /// The collection of sinks this source acts on
    std::vector<TranslationSink*> mSinks;

public:
    TranslationSource();

    /// Copy constructor (disabled)
    TranslationSource(const TranslationSource &) = delete;

    /// Assignment operator
    void operator=(const TranslationSource &) = delete;

    void Update(wxPoint position);

    /**
     * Adds a sink to this source's collection
     * @param sink Pointer to the TranslationSink object
     */
     void AddSink(TranslationSink* sink) { mSinks.push_back(sink); }

};

#endif //CANADIANEXPERIENCE_TRANSLATIONSOURCE_H
