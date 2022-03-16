#include "sequence.h"

NodeList::Iterator NodeSequence::atIndex(int i) const
{
    Iterator p = begin();
    for (int j = 0; j < i; j++)
        ++p;
    return p;
}