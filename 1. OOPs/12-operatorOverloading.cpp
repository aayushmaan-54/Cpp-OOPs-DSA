#include <iostream>
using namespace std;

class Complex {
private:
  double real, imag;

public:
  Complex(double r = 0, double i = 0) : real(r), imag(i) {}

  Complex operator+(const Complex& obj) const {
    return Complex(real + obj.real, imag + obj.imag);
  }

  void display() const {
    cout << real << " + " << imag << "i" << endl;
  }
};

class Complexx {
private:
  double real, imag;

public:
  Complexx(double r = 0, double i = 0) : real(r), imag(i) {}

  // Friend function to overload + operator
  friend Complexx operator+(const Complexx& c1, const Complexx& c2);

  // Friend function to overload * operator
  friend Complexx operator*(const Complexx& c1, const Complexx& c2);

  // Friend function to overload << operator for easy output
  friend ostream& operator<<(ostream& out, const Complexx& c);

  // Friend function to overload >> operator for input
  friend istream& operator>>(istream& in, Complexx& c);
};

// Implementation of friend functions
Complexx operator+(const Complexx& c1, const Complexx& c2) {
  return Complexx(c1.real + c2.real, c1.imag + c2.imag);
}

Complexx operator*(const Complexx& c1, const Complexx& c2) {
  return Complexx(c1.real * c2.real - c1.imag * c2.imag,
                  c1.real * c2.imag + c1.imag * c2.real);
}

ostream& operator<<(ostream& out, const Complexx& c) {
  out << c.real;
  if (c.imag >= 0) out << "+";
  out << c.imag << "i";
  return out;
}

istream& operator>>(istream& in, Complexx& c) {
  cout << "Enter real part: ";
  in >> c.real;
  cout << "Enter imaginary part: ";
  in >> c.imag;
  return in;
}

int main() {
  Complex c1(3, 2), c2(1, 4);
  Complex c3 = c1 + c2;
  c3.display();

  Complexx c4(3, 2), c5(1, 4);
  Complexx c6 = c4 + c5;
  Complexx c7 = c4 * c5;

  cout << "c4 = " << c4 << endl;
  cout << "c5 = " << c5 << endl;
  cout << "c4 + c5 = " << c6 << endl;
  cout << "c4 * c5 = " << c7 << endl;

  Complexx c8;
  cout << "Enter a complex number:" << endl;
  cin >> c8;
  cout << "You entered: " << c8 << endl;

  return 0;
}