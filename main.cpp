// This is where the tests will happen and where the program will be launched

#include <iostream>

#include "car.h"

int main()
{
    Item test_item("Ali", 2, 3.40f);
    std::cout << "Item's name is " << test_item.getName() << std::endl;
    test_item.printInfo();

    Car test_car("Car 1", 1, 2340.5, "honda", "Civic");
}