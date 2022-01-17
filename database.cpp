#include "database.h"
#include <iostream>

//Will implement a linked list here.

Database::Database() : head(nullptr) {}

bool Database::empty() const { return (head == NULL); }

Database::~Database()
{
  while (!empty())
    removeFront();
}

const Item &Database::front() const
{
  return head->item;
}

void Database::addFront(const Item &newItem)
{
  ItemNode *newNode = new ItemNode; //Create a new node to store the  variable in
  newNode->item = newItem;
  newNode->next = head;
  head = newNode;
}

void Database::removeFront()
{
  ItemNode *old = head;
  head = old->next;
  delete old;
}

// std::ostream &operator<<(std::ostream &os, const Database &d)
// {
//   ItemNode *temp;
//   temp = head;
//   if (d.empty())
//   {
//     os << "Database is empty";
//   }
//   else
//   {
//     os << "Members are: ";
//     while (d.head != NULL)
//     {
//     }
//   }
//   return os;
// }

void Database::display() const
{
  if (this->empty())
  {
    std::cout << "The database is empty" << std::endl;
  }
  else
  {
    ItemNode *temp;
    temp = head;
    std::cout << "The members are: " << std::endl;
    while (temp != NULL)
    {
      (temp->item).printInfo();
      temp = temp->next;
    }
  }
}