#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(const string& accNumber, const string& accHolderName)
        : accountNumber(accNumber), accountHolderName(accHolderName), balance(0.0) {}

    string getAccountNumber() const {
        return accountNumber;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << " into account " << accountNumber << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            cout << "Withdrawn $" << amount << " from account " << accountNumber << endl;
        } else {
            cout << "Insufficient balance or invalid withdrawal amount." << endl;
        }
    }

    void checkBalance() const {
        cout << "Account " << accountNumber << " has a balance of $" << balance << endl;
    }

    void displayAccountInfo() const {
        cout << "Account Number: " << accountNumber << ", Account Holder: " << accountHolderName << ", Balance: $" << balance << endl;
    }
};

int main() {
    vector<BankAccount> accounts;

    while (true) {
        cout << "\nBank Account Management System" << endl;
        cout << "1. Create Account\n2. Deposit\n3. Withdraw\n4. Check Balance\n5. Display All Accounts\n6. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string accountNumber, accountHolderName;
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter account holder name: ";
                cin.ignore(); 
                getline(cin, accountHolderName);

                bool exists = false;
                for (const BankAccount& account : accounts) {
                    if (account.getAccountNumber() == accountNumber) {
                        exists = true;
                        break;
                    }
                }
                if (exists) {
                    cout << "Account number already exists. Please use a unique account number." << endl;
                } else {
                    accounts.push_back(BankAccount(accountNumber, accountHolderName));
                    cout << "Account created successfully." << endl;
                } 
                break;
            }
            case 2: {
                string accountNumber;
                double amount;
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter deposit amount: $";
                cin >> amount;
                cin.ignore(); // Clear the input buffer before the next input
                bool found = false;
                for (BankAccount& account : accounts) {
                    if (accountNumber == account.getAccountNumber()) {
                        account.deposit(amount);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Account number not found." << endl;
                }
                break;
            }
            case 3: {
                string accountNumber;
                double amount;
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter withdrawal amount: $";
                cin >> amount;
                cin.ignore(); // Clear the input buffer before the next input
                bool found = false;
                for (BankAccount& account : accounts) {
                    if (accountNumber == account.getAccountNumber()) {
                        account.withdraw(amount);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Account number not found." << endl;
                }
                break;
            }
            case 4: {
                string accountNumber;
                cout << "Enter account number: ";
                cin >> accountNumber;
                bool found = false;
                for (const BankAccount& account : accounts) {
                    if (accountNumber == account.getAccountNumber()) {
                        account.checkBalance();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Account number not found." << endl;
                }
                break;
            }
            case 5: {
                cout << "Displaying all accounts:" << endl;
                for (const BankAccount& account : accounts) {
                    account.displayAccountInfo();
                }
                break;
            }
            case 6:
                cout << "Exiting Program.. \nGoodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
