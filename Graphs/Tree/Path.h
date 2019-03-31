//#pragma once
#ifndef PATH_H
#define PATH_H
#include "Node.h"

template <typename V>
class Path
{
private:
    std::vector<Node<V>*> Path_vec;
    int size;
    V cost;

public:
    Path();
    ~Path();
    int return_size();
    void add_element_size();
    void add_to_Path(Node<V>* Node);
    void print_Path();
    void count_cost();
    V return_cost();
};
template class Path<int>;
#endif