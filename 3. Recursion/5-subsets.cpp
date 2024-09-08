#include <iostream>
#include <string>
using namespace std;

int subsets(string &str, string curr, int i) {
  if(i == str.length()) {
    cout << curr << endl;
    return 0;
  }
  subsets(str, curr, i + 1);
  subsets(str, curr + str[i], i + 1);
}

int main() {
  string str;
  cout << "Enter a String: ";
  cin >> str;

  subsets(str, "", 0);

  return 0;
}