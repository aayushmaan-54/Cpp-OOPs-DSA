#include <iostream>
using namespace std;

int main() {
  int arr[5] = {4, 3, 9, 17, 1};
  int start = 0, end = 4;

  cout << "Before Reverse: " << endl;
  for(int i = 0; i < 5; i++) {
    cout << arr[i] << " ";
  }

  while(start < end) {
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    start++;
    end--;
  }

  cout << endl << "After Reverse: " << endl;
  for(int i = 0; i < 5; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}