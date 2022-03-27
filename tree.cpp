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
