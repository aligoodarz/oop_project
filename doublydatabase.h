#ifndef _DOUBLYDATABASE_H_
#define _DOUBLYDATABASE_H_

// This includes a doubly linked list with an iterator implementation
typedef int Elem;
class NodeList
{
private:
    class DoublyNode
    {
    public:
        Elem elem;
        DoublyNode *prev;
        DoublyNode *next;
    };

public:
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

public:
    NodeList();
    int size() const;
    bool empty() const;
    Iterator begin() const;
    Iterator end() const;
    void insertFront(const Elem &e);
    void insertBack(const Elem &e);
    void insert(const Iterator &p, const Elem &e);
    void eraseFront();
    void eraseBack();
    void erase(const Iterator &p);
    // Can add copy and assignment constructor
private:
    int n; // Number of items in set
    DoublyNode *header;
    DoublyNode *trailer;
};

#endif