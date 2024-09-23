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

* Insertion sort is a straightforward sorting algorithm that builds a sorted array one element at a time. It works by taking each element from the unsorted portion and inserting it into the correct position within the sorted portion. Starting from the second element, it compares the current element to those in the sorted section and shifts larger elements to the right until it finds the appropriate spot. This process continues until all elements are sorted. Insertion sort has a time complexity of O(n²) in the worst case but performs well on small or nearly sorted datasets.

*/