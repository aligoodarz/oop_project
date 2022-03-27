typedef int Elem;
class LinkedBinaryList
{
protected:
    struct Node
    {
        Elem elt;
        Node *par;
        Node *left;
        Node *right;
        Node() : elt(), par(nullptr), left(nullptr), right(nullptr) {}
    };

public:
    class Position
    {
    private:
        Node *v;

    public:
        Position(Node *_v = nullptr) : v(_v) {} // constructor
    }
};