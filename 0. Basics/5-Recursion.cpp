#include <iostream>
#include <string>

using namespace std;

void printNumbers(int n) {
    if (n == 0) return;
    printNumbers(n - 1);
    cout << n << " ";
}

void printReverse(int n) {
    if (n == 0) return;
    cout << n << " ";
    printReverse(n - 1);
}

int sumOfNumbers(int n) {
    if (n == 0) return 0;
    return n + sumOfNumbers(n - 1);
}

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

void reverseArray(int arr[], int size, int left, int right) {
    if (left >= right) return;
    swap(arr[left], arr[right]);
    reverseArray(arr, size, left + 1, right - 1);
}

bool isPalindrome(string s, int left, int right) {
    if (left >= right) return true;
    if (s[left] != s[right]) return false;
    return isPalindrome(s, left + 1, right - 1);
}

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int power(int base, int exponent) {
    if (exponent == 0) return 1;
    if (exponent == 1) return base;
    int half = power(base, exponent / 2);
    if (exponent % 2 == 0) return half * half;
    else return base * half * half;
}

void generatePermutations(string s, int left, int right) {
    if (left == right) {
        cout << s << endl;
        return;
    }
    for (int i = left; i <= right; i++) {
        swap(s[left], s[i]);
        generatePermutations(s, left + 1, right);
        swap(s[left], s[i]);
    }
}

int main() {
    cout << "1. Print numbers from 1 to n\n";
    printNumbers(5);
    cout << "\n\n2. Print numbers from n to 1\n";
    printReverse(5);
    cout << "\n\n3. Sum of first n numbers\n";
    cout << sumOfNumbers(5) << "\n\n";
    cout << "4. Factorial\n";
    cout << factorial(5) << "\n\n";
    
    int arr[] = {1, 2, 3, 4, 5};
    cout << "5. Reverse array\n";
    reverseArray(arr, 5, 0, 4);
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n\n6. Check if string is palindrome\n";
    cout << boolalpha << isPalindrome("racecar", 0, 6) << "\n\n";
    cout << "7. Fibonacci sequence\n";
    cout << fibonacci(10) << "\n\n";
    cout << "8. Power calculation\n";
    cout << power(2, 5) << "\n\n";
    cout << "9. Permutations of a string\n";
    generatePermutations("abc", 0, 2);
    
    return 0;
}