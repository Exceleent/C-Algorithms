#define SIZE 10
#include <iostream>
#include "queue_imp.hpp"

using namespace std;
Queue::Queue()
{
  array = new int[SIZE];
  front = rear = 0;
}
bool Queue::empty()
{
  if (front == rear)
    return true;
  else
    return false;
}

int Queue::size()
{
  cout << (SIZE - front + rear + 1) % SIZE << "\n";
}

void Queue::push(int x)
{
  if ((rear + 1) % SIZE == front)
    cout << "Queue is full, cannot add more\n";
  else
  {
    rear = (rear + 1) % SIZE;
    array[rear] = x;
  }
}

int &Queue::showfront()
{
  if (empty())
    cout << "Queue is empty\n";
  else
    cout << array[rear] << "\n";
  return array[rear];
}

int Queue::pop()
{
  if (empty())
    cout << "Queue is empty, cannot delete anything\n";
  else
  {
    Queue::showfront();
    if (front == rear)
      front = rear = 0;
    front = (front + 1) % SIZE;
  }
}
