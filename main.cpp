#include <iostream>

#include "item.h"

int main()
{
    Item test_item("Ali", 2, 3.40f);
    std::cout << "Item's name is " << test_item.getName() << std::endl;
    test_item.printInfo();
}