#include <iostream>
using namespace std;
void takearray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }
}
void printarray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << ",";
  }
}
int main()
{
  int n;
  cout << "the numbers in array are" << endl;
  cin >> n;
  int arr[100];
  takearray(arr, n);
  printarray(arr, n);
  return 0;
}
