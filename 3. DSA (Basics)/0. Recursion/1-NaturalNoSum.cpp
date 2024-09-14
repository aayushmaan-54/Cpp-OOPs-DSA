#include <iostream>
using namespace std;

int sumOfNNaturalNo(int n, int sum = 0) { // to make it tail recursive i have passed sum as params
  if (n == 0) {
    cout << "Sum: " << sum << endl;
    return 0;
  }

  return sumOfNNaturalNo(n - 1, sum += n);
}

int main() {
  int num;

  cout << "Enter a Number: ";
  cin >> num;

  sumOfNNaturalNo(num);

  return 0;
}