// IMPORTANT!: Array should be ***SORTED***
#include <iostream>
#include <vector>
using namespace std;

int binarySearchRecursive(vector <int> &arr, int target, int low, int high) {
  int medium = (low + high) / 2; // floor value, low + (high - low) / 2 for large values we can use this

  if (low > high) return -1;
  else if(target == arr[medium]) return medium;
  else if(target > arr[medium]) return binarySearchRecursive(arr, target, medium + 1, high);
  else if(target < arr[medium]) return binarySearchRecursive(arr, target, low, medium - 1);
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

  int result = binarySearchRecursive(arr, targetEle, 0, arr.size() - 1);

  (result != -1) 
    ? (cout << "Element found at " << result + 1 << endl)
    : (cout << "Element Not Found!");
  
  return 0;
}