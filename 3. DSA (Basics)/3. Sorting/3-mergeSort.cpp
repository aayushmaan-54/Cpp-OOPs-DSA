#include <bits/stdc++.h>
using namespace std;

void mergeTwoSortedArr() {
  int a[] = {10, 15, 20}, a_size = 3;
  int b[] = {5, 6, 6, 15}, b_size = 4;
  int i = 0, j = 0;

  cout << "Merge 2 Sorted array in sorted way: ";
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
  cout << endl;
}

void mergeSortedSubarrays(int arr[], int low, int mid, int high) {
  // Here we take a single array with three points namely, the lower, the middle and the highest point. The elements from the lower to the middle are sorted and the elements from the (middle+1) to the higher are sorted. The task is to merge these two sorted parts into one.
  //  int arr[] = {10, 20, 15, 25, 30, 15, 50, 60}; Sorted subarrays: [15, 25, 30] and [15, 50]
    
  int n1 = mid - low + 1;
  int n2 = high - mid;
  vector<int> left(n1), right(n2);
    
  for (int i = 0; i < n1; i++) {
    left[i] = arr[low + i];
  }

  for (int i = 0; i < n2; i++) {
    right[i] = arr[mid + 1 + i];
  }
    
  int leftIndex = 0, rightIndex = 0, k = low;
    
  while (leftIndex < n1 && rightIndex < n2) {
    if (left[leftIndex] <= right[rightIndex]) {
      arr[k++] = left[leftIndex++];
    } else {
      arr[k++] = right[rightIndex++];
    }
  }
    
  while (leftIndex < n1) {
    arr[k++] = left[leftIndex++];
  }
    
  while (rightIndex < n2) {
    arr[k++] = right[rightIndex++];
  }
}

void MergeSort(vector<int> &arr, int l, int r) {
  if(r > l) { // atleast 2 ele should be in arr
    int m = l + (r - l) / 2; // same as l + r / 2 but used this to avoid overflow for large values
    MergeSort(arr, l, m); // sorts left half
    MergeSort(arr, m + 1, r); // sorts right half
    mergeSortedSubarrays(&arr[0], l, m, r); // merge subarray in sorted manner
  }
}

int main() {
  mergeTwoSortedArr();

  int arr[] = {10, 20, 15, 25, 30, 15, 50, 60};
  mergeSortedSubarrays(arr, 2, 4, 6);
  
  cout << "Merge Sorted Sub Array: ";
  for (int i = 0; i < 8; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  int size;
  cout << "Enter Size of Array: ";
  cin >> size;

  vector<int> vec(size);
  for(int i = 0; i < vec.size(); ++i) {
    cout << "Enter Array Element " << i + 1 << " : ";
    cin >> vec[i];
  }

  cout << "Before Merge Sort: ";
  for(int i = 0; i < vec.size(); ++i) {
    cout << vec[i] << " ";
  }
  cout << endl;

  MergeSort(vec, 0, vec.size() - 1);

  cout << "After Merge Sort: ";
  for(int i = 0; i < vec.size(); ++i) {
    cout << vec[i] << " ";
  }
  cout << endl;

  return 0;
}

/*

  * Divide and Conqurer Algorithm
  * Stable Algo
  * O(n logn) Time Complexity, O(n) Space Complexity
  * Well suited for Linked Lists 
  * Quick sort outperform it for arrays in general

*/