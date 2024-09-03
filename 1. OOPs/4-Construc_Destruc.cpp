#include <iostream>
#include <cstring>

class MyClass {
  private:
    char* name;
    int age;

  public:
    // Default Constructor
    MyClass() : name(nullptr), age(0) {
      std::cout << "Default Constructor Called!" << std::endl;
    }

    // Parameterized Constructor
    MyClass(const char* n, int a) {
      std::cout << "Parameterized Constructor Called!" << std::endl;
      age = a;
      name = new char[strlen(n) + 1];
      strcpy(name, n);
    }

    // Copy Constructor
    MyClass(const MyClass &other) {
      std::cout << "Copy Constructor Called!" << std::endl;
      age = other.age;
      if (other.name) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
      } else {
        name = nullptr;
      }
    }

    // Destructor
    ~MyClass() {
      std::cout << "Destructor Called!" << std::endl;
      delete[] name;
    }

    // Function to display the details
    void display() const {
      std::cout << "Name: " << (name ? name : "No Name") << ", Age: " << age << std::endl;
    }
};

int main() {
  // Using Default Constructor
  MyClass obj1;
  obj1.display();

  // Using Parameterized Constructor
  // MyClass obj2("Alice", 30);
  MyClass obj2 = {"Alice", 30};
  obj2.display();

  // Using Copy Constructor
  MyClass obj3 = obj2;
  // MyClass obj3(obj2);
  obj3.display();

  // Destructor is called automatically for obj1, obj2, and obj3 when they go out of scope
  return 0;
}