/**
 * @file RodSource.h
 * @author Henry Barton
 *
 * The source class which handles updating a RodSink
 */

#ifndef CANADIANEXPERIENCE_RODSOURCE_H
#define CANADIANEXPERIENCE_RODSOURCE_H

class RodSink;
class Rod;

class RodSource{
private:
    /// The sinks this source acts on
    std::vector<RodSink*> mSinks;
public:
    RodSource();

    /// Copy constructor (disabled)
    RodSource(const RodSource &) = delete;

    /// Assignment operator
    void operator=(const RodSource &) = delete;

    void Update(Rod* rod);

    /**
     * Adds a sink to this source's collection
     * @param sink Pointer to the TranslationSink object
     */
    void AddSink(RodSink* sink) { mSinks.push_back(sink); }
};

#endif //CANADIANEXPERIENCE_RODSOURCE_H
