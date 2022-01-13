#include "database.h"

//Will implement a linked list here.

Database::Database() : head(NULL) {}

bool Database::empty() const { return (head == NULL); }

Database::~Database()
{
  while (!empty())
    removeFront();
}

const Placeholder& Database::front() const
{
  return head->element;
}

void Database::addFront(const Placeholder &item)
{
  ItemNode *newNode = new ItemNode; //Create a new node to store the  variable in
}

void Database::removeFront() {
  ItemNode* old = head;
  head = old->next;
  delete old;
}