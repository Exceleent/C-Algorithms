//#pragma once
#ifndef _Node_h_
#define _Node_h_
#include <vector>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

template <typename V>
class Node
{
private:
    bool visited_print;
    bool visited_find;
    V value;
    std::vector<Node *> children;
    Node *parent;

public:
    Node(const Node<V> &node1);
    Node();
    ~Node();
    bool was_visited_print();
    void we_visit_print();
    void we_unvisit_print();
    bool was_visited_find();
    void we_visit_find();
    void set_value(V value);
    int get_value();
    void set_parent(Node*parent);
    Node* return_parent();
    void add_child(Node*child);
    int nb_of_children();
    Node * return_random_child();
    Node * return_child(int i);

};
template class Node<int>;
#endif
