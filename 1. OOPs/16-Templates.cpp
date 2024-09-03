#include <iostream>
using namespace std;

// Function template to find the maximum of two values
template <typename T>
T findMax(T a, T b) {
  return (a > b) ? a : b;
}

// Class template for a simple pair
template <typename T1, typename T2>
class Pair {
  public:
    T1 first;
    T2 second;

    Pair(T1 f, T2 s) : first(f), second(s) {}

    void display() const {
      cout << "Pair: (" << first << ", " << second << ")" << endl;
    }
};

int main() {
  // Using the function template
  int a = 10, b = 20;
  cout << "Max of " << a << " and " << b << " is " << findMax(a, b) << endl;

  double x = 15.5, y = 7.3;
  cout << "Max of " << x << " and " << y << " is " << findMax(x, y) << endl;

  // Using the class template
  Pair<int, double> p1(5, 3.14);
  Pair<string, int> p2("Age", 25);

  p1.display();
  p2.display();

  return 0;
}