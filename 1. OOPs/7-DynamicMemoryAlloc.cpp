#include <iostream>

class Example {
  public:
    int value;

    // Constructor
    Example(int v) : value(v) {
      std::cout << "Constructor called with value: " << value << std::endl;
    }

    // Default constructor
    Example() : value(0) {
      std::cout << "Default constructor called" << std::endl;
    }

    // Destructor
    ~Example() {
      std::cout << "Destructor called for value: " << value << std::endl;
    }
};

int main() {
  // 1. Allocating and deallocating memory for a single object
  std::cout << "Allocating memory for a single Example object." << std::endl;
    
  // Allocate memory for a single Example object
  Example* obj = new Example(10);

  // Use the object
  std::cout << "The value of the object is: " << obj->value << std::endl;

  // Deallocate memory for the single object
  delete obj;

  std::cout << "Memory for the single Example object has been deallocated." << std::endl;

  // 2. Allocating and deallocating memory for an array of objects
  std::cout << "\nAllocating memory for an array of Example objects." << std::endl;
    
    // Allocate memory for an array of Example objects
    int arraySize = 3;
    Example* objArray = new Example[arraySize]; // Use default constructor for each element

  // Initialize each element
  for (int i = 0; i < arraySize; ++i) {
    objArray[i] = Example(i + 1); // Call constructor to initialize the object
  }

  // Use the objects in the array
  for (int i = 0; i < arraySize; ++i) {
    std::cout << "The value of objArray[" << i << "] is: " << objArray[i].value << std::endl;
  }

  // Deallocate memory for the array of objects
  delete[] objArray;

  std::cout << "Memory for the array of Example objects has been deallocated." << std::endl;

  return 0;
}
