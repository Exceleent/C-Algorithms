***************
C++ BinaryTree
***************
In computer science, a binary tree is a tree data structure in which each node has at most two children, which are referred to as the left child and the right child. Thanks to it structures BinaryTree allow fast insertion, find and remove operations. 
Quick Overview
--------------
In my implementation of a tree I used structure Node. Each node holds his value , pointer to the parent and two pointer,  one to left child , second one to right child (Wrote in c++ standard 11 ).


Functions
------------
* insert(V x) - Adding element x to the Binarytree ;
* size() const - Return size of Binarytree;
* print() - Print tree;
* swap(Tree swap, V parent1, V value1, V parent2, V value2) - swapping subtrees roots are defined by arguemnts;
* search_iterative (int x) - Return defined node by argument, if there is no such node return NULL;
* minimum() - Return the smallest value hold by Binarytree;
* maximum() - Return the biggest value hold by BinaryTree;
* depth() - Return depth of BinaryTree;
