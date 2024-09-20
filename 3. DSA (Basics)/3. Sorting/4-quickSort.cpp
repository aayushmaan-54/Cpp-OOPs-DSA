#include <bits/stdc++.h>
using namespace std;

int naivePartition(int *arr, int low, int high, int partitionEleIndex) {
  int pivot = arr[partitionEleIndex];
  int temp[high - low + 1];
  int index = 0;

  for(int i = low; i <= high; i++) {
    if(arr[i] <= pivot && i != partitionEleIndex) {
      temp[index++] = arr[i];
    }
  }

  temp[index++] = pivot;

  for(int i = low; i <= high; i++) {
    if(arr[i] > pivot) {
      temp[index++] = arr[i];
    }
  }

  for(int i = low; i <= high; i++) {
    arr[i] = temp[i - low];
  }

  for(int i = low; i <= high; i++) {
    cout << arr[i] << " ";
  }
}

int swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

int lomutoPartition(int *arr, int low, int high, int partitionEleIndex) { // in this partition ele is genrally last element if not we swap it with last element to make it as last element, it uses two pointers i and j, i keep tracks of elements <= pivot, while j scans through array each element, in here first we set i = start - 1 and j is iterated from start to second last as last element is pivot, if current element is less than pivot we incrememnt i by 1 and swap(i, j) elements, after loop ends we swap pivot(last) element with element at i + 1
  if(partitionEleIndex != high) {
    swap(arr[partitionEleIndex], arr[high]);
  }
  int pivot = arr[high];
  int i = low - 1;

  for(int j = low; j < high; j++) {
    if(arr[j] <= pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);

  for(int i = low; i <= high; i++) {
    cout << arr[i] << " ";
  }

  return (i + 1);
}

int hoarePartition(int *arr, int low, int high, int partitionEleIndex) { // in this pivot element is not end up in its final sorted position but smaller elements are on left(uptill j pointer) and right side(after j pointer), also generally, the pivot element is the first element. Two pointers, i and j, are chosen. i initially points to low - 1 and j points to high + 1. These pointers move toward each other, swapping elements that are in the wrong position relative to the pivot.
  if(partitionEleIndex != low) {
    swap(arr[partitionEleIndex], arr[low]);
  }
  int pivot = arr[low];
  int i = low - 1, j = high + 1;

  while(true) {
    do{
      i++;
    } while(arr[i] < pivot);

    do{
      j--;
    } while(arr[j] > pivot);

    if(i >= j) return j;

    swap(arr[i], arr[j]);
  }
}

int lomuto_partition(int *arr, int low, int high) {
  int pivot = arr[high];
  int i = low - 1;

  for(int j = low; j < high; j++) {
    if(arr[j] <= pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);

  return (i + 1);
}

int quickSortLomutoPartition(int arr[], int low, int high) {
    if (low < high) {
        int partitionEleIndex = lomuto_partition(arr, low, high);
        quickSortLomutoPartition(arr, low, partitionEleIndex - 1);
        quickSortLomutoPartition(arr, partitionEleIndex + 1, high);
    }
}

int hoare_partition(int *arr, int low, int high) {
  int pivot = arr[low];
  int i = low - 1, j = high + 1;

  while(true) {
    do{
      i++;
    } while(arr[i] < pivot);

    do{
      j--;
    } while(arr[j] > pivot);

    if(i >= j) return j;

    swap(arr[i], arr[j]);
  }
}

int quickSortHoarePartition(int arr[], int low, int high) {
  if(low < high) {
    int partitionEleIndex = hoare_partition(arr, low, high);
    quickSortHoarePartition(arr, low, partitionEleIndex);
    quickSortHoarePartition(arr, partitionEleIndex + 1, high);
  }
}

int naive_partition(int *arr, int low, int high, int partitionEleIndex) {
  int pivot = arr[partitionEleIndex];
  int temp[high - low + 1];
  int index = 0;

  for(int i = low; i <= high; i++) {
    if(arr[i] <= pivot && i != partitionEleIndex) {
      temp[index++] = arr[i];
    }
  }

  temp[index++] = pivot;

  for(int i = low; i <= high; i++) {
    if(arr[i] > pivot) {
      temp[index++] = arr[i];
    }
  }

  for(int i = low; i <= high; i++) {
    arr[i] = temp[i - low];
  }
}

int quickSortNaivePartition(int arr[], int low, int high) {
  if(low < high) {
    int partitionEleIndex = high;
    int pivotIndex  = naive_partition(arr, low, high, partitionEleIndex);
    quickSortHoarePartition(arr, low, pivotIndex - 1);
    quickSortHoarePartition(arr, pivotIndex + 1, high);
  }
}

int main() {
  int arr[] = {3, 8, 6, 12, 10, 7, 7};
  cout << "Naive Partition: ";
  naivePartition(arr, 0, 6, 5);

  cout << "\nLomuto Partition: ";
  lomutoPartition(arr, 0, 6, 5);

  cout << "\nHoare Partition: ";
  hoarePartition(arr, 0, 6, 5);
  for(int i = 0; i < 7; i++) {
    cout << arr[i] << " ";
  }



  int size;
  cout << "\n\n\nEnter Size of Array: ";
  cin >> size;

  int arr1[size] = {0};
  for(int i = 0; i < size; i++) {
    cout << "Enter element " << i + 1 << " : ";
    cin >> arr1[i];
  }

  cout << "\n\nBefore Quick Sort Lomuto Partition: ";
  for(int i = 0; i < size; i++) {
    cout << arr1[i] << " ";
  }

  quickSortLomutoPartition(arr1, 0, size - 1);

  cout << "\nAfter Quick Sort Lomuto Partition: ";
  for(int i = 0; i < size; i++) {
    cout << arr1[i] << " ";
  }



  cout << "\n\nBefore Quick Sort Hoare Partition: ";
  for(int i = 0; i < size; i++) {
    cout << arr1[i] << " ";
  }

  quickSortHoarePartition(arr1, 0, size - 1);

  cout << "\nAfter Quick Sort Hoare Partition: ";
  for(int i = 0; i < size; i++) {
    cout << arr1[i] << " ";
  }



  cout << "\n\nBefore Quick Sort Naive Partition: ";
  for(int i = 0; i < size; i++) {
    cout << arr1[i] << " ";
  }

  quickSortNaivePartition(arr1, 0, size - 1);

  cout << "\nAfter Quick Sort Naive Partition: ";
  for(int i = 0; i < size; i++) {
    cout << arr1[i] << " ";
  }

  return 0;
}


/*

* In the partitioning phase of QuickSort, the partition element is placed in its correct position with all elements less than or equal to it on its left and all elements greater on its right, while elements equal to the partition element are moved to the front.

* Divide and Conquer algo
* Worst Case: O(n^2)
* Despite worst case it is considered faster because of following reasons:
  * In place
  * Cache friendly
  * Average Case: O(n Logn)
  * Tail Recursive
* Partition is key function(Naive, Lomuto, Hoare Partition)

* in quick sort if array is sorted or nearly sorted it goes to worst case so to avoid it we can pick a random pivot or mid element as pivot and swap pivot according to partition algo used 

*/