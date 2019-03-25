***************
C++ Tree
***************
In computer science, a tree is a widely used abstract data type (ADT)—or data structure implementing this ADT—that simulates a hierarchical tree structure, with a root value and subtrees of children with a parent node, represented as a set of linked nodes.

Quick Overview
--------------
In my implementation of a tree I used structure Node. Each node holds his value , pointer to the parent and vector of pointers to his children(Wrote in c++ standard 17 ).


Functions
------------
* insert(V x) - Adding element x to the tree ;
* size() const - Return size of tree;
* return_root() const - Return root of the tree;
* print() - Print tree InOrder;
* swap(Tree swap, V parent1, V value1, V parent2, V value2) - swapping subtrees roots are defined by arguemnts;
* find_node(V parent, V vale) - Return defined node by arguments, if there is no such node return NULL;
* catch_node(V parent, V value) - Find node and then print information about him in details ;

main.cpp
----------
Program creates set of trees size defined by user. Then randomly choose 2 trees, and allows user to swap their subtrees.
