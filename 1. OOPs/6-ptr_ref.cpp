#include <iostream>
#include <string>

// Define a struct called Person
struct Person {
  std::string name;
  int age;

  // Method to display person's information
  void display() const {
    std::cout << "Name: " << name << ", Age: " << age << std::endl;
  }
};

// Function to demonstrate pointers to objects
void pointerToObjectDemo(Person* ptr) {
  if (ptr) {
    std::cout << "Pointer to Object Demo:\n";
    ptr->display(); // Access members using pointer
    ptr->age = 40;  // Modify members using pointer
  }
}

// Function to demonstrate references to objects
void referenceToObjectDemo(Person& ref) {
  std::cout << "Reference to Object Demo:\n";
  ref.display(); // Access members using reference
  ref.age = 50;  // Modify members using reference
}

int main() {
  // Create an object of Person
  Person person1 = {"Alice", 30};

  // Demonstrate pointer to object
  Person* personPtr = &person1; // Pointer to the person1 object
  std::cout << "Original Person object:\n";
  person1.display(); // Display the original object

  pointerToObjectDemo(personPtr); // Pass pointer to function

  // Display after modification through pointer
  std::cout << "Person object after modification through pointer:\n";
  person1.display();

  // Demonstrate reference to object
  Person& personRef = person1; // Reference to the person1 object
  referenceToObjectDemo(personRef); // Pass reference to function

  // Display after modification through reference
  std::cout << "Person object after modification through reference:\n";
  person1.display();

  return 0;
}
