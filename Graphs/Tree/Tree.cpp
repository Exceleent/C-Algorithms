#include "Tree.h"
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stack>

struct Node;
template <typename V>
Tree<V>::Tree()
{
    size_of_Tree = 0;
    root = NULL;
}
template <typename V>
Tree<V>::Tree(const Tree &tree)
{
    this->size_of_Tree = tree.size();
    this->root = tree.return_root();
}

template <typename V>
int Tree<V>::size() const
{
    return size_of_Tree;
}

template <typename V>
typename Tree<V>::Node *Tree<V>::return_root() const
{
    return root;
}

template <typename V>
void Tree<V>::insert(V value)
{
    int type;
    srand(time(NULL));
    Node *inserting = new Node;
    inserting->value = value;
    inserting->parent = root;
    if (size_of_Tree == 0)
    {
        root = inserting;
        size_of_Tree++;
    }
    else if (size_of_Tree == 1)
    {
        inserting->parent = root;
        root->children.push_back(inserting);
        size_of_Tree++;
    }
    else
    {
        Node *iterator = new Node;
        iterator = root;
        while (true)
        {
            type = rand() % 2;
            if (type == 0)
            {
                inserting->parent = iterator;
                iterator->children.push_back(inserting);
                size_of_Tree++;
                break;
            }
            if (type == 1)
            {
                if (iterator->children.size() == 0)
                {
                    inserting->parent = iterator;
                    iterator->children.push_back(inserting);
                    size_of_Tree++;
                    break;
                }
                else
                {
                    iterator = iterator->children[rand() % (iterator->children.size())];
                }
            }
        }
    }
}
template <typename V>
void Tree<V>::print()
{
    std::stack<Node *> mystack;
    Node *temporary = new Node();
    mystack.push(root);
    while (!mystack.empty())
    {
        temporary = mystack.top();
        mystack.pop();
        if (!temporary->was_visited_print())
        {
            if (temporary->value == 0)
            {
                std::cout << "(";
            }
            else if (temporary->value == -1)
            {
                std::cout << ")";
            }
            else
            {
                std::cout << temporary->value << " ";
            }
            temporary->we_visit_print();
        }
        if (temporary->children.size() > 0 || !temporary->was_visited_print())
        {
            Node *temporary_3 = new Node();
            temporary_3->value = -1;
            mystack.push(temporary_3);
        }
        for (int i = 0; i < temporary->children.size(); i++)
        {
            if (!(temporary->children[i]->was_visited_print()))
            {
                mystack.push((temporary->children[i]));
            }
        }
        if (temporary->children.size() > 0 || !temporary->was_visited_print())
        {
            Node *temporary_2 = new Node();
            temporary_2->value = 0;
            mystack.push(temporary_2);
        }
    }
}
template <typename V>
typename Tree<V>::Node *Tree<V>::find_node(V parent, V value)
{
    std::stack<Node *> mystack;
    Node *temporary = new Node();
    mystack.push(root);
    while (!mystack.empty())
    {
        temporary = mystack.top();
        mystack.pop();
        if (!temporary->was_visited_find())
        {
            if(temporary == root) {
                ////
            }
            else if (temporary->value == value && temporary->parent->value == parent)
            {
                return temporary;
            }
            else
            {
                //....//
            }
            temporary->we_visit_find();
        }
        for (int i = 0; i < temporary->children.size(); i++)
        {
            if (!(temporary->children[i]->was_visited_find()))
            {
                mystack.push((temporary->children[i]));
            }
        }
    }
    return NULL;
}

template <typename V>
void Tree<V>::catch_node(V parent, V value)
{
    Node *print = new Node();
    print = this->find_node(parent, value);
    if (print == NULL)
    {
        std::cout << "There is no such node";
    }
    else
    {
        std::cout << print->value;
    }
}

template <typename V>
Tree<V> Tree<V>::swap(Tree<V> tree, V this_parent, V this_value, V tree_parent, V tree_value)
{
    Node *swap = new Node();
    Node *swap2 = new Node();
    Node *swap_temp = new Node();
    swap = this->find_node(this_parent, this_value);
    swap2 = tree.find_node(tree_parent, tree_value);
    if (swap == NULL || swap2 == NULL)
    {
        std::cout << "Cannot swap, such node does not exist\n";
    }
    else
    {
        *swap_temp = *swap;
        *swap = *swap2;
        *swap2 = *swap_temp;
    }
}

