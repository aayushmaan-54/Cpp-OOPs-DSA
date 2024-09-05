#include <iostream>
using namespace std;

void func() {
  cout << "Hello, World!" << endl;
}

int add(int x, int y) { return x + y; }
int multiply(int x, int y) { return x * y; }
int compute(int x, int y, int (*fun_ptr)(int, int)) { 
  return fun_ptr(x, y);
}

int main() {
  //void (*func_ptr)() = &func; 
  cout << func << endl;
  
  // void (*func_ptr)() = func;
  auto func_ptr = func;
  func_ptr();
  // (*func_ptr)();


  cout << compute(10, 20, add) << endl;
  cout << compute(10, 20, multiply) << endl;

  return 0;
}