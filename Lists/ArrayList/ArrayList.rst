
***************
C++ List
***************

Abstract data type that represents a countable number of ordered values, where the same value may occur more than once.
Access is sequential.

Functions
------------
* push_front(int x) pushes x at the beggining of the list
* pop_front() removes first element of list and return his value 
* push_back(int x) pushes x at the end of the list
* pop_back() removes last element of the list and return his value
* find(int x) finds element x, and return his position in list or nullptr if x is not include in list
* erase(position_t pos) removes element for position pos and return his value.
* insert(position_t pos, int x) inserts element x on position pos and returns his value
* size() returns size of list
* bool empty() checks if list is empty  

Interface
----------
Input format n lines of operations.
Type of operations:
 * F x - push x.
 * B x push_back x
 * f - pop and print value of the element, if queue is empty print "EMPTY"
 * b - pop_back and print value of the element, if queue is empty print "EMPTY"
 * S - print size.
 * C x - find x, print "TRUE" is element was find, otherwise "FALSE".

Example
----------
      ./Interface << example_input.txt 

