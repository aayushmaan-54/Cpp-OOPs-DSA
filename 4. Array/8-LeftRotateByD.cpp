#include <iostream>
using namespace std;

void leftRotate(int arr[], int n, int d) {
  int temp[d];

  for (int i = 0; i < d; i++) {
    temp[i] = arr[i];
  }

  for (int i = d; i < n; i++) {
    arr[i - d] = arr[i];
  }

  for (int i = 0; i < d; i++) {
    arr[n - d + i] = temp[i];
  }
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  int n, d;
  cout << "Enter the size of the array: ";
  cin >> n;
  cout << "Enter number of rotations: ";
  cin >> d;
  int arr[n];
  cout << "Enter array elements: ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  leftRotate(arr, n, d);
  cout << "Array after left rotation: ";
  printArray(arr, n);
  return 0;
}