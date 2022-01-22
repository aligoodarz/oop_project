#include "doublydatabase.h"

DoublyDatabase::DoublyDatabase() : header(trailer->prev), trailer(header->next){};

void DoublyDatabase::add(const Item &item, int pos)
{
    DoublyItemNode *temp = header;
    for (int i = 0; i < pos; i++)
    {
    }
}