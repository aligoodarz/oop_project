#include "doublydatabase.h"

class NodeSequence : public NodeList
{
public:
    Iterator atIndex(int i) const;        // Get position from index
    int indexOf(const Iterator &p) const; // Get index from position
};