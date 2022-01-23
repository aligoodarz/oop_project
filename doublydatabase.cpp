#include "doublydatabase.h"

DoublyDatabase::DoublyDatabase()
{
    Item item = Item();
    header->next = trailer;
    trailer->prev = header;
};

void DoublyDatabase::add(const Item &item, int pos)
{
    DoublyItemNode *temp = header;
    for (int i = 0; i < pos; i++)
    {
    }
}