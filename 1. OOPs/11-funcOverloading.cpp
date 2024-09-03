#include <iostream>
using namespace std;

// Function declarations (overloaded functions)
void print(int);
void print(double);
void print(const std::string&);

int main() {
  int i = 10;
  double d = 20.5;
  string s = "Hello, World!";
    
  // Function calls (overloaded functions)
  print(i);       // Calls print(int)
  print(d);       // Calls print(double)
  print(s);       // Calls print(const std::string&)

  return 0;
}

// Function definitions
void print(int x) {
  std::cout << "Printing integer: " << x << std::endl;
}

void print(double x) {
  std::cout << "Printing double: " << x << std::endl;
}

void print(const std::string& s) {
  std::cout << "Printing string: " << s << std::endl;
}



/*

RULES:
* Function names must be the same, but the parameter lists must be different (either in type or number of parameters).
* The return type alone is not sufficient to differentiate overloaded functions.

*/