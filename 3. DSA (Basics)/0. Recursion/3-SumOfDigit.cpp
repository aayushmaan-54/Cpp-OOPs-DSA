#include <iostream>
using namespace std;

int digitSum(int n) {
  if(n == 0) 
    return 0;
  else 
    return digitSum(n / 10) + n % 10;
}

int main() {
  int num;

  cout << "Enter a Number: ";
  cin >> num;

  int sum = digitSum(num);
  cout << "Sum: " << sum << endl;

  return 0;
}