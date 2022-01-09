/**
 * @file CustomMachineFactory.h
 * @author Henry Barton
 *
 * Factory for our type 1 custom machine class
 */

#ifndef CANADIANEXPERIENCE_CUSTOMMACHINEFACTORY_H
#define CANADIANEXPERIENCE_CUSTOMMACHINEFACTORY_H

class MachineController;

class CustomMachineFactory {
private:
    /// The images directory
    std::wstring mImagesDir;

public:
    /// Default constructor (disabled)
    CustomMachineFactory() = delete;

    /// Copy constructor (disabled)
    CustomMachineFactory(const CustomMachineFactory &) = delete;

    /// Assignment operator
    void operator=(const CustomMachineFactory &) = delete;

    CustomMachineFactory(std::wstring imagesDir);
    std::shared_ptr<MachineController> CreateMachine();

};

#endif //CANADIANEXPERIENCE_CUSTOMMACHINEFACTORY_H
