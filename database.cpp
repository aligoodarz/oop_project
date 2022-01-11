#include <iostream>
#include <map>
#include <string>
#include "item.h"

//Will implement a linked list here.
//This will be done to reinforce the ideas that were learned while exploring linked lists.
class Node
{
  Item::Item element; //Element is an object of type Item
  Node *next;         //Pointer to the next Item
};

class Database
{
private:
  std::map<int, std::string> database;

public:
};