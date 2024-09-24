#include <iostream>
#include <unordered_map>
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
        cout << "Account Number: " << accountNumber 
             << ", Account Holder: " << accountHolderName 
             << ", Balance: $" << balance << endl;
    }
};

class Bank {
private:
    unordered_map<string, BankAccount> accounts; 

    BankAccount* findAccount(const string& accountNumber) {
        if (accounts.find(accountNumber) != accounts.end()) {
            return &accounts[accountNumber];
        }
        return nullptr;
    }

public:
    void createAccount(const string& accountNumber, const string& accountHolderName) {
        if (accounts.find(accountNumber) != accounts.end()) {
            cout << "Account number already exists. Please use a unique account number." << endl;
        } else {
            accounts[accountNumber] = BankAccount(accountNumber, accountHolderName);
            cout << "Account created successfully." << endl;
        }
    }

    void deposit(const string& accountNumber, double amount) {
        BankAccount* account = findAccount(accountNumber);
        if (account) {
            account->deposit(amount);
        } else {
            cout << "Account number not found." << endl;
        }
    }

    void withdraw(const string& accountNumber, double amount) {
        BankAccount* account = findAccount(accountNumber);
        if (account) {
            account->withdraw(amount);
        } else {
            cout << "Account number not found." << endl;
        }
    }

    void checkBalance(const string& accountNumber) {
        BankAccount* account = findAccount(accountNumber);
        if (account) {
            account->checkBalance();
        } else {
            cout << "Account number not found." << endl;
        }
    }

    void displayAllAccounts() const {
        if (accounts.empty()) {
            cout << "No accounts found." << endl;
        } else {
            cout << "Displaying all accounts:" << endl;
            for (const auto& [accNumber, account] : accounts) {
                account.displayAccountInfo();
            }
        }
    }
};

int main() {
    Bank bank;

    while (true) {
        cout << "\nBank Account Management System" << endl;
        cout << "1. Create Account\n2. Deposit\n3. Withdraw\n4. Check Balance\n5. Display All Accounts\n6. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        string accountNumber, accountHolderName;
        double amount;

        switch (choice) {
            case 1: 
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter account holder name: ";
                cin.ignore();
                getline(cin, accountHolderName);
                bank.createAccount(accountNumber, accountHolderName);
                break;

            case 2: 
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter deposit amount: $";
                cin >> amount;
                bank.deposit(accountNumber, amount);
                break;

            case 3: 
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter withdrawal amount: $";
                cin >> amount;
                bank.withdraw(accountNumber, amount);
                break;

            case 4:
                cout << "Enter account number: ";
                cin >> accountNumber;
                bank.checkBalance(accountNumber);
                break;

            case 5:
                bank.displayAllAccounts();
                break;

            case 6: 
                cout << "Exiting Program... Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
