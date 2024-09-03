#include <iostream>
#include <cmath>
using namespace std;

bool isPalindrome(int num) { // A number reads the same forward and backward. Example: 121 (Palindrome)
  int original = num, reversed = 0;
  while (num > 0) {
    int digit = num % 10;
    reversed = reversed * 10 + digit;
    num /= 10;
  }
  return original == reversed;
}

int HCF(int a, int b) { // HCF: Largest number that divides both numbers evenly. Example: HCF of 12 and 15 is 3. using Euclidean Algorithm
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

int LCM(int a, int b) { // LCM: Smallest number that both numbers divide into evenly. Example: LCM of 12 and 15 is 60.
  int lcm = a * b;
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return lcm / a;
}

bool isArmstrong(int num) { // Armstrong Number: Number equals the sum of its digits each raised to the power of the number of digits. Example: 153 (1^3 + 5^3 + 3^3 = 153).
  if (num < 0)
    return false;
  int original = num, sum = 0, n = 0;

  while (original > 0) {
    n++;
    original /= 10;
  }

  original = num;
  while (original > 0) {
    int digit = original % 10;

    int power = 1;
    for (int i = 0; i < n; i++) {
      power *= digit;
    }
    sum += power;

    original /= 10;
  }
  return sum == num;
}

bool isPrime(int num) { // Prime Check: Number greater than 1 with no divisors other than 1 and itself. Example: 7 (Prime).
  if (num <= 1)
    return false;
  for (int i = 2; i * i <= num; i++) {
    if (num % i == 0)
      return false;
  }
  return true;
}

bool isPerfect(int num) { // Perfect Number: Number equals the sum of its proper divisors(Divisors of a number excluding the number itself). Example: 6 (1 + 2 + 3 = 6).
  int sum = 0;
  for (int i = 1; i <= num / 2; i++) {
    if (num % i == 0)
      sum += i;
  }
  return sum == num;
}

void printFibonacci(int n) { // Fibonacci Sequence: Each number is the sum of the two preceding ones. Example: 0, 1, 1, 2, 3.
  int a = 0, b = 1, next;
  for (int i = 0; i < n; i++) {
    cout << a << " ";
    next = a + b;
    a = b;
    b = next;
  }
  cout << endl;
}

int factorial(int num) { // Factorial: Product of all positive integers up to that number. Example: 4! = 24 (4 * 3 * 2 * 1).
  int fact = 1;
  for (int i = 1; i <= num; i++) {
    fact *= i;
  }
  return fact;
}

int main() {
  int num1, num2, choice;

  cout << "Choose an option:\n";
  cout << "1. Check Palindrome\n";
  cout << "2. Find HCF\n";
  cout << "3. Find LCM\n";
  cout << "4. Check Armstrong Number\n";
  cout << "5. Check Prime Number\n";
  cout << "6. Check Perfect Number\n";
  cout << "7. Print Fibonacci Sequence\n";
  cout << "8. Find Factorial\n";
  cout << "Enter your choice: ";
  cin >> choice;

  if (choice == 1) {
    cout << "Enter a number: ";
    cin >> num1;
    if (isPalindrome(num1)) {
      cout << num1 << " is a palindrome." << endl;
    }
    else {
      cout << num1 << " is not a palindrome." << endl;
    }
  }
  else if (choice == 2) {
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    cout << "HCF of " << num1 << " and " << num2 << " is " << HCF(num1, num2) << endl;
  }
  else if (choice == 3) {
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    cout << "LCM of " << num1 << " and " << num2 << " is " << LCM(num1, num2) << endl;
  }
  else if (choice == 4) {
    cout << "Enter a number: ";
    cin >> num1;
    if (isArmstrong(num1)) {
      cout << num1 << " is an Armstrong number." << endl;
    }
    else {
      cout << num1 << " is not an Armstrong number." << endl;
    }
  }
  else if (choice == 5) {
    cout << "Enter a number: ";
    cin >> num1;
    if (isPrime(num1)) {
      cout << num1 << " is a prime number." << endl;
    }
    else {
      cout << num1 << " is not a prime number." << endl;
    }
  }
  else if (choice == 6) {
    cout << "Enter a number: ";
    cin >> num1;
    if (isPerfect(num1)) {
      cout << num1 << " is a perfect number." << endl;
    }
    else {
      cout << num1 << " is not a perfect number." << endl;
    }
  }
  else if (choice == 7) {
    cout << "Enter the number of terms: ";
    cin >> num1;
    printFibonacci(num1);
  }
  else if (choice == 8) {
    cout << "Enter a number: ";
    cin >> num1;
    cout << "Factorial of " << num1 << " is " << factorial(num1) << endl;
  }
  else {
    cout << "Invalid choice!" << endl;
  }

  return 0;
}