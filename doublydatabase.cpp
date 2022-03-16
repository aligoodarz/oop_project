#include "doublydatabase.h"

// The following are function defenitions for the iterator

NodeList::Iterator::Iterator(DoublyNode *u) { v = u; }

Elem &NodeList::Iterator::operator*() { return v->elem; }

bool NodeList::Iterator::operator==(const Iterator &p) const { return v == p.v; }

bool NodeList::Iterator::operator!=(const Iterator &p) const { return v != p.v; }

NodeList::Iterator &NodeList::Iterator::operator++()
{
    v = v->next;
    return *this;
}

NodeList::Iterator &NodeList::Iterator::operator--()
{
    v = v->prev;
    return *this;
}

// The following are the function definitions for the list itself

NodeList::NodeList()
{
    n = 0; // Initialize size to zero
    // Create the sentinel nodes and point them to each other
    header = new DoublyNode;
    trailer = new DoublyNode;
    header->next = trailer;
    trailer->prev = header;
}

int NodeList::size() const { return n; }

bool NodeList::empty() const { return (n == 0); }

NodeList::Iterator NodeList::begin() const
{
    return Iterator(header->next);
}
