#include <iostream>
using namespace std;

int main() {
  int arr[5] = {10, 11, 7, 9, 13};

  int largestIndex = 0, secondLargestIndex = -1;

  for (int i = 1; i < 5; i++) {
    if (arr[i] > arr[largestIndex]) {
      secondLargestIndex = largestIndex; 
      largestIndex = i; 
    } else if (arr[i] > arr[secondLargestIndex] || secondLargestIndex == -1) {
      secondLargestIndex = i;
    }
  }

  cout << "Largest Element: " << arr[largestIndex] << endl;
  cout << "Second Largest Element: " << arr[secondLargestIndex] << endl;

  return 0;
}
