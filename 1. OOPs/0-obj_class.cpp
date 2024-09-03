#include <iostream>
using namespace std;
class Car {
  public:
    string model; // properties or member variables or data members
    int year; // properties or member variables or data members

    Car(string Model, int Year) { // Constructor
      model = Model;
      year = Year;
      cout << "Car object created: " << model << ", " << year << endl;
    }
  
    ~Car() { // Destructor
      cout << "Car object destroyed: " << model << ", " << year << endl;
    }


    void displayDetails() { // member function
      cout << "Model: " << model << ", Year: " << year << endl;
    }
};

int main() {
  Car myCar("Toyota Corolla", 2020);
  myCar.displayDetails();

  myCar.year = 2021;
  myCar.displayDetails();

  // The destructor will be automatically called at the end of the scope
  return 0;
}
/*

Four Fundamental Pillars of Object-Oriented Programming System (OOPs) are:
(i) Encapsulation:
  bundling data (properties) and methods (functions) that operate on the data into a single unit called a class. It hides the internal state of the object from the outside world and only exposes a controlled interface.
  ex: class encapsulates properties and methods under one class

(ii) Abstraction:
  simplifying complex systems by modeling classes based on the essential properties and behaviors an object should have while hiding irrelevant details. It allows focusing on what an object does rather than how it does it.
  ex: Abstract classes and pure virtual functions, Access specifier

(iii) Inheritance:
  Inheritance is a mechanism that allows one class (derived class) to inherit properties and methods from another class (base class). It promotes code reusability and establishes a hierarchical relationship between classes.
  ex: single, multi -level, multiple, hierarchical inheritance

(iv) Polymorphism:
  Polymorphism allows objects to be treated as instances of their base class rather than their actual class. It enables a single function or operator to work in different ways depending on the context
  ex: function overloading, operator overloading, function overriding

*/