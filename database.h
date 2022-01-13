#include "item.h"
#include <string>

typedef std::string Placeholder; //Placeholder for now

class ItemNode
{
private:
    Placeholder element; //Element is an object of type Item
    ItemNode *next;      //Pointer to the next Item

    friend class Database;
};

class Database
{
public:
    Database();                             //Empty List Constructor
    ~Database();                            //Destructor
    bool empty() const;                     //Check if list is empty
    const Placeholder &front() const;       //Get the front element in the list
    void addFront(const Placeholder &item); //Add to the front of list
    void removeFront();                     //Remove front item
private:
    ItemNode *head; //Pointer to the head of the list
};