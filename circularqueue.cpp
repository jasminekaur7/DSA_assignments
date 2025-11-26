#include <iostream>
using namespace std;
int arr[4];
int rear = -1;
int front = -1;
int N;
int main()
{
  bool isEmpty()
  {
    if (front == -1 && rear == -1)
      return true;
    else
      return false;
  }

  void isFull()
  {
    if ((rear + 1) % N == front)
      return true;
    else
      return false;
  }
  enqueue(value)
  {
    if (isFull())
      return;
    else if (isEmpty)
      rear = 0;
    front = 0;
    else {
        rear = (rear + 1) % N} arr[rear] = value
  }
  int dequeue(value)
  {
    if (isEmpty())
      return;
    else if (isFull)
      x = arr[front];
    rear = -1;
    front = -1;
    return x;
    else
    {
      x = arr[front];
      front = (front + 1) % N return N;
    }
  }
