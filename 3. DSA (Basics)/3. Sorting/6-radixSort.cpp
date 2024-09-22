#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size) {
  for(int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}


int getMax(int arr[], int n) {
  int maxVal = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > maxVal) {
      maxVal = arr[i];
    }
  }
  return maxVal;
}


void countingSort(int arr[], int n, int exp) {
  int output[n];  
  int count[10] = {0}; 

  for (int i = 0; i < n; i++) {
    count[(arr[i] / exp) % 10]++;
  }

  for (int i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }

  for (int i = n - 1; i >= 0; i--) {
    output[count[(arr[i] / exp) % 10] - 1] = arr[i];
    count[(arr[i] / exp) % 10]--;
  }

  for (int i = 0; i < n; i++) {
    arr[i] = output[i];
  }
}

void radixSort(int arr[], int n) {
  int maxNumber = getMax(arr, n);

  for (int exp = 1; maxNumber / exp > 0; exp *= 10) {
    countingSort(arr, n, exp);
  }
}


int main() {
  int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Before Radix Sort: ";
  printArray(arr, n);

  radixSort(arr, n);

  cout << "After Radix Sort: ";
  printArray(arr, n);

  return 0;
}



/*

Radix sort is a non-comparative sorting algorithm that sorts numbers by processing individual digits. It works in multiple passes, starting from the least significant digit (LSD) to the most significant digit (MSD). During each pass, it uses a stable sorting algorithm, like counting sort, to arrange the numbers based on the current digit being processed. This continues until all digits have been processed, resulting in a sorted array. Radix sort is particularly efficient for sorting large sets of integers or strings with fixed lengths, achieving a time complexity of O(nk), where n is the number of elements and k is the number of digits in the largest number.

*/