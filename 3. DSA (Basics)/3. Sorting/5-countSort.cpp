#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size) {
  for(int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void countSortNaive(int arr[], int size, int range) {
  int count[range] = {0};

  for(int i = 0; i < size; i++) 
    count[arr[i]]++;
  
  int index = 0;
  for(int i = 0; i < range; i++) {
    for(int j = 0; j < count[i]; j++) {
      arr[index] = i;
      index++;
    }
  }
}

void countSort(int arr[], int n, int k) {
  int count[k + 1] = {0};

  for(int i = 0; i < n; i++) 
    count[arr[i]]++;

  for(int i = 1; i <= k; i++) 
    count[i] += count[i - 1];

  int output[n];
  for(int i = n - 1; i >= 0; i--) {
    output[count[arr[i]] - 1] = arr[i];
    count[arr[i]]--;
  }

  for(int i = 0; i < n; i++)
    arr[i] = output[i];
}

int main() {
  int arr1[] = {1, 4, 4, 1, 0, 1};
  cout << "Before Naive Count Sort: ";
  printArray(arr1, 6);
  countSortNaive(arr1, 6, 5); // range(k): 0 - 4 + 1 = 5
  cout << "After Naive Count Sort: ";
  printArray(arr1, 6);

  int arr2[] = {10, 13, 7, 9, 1, 13};
  cout << "Before Count Sort: ";
  printArray(arr2, 6);
  countSort(arr2, 6, 13);
  cout << "After Count Sort: ";
  printArray(arr2, 6);

  return 0;
}

/*

* First, we create an array, called count, with a size equal to the highest element in the original array. Each index in the count array represents an element in the original array, and the value at each index indicates how many times that element appears.
Next, we modify the count array so that each index holds the cumulative sum of the previous counts. This tells us the position where each element should be placed in the sorted array. If an element repeats, the cumulative sum ensures that repeated values are correctly shifted by the number of repetitions.
This approach allows us to determine the exact position of each element in the sorted array efficiently.


* non-comparative
* integer based sorting algo
* complexity: O(n + k), n is number of elements, k is the range of input values(maximum value - minimum value + 1)
* it works well when range of input value is not significantly larger than the number of elements, making it particularly useful for sorting integers or objects that can be mapped to integers
* in couting sort we tracverse from last so that sorting becomes stable

*/
