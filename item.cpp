//This is the base class for items that will be used in the shop
#include <iostream>

#include "item.h"

Item::Item() {}                                                                               //default constructor
Item::Item(std::string name, int count, float cost) : name(name), count(count), cost(cost) {} //constructor

/* Getters and Setters
-------------------------------------------*/
std::string Item::getName() const { return name; }
void Item::setName(std::string name) { this->name = name; }

int Item::getCount() const { return count; }
void Item::setCount(int count) { this->count = count; }

float Item::getCost() const { return cost; }
void Item::setCost(float cost) { this->cost = cost; }
//-------------------------------------------

//---------------Other Methods-------------------
void Item::printInfo() const
{
    std::cout << "Name:    " << name << std::endl
              << "Count:    " << count << std::endl
              << "Cost:    " << cost << std::endl;
}
//-----------------------------------------------
