#include "doublydatabase.h"

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
