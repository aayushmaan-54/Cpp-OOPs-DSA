#include <iostream>

using std::cin;
using std::cout;
using std::endl;

namespace MyNamespace {
  void incrementCount() {
    // int count = 0; o/p -> Count: 1   Count: 1
    static int count = 0; // value of count persist
    count++;
    cout << "Count: " << count << endl;
  }

  static void funct() {
    cout << "Hola" << endl;
  } // this function it can only be called or accessed within the file in which it is defined.
}

class MyClass {
  public:
    static int staticData;
    static void staticFunction() {
      // Can access staticData, but not non-static members
      staticData = 10;
    }
};
// Definition of static data member
int MyClass::staticData = 0;


int main() {
  MyNamespace::incrementCount();
  MyNamespace::incrementCount();



  MyClass::staticFunction();
  int value = MyClass::staticData;
  cout << "Static memeber variable value: " << value << endl;

  return 0;
}
// * static data member: all object created using class have one copy of same variable(belong to class)

// * Static member function: belong to class, can be called without creating object, can only access static memeber without an object reference, dont have 'this' pointer