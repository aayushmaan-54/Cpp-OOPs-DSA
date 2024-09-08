#include <iostream>
using namespace std;

int oneToN(int num) {
  if(num == 0) 
    return 0;
  
  oneToN(num - 1);
  cout << num << endl;
}

int NToOne(int num) {
  if(num == 0) 
    return 0;
  
  cout << num << endl;
  NToOne(num - 1);
}

int main() {
  int num;

  cout << "Enter a Number: ";
  cin >> num;

  oneToN(num);
  cout << "*----------------------------------------*" << endl;
  NToOne(num);

  return 0;
}

/*

* in here NToOne will take less time as it is A tail recursive function

NToOne(3)
  |
  -> 3
  -> NToOne(2)
        |
        -> 2
        -> NToOne(1)
              |
              -> 1
              -> NToOne(0)
                    |
                    -> 0


* A tail recursive function is a type of recursive function where the recursive call is the last operation performed by the function, it is more efficient and may take less time to run because it does not need to Store Intermediate States also optimizes last reccursive call by replacing it with n -= 1; and goto start; due to this complexity decreases 

* if a function last line is this return n * fact(n - 1); then it is not tail recursive as its last job is not to just not do anything but to multiply result returned by n

*/