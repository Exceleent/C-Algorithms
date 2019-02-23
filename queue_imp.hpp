
#include <iostream>
class Queue
{
  public:
    Queue();
    int front;
    int rear;
    int *array;
    void push(int x);
    int pop();
    int &showfront();
    int size();
    bool empty();
};
