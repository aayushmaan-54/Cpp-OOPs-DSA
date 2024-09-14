#include <iostream>
using namespace std;

int main() {
  int arr[] = {8, 5, 0, 10, 0, 20};
  int size = sizeof(arr) / sizeof(arr[0]);
  int index = 0;

  for (int i = 0; i < size; i++) {
    if (arr[i] != 0) {
      arr[index++] = arr[i];
    }
  }

  while (index < size) {
    arr[index++] = 0;
  }

  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}
