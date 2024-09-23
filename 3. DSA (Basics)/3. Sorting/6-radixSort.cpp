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

* uses counting sort as subroutine

* Radix sort is a non-comparative sorting algorithm that sorts integers by processing individual digits, using a stable sorting algorithm like counting sort as a subroutine. The process begins by determining the maximum number in the array to establish how many digits need to be sorted. Radix sort sorts the array starting from the least significant digit (LSD) to the most significant digit (MSD), applying counting sort for each digit.

Counting sort works by first creating a count array that records the frequency of each digit (0-9 for decimal numbers). It then transforms this count array into cumulative counts, which helps determine the position of each element in the output array. By placing elements in their correct positions based on the cumulative counts and then copying the output back to the original array, counting sort maintains stability. For example, when sorting the array [170, 45, 75, 90, 802, 24, 2, 66], radix sort processes each digit in turn, leading to the final sorted array [2, 24, 45, 66, 75, 90, 170, 802]. The overall time complexity of radix sort is O(d * (n + k)), where 
n is the number of elements, 
d is the number of digits in the maximum number, and 
k is the range of the input, making it efficient for sorting large datasets with a limited range of digits.

*/