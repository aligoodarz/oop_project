#ifndef _DATABASE_H_
#define _DATABASE_H_

#include "item.h"
#include <string>
#include <iostream>

class ItemNode
{
    ItemNode(const Item &item, ItemNode *next) : item(item), next(next) {}
    // ItemNode(ItemNode *next) : next(next) {}

private:
    const Item &item; //Element is an object of type Item
    ItemNode *next;   //Pointer to the next Item

    friend class Database;
};

class Database
{
public:
    Database();                      //Empty List Constructor
    ~Database();                     //Destructor
    bool empty() const;              //Check if list is empty
    const Item &front() const;       //Get the front element in the list
    void addFront(const Item &item); //Add to the front of list
    void removeFront();              //Remove front item
    // friend std::ostream &operator<<(std::ostream &os, const Database &d);
    void display() const; //Displays the items in the database
    const Item &at(int i) const;
    void remove(int pos); //Generic remove function for any item in the list
    void add(const Item &item, int pos);
    int size() const;
    void add_dummy(const Item &item, int pos);

private:
    ItemNode *head; //Pointer to the head of the list
};

#endif