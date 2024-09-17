#include <bits/stdc++.h>
using namespace std;

int mergeTwoSortedArr() {
  int a[] = {10, 15, 20}, a_size = 3;
  int b[] = {5, 6, 6, 15}, b_size = 4;
  int i = 0, j = 0;

  while(i < a_size && j < b_size) {
    if(a[i] <= b[j]) {
      cout << a[i++] << " ";
    } else {
      cout << b[j++] << " ";
    }
  }

  while(i < a_size) {
    cout << a[i++] << " ";
  }

  while(j < b_size) {
    cout << b[j++] << " ";
  }
}

int mergeSortedSubarrays() { // Here we take a single array with three points namely, the lower, the middle and the highest point. The elements from the lower to the middle are sorted and the elements from the (middle+1) to the higher are sorted. The task is to merge these two sorted parts into one.
  int arr[] = {10, 20, 30, 15, 25, 35, 50, 60}; // here just focus on sorting [30, 15, 25], [35, 50]
  int low = 2, mid = 4, high = 6;
    
  int n1 = mid - low + 1;
  int n2 = high - mid;
  int left[n1], right[n2];
    
  for (int i = 0; i < n1; i++) {
    left[i] = arr[low + i];
  }

  for (int i = 0; i < n2; i++) {
    right[i] = arr[mid + 1 + i];
  }
    
  int leftIndex = 0, rightIndex = 0, k = low;
    
  while (leftIndex < n1 && rightIndex < n2) {
    if (left[leftIndex] <= right[rightIndex]) {
      arr[k] = left[leftIndex];
      leftIndex++;
      k++;
    } else {
      arr[k] = right[rightIndex];
      rightIndex++;
      k++;
    }
  }
    
  while (leftIndex < n1) {
    arr[k] = left[leftIndex];
    leftIndex++;
    k++;
  }
    
  while (rightIndex < n2) {
    arr[k] = right[rightIndex];
    rightIndex++;
    k++;
  }
    
  for (int i = 0; i < 8; i++) {
    cout << arr[i] << " ";
  }
}

int main() {
  // int size;
  // cout << "Enter Size of Array: ";
  // cin >> size;

  // vector<int> arr(size);
  // for(int i = 0; i < arr.size(); ++i) {
  //   cout << "Enter Array Element " << i + 1 << " : ";
  //   cin >> arr[i];
  // }

  // cout << "Before Merge Sort: ";
  // for(int i = 0; i < arr.size(); ++i) {
  //   cout << arr[i] << " ";
  // }

  // mergeTwoSortedArr();
  mergeSortedSubarrays();

  // cout << "\nAfter Merge Sort: ";
  // for(int i = 0; i < arr.size(); ++i) {
  //   cout << arr[i] << " ";
  // }

  return 0;
}



/*

  * Divide and Conqurer Algorithm
  * Stable Algo
  * O(n logn) Time Complexity, O(n) Space Complexity
  * Well suited for Linked Lists 
  * Quick sort outperform it for arrays in general

*/