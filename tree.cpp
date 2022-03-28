#include "tree.h"
LinkedBinaryTree::LinkedBinaryTree() : _root(nullptr), n(0) {}

int LinkedBinaryTree::size() const { return n; }

bool LinkedBinaryTree::empty() const { return size() == 0; }

LinkedBinaryTree::Position LinkedBinaryTree::root() const { return Position(_root); }

void LinkedBinaryTree::addRoot()
{
    _root = new Node;
    n = 1;
}

void LinkedBinaryTree::expandExternal(const Position &p)
{
    Node *v = p.v;
    v->left = new Node;
    v->left->par = v;
    v->right = new Node;
    v->right->par = v;
    n += 2;
}

LinkedBinaryTree::Position
LinkedBinaryTree::removeAboveExternal(const Position &p)
{
    Node *w = p.v;                                   // Get node at position p
    Node *v = w->par;                                // Get the parent of node w
    Node *sib = (w == v->left ? v->right : v->left); // Set the sibling of w
    if (v == _root)
    {
        _root = sib;
        sib->par = nullptr;
    }
    else
    {
        Node *gpar = v->par; // Get w's grandparent
        if (v == gpar->left)
            gpar->left = sib;
        else
            gpar->right = sib;
        sib->par = gpar;
    }
    delete w;
    delete v;
    n -= 2;
    return Position(sib);
}

void LinkedBinaryTree::preorder(Node *v, PositionList &pl) const
{
    pl.push_back(Position(v));
    if (v->left != nullptr)
        preorder(v->left, pl);
    if (v->right != nullptr)
        preorder(v->right, pl);
}

LinkedBinaryTree::PositionList LinkedBinaryTree::positions() const
{
    PositionList pl;
    preorder(_root, pl);
    return PositionList(pl);
}