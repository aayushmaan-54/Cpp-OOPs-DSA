#include <iostream>
using namespace std;

int deletionArr(int arr[], int ele, int size) {
  int index = -1;

  for(int i = 0; i < size; i++) {
    if(arr[i] == ele) {
      index = i;
      break;  
    }
  }

  if(index == -1) {
    cout << "Element not found!" << endl;
    return size;  
  }

  for(int i = index; i < size - 1; i++) {
    arr[i] = arr[i + 1];
  }

  return size - 1;  
}

int main() {
  int arr[5] = {5, 10, 15, 20, 25};
  int size = 5;

  cout << "Before Deletion: " << endl;
  for(int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }

  size = deletionArr(arr, 15, size);

  cout << "\nAfter Deletion: " << endl;
  for(int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}