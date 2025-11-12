#include <iostream>
using namespace std;

void improvedSelectionSort(int arr[], int n) {
    int left = 0, right = n - 1;
    while (left < right) {
        int minIdx = left, maxIdx = left;
        for (int i = left; i <= right; i++) {
            if (arr[i] < arr[minIdx]) minIdx = i;
            if (arr[i] > arr[maxIdx]) maxIdx = i;
        }
        swap(arr[left], arr[minIdx]);
        if (maxIdx == left) maxIdx = minIdx;
        swap(arr[right], arr[maxIdx]);
        left++;
        right--;
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    improvedSelectionSort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
