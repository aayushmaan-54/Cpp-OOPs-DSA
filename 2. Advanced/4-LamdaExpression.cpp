#include <iostream>
#include <algorithm>
#include <cstdlib> 
using namespace std;

int main() {
  int arr[] = {-20, 10, -30, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  // Sort the array based on the absolute values
  // sort(arr, arr + n, [](int a, int b) { return abs(a) < abs(b); });

  auto myCmp = [](int a, int b) {
    return abs(a) < abs(b);
  };
  sort(arr, arr + n, myCmp);

  // Print the sorted array
  for (auto x : arr) {
    cout << x << ", ";
  }

  return 0;
}


/*
  * lamda expression allow you to define anonymous functions (or lambda functions) inline. They provide a convenient way to create short, throwaway functions without having to write a separate function

  * [capture](parameters) -> return_type { // function body }
  * ->, return_type are optional
  * lamda expression cant directly access local var, so we have to write those var in capture list if we are using them
*/