// question - Given an array of integer and a number k, find the maximum sum of k consecutive elements

#include <iostream>
using namespace std;

int maxSum(int arr[], int n, int k) {
  if (n < k) {
    cout << "Invalid input: Array size is smaller than k." << endl;
    return -1;
  }

  int maxSum = 0;
  for (int i = 0; i < k; i++) {
    maxSum += arr[i];
  }

  int windowSum = maxSum;
  for (int i = k; i < n; i++) {
    windowSum += arr[i] - arr[i - k];
    maxSum = max(maxSum, windowSum);   
  }

  return maxSum;
}

int main() {
  int arr[] = {2, 1, 5, 1, 3, 2, 8, 1, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  int k = 3;

  cout << "Maximum sum of " << k << " consecutive elements: " << maxSum(arr, n, k) << endl;

  return 0;
}
