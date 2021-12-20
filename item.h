#ifndef _ITEM_H
#define _ITEM_H

#include <string>

class Item
{
private:
    std::string name;
    int count;
    float cost;

public:
    Item(std::string name, int count, float cost); //Constructor

    //------------Getters and Setters----------
    std::string getName();
    void setName(std::string name);

    int getCount();
    void setCount(int count);

    float getCost();
    void setCost(float cost);
    //-----------------------------------------

    //--------------Other methods--------------
    virtual void printInfo(); //This is a virtual method and will be changed for each derived class
};

#endif // ending the definition of ITEM