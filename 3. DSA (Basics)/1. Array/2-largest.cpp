#include <iostream>
using namespace std;

int main() {
  int arr[5] = {7, 11, 13, 19, 5};

  int largestEleIndex = 0;
  for(int i = 0; i < 5; i++) {
    if(arr[i] > arr[largestEleIndex]) {
      largestEleIndex = i;
    }
  }


  cout << "Largest element index: " << largestEleIndex << endl;

  return 0;
}