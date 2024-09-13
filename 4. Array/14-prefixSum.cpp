// A prefix sum array is a useful concept in algorithms, where you preprocess an array so that each element in the prefix sum array represents the sum of elements from the start of the original array up to that index. This can make it easier to quickly calculate the sum of elements in any subarray.

#include <iostream>
using namespace std;

int computePrefixSum(int arr[], int prefixSum[], int n) {
  prefixSum[0] = 0; 

  for (int i = 1; i <= n; ++i) {
    prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
  }

  return 0;
}

int main() {
  const int n = 5;
  int arr[n] = {1, 2, 3, 4, 5};
  int prefixSum[n + 1]; 

  computePrefixSum(arr, prefixSum, n);

  cout << "Prefix Sum Array: ";
  for (int i = 1; i <= n; ++i) {
    cout << prefixSum[i] << " ";
  }
  cout << endl;

  return 0;
}
