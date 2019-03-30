//#pragma once
#ifndef TREE_H
#define TREE_H
#include "Path.h"
template <typename V>
class Tree
{
public:
    Tree();
    Tree(const Tree &tree);
    void insert(V x);
    int size() const;
    Node<V> *return_root() const;
    void print();
    void unprint();
    Tree swap(Tree swap, V parent1, V value1, V parent2, V value2);
    Node<V> *find_node(V parent, V value);
    void catch_node(V parent, V value);
    void create_paths();
    void print_paths();

private:
    Node<V> *root;
    int size_of_Tree;
    std::vector<Path<V>*> vector_paths;
};
template class Tree<int>;
#endif