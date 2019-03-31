#include "Path.h"
#include <iostream>

template <typename V>
Path<V>::Path()
{
    size = 0;
}
template <typename V>
Path<V>::~Path()
{
    std::vector<Node<V>*> tempVector;
    this->Path_vec = tempVector;
}
template <typename V>
void Path<V>::add_to_Path(Node<V> *Node)
{
    this->Path_vec.push_back(Node);
    size++;
}
template <typename V>
void Path<V>::print_Path()
{
    for (int i = 0; i < size; i++)
    {
        std::cout << this->Path_vec[i]->get_value() << "\t";
    }
    std::cout << "\n";
}
template <typename V>
void Path<V>::add_element_size() {
    size++;
}
template <typename  V>
int Path<V>::return_size() {
    return size;
}
template <typename  V>
void Path<V>::count_cost(){
    for(int i = 0 ; i < size ; i++) {
        cost += Path_vec[i]->get_value();
    }
}
template <typename  V>
V Path<V>::return_cost(){
    this->count_cost();
    return cost;
}


