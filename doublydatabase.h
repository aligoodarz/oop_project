#ifndef _DOUBLYDATABASE_H_
#define _DOUBLYDATABASE_H_

// This includes a doubly linked list with an iterator implementation

typedef int Elem;
class DoublyNode
{
    Elem elem;
    DoublyNode *prev;
    DoublyNode *next;
};

class Iterator
{
public:
    Elem &operator*(); // Refrecene to the element
    bool operator==(const Iterator &p) const;
    bool operator!=(const Iterator &p) const;
    Iterator &operator++();
    Iterator &operator--();
    friend class NodeList;

private:
    DoublyNode *v;           // Poiter to the node
    Iterator(DoublyNode *u); // Create from node
};

#endif