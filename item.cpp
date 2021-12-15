#include <iostream>

#include "item.h"

Item::Item(std::string name, int count, float cost) : name(name), count(count), cost(cost) {}

std::string Item::getName() { return name; }
void Item::setName(std::string name) { this->name = name; }

int Item::getCount() { return count; }
void Item::setCount(int count) { this->count = count; }

float Item::getCost() { return cost; }
void Item::setCost(float cost) { this->cost = cost; }

void Item::printInfo()
{
    std::cout << "Name:    " << name << std::endl
              << "Count:    " << count << std::endl
              << "Cost:    " << cost << std::endl;
}
