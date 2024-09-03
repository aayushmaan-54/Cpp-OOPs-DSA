#include <iostream>

// Abstract class
class Shape {
  public:
    // Pure virtual function
    virtual void draw() const = 0;

    // Normal member function
    void info() const {
      std::cout << "This is a shape." << std::endl;
    }

    // Virtual destructor to ensure proper cleanup of derived classes
    virtual ~Shape() {}
};

// Derived class
class Circle : public Shape {
  public:
    void draw() const override {
      std::cout << "Drawing a circle." << std::endl;
    }
};

// Derived class
class Rectangle : public Shape {
  public:
    void draw() const override {
      std::cout << "Drawing a rectangle." << std::endl;
    }
};

int main() {
  // Shape s; // Error: Cannot instantiate an abstract class

  Circle c;
  Rectangle r;

  c.draw();  // Output: Drawing a circle.
  r.draw();  // Output: Drawing a rectangle.

  c.info();  // Output: This is a shape.
  r.info();  // Output: This is a shape.

  return 0;
}


/*

Abstract Class: In the example above, Shape is an abstract class because it has a pure virtual function draw().

Pure Virtual Function: Declared with = 0, making Shape an abstract class.

Derived Classes: Circle and Rectangle are derived from Shape and must implement the draw() function.

*/