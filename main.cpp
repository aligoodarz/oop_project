// This is where the tests will happen and where the program will be launched

#include <iostream>

#include "car.h"
#include "shop.h"
#include "database.h"

int main()
{
    Item test_item("Ali", 2, 3.40f);
    Item test_item_2("Ash", 2, 3.40f);
    // std::cout << "Item's name is " << test_item.getName() << std::endl;
    // test_item.printInfo();

    // Car test_car("Car 1", 1, 2340.5, "honda", "Civic");

    // Shop shop;
    // shop.run();
    Database database;
    database.display();
    database.addFront(test_item);
    database.display();
    database.addFront(test_item_2);
    database.display();
    test_item_2.setName("Nazli");
    database.display();
    database.removeFront();
    database.display();
    database.removeFront();
    database.display();
}