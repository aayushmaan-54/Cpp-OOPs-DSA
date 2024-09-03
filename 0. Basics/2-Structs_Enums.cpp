#include <iostream>
#include <string>
using namespace std; 

enum class Status {
    ACTIVE,
    INACTIVE,
    PENDING
};

struct Employee {
    std::string name;
    int id;
    Status status;
};

void printEmployee(const Employee& e) {
  cout << "Name: " << e.name << "\n";
  cout << "ID: " << e.id << "\n";
  cout << "Status: ";

  switch (e.status) {
    case Status::ACTIVE: cout << "Active"; break;
    case Status::INACTIVE: cout << "Inactive"; break;
    case Status::PENDING: cout << "Pending"; break;
  }
  cout << "\n";
}


int main() {
  Employee emp1 = {"John Doe", 45, Status::ACTIVE};
  printEmployee(emp1);
  return 0;
}