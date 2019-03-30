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

public:
    Path();
    ~Path();
    void add_to_Path(Node<V>* Node);
    void print_Path();
};
template class Path<int>;
#endif