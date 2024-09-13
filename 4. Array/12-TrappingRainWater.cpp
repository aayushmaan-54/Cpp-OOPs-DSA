// question - The trapping rainwater problem involves finding the amount of water that can be trapped between bars after a rainfall, given an array of non-negative integers representing the height of bars at different positions.

#include <iostream>
using namespace std;

int trap(int height[], int n) {
  if (n <= 2) return 0;  

  int left = 0, right = n - 1;
  int leftMax = 0, rightMax = 0;
  int waterTrapped = 0;

  while (left < right) {
    if (height[left] < height[right]) {
      if (height[left] >= leftMax) {
        leftMax = height[left];
      } else {
        waterTrapped += leftMax - height[left];
      }
    left++;
    } else {
      if (height[right] >= rightMax) {
        rightMax = height[right];
      } else {
        waterTrapped += rightMax - height[right];
      }
      right--;
    }
  }

  return waterTrapped;
}

int main() {
  int height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  int n = sizeof(height) / sizeof(height[0]);
  cout << "Water trapped: " << trap(height, n) << endl;
  return 0;
}
