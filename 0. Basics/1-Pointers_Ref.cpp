#include <iostream>
using namespace std;

void printVal(void *ptr, char type) {
  switch (type) {
    case 'i':
      cout << *(static_cast<int*>(ptr)) << endl;
      break;
    case 'c':
      cout << *((char*)(ptr)) << endl;
  }
}

int main() {
  int x = 10;
  
  int *y = &x;
  cout << y << endl;
  cout << *y << endl;
  *y += 10;
  cout << x << endl;

  int &z = x;
  z += 10;
  cout << x << endl;

  int num = 5;
  char letter = 'a';
  printVal(&num, 'i');
  printVal(&letter, 'c');

  int nums[5] = { 4, 5, 7, 25, 45 };
  cout << nums << " = " << &nums[0] << endl; // prints address of 1st element of array
  cout << nums + 2 << endl; // moves pointer by 2 * sizeof pointer type and print that memory address
  cout << nums[4] << " = " << *(nums + 4) << endl; // prints value of last element of array

  int rows, cols;
  cout << "Enter number of rows & columns: " << endl;
  cin >> rows >> cols;
  int **table = new int *[rows];
  for(int i = 0; i < rows; i++) {
    table[i] = new int[cols];
  }
  table[1][2] = 88;
  cout << "Value at matrix[1][2]: " << table[1][2] << endl;
  for(int i = 0; i < rows; i++) {
    delete[] table[i];
  }
  delete[] table;
  table = NULL;

  return 0;
}