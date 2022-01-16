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
    Item();                                        //Default constructor
    Item(std::string name, int count, float cost); //Constructor

    //------------Getters and Setters----------
    std::string getName() const;
    void setName(std::string name);

    int getCount() const;
    void setCount(int count);

    float getCost() const;
    void setCost(float cost);
    //-----------------------------------------

    //--------------Other methods--------------
    virtual void printInfo() const; //This is a virtual method and will be changed for each derived class
};

#endif // ending the definition of ITEM