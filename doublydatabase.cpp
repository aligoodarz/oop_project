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

NodeList::Iterator NodeList::end() const
{
    return Iterator(trailer);
}

void NodeList::insert(const NodeList::Iterator &p, const Elem &e)
{
    DoublyNode *w = p.v; // Iterator p node
    DoublyNode *u = w->prev;
    DoublyNode *v = new DoublyNode; // New node to insert into the list

    v->elem = e;
    v->next = w;
    w->prev = v;
    v->prev = u;
    u->next = v;
    n++;
}

void NodeList::insertFront(const Elem &e)
{
    insert(begin(), e);
}

void NodeList::insertBack(const Elem &e)
{
    insert(end(), e);
}

void NodeList::erase(const Iterator &p)
{
    DoublyNode *v = p.v;
    DoublyNode *w = v->next; // After v
    DoublyNode *u = v->prev; // Before v

    u->next = w;
    w->prev = u;
    delete v;
    n--;
}

void NodeList::eraseFront()
{
    erase(begin());
}

void NodeList::eraseBack()
{
    erase(--end()); // Because end points to the element outside of the list
}