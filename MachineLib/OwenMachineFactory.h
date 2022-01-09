/**
 * @file OwenMachineFactory.h
 * @author Henry Barton
 *
 * Type 2 machine factory class
 */

#ifndef CANADIANEXPERIENCE_OWENMACHINEFACTORY_H
#define CANADIANEXPERIENCE_OWENMACHINEFACTORY_H

class MachineController;

class OwenMachineFactory {
private:
    /// The images directory
    std::wstring mImagesDir;

public:
    /// Default constructor (disabled)
    OwenMachineFactory() = delete;

    /// Copy constructor (disabled)
    OwenMachineFactory(const OwenMachineFactory &) = delete;

    /// Assignment operator
    void operator=(const OwenMachineFactory &) = delete;

    OwenMachineFactory(std::wstring imagesDir);
    std::shared_ptr<MachineController> CreateMachine();
};

#endif //CANADIANEXPERIENCE_OWENMACHINEFACTORY_H
