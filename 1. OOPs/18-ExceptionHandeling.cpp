#include <iostream>
#include <stdexcept>

using namespace std;

// Custom exception class
class DivideByZeroException : public exception {
  public:
    const char* what() const noexcept override {
      return "Division by zero is not allowed";
    }
};

// Function that may throw an exception
double divide(double numerator, double denominator) {
  if (denominator == 0) {
    throw DivideByZeroException();
  }
  return numerator / denominator;
}

int main() {
  double num, den;

  cout << "Enter numerator: ";
  cin >> num;
  cout << "Enter denominator: ";
  cin >> den;

  try {
    double result = divide(num, den);
    cout << "Result: " << result << endl;
  } catch (const DivideByZeroException& e) {
    cerr << "Error: " << e.what() << endl;
  } catch (const exception& e) {
    cerr << "Unexpected error: " << e.what() << endl;
  } catch (...) {
    cerr << "Unknown exception occurred" << endl;
  }

  return 0;
}