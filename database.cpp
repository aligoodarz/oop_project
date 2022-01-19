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
  head = newNode;
  count++;
}

void Database::add(const Item &item, int pos)
{
  ItemNode *temp = head;
  if (pos == 0) //handle special case of zero
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
  count++;
}

void Database::add_dummy(const Item &item, int pos)
{
  ItemNode fakeHead(item, nullptr); //Create fakehead to point to the real head
  fakeHead.next = head;             //Point it to the real head
  ItemNode *temp = &fakeHead;
  pos++; //increment pos because of the fake head
  for (int i = 0; i < pos - 1; i++)
  {
    temp = temp->next;
  }
  ItemNode *newNode = new ItemNode(item, temp->next);
  // newNode->next = temp->next;
  temp->next = newNode;
  head = fakeHead.next;
  count++;
}

void Database::removeFront()
{
  ItemNode *old = head;
  head = old->next;
  delete old;
  count--;
}

void Database::remove(int pos)
{
  ItemNode fakeHead = *head;
  fakeHead.next = head;
  ItemNode *temp = &fakeHead;

  pos++;
  for (int i = 0; i < pos - 1; i++)
  {
    temp = temp->next; //Points to (n-1)th node
  }
  ItemNode *nthNode = temp->next;
  temp->next = nthNode->next; //(n+1)th node
  delete nthNode;
  head = fakeHead.next;
  count--;
}

void Database::remove(std::string name) //This function deletes an item based on the item name, it deletes the first instance of that item name
{
  ItemNode *currNode = head;
  ItemNode *prevNode = nullptr;

  for (int i = 0; i < count; i++)
  {
    if (currNode->item.getName() == name)
    {
      if (prevNode == nullptr)
      {
        head = currNode->next;
      }
      else
      {
        prevNode->next = currNode->next;
      }
      delete currNode;
      count--;
      return;
    }
    prevNode = currNode;
    currNode = currNode->next;
  }
  std::cout << name << " was not found in the database" << std::endl;
}

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

int Database::size() const
{
  return count;
}
