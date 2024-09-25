

# Bank Account Management System

This is a simple **Bank Account Management System** implemented in C++. The system allows users to create bank accounts, deposit and withdraw money, check their account balances, and view all registered accounts. The project demonstrates basic object-oriented programming (OOP) principles along with the usage of the `unordered_map` container for efficient account management.

## Features

- **Create Account**: Users can create a new bank account by providing a unique account number and the account holder's name.
- **Deposit**: Users can deposit a specified amount of money into their account.
- **Withdraw**: Users can withdraw a specified amount from their account, provided sufficient balance is available.
- **Check Balance**: Users can check the current balance of their account.
- **Display All Accounts**: The system displays the details of all created accounts.
- **Exit**: Exits the program.

## How It Works

The system stores the bank accounts in an `unordered_map` with the account number as the key, providing O(1) average time complexity for account-related operations like lookups, deposits, withdrawals, etc.

### Classes and Methods

- **`BankAccount` Class**:
  - Holds information about the account number, account holder's name, and balance.
  - Methods: `deposit()`, `withdraw()`, `checkBalance()`, and `displayAccountInfo()`.

- **`Bank` Class**:
  - Manages multiple `BankAccount` objects.
  - Provides functions to:
    - Create an account.
    - Deposit and withdraw money from accounts.
    - Check the balance of an account.
    - Display details of all accounts.
  - Internally uses an `unordered_map` for fast account retrieval.

### Menu-Driven Interface

The system presents a menu-driven interface for users to interact with the bank accounts:
```
Bank Account Management System
1. Create Account
2. Deposit
3. Withdraw
4. Check Balance
5. Display All Accounts
6. Exit
```

 **Interact with the System**:
    Follow the on-screen instructions to create accounts, deposit/withdraw funds, and check balances.

## Example Output

```
Bank Account Management System
1. Create Account
2. Deposit
3. Withdraw
4. Check Balance
5. Display All Accounts
6. Exit
Enter your choice: 1
Enter account number: 123456
Enter account holder name: John Doe
Account created successfully.

Bank Account Management System
1. Create Account
2. Deposit
3. Withdraw
4. Check Balance
5. Display All Accounts
6. Exit
Enter your choice: 2
Enter account number: 123456
Enter deposit amount: $500
Deposited $500 into account 123456
```

## Improvements and Future Enhancements

Here are some ideas for future improvements:
- **Password Protection**: Add a password for each account to improve security.
- **Transaction History**: Maintain a record of each account’s transaction history (deposits and withdrawals).
- **Interest Calculation**: Implement functionality to calculate interest on the balance.

