#include "Node.h"

template <typename V>
int Node<V>::get_value()
{
    return value;
}
template <typename V>
void Node<V>::set_value(V value1)
{
    value = value1;
}
template <typename V>
Node<V>::Node()
{
    visited_print = false;
    visited_find = false;
}
template <typename V>
bool Node<V>::was_visited_print()
{
    return visited_print;
}
template <typename V>
void Node<V>::we_visit_print()
{
    visited_print = true;
}
template <typename V>
void Node<V>::we_unvisit_print()
{
    visited_print = false;
}
template <typename V>
bool Node<V>::was_visited_find()
{
    return visited_find;
}
template <typename V>
void Node<V>::we_visit_find()
{
    visited_find = true;
}
template <typename V>
Node<V>::Node(const Node &node)
{
    value = node.value;
    parent = node.parent;
    children = node.children;
}
template <typename V>
Node<V>::~Node()
{
    delete parent;
    std::vector<Node*>Vec_temp;
    children = Vec_temp;
}
template <typename V>
void Node<V>::set_parent(Node *node)
{
    parent = node;
}
template <typename V>
void Node<V>::add_child(Node *node)
{
    children.push_back(node);
}
template <typename V>
int Node<V>::nb_of_children()
{
    return children.size();
}
template <typename V>
Node<V> *Node<V>::return_random_child()
{
    srand(time(NULL));
    return children[rand() % (children.size())];
}
template<typename V>
Node<V> *Node<V>::return_child(int i ){
    return children[i];
}
template<typename V>
Node<V> *Node<V>::return_parent(){
    return parent;
}
