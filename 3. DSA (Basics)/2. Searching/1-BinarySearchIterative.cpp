// IMPORTANT!: Array should be ***SORTED***
#include <iostream>
#include <vector>
using namespace std;

int binarySearchIterative(vector <int> &arr, int target) {
  int low = 0,
      high = arr.size() - 1;
  
  while(low <= high) {
    int medium = (low + high) / 2; // floor value

    if(arr[medium] == target) return medium;
    else if(target > arr[medium]) low = medium + 1;
    else if(target < arr[medium]) high = medium - 1;
  }
  return -1;
}

int main() {
  int size, targetEle;

  cout << "Enter Size of Array: ";
  cin >> size;

  vector<int> arr(size);
  for (int i = 0; i < size; i++) {
    cout << "Enter Array Element " << i + 1 << ": ";
    cin >> arr[i];
  }

  cout << "Enter Element to be searched: ";
  cin >> targetEle;

  int result = binarySearchIterative(arr, targetEle);

  (result != -1) 
    ? (cout << "Element found at " << result + 1 << endl)
    : (cout << "Element Not Found!");
  
  return 0;
}