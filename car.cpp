#include "car.h"
#include <iostream>

Car::Car(std::string name, int count, float cost, std::string make, std::string model) : Item(name, count, cost), make(make), model(model) {}

void Car::printInfo() const
{
    Item::printInfo();
    std::cout << "Make:    " << make << std::endl
              << "Model:    " << model << std::endl;
}