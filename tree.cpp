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