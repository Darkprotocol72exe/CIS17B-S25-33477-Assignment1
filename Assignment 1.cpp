// This program is a simple banking system in C++ where a user can:
// Create an account with a name and an initial balance,
// deposit and withdraw money from the account,
// view the account balance,
// and exit the system.
// Hugo Willis 
// CIS17B-S25-33477
// LMD: 03/02/2025

#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolderName;
    int accountNumber;
    double balance;
public:
    BankAccount(string name, int number, double startingBalance) {
        accountHolderName = name;
        accountNumber = number;
        balance = startingBalance;
    }
    
    void deposit(double amount) {
        if (amount < 0) {
            throw "Deposit amount cannot be negative.";
        }
        balance += amount;
    }
    
    void withdraw(double amount) {
        if (amount < 0) {
            throw "Withdrawal amount cannot be negative.";
        }
        if (amount > balance) {
            throw "Insufficient funds.";
        }
        balance -= amount;
    }
    
    double getBalance() {
        return balance;
    }
};

double getValidDouble() {
    double value;
    cin >> value;
    if (cin.fail()) {
        cin.clear();
        throw "Invalid input. Please enter a numeric value.";
    }
    return value;
}

void depositMoney(BankAccount* account) {
    cout << "Enter deposit amount: ";
    try {
        double amount = getValidDouble();
        account->deposit(amount);
        cout << "Deposit successful. New balance:$" << account->getBalance() << endl;
    } catch (const char* errorMessage) {
        cout << "Error: " << errorMessage << endl;
    }
}

void withdrawMoney(BankAccount* account) {
    cout << "Enter withdrawal amount: ";
    try {
        double amount = getValidDouble();
        account->withdraw(amount);
        cout << "Withdrawal successful. New balance:$" << account->getBalance() << endl;
    } catch (const char* errorMessage) {
        cout << "Error: " << errorMessage << endl;
    }
}

void displayBalance(BankAccount* account) {
    cout << "Your current balance is:$" << account->getBalance() << endl;
}

int main() {
    int choice = 0;
    BankAccount* myAccount = nullptr; 

    while (choice != 5) {
        cout << "\n----- Welcome to Norco Bank! -----\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear();

            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
            continue;
        }
        
        switch (choice) {
            case 1: {
                if (myAccount != nullptr) {
                    cout << "Account already exists." << endl;
                } else {
                    string name;
                    int number;
                    double startingBalance;
                    cout << "Enter account holder name: ";
                    getline(cin, name); 
                    getline(cin, name); 
                    
                    cout << "Enter account number: ";
                    cin >> number;
                    
                    cout << "Enter starting balance: ";
                    try {
                        startingBalance = getValidDouble();
                    } catch (const char* errorMessage) {
                        cout << "Error: " << errorMessage << endl;
                        break;
                    }
                    
                    myAccount = new BankAccount(name, number, startingBalance);
                    cout << "Account created successfully!" << endl;
                }
                break;
            }
            case 2:
                if (myAccount == nullptr) {
                    cout << "No account exists. Please create an account first." << endl;
                } else {
                    depositMoney(myAccount);
                }
                break;
            case 3:
                if (myAccount == nullptr) {
                    cout << "No account exists. Please create an account first." << endl;
                } else {
                    withdrawMoney(myAccount);
                }
                break;
            case 4:
                if (myAccount == nullptr) {
                    cout << "No account exists. Please create an account first." << endl;
                } else {
                    displayBalance(myAccount);
                }
                break;
            case 5:
                cout << "Thank you for visiting Norco Bank!" << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }
    }

    if (myAccount != nullptr) {
        delete myAccount;
        myAccount = nullptr;
    }
    
    return 0;
}
