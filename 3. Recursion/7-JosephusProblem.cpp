// question - Given the number of people n and a step k, where every k-th person is removed in a circular manner, we need to find the position of the survivor.

#include <iostream>
using namespace std;

int josephusProblem(int n, int k) {
  if(n == 1) return 0;

  return (josephusProblem(n - 1, k) + k) % n;
}

int main() {
  cout << josephusProblem(4, 2) << endl;
  cout << josephusProblem(7, 3) << endl;
  cout << josephusProblem(5, 3) << endl;

  return 0;
}