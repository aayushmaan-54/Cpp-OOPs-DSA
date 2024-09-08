/*
Objective - The objective is to maximize the number of pieces that can be cut from a rope of length n, using three possible lengths: a, b, and c. The rope must be cut into pieces of exactly these lengths, and the lengths can be repeated. The function should return the maximum number of pieces if it is possible to cut the rope this way. If it's not possible, the function should return -1.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int ropeCutting(int n, int a, int b, int c) {
  if (n == 0) return 0;  // If no rope is left, no more cuts are possible, return 0
  if (n < 0) return -1;  // If n is negative, this is an invalid solution, return -1

  // Recursively try all possible cuts and get the maximum result
  int res = max({
    ropeCutting(n - a, a, b, c),
    ropeCutting(n - b, a, b, c),
    ropeCutting(n - c, a, b, c)
  });

  if (res == -1) return -1;  // If none of the cuts are valid, return -1

  return res + 1;  // Otherwise, return the maximum number of cuts plus 1 for the current cut
}

int main() {
  int length, a, b, c;

  cout << "Enter Length of Rope: ";
  cin >> length;

  cout << "Enter 3 Length options we can cut: ";
  cin >> a >> b >> c;

  int result = ropeCutting(length, a, b, c);

  if (result == -1)
    cout << "It's not possible to cut the rope into the given lengths." << endl;
  else
    cout << "Maximum number of pieces: " << result << endl;

  return 0;
}