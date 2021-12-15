#include "item.h"

class Car : public Item
{
public:
    Car(std::string name, int count, float cost, std::string make, std::string model);

private:
    std::string make;
    std::string model;
};

/*Shop 
    list of items

    method()
        dump inventory and put code
        buy()
        sell()*/