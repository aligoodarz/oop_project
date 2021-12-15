#include "item.h"

class Car : public Item //Publicly inherits from Item
{
public:
    Car(std::string name, int count, float cost, std::string make, std::string model); //Constructor

private:
    std::string make;
    std::string model;
};
