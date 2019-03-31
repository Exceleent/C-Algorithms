//#pragma once
#ifndef TREE_H
#define TREE_H

#include <fstream>
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
    void  swap(Tree swap, V parent1, V value1, V parent2, V value2);
    Node<V> *find_node(V parent, V value);
    void catch_node(V parent, V value);
    void create_path_tostream(Node<V>*node,Node<V>* path[],int lenght, std::ofstream &stream);
    void create_path_fromstream( std::ifstream &stream);

    void add_path(Path<V>* path);
    void print_paths();
    V return_cost_of_path(int index);


private:
    Node<V> *root;
    int size_of_Tree;
    std::vector<Path<V>*> vector_paths;



};
template class Tree<int>;
#endif