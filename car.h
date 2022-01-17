#ifndef _CAR_H
#define _CAR_H

#include "item.h"

class Car : public Item //Publicly inherits from Item
{
public:
    Car(std::string name, int count, float cost, std::string make, std::string model); //Constructor
    void printInfo() const;

private:
    std::string make;
    std::string model;
};

#endif // ending the definition of CAR