#include <iostream>
#include <string>

// Define a class called Person
class Person {
  public:
    // Constructor to initialize name and age
    Person(const std::string& name, int age) : name(name), age(age) {}

    // Method to display person's information
    void display() const {
      std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }

    // Method to get the name (getter)
    std::string getName() const {
      return name;
    }

    // Method to get the age (getter)
    int getAge() const {
      return age;
    }

  private:
    std::string name;
    int age;
};

int main() {
  // Create an array of Person objects
  Person people[] = {
    Person("Alice", 30),
    Person("Bob", 25),
    Person("Charlie", 35)
  };

  // Calculate the number of elements in the array
  const int numPeople = sizeof(people) / sizeof(people[0]);

  // Access and display elements in the array
  for (int i = 0; i < numPeople; ++i) {
    std::cout << "Person " << i + 1 << ": ";
    people[i].display();
  }

  // Example of accessing specific elements
  std::cout << "\nAccessing specific elements:\n";
  std::cout << "First Person: ";
  people[0].display();

  std::cout << "Second Person: ";
  people[1].display();

  // Modify an object's attributes directly (if you had setters)
  // people[2].setName("David"); // Assuming you had a setName method

  return 0;
}
