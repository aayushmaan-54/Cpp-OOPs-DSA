#include <iostream>
using namespace std;

void leadersInArray(int *arr, int size) {
  int maxFromRight = arr[size - 1];
  cout << maxFromRight << " "; 
    
  for (int i = size - 2; i >= 0; i--) {
    if (arr[i] >= maxFromRight) {
      maxFromRight = arr[i];
      cout << arr[i] << " ";
    }
  }
}

int main() {
  int arr[] = {7, 10, 4, 3, 6, 5, 2};

  leadersInArray(arr, 7);

  return 0;
}
