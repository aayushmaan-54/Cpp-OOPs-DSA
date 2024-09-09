#include <iostream>
using namespace std;

bool isArrSorted(int arr[], int size) {
  for(int i = 0; i < size - 1; i++) {
    if(arr[i] > arr[i + 1]) {
      return false;
    }
  }
  return true;
}

int main() {
  int arr1[5] = {5, 10, 15, 20, 25};
  int arr2[5] = {7, 9, 3, 6, 1};

  if(isArrSorted(arr1, 5)) {
    cout << "Array is Sorted!" << endl;
  } else {
    cout << "Array is not Sorted!" << endl;
  }

  if(isArrSorted(arr2, 5)) {
    cout << "Array is Sorted!" << endl;
  } else {
    cout << "Array is not Sorted!" << endl;
  }

  return 0;
}