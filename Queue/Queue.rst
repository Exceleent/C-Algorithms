
***************
C++ Queue
***************

Collection in which the entities are kept based around some principal. 
We can only remove  entities from the front terminal position, this makes Queue First in First out(FIFO) data structure.

Functions
------------
* push(x) - push x element on the top of queue.
* pop() - remove last element of queue.
* showfront() - return first element of queue. 
* size() - return size of queue.
* empty() - checks if queue is empty.

Interface
----------
Input format number(n) which holds information about how many operation we want to do, and n command lines.
Type of operations:
 * F x - push x.
 * B x - same as above.
 * f - pop and print value of the element, if queue is empty print "EMPTY".
 * b - same as above.
 * S - print size.
 * C x - do nothing.

Example
----------
          ./Interface n << example_input.txt 

