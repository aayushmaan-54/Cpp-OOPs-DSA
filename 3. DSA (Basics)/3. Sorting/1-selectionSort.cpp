#include <iostream>
#include <vector>
using namespace std;

int SelectionSortNaiveApproach(vector<int> &arr) { // find smallest element push it to temp array and in orig array replace it with infinity and agian find smallest element until temp array is filled
  vector<int> temp(arr.size());
    
  for(int i = 0; i < arr.size(); i++) {
    int minIndex = 0;
    for(int j = 1; j < arr.size(); j++) {
      if(arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    temp[i] = arr[minIndex];
    arr[minIndex] = INT32_MAX;
  }
    
  for(int i = 0; i < arr.size(); i++) {
    arr[i] = temp[i];
  }
}

int SelectionSortOptimizedApproach(vector<int> &arr) { // we find smallest element and we swap it with current value of i, and we now ignore sorted part that is swapped from front and try to sort remainig part
  for(int i = 0; i < arr.size() - 1; i++) {
    int minIndex = i;
    for(int  j = i + 1; j < arr.size(); j++) {
      if(arr[j] < arr[minIndex]) 
        minIndex = j;
    }
    if(minIndex != i) {
      int temp = arr[minIndex];
      arr[minIndex] = arr[i];
      arr[i] = temp;
    }
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

  cout << "Before Selection Sort: ";
  for(int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }

  // SelectionSortNaiveApproach(arr);
  SelectionSortOptimizedApproach(arr);

  cout << endl << "After Selection Sort: ";
  for(int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }

  return 0;
}


/*

* Does less memory writes compared to quick sort, merge sort, insertion sort, etc. but cycle sort is optimal in terms of memory writes.
* Basic idea for heap sort
* not stable
* in place algo means does not require extra space for memory

*/