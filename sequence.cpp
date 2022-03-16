#include "sequence.h"

NodeList::Iterator NodeSequence::atIndex(int i) const
{
    Iterator p = begin();
    for (int j = 0; j < i; j++)
        ++p;
    return p;
}

int NodeSequence::indexOf(const Iterator &p) const
{
    Iterator q = begin();
    int j = 0;
    while (q != p)
    {
        ++q;
        ++j;
    }
    return j;
}