#include "database.h"
#include <iostream>

Database::Database() : head(nullptr) {}

// ItemNode::ItemNode(const Item &item, ItemNode *next) : item(Item(item)), next(next) {}

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
  ItemNode *newNode = new ItemNode(newItem, head); //Create a new node to store the  variable in
  // newNode->item = newItem;
  // newNode->next = head;
  head = newNode;
}

void Database::add(const Item &item, int pos)
{
  ItemNode *temp = head;
  if (pos == 0)
  {
    addFront(item);
  }
  else
  {
    for (int i = 0; i < (pos - 1); i++)
    {
      temp = temp->next;
    }
    ItemNode *newNode = new ItemNode(item, temp->next);
    // newNode->next = temp->next;
    temp->next = newNode;
  }
}

void Database::add_dummy(const Item &item, int pos)
{
  ItemNode fakeHead(item, nullptr);
  fakeHead.next = head;
  ItemNode *temp = &fakeHead;
  pos++;
  for (int i = 0; i < pos - 1; i++)
  {
    temp = temp->next;
  }
  ItemNode *newNode = new ItemNode(item, temp->next);
  // newNode->next = temp->next;
  temp->next = newNode;
  head = fakeHead.next;
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
