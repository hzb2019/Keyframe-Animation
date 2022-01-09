/**
 * @file RotationSource.h
 * @author Henry Barton
 *
 * RotationSource connection class, connects sources to sinks and passes update instructions
 */

#ifndef CANADIANEXPERIENCE_ROTATIONSOURCE_H
#define CANADIANEXPERIENCE_ROTATIONSOURCE_H

class RotationSink;

class RotationSource {
private:
    /// The collection of Sinks this Source will affect when updating
    std::vector<RotationSink* > mSinks;

public:
    /// Default constructor
    RotationSource();

    /// Copy constructor (disabled)
    RotationSource(const RotationSource &) = delete;

    /// Assignment operator
    void operator=(const RotationSource &) = delete;

    void UpdateSinks(double rotation);

    /**
     * Adds a RotationSink for this Source
     * @param sink The RotationSink to add to the collection
     */
    void AddSink(RotationSink* sink);

};

#endif //CANADIANEXPERIENCE_ROTATIONSOURCE_H
