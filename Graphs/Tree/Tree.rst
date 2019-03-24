***************
C++ Tree
***************
In computer science, a tree is a widely used abstract data type (ADT)—or data structure implementing this ADT—that simulates a hierarchical tree structure, with a root value and subtrees of children with a parent node, represented as a set of linked nodes.

Quick Overview
--------------
In my implementation of a tree I used structure Node. Each node holds his value , pointer to the parent and vector of pointers to his children.


Function
------------
* Tree();
* Tree(const Tree &tree);
* void insert(V x);
* int size() const;
* Node *return_root() const;
* void print();
* Tree swap(Tree swap, V parent1, V value1, V parent2, V value2);
* Node *find_node(V parent, V value);
* void catch_node(V parent, V value);

Interface
----------
Input format n lines of operations.
Type of operations:
 * F x - push x.
 * B x - same as above.
 * f - pop and print value of the element, if queue is empty print "EMPTY".
 * b - same as above.
 * S - print size.
 * C x - do nothing.

Example
----------
          ./Interface << example_input.txt 
