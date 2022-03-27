#include <list>

typedef int Elem;
class LinkedBinaryTree
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
        Elem &operator*()
        {
            return v->elt;
        }
        Position left() const
        {
            return Position(v->left);
        }
        Position right() const
        {
            return Position(v->right);
        }
        Position parent() const
        {
            return Position(v->par);
        }
        bool isRoot() const
        {
            return v->par == nullptr;
        }
        bool isExternal() const
        {
            return v->left == nullptr && v->right == nullptr;
        }
        friend class LinkedBinaryTree;
    };
    typedef std::list<Position> PositionList;

public:
    LinkedBinaryTree(); // Constructor
    int size() const;
    bool empty() const;
    Position root() const;          // Get the root
    PositionList positions() const; // List of nodes
    void addRoot();                 // Add root to empty tree
    void expandExternal(const Position &p);
    Position removeAboveExternal(const Position &p);

protected:
    void preorder(Node *v, PositionList &pl) const;

private:
    Node *_root;
    int n;
};