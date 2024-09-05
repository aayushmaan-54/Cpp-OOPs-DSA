#include <iostream>
#include <memory> // for unique_ptr, shared_ptr, weak_ptr
using namespace std;

class SmartPointer {
  int *ptr;

  public:
    SmartPointer(int *p = nullptr) { ptr = p; }
    ~SmartPointer() { delete ptr; }
    int &operator *() { return *ptr; }
};

class Test {
  int x;

  public:
    Test(int a = 0) { x = a; cout << "Constructor Called! \n"; }
    ~Test() { cout << "Destrcutor Called! \n"; }
    int func() { cout << x << endl; }
};

int main() {

  SmartPointer sp(new int());
  *sp = 20;
  cout << *sp << "\n";

  int *ptr1 = new int(10);
  {
    int *ptr2 = ptr1;
    SmartPointer sp1(ptr2);
    cout << *ptr1 << " = " << *ptr2 << "\n";
  }
  cout << *ptr1 << "\n"; // here due to above code when sp1 goes out of scope inside the inner block, it deletes ptr2, which was initially pointing to the same memory location as ptr1. As a result, ptr1 becomes a dangling pointer. so due to this we can use shared_ptr

  //--------------------------------------------------------------//

  {
    unique_ptr<Test> ptr = make_unique<Test>(10);
    // unique_ptr<Test> ptr(new Test(10));
    unique_ptr<Test> ptr1 = move(ptr); // this dont create 2 pointer sharing same class instead move ownership
    ptr -> func();
  }

  {
    // shared_ptr<Test> ptr = make_shared<Test>(10);
    shared_ptr<Test> ptr1 (new Test(10));
    shared_ptr<Test> ptr2 = ptr1; // ptr1 and ptr2 both own same class now

    cout << ptr1.use_count() << endl;
    cout << ptr2.use_count() << endl;
  }

  {
    weak_ptr<Test> p1;
    {
      shared_ptr<Test> p2 = make_shared<Test> (10);
      p1 = p2;
      cout << p1.use_count() << endl;
    }
    cout << p1.expired(); // checks wether obj pointed by p1 is valid or not if 1 is output then obj is valid
    shared_ptr<Test> p3 = p1.lock(); // creates shared_ptr from weak_ptr
  }

  return 0;
}




/*


 * Smart Pointer is a class which wraps a raw pointer, to manage the life time of the pointer
 *
 * the most fundamental job of smart pointer is to remove the chances of memory leak
 
 * it make sure that the obj is deleted if it is not reference any more
 


 * TYPES:
 * unique ptr: allows only one owner of the underlying pointer
 
 * shared ptr: allows multiple owners of the same pointer(reference count is maintined), refrence of pointer is removed only when all pointer reference is lost then destructor is called
 
 * weak ptr: it is a Smart type of shared ptr which doesnt count the reference


 */