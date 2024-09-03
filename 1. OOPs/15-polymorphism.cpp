#include <iostream>
#include <cmath>

using namespace std;

// Base class
class Shape {
  public:
    // Virtual function for runtime polymorphism
    virtual void draw() {
      cout << "Drawing a generic shape" << endl;
    }

    // Function overloading for compile-time polymorphism
    double area(double side) {
      return side * side; // Area of square
    }

    double area(double length, double breadth) {
      return length * breadth; // Area of rectangle
    }

    double area(double radius, bool isCircle) {
      return M_PI * radius * radius; // Area of circle
    }
};

// Derived class for Circle
class Circle : public Shape {
  public:
    void draw() override {
      cout << "Drawing a circle" << endl;
    }
};

// Derived class for Rectangle
class Rectangle : public Shape {
  public:
    void draw() override {
      cout << "Drawing a rectangle" << endl;
    }
};

int main() {
  Shape* shape1 = new Shape();
  Shape* shape2 = new Circle();
  Shape* shape3 = new Rectangle();

  // Compile-time polymorphism (function overloading)
  cout << "Area of square (side = 5): " << shape1->area(5) << endl;
  cout << "Area of rectangle (5x10): " << shape1->area(5.0, 10.0) << endl;
  cout << "Area of circle (radius = 7): " << shape1->area(7.0, true) << endl;

  // Runtime polymorphism (virtual functions)
  shape1->draw();
  shape2->draw();
  shape3->draw();

  // Cleaning up memory
  delete shape1;
  delete shape2;
  delete shape3;

  return 0;
}



/*

                       +--------------------+
                       |    Polymorphism    |
                       +--------------------+
                               |
              +----------------+----------------+
              |                                 |
     +------------------+               +-----------------+
     |  Compile Time   |                |   Run Time     |
    +------------------+               +-----------------+
              |                                 |
             ▼                                  ▼
     +-----------------+               +-----------------+
     | Method          |               | Virtual         |
     | Overloading     |               | Function        |
     +-----------------+               +-----------------+
              |                                 |
     +-----------------+               +-----------------+
     | Operator        |               | Function        |
     | Overloading     |               | Overriding      |
     +-----------------+               +-----------------+


*/