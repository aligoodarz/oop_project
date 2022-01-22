#ifndef _DOUBLYDATABASE_H_
#define _DOUBLYDATABASE_H_

#include "item.h"

class DoublyItemNode
{
private:
    const Item &item;
    DoublyItemNode *next;
    DoublyItemNode *prev;
    DoublyItemNode(const Item &item, DoublyItemNode *next, DoublyItemNode *prev) : item(item), next(next), prev(prev){};

    friend class DoublyDatabase;
};

class DoublyDatabase
{
public:
    DoublyDatabase();
    ~DoublyDatabase();
    bool empty() const;
    void add(const Item &item, int pos);
    void remove(int pos);

private:
    DoublyItemNode *header;
    DoublyItemNode *trailer;
    int count = 0;
};

#endif