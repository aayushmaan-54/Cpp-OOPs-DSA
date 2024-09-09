#include <iostream>
using namespace std;

int removeDuplicate(int *arr, int size) {
  if (size == 0 || size == 1)
    return size;

  int temp[size];

  int j = 0;

  for (int i = 0; i < size - 1; i++) {
    if (arr[i] != arr[i + 1]) {
      temp[j++] = arr[i];
    }
  }

  temp[j++] = arr[size - 1];

  for (int i = 0; i < j; i++) {
    arr[i] = temp[i];
  }

  return j;
}

int main() {
  int arr[] = {10, 20, 20, 30, 30, 30, 30, 30};
  int size = sizeof(arr) / sizeof(arr[0]);

  cout << "Before Removing Duplication: " << endl;
  for (int i = 0; i < 8; i++) {
    cout << arr[i] << " ";
  }

  int newSize = removeDuplicate(arr, size);

  cout << endl <<  "After Removing Duplication of array of size " << newSize << " : " << endl;
  for (int i = 0; i < newSize; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}
