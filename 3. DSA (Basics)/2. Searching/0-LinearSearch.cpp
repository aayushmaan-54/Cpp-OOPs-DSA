#include <iostream>
#include <vector>
using namespace std;

int LinearSearch(const vector<int>& arr, int target) {
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] == target) {
      return i;
    }
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

  int result = LinearSearch(arr, targetEle);

  if (result != -1) {
    cout << "Element Found at position " << result + 1 << endl;
  } else {
    cout << "Element not found!" << endl;
  }

  return 0;
}