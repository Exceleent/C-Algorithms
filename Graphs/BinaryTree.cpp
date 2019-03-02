#include "BinaryTree.h"
#include <iostream>
#include <stack>
struct Root;

BinaryTree::BinaryTree()
{
    size_of_Tree = 0;
    root = NULL;
}
void BinaryTree::insert(int x)
{
    Root *inserting = new Root;
    inserting->value = x;
    inserting->left_child = NULL;
    inserting->right_child = NULL;
    inserting->parent = NULL;
    if (size_of_Tree == 0)
    {
        root = inserting;
        size_of_Tree++;
    }
    else
    {
        Root *temporary_root = new Root;
        temporary_root = root;
        while (1)
        {
            while (inserting->value <= temporary_root->value)
            {
                if (temporary_root->left_child == NULL)
                {
                    temporary_root->left_child = inserting;
                    size_of_Tree++;
                    return;
                }
                temporary_root = temporary_root->left_child;
            }
            while (inserting->value >= temporary_root->value)
            {
                if (temporary_root->right_child == NULL)
                {
                    temporary_root->right_child = inserting;
                    size_of_Tree++;
                    return;
                }
                temporary_root = temporary_root->right_child;
            }
        }
    }
}

BinaryTree::Root *BinaryTree::searchIterative(int x)
{
    Root *returning = new Root;
    returning->left_child = NULL;
    returning->right_child = NULL;
    returning->parent = NULL;
    if (size_of_Tree == 0)
    {
        std::cout << "Tree is empty";
        return NULL;
    }
    else
    {
        Root *temporary_root = new Root;
        temporary_root = root;
        while (true)
        {
            while (temporary_root->value >= x)
            {
                if (temporary_root->value == x)
                {
                    returning = temporary_root;
                    return returning;
                }
                if (temporary_root->left_child == NULL)
                    return NULL;
                temporary_root = temporary_root->left_child;
            }
            while (temporary_root->value <= x)
            {
                if (temporary_root->value == x)
                {
                    returning = temporary_root;
                    return returning;
                }
                if (temporary_root->right_child == NULL)
                    return NULL;
                temporary_root = temporary_root->right_child;
            }
        }
}
    
int BinaryTree::size()
{
    return size_of_Tree;
}

int BinaryTree::minimum()
{
    int current_minimum = 0;
    Root *temporary_root = new Root;
    temporary_root = root;
    while (temporary_root->left_child != NULL)
    {
        temporary_root = temporary_root->left_child;
        current_minimum = temporary_root->value;
    }
    return current_minimum;
}

int BinaryTree::maximum()
{
    int current_maximum = 0;
    Root *temporary_root = new Root;
    temporary_root = root;
    while (temporary_root->right_child != NULL)
    {
        temporary_root = temporary_root->right_child;
        current_maximum = temporary_root->value;
    }
    return current_maximum;
}

void BinaryTree::printPostorder(Root *node)
{
    if (node == NULL)
        return;
    printPostorder(node->left_child);
    printPostorder(node->right_child);
    std::cout << node->value << "\n";
}

void BinaryTree::printInorder(Root *node)
{
    if (node == NULL)
        return;
    printInorder(node->left_child);
    std::cout << node->value << "\n";
    printInorder(node->right_child);
}

void BinaryTree::printPreorder(Root *node)
{
    if (node == NULL)
        return;
    std::cout << node->value << "\n";
    printPreorder(node->left_child);
    printPreorder(node->right_child);
}

int BinaryTree::depth(Root *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int left_path = depth(node->left_child);
        int right_path = depth(node->right_child);
        if (left_path > right_path)
            return (left_path + 1);
        else
            return (right_path + 1);
    }
}

void BinaryTree::Print_iterative()
{
    std::stack<Root *> mystack;
    Root *temporary_root = root;
    while (temporary_root != NULL || mystack.empty() == false)
    {

        while (temporary_root != NULL)
        {
            mystack.push(temporary_root);
            temporary_root = temporary_root->left_child;
        }
        temporary_root = mystack.top();
        mystack.pop();
        std::cout << "Print " << temporary_root->value << "\n";
        temporary_root = temporary_root->right_child;
    }
}
