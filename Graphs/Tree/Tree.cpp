#include "Tree.h"
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <experimental/random>
#define MAX_NUMB_OF_PATH 30


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
Node<V> *Tree<V>::return_root() const
{
    return root;
}

template <typename V>
void Tree<V>::insert(V value)
{
    int type;
    Node<V> *inserting = new Node<V>();
    inserting->set_value(value);
    inserting->set_parent(root);
    if (size_of_Tree == 0)
    {
        root = inserting;
        size_of_Tree++;
    }
    else if (size_of_Tree == 1)
    {
        inserting->set_parent(root);
        root->add_child(inserting);
        size_of_Tree++;
    }
    else
    {
        Node<V> *iterator = new Node<V>();
        iterator = root;
        while (true)
        {
            type = std::experimental::randint(0,1);
            if (type == 0)
            {
                inserting->set_parent(iterator);
                iterator->add_child(inserting);
                size_of_Tree++;
                break;
            }
            if (type == 1)
            {
                if (iterator->nb_of_children() == 0)
                {
                    inserting->set_parent(iterator);
                    iterator->add_child(inserting);
                    size_of_Tree++;
                    break;
                }
                else
                {
                    iterator = iterator->return_random_child();
                }
            }
        }
    }
}
template <typename V>
void Tree<V>::print()
{
    std::stack<Node<V> *> mystack;
    Node<V> *temporary = new Node<V>();
    mystack.push(root);
    while (!mystack.empty())
    {
        temporary = mystack.top();
        mystack.pop();
        if (!temporary->was_visited_print())
        {
            if (temporary->get_value() == 0)
            {
                std::cout << "(";
            }
            else if (temporary->get_value() == -1)
            {
                std::cout << ")";
            }
            else
            {
                std::cout << temporary->get_value() << " ";
            }
            temporary->we_visit_print();
        }
        if (temporary->nb_of_children() > 0 || !temporary->was_visited_print())
        {
            Node<V> *temporary_3 = new Node<V>();
            temporary_3->set_value(-1);
            mystack.push(temporary_3);
        }
        for (int i = 0; i < temporary->nb_of_children(); i++)
        {
            if (!(temporary->return_child(i)->was_visited_print()))
            {
                mystack.push((temporary->return_child(i)));
            }
        }
        if (temporary->nb_of_children() > 0 || !temporary->was_visited_print())
        {
            Node<V> *temporary_2 = new Node<V>();
            temporary_2->set_value(0);
            mystack.push(temporary_2);
        }
    }
}
template <typename V>
void Tree<V>::unprint()
{
    std::stack<Node<V> *> mystack;
    Node<V> *temporary = new Node<V>();
    mystack.push(root);
    while (!mystack.empty())
    {
        temporary = mystack.top();
        mystack.pop();
        if (!temporary->was_visited_print())
        {
            std::cout << temporary->get_value() << " ";
        }
        temporary->we_unvisit_print();

        for (int i = 0; i < temporary->nb_of_children(); i++)
        {
            if ((temporary->return_child(i)->was_visited_print()))
            {
                mystack.push((temporary->return_child(i)));
            }
        }
    }
}





template <typename V>
Node<V> *Tree<V>::find_node(V parent, V value)
{
    std::stack<Node<V> *> mystack;
    Node<V> *temporary = new Node<V>();
    mystack.push(root);
    while (!mystack.empty())
    {
        temporary = mystack.top();
        mystack.pop();
        if (!temporary->was_visited_find())
        {
            if (temporary == root)
            {
                ////
            }
            else if (temporary->get_value() == value && temporary->return_parent()->get_value() == parent)
            {
                return temporary;
            }
            else
            {
                //....//
            }
            temporary->we_visit_find();
        }
        for (int i = 0; i < temporary->nb_of_children(); i++)
        {
            if (!(temporary->return_child(i)->was_visited_find()))
            {
                mystack.push((temporary->return_child(i)));
            }
        }
    }
    return NULL;
}

template <typename V>
void Tree<V>::catch_node(V parent, V value)
{
    Node<V> *print = new Node<V>();
    print = this->find_node(parent, value);
    if (print == NULL)
    {
        std::cout << "There is no such node";
    }
    else
    {
        std::cout << print->get_value();
    }
}

template <typename V>
Tree<V> Tree<V>::swap(Tree<V> tree, V this_parent, V this_value, V tree_parent, V tree_value)
{
    Node<V> *swap = new Node<V>();
    Node<V> *swap2 = new Node<V>();
    Node<V> *swap_temp = new Node<V>();
    Node<V> *swap_temp_par = new Node<V>();
    swap = this->find_node(this_parent, this_value);
    swap2 = tree.find_node(tree_parent, tree_value);
    if (swap == NULL || swap2 == NULL)
    {
        std::cout << "Cannot swap, such node does not exist\n";
    }
    else
    {
        //*swap_temp_par = *swap->return_parent();
        //*swap->return_parent() = *swap2->return_parent();
        //*swap2->return_parent() = *swap_temp_par;
        *swap_temp = *swap;
        *swap = *swap2;
        *swap2 = *swap_temp;
    }
}
template <typename V>
void Tree<V>::create_paths()
{
    int iterator = 0;
    Path<V>* tab = new Path<V>[MAX_NUMB_OF_PATH];
    std::stack<Node<V>*> mystack;
    std::queue<Node<V>*> myqueue;
    Node<V> *temporary;
    mystack.push(root);
    while (!mystack.empty())
    {
        if (temporary->nb_of_children() == 0)
        {
            std::cout <<" Jedna Sciezka \t ";
            tab[iterator].print_Path();
            vector_paths.push_back(&tab[iterator]);
            iterator++;
        }
        temporary = mystack.top();
        mystack.pop();
        tab[iterator].add_to_Path(temporary);
        for (int i = 0; i < temporary->nb_of_children(); i++)
        {
            mystack.push((temporary->return_child(i)));
            std::cout <<"Wrtosc pushnietego "<< temporary->return_child(i)->get_value() << "\n";
        }
    }
}
template<typename V>
void Tree<V>::print_paths(){
    //std::cout << "print";
    for(int i = 0 ; i < vector_paths.size() ; i++) {
        vector_paths[i]->print_Path();
    }
}
