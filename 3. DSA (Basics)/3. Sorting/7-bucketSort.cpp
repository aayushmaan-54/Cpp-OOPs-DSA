#include <bits/stdc++.h>
using namespace std;

int printArray(int arr[], int n) {
  for(int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
}

void bucketSort(int arr[], int size, int numBuckets) {
  int maxVal = arr[0];
  for (int i = 1; i < size; i++) 
    if (arr[i] > maxVal) 
      maxVal = arr[i];
  maxVal++;

  vector<int> buckets[numBuckets];
  
  for (int i = 0; i < size; i++) {
    int bucketIndex = (numBuckets * arr[i]) / maxVal; 
    buckets[bucketIndex].push_back(arr[i]);
  }

  for (int i = 0; i < numBuckets; i++) 
    sort(buckets[i].begin(), buckets[i].end());
  
  int index = 0;
  for (int i = 0; i < numBuckets; i++) 
    for (int j = 0; j < buckets[i].size(); j++) 
      arr[index++] = buckets[i][j];
}

int main() {
  int arr[] = {20, 80, 10, 85, 75, 99, 18};

  cout << "Before Bucket Sort: ";
  printArray(arr, 7);

  bucketSort(arr, 7, 5);

  cout << "After Bucket Sort: ";
  printArray(arr, 7);

  return 0;
}

/*

* Efficient for sorting floating-point numbers uniformly distributed over a range.
* in bucket sort first we create bucket for a certain range and according to that range we put element in bucket, a bucket can have multiple elements if it is in the specified range bucket, then we sort bucket individually and then we concatenate all sorted bucket in sorted array
* for sorting bucket we can use merge, insertion sort, ... 
* if buckets have less number of elements we can use insertion sort, as it is best for less amount of data

*/