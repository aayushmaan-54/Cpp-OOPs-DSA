#include <iostream>
#include <fstream> // For file handling
#include <string>

using namespace std;

int main() {
  // File handling example

  // Create and open a file for writing
  ofstream outFile("example.txt"); // Open file in write mode
  if (!outFile) {
      cerr << "Error: Unable to open file for writing" << endl;
      return 1;
  }

  // Write data to the file
  outFile << "Hello, world!" << endl;
  outFile << "This is a file handling example in C++." << endl;
  outFile.close(); // Close the file

  // Open the file for reading
  ifstream inFile("example.txt"); // Open file in read mode
  if (!inFile) {
      cerr << "Error: Unable to open file for reading" << endl;
      return 1;
  }

  // Read data from the file
  string line;
  while (getline(inFile, line)) {
    cout << line << endl;
  }
  inFile.close(); // Close the file

  // File handling with binary mode

  // Create and open a binary file for writing
  ofstream binOutFile("example.bin", ios::binary);
  if (!binOutFile) {
    cerr << "Error: Unable to open binary file for writing" << endl;
    return 1;
  }

    // Write binary data to the file
  int num = 12345;
  binOutFile.write(reinterpret_cast<char*>(&num), sizeof(num));
  binOutFile.close(); // Close the binary file

  // Open the binary file for reading
  ifstream binInFile("example.bin", ios::binary);
  if (!binInFile) {
    cerr << "Error: Unable to open binary file for reading" << endl;
    return 1;
  }

  // Read binary data from the file
  int readNum;
  binInFile.read(reinterpret_cast<char*>(&readNum), sizeof(readNum));
  cout << "Read number from binary file: " << readNum << endl;
  binInFile.close(); // Close the binary file

  return 0;
}