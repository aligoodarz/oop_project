// This is where the tests will happen and where the program will be launched

#include <iostream>
#include <stdlib.h>

#include "car.h"
#include "shop.h"
#include "database.h"
#include "tree.h"

int main()
{
    // Item test_item("Ali", 2, 3.40f);
    // Item test_item_2("Ash", 2, 3.40f);

    // // std::cout << "Item's name is " << test_item.getName() << std::endl;
    // // test_item.printInfo();

    // Car test_car("Car 1", 1, 2340.5, "honda", "Civic");

    // // Shop shop;
    // // shop.run();
    // Database database;
    // database.addFront(test_item);
    // database.addFront(test_item_2);
    // database.addFront(test_car);
    // database.add_dummy(test_item, 0);
    // database.display();
    // database.remove("Ali");
    // database.display();
    Tree tree;
    for (int i = 0; i < 10; i++)
    {
        tree.insert(rand() % 100);
    }
    tree.printFlat(tree.root);
}
