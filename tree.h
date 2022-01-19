#include <iostream>

class TreeNode
{
private:
    int value;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    friend class Tree;
};

class Tree
{
public:
    void insert(int number);
    void printFlat(TreeNode *currNode);
    TreeNode *root = nullptr;
};

void Tree::insert(int number)
{
    TreeNode *insertedNode = new TreeNode;

    insertedNode->value = number;

    if (root == nullptr)
    {
        root = insertedNode;
        return;
    }

    TreeNode *currNode = root;
    while (true)
    {
        if (number > currNode->value)
        {
            if (currNode->right == nullptr)
            {
                currNode->right = insertedNode;
                break;
            }
            currNode = currNode->right;
        }
        else if (number < currNode->value)
        {
            if (currNode->left == nullptr)
            {
                currNode->left = insertedNode;
                break;
            }
            currNode = currNode->left;
        }
        else
        {
            delete insertedNode;
            return;
        }
    }
}

void Tree::printFlat(TreeNode *currNode)
{
    if (currNode == nullptr)
        return;
    printFlat(currNode->left);
    std::cout << currNode->value << std::endl;
    printFlat(currNode->right);
}
