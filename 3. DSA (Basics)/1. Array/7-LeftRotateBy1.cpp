#include <iostream>
using namespace std;

int lRotateOne(int *arr, int n) {
  int temp = arr[0];

  for(int i = 1; i < n; i++) {
    arr[i - 1] = arr[i];
  }
  arr[n - 1] = temp;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};

  cout << "Before Left Rotation by 1: " << endl;
  for (int i = 0; i < 5; i++) {
    cout << arr[i] << " ";
  }

  lRotateOne(arr, 5);

  cout << endl << "After Left Rotation by 1: " << endl;
  for (int i = 0; i < 5; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}