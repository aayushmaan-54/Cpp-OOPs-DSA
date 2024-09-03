#include <iostream>
using namespace std;

// Base class
class Base {
  public:
    // Virtual function to allow overriding in derived class
    virtual void show() {
      cout << "Base class show function" << endl;
    }

    void display() {
      cout << "Base Display" << endl;
    }
};

// Derived class
class Derived : public Base {
  public:
    // Override the base class show function
    void show() override {
      cout << "Derived class show function" << endl;
    }

    void display() {
      cout << "Derived Display" << endl;
    }
};

int main() {

  Base* basePtr;
  Derived derivedObj;

  derivedObj.display(); // Calls Derived::display() - Early Binding

  basePtr = &derivedObj;
  basePtr->display();  // Calls Base::display() - Early Binding
  basePtr->show();     // Calls Derived::show() - Late Binding (due to virtual)
    
  /*
  in here why is that baseptr of different function running diffrent classes function cuz one is virtaul function overriding and another is normal

  - virtual function: based on the pointer like my pointer is Base* basePtr; means for base class so it will run base class function if it was Derived* basePtr; it will run for derived

  - normal function overriding: For non-virtual functions, the function called is always determined by the pointer type, not the object type.
  */

  return 0;
}

// Defines a virtual function show(). The virtual keyword allows the function to be overridden in derived classes.


/*

* Early Binding (or static binding) refers to the process where the method to be invoked is determined at compile time. This means the compiler knows exactly which function or method will be called based on the type of the object or pointer at compile time.

* Late Binding (or dynamic binding) refers to the process where the method to be invoked is determined at runtime. This is typically used with virtual functions in C++, allowing for polymorphic behavior where the method to be called depends on the actual type of the object pointed to or referenced, not just the type of the pointer or reference. this is function overriding

*/