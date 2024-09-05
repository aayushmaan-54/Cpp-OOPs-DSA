#include <iostream>
using namespace std;

int main(int argc, char *argv[], char *envp[]) {

  cout << "You entered " << argc << " arguments:\n";

  for (int i = 0; i < argc; i++) {
    cout << argv[i] << "\n";
  }

  getchar();  // Wait for user input before displaying environment variables

  for (int i = 0; envp[i] != NULL; i++) {
    cout << envp[i] << "\n";
  }

  getchar();  // Wait for user input before exiting

  return 0;
}



/*
g++ test.cpp -o main
./main arg1 arg2 arg3


* int argc(argument count) is the number of command-line arguments.

* char *argv[](argument vector) is an array of strings representing the command-line arguments.

* char *envp[] is an array of strings representing the environment variables (this parameter is not standard in C++ but can be used in some compilers like GCC).

*/