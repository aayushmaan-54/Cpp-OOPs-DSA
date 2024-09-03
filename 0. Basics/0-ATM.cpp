#include <iostream>
using namespace std;

int BALANCE = 4500;

void showMenu() {
    cout << "Choose an option from below: " << endl;
    cout << "*********** MENU ***********" << endl;
    cout << "* 1. Check Balance         *" << endl;
    cout << "* 2. Deposit               *" << endl;
    cout << "* 3. Withdraw              *" << endl;
    cout << "* 4. Exit                  *" << endl;
    cout << "****************************" << endl;
}

int main() {
    int option;

    do {
      showMenu();
      cout << "Enter your choice: ";
      cin >> option;

      switch(option) {
        case 1:
          cout << "Your Current Balance is $" << BALANCE << endl;
          break;

        case 2:
          int deposit_amount;
          cout << "Enter amount to be deposited: ";
          cin >> deposit_amount;
          BALANCE += deposit_amount;
          cout << "Deposit successful. New balance: $" << BALANCE << endl;
          break;

        case 3:
          int withdraw_amount;
          cout << "Enter amount to be withdrawn: ";
          cin >> withdraw_amount;
          if(withdraw_amount > BALANCE)
            cout << "Insufficient Balance!!" << endl;
          else {
              BALANCE -= withdraw_amount;
              cout << "Withdrawal successful. New balance: $" << BALANCE << endl;
          }
          break;
            
        case 4:
          cout << "Thank you for using our ATM. Goodbye!" << endl;
          return 0;

        default: 
          cout << "Invalid option. Please choose a valid option." << endl;
      }
    cout << endl;
  } while (true);

  return 0;
}