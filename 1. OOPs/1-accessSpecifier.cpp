#include <iostream>
using namespace std;

// Base class
class Base {
  public:
    int publicVar;       // Public access specifier
    Base() : publicVar(1), privateVar(2), protectedVar(3) {}

    void showBase() {
      cout << "Public Variable: " << publicVar << endl;
      cout << "Private Variable: " << privateVar << endl;
      cout << "Protected Variable: " << protectedVar << endl;
    }

  private:
    int privateVar;      // Private access specifier

  protected:
    int protectedVar;    // Protected access specifier
};

// Derived class
class Derived : public Base {
  public:
    void showDerived() {
      cout << "Accessing from Derived class:" << endl;
      cout << "Public Variable: " << publicVar << endl;
      // cout << "Private Variable: " << privateVar << endl; // Error: privateVar is private in Base
      cout << "Protected Variable: " << protectedVar << endl;
    }
};

int main() {
  Base baseObj;
  Derived derivedObj;

  // Accessing members from outside the class
  cout << "Accessing from Main:" << endl;
  cout << "Public Variable: " << baseObj.publicVar << endl;
  // cout << "Private Variable: " << baseObj.privateVar << endl; // Error: privateVar is private
  // cout << "Protected Variable: " << baseObj.protectedVar << endl; // Error: protectedVar is protected

  // Accessing through member functions
  baseObj.showBase();
  derivedObj.showDerived();

  return 0;
}

/*

* they are not typically called inheritance they are called visibility modifiers

* in public inheritance, data member:-
  * Public data memeber or functions: accessed anywhere in program
  * private data memeber or functions: accessed only within class, no inherit
  * protected data memeber or functions: accessed in both derived and base class but not in outside class
  * default or no modifier: same as private

* in private inheritance, data member:-
  * Public data memeber or functions: becomes private
  * Private data memeber or functions: not inherit, accessed only within class
  * Protected data memeber or functions: becomes private
  * default inheritance or no access modifier: same as private

* in protected inheritance, data member:-
  * Public data memeber or functions: becomes protected
  * Private data memeber or functions: not inherit, accessed only within class
  * Protected data memeber or functions: will remain same as protected
  * default inheritance or no access modifier: same as private

*/