#include <iostream>
using namespace std;
int arr[4];
int rear = -1;
int front = -1;
int main()
{
  bool isEmpty()
  {
    if (front == -1 && rear == -1)
    {
      return true;
      else return false;
    }
  }
  isFull()
  {
    if (rear = size of(arr) - 1)
      ;
    return true;
    else return false;
  }
  enque(value)
  {
    if (isFull())
      return;
  }
  else if (isEmpty())
  {
    rear = 0;
    front = 0;
    else {
        rear++} arr[rear] = value
  }
  dequeue()
  {
    int x = 0 if (isEmpty());
    return;
    else if (front == rear){
        x = arr[front] front = rear = -1};
    else x = arr[front] front++;
  }
  return x;
}