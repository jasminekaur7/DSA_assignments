#include <iostream>
using namespace std;
int num;
void insert(int arr[], int n, int pos)
{
  for (int i = n - 1; i >= pos; i--)
  {
    arr[i + 1] = arr[i];
  }
  arr[pos] = num;
}
int main()
{
  int pos;
  int arr[25];
  int n = 10;
  cout << "insert the number as" << num;
  cin >> num;
  cout << "the number is added to position" << n << ",";
  cin >> pos;
  insert(arr, n, pos);
  return 0;
}