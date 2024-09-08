#include <iostream>
using namespace std;

int insertionArr(int *arr, int filledSize, int ele, int pos, int capacity) {
  if (filledSize >= capacity || pos < 0 || pos > filledSize) {
    cout << "Invalid insertion!" << endl;
    return filledSize;
  }

  for (int i = filledSize; i > pos; i--) {
    arr[i] = arr[i - 1];
  }

  arr[pos] = ele;
  return filledSize + 1;
}

int main() {
  int arr[5] = {5, 10, 15};
  int size = 3;

  cout << "Array before insertion: " << endl;
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }

  size = insertionArr(arr, size, 20, 2, 5);

  cout << endl << "Array after insertion: " << endl;
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}