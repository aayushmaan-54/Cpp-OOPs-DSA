#include <bits/stdc++.h>
using namespace std;

int countingSortNaive(int arr[], int size, int range) {
  int count[range];

  for(int i = 0; i < range; i++)
    count[i] = 0;

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

int countingSort(int arr[], int size, int range) {

}

int main() {
  int arr[] = {1, 4, 4, 1, 0, 1};
  countingSortNaive(arr, 6, 5); // range(k): 0 - 4 + 1 = 5

  return 0;
}


/*

* it works by counting the occurances of rach unique element in array, we use this info and put elements in correct pos.
* non-comparative
* integer based sorting algo
* complexity: O(n + k), n is number of elements, k is the range of input values(maximum value - minimum value + 1)
* it works well when range of input vlaue is not significantly larger than the number of elments, making it particularly useful for sorting integers or objects that can be mapped to integers

*/