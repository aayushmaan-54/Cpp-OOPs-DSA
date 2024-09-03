#include <iostream>
using namespace std;

class A {
  public:
    void display() {
      cout << "Hello, World!" << endl;
    }
};

// class B: public A {};
// class C: public A {};

class B: virtual public A {};
class C: virtual public A {};
class D: public B, public C {};

int main() {
  D d;
  d.display();

  return 0;
}

/*

             +----------------+
             |      CLASS A    |
             |    display()   |
             +----------------+
               /            \
      public /               \  public
           /                  \
   +----------------+    +----------------+
   |     CLASS B    |    |     CLASS C    |
   |                |    |                |
   +----------------+    +----------------+
           \                      /
     public \                   / public
             \                /
             +----------------+
             |     CLASS D    |
             |                |
             +----------------+


in here dispaly() is function in class A if we call from class D compiler will confuse for which class display() to run B to A or C to A
*/


/*

when a base class is inherited using the virtual keyword, all derived classes share the same instance of the base class within a single inheritance hierarchy. This means that:

1. Shared Methods and Properties: All the derived classes that virtually inherit from the base class have access to the same methods and properties (members) defined in the base class.

2. Single Instance: There is only one instance of the base class in the entire hierarchy, regardless of how many classes derive from it. This ensures that changes made to the base class members in one part of the hierarchy are reflected in all other parts.

*/