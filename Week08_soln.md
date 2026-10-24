# Discussion Problems Week 8 — Solutions

These solutions correspond to [Week08.md](Week08.md). Each program is standalone; compile and run one at a time. The exercises use constructors, encapsulation, and member functions without inheritance or polymorphism.

## Practice Problem 1 — Your First Bank Account

Save as `bank_account.cpp`.

```cpp
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class BankAccount {
private:
    string owner;
    double balance;

public:
    BankAccount(string name, double initialBalance) {
        owner = name;
        balance = (initialBalance >= 0) ? initialBalance : 0;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    bool withdraw(double amount) {
        if (amount <= 0 || amount > balance) {
            return false;
        }
        balance -= amount;
        return true;
    }

    void printAccount() {
        cout << "Owner: " << owner << '\n';
        cout << "Balance: $" << fixed << setprecision(2) << balance << '\n';
    }
};

int main() {
    string name;
    double initialBalance, depositAmount, withdrawalAmount;

    cout << "Enter owner's first name: ";
    cin >> name;
    cout << "Enter initial balance: ";
    cin >> initialBalance;

    BankAccount account(name, initialBalance);

    cout << "Enter deposit amount: ";
    cin >> depositAmount;
    account.deposit(depositAmount);

    cout << "Enter withdrawal amount: ";
    cin >> withdrawalAmount;
    if (!account.withdraw(withdrawalAmount)) {
        cout << "Withdrawal denied!\n";
    }
    account.printAccount();
    return 0;
}
```

**Checks:** Starting with `100`, depositing `50`, and withdrawing `30` produces `$120.00`. Starting with `20`, depositing `-5`, and withdrawing `50` leaves `$20.00` and prints `Withdrawal denied!`. A negative initial balance becomes zero. Zero-value deposits do nothing, and zero-value withdrawals fail.

## Practice Problem 2 — Two Objects, Two Balances

Use the **same `BankAccount` class** from Problem 1, replacing only `main()` with the following:

```cpp
int main() {
    BankAccount account1("Alex", 100);
    BankAccount account2("Jordan", 200);

    account1.deposit(25);
    account2.withdraw(50);

    account1.printAccount();
    account2.printAccount();

    if (!account1.withdraw(500)) {
        cout << "Withdrawal denied!\n";
    }

    account1.printAccount();
    account2.printAccount();
    return 0;
}
```

**Expected output:**

```text
Owner: Alex
Balance: $125.00
Owner: Jordan
Balance: $150.00
Withdrawal denied!
Owner: Alex
Balance: $125.00
Owner: Jordan
Balance: $150.00
```

### Discussion answers

1. Each object has its **own** `owner` and `balance` data members; changes to one account do not affect the other.
2. A **class** defines the structure and behavior of a type. An **object** is an individual instance of that class with its own state.
3. `private` prevents unrelated code from bypassing the validation in `deposit()` and `withdraw()`.
4. `account1.balance = -100;` in `main()` causes a **compile-time access error** because `balance` is private.

## Practice Problem 3 — Add a Transfer Method

Add this method to the **public** section of the `BankAccount` class from Problem 1:

```cpp
bool transferTo(BankAccount& other, double amount) {
    if (&other == this || amount <= 0 || amount > balance) {
        return false;
    }
    if (!withdraw(amount)) {
        return false;
    }
    other.deposit(amount);
    return true;
}
```

Then replace `main()` with:

```cpp
int main() {
    BankAccount account1("Alex", 100);
    BankAccount account2("Jordan", 40);

    if (!account1.transferTo(account2, 30)) {
        cout << "Transfer denied!\n";
    }
    account1.printAccount();
    account2.printAccount();

    if (!account2.transferTo(account1, 200)) {
        cout << "Transfer denied!\n";
    }
    account1.printAccount();
    account2.printAccount();
    return 0;
}
```

**Expected output:**

```text
Owner: Alex
Balance: $70.00
Owner: Jordan
Balance: $70.00
Transfer denied!
Owner: Alex
Balance: $70.00
Owner: Jordan
Balance: $70.00
```

### Discussion answer

`BankAccount& other` is a **reference to the original destination object**, so depositing into `other` updates the actual recipient. Passing `BankAccount other` by value would instead make a copy, and the deposit would affect only that copy. The expression `&other == this` compares object addresses to reject self-transfers; `this` points to the object whose `transferTo()` method was called.

### Additional checks

- `account1.transferTo(account2, 0)` → `false`; neither balance changes.
- `account1.transferTo(account2, -10)` → `false`; neither balance changes.
- `account1.transferTo(account2, 1000)` → `false` when funds are insufficient.
- `account1.transferTo(account1, 10)` → `false` (same object).
- `account1.transferTo(account2, 70)` succeeds when Alex has exactly `$70.00`.

## Compile and Run

For Problem 1, compile with:

```bash
g++ -std=c++11 -Wall -Wextra bank_account.cpp -o bank_account
./bank_account
```

For Problems 2 and 3, use the same compile command after replacing `main()` and (for Problem 3) adding `transferTo()`.

**Instructor note:** The examples use `double` to match the assignment and introduce object behavior. Real financial software should avoid floating-point types for exact currency accounting.
