#include <iostream>
using namespace std;
int ROWS = 5;
int COLS = 4;

void rectangle() {
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      cout << "*";
    }
    cout << "\n";
  }
}

void pyramid() {
  for(int i = 0; i < ROWS; i++) {
    for (int j = 0; j <= i; j++) {
      cout << "*";
    }
    cout << endl;
  }
}

void numberedColsPyramid() {
  int count { 1 };

  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j <= i; j++) {
      cout << count;
      count++;
    }
    count = 1;
    cout << endl;
  }
}

void numberedRowsPyramid() {
  int count { 1 };

  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j <= i; j++) {
      cout << count;
    }
    count++;
    cout << endl;
  }
}

void reversedPyramid() {
  for(int i = ROWS; i >= 0; i--) {
    for (int j = i; j > 0; j--) {
      cout << "*";
    }
    cout << endl;
  }
}

void numberedColsReversedPyramid() {
  int count { 1 };
  for(int i = ROWS; i >= 0; i--) {
    for(int j = i; j > 0; j--) {
      cout << count;
      count++;
    }
    count = 1;
    cout << "\n";
  }
}

void equilateralTriangle() {
  for (int i = 1; i <= ROWS; ++i) {
    for (int j = i; j < ROWS; ++j) {
      cout << " ";
    }
    for (int k = 1; k <= (2 * i - 1); ++k) {
      cout << "*";
    }
    cout << endl;
  }
}

void reversedEquilateralTriangle() {
  for (int i = ROWS; i >= 1; --i) {
    for (int j = ROWS; j > i; --j) {
      cout << " ";
    }
    for (int k = 1; k <= (2 * i - 1); ++k) {
      cout << "*";
    }
    cout << endl;
  }
}

void equilateralDiamond() {
  for (int i = 0; i < ROWS / 2; ++i) {
    for (int j = 0; j < ROWS / 2 - i; ++j) {
      cout << " ";
    }
    for (int j = 0; j < 2 * i + 1; ++j) {
      cout << "*";
    }
    cout << endl;
  }
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < ROWS; ++j) {
      cout << "*";
    }
    cout << endl;
    }
    for (int i = ROWS / 2 - 1; i >= 0; --i) {
      for (int j = 0; j < ROWS / 2 - i; ++j) {
        cout << " ";
      }
      for (int j = 0; j < 2 * i + 1; ++j) {
        cout << "*";
      }
    cout << std::endl;
  }
}

void hollowSquare() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < ROWS; j++) {
      if (i == 0 || i == ROWS - 1 || j == 0 || j == ROWS - 1) {
        cout << "* ";
      } else {
          cout << "  ";
      }
    }
    cout << endl;
  }
}

void alphaRepeatitiveEquilateralTriangle() {
  for(int i = 0; i < ROWS; i++){
    for(int j = 0; j < ROWS - i - 1; j++){
      cout<<" ";
    }
    char ch = 'A';
    int breakpoint = ( 2 * i + 1 ) / 2;
    for(int j = 1; j <= 2 * i + 1; j++){
      cout << ch ;
        if(j <= breakpoint) ch++;
          else ch--;
        }
    for(int j=0; j< ROWS - i - 1; j++){
      cout<<" ";
    }
    cout<<endl;
  }
}

void twoHalfDiamond() {
  int spaces= 2 * ROWS - 2;
  for(int i = 1; i <= 2 * ROWS - 1; i++){
    int stars = i;
    if(i > ROWS) stars = 2 * ROWS - i;
    for(int j = 1; j <= stars; j++){
      cout << "*";
    }
    for(int j = 1; j <=spaces; j++){
      cout << " ";
    }
    for(int j = 1; j <= stars; j++){
      cout << "*";
    }
    cout << endl;
    if(i < ROWS) spaces -= 2;
    else spaces += 2;
  }
}


int main() {
  rectangle();
  cout << endl;
  pyramid();
  cout << endl;
  numberedColsPyramid();
  cout << endl;
  numberedRowsPyramid();
  cout << endl;
  reversedPyramid();
  cout << endl;
  numberedColsReversedPyramid();
  cout << endl;
  equilateralTriangle();
  cout << endl;
  reversedEquilateralTriangle();
  cout << endl;
  equilateralDiamond();
  cout << endl;
  hollowSquare();
  cout << endl;
  alphaRepeatitiveEquilateralTriangle();
  cout << endl;
  twoHalfDiamond();
  cout << endl;

  return 0;
}