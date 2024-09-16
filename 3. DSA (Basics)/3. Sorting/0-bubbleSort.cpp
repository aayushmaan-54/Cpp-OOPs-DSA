#include <iostream>
#include <vector>
using namespace std;

int bubbleSort(vector<int> &arr) {
  for(int i = 0; i < arr.size() - 1; i++) {
    bool swapped = false;
    for(int j = 0; j < arr.size() - 1 - i; j++) {
      if(arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        swapped = true;
      }
    }
    if (!swapped) break;
  }
}

int main() {
  int size;
  cout << "Enter size of Array: ";
  cin >> size;

  vector<int> arr(size);
  for(int i = 0; i < arr.size(); i++) {
    cout << "Enter array element " << i + 1 << ": ";
    cin >> arr[i];
  }

  cout << "Before Bubble Sort: ";
  for(int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }

  bubbleSort(arr);

  cout << endl << "After Bubble Sort: ";
  for(int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }

  return 0;
}


/*

* Stable Sort: This means if two elements are equal, their order in the sorted output will be the same as their order in the input.
ex: Input: [(4, 'A'), (3, 'B'), (4, 'C')]
    Output: [(3, 'B'), (4, 'A'), (4, 'C')]
ex: Merge Sort, Timsort, Insertion Sort, Bubble Sort.

* Unstable Sort: An unstable sort does not guarantee preserving the relative order of elements with equal values.
ex: Input: [(4, 'A'), (3, 'B'), (4, 'C')]
    Output: [(3, 'B'), (4, 'C'), (4, 'A')]
ex: Quick Sort (in most implementations), Heap Sort, Selection Sort.

*/