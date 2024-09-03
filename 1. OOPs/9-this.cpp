#include <iostream>

class MyClass {
  private:
    int value;
    
  public:
    // Constructor
    MyClass(int val) : value(val) {
      std::cout << "Constructor called. Value initialized to " << value << std::endl;
    }
    
    // Member function that uses 'this' pointer
    void displayValue() const {
      std::cout << "The value is " << this->value << std::endl;
    }
    
    // Member function that modifies the object and uses 'this' to return the object itself
    MyClass& setValue(int val) {
      this->value = val; // Set the value
      return *this;      // Return the current object
    }
    
    // Member function to compare two objects
    bool isEqual(const MyClass& other) const {
      return this->value == other.value;
    }
    
    // Static member function that cannot use 'this' pointer
    static void staticFunction() {
      std::cout << "Static function called." << std::endl;
    }
};

int main() {
  MyClass obj1(10); // Create an object with initial value 10
  MyClass obj2(20); // Create another object with initial value 20
    
  obj1.displayValue(); // Display value of obj1
  obj2.displayValue(); // Display value of obj2
    
  obj1.setValue(30); // Set obj1's value to 30
  obj1.displayValue(); // Display updated value of obj1
    
  // Check if obj1 and obj2 are equal
  if (obj1.isEqual(obj2)) {
    std::cout << "obj1 and obj2 are equal." << std::endl;
  } else {
    std::cout << "obj1 and obj2 are not equal." << std::endl;
  }
    
  MyClass::staticFunction(); // Call the static function
    
  return 0;
}

// The this pointer in C++ is a special pointer available inside non-static member functions of a class. It points to the object for which the member function is called