#include <bits/stdc++.h>
using namespace std;

int insertionSort(vector<int> &arr) {
  for(int i = 1; i < arr.size(); i++) {
    int key = arr[i];
    int j = i - 1;

    while(j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

int main() {
  int size;
  cout << "Enter size of array: ";
  cin >> size;

  vector<int> arr(size);
  for(int i = 0; i < arr.size(); i++) {
    cout << "Enter array element " << i + 1 << " : ";
    cin >> arr[i];
  }

  cout << "Before Insertion Sort: ";
  for(int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }

  insertionSort(arr);

  cout << "\nAfter Insertion Sort: ";
  for(int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }
}



/*

* In Place and stable
* can be used in array of short size

*/