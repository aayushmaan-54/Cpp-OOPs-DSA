#include <iostream>

class B; // Forward declaration of class B
class A {
  private:
    int privateDataA;

  public:
    A(int data) : privateDataA(data) {}

    // Friend function declaration
    friend void showDataA(const A& a);
    
    // Friend class declaration
    friend class B;
};
class B {
  public:
    void accessA(const A& a) {
      std::cout << "Accessing A's private data from B: " << a.privateDataA << std::endl;
    }
};

// Friend function definition
void showDataA(const A& a) {
  std::cout << "Accessing A's private data from friend function: " << a.privateDataA << std::endl;
}

int main() {
  A objA(123);
  B objB;

  // Accessing A's private data through a friend function
  showDataA(objA);
    
  // Accessing A's private data through a friend class
  objB.accessA(objA);

  return 0;
}
/*

* private section of class can only be accessed through public section if methods are defined but we cant access them directly except if we make a friend function that is like a normal function but it has access to private section of class
* friend function uses the resource of class only using an object

*/