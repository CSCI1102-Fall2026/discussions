# Discussion Problems Week 8

## Overview

This week, we will practice **classes and objects** in C++. In earlier discussions, you worked with functions, arrays, and pointers. Now you will organize data and the functions that operate on it into a class.

For these problems, use **classes, constructors, private data members, and public member functions**. You do **not** need inheritance, polymorphism, `virtual` functions, or dynamic memory allocation.

## Practice Problem 1 - Your First Bank Account

Create a file named `bank_account.cpp`.

Write a program that represents a simple bank account using a class named `BankAccount`.

Your class should have the following **private** data members:

- `string owner` — the account owner's name.
- `double balance` — the amount of money in the account.

Implement these **public** members:

- `BankAccount(string name, double initialBalance)` — a constructor that initializes both data members. If the initial balance is negative, set the balance to `0` instead.
- `void deposit(double amount)` — adds `amount` to the balance, but only if `amount` is positive.
- `bool withdraw(double amount)` — subtracts `amount` and returns `true` only if the amount is positive and does not exceed the current balance. Otherwise, leave the balance unchanged and return `false`.
- `void printAccount()` — prints the owner's name and current balance, formatted with exactly two digits after the decimal point.

In `main()`:

1. Ask the user for the account owner's first name and an initial balance.
2. Create **one `BankAccount` object** using the constructor.
3. Ask for an amount to deposit and call `deposit()`.
4. Ask for an amount to withdraw and call `withdraw()`. If it returns `false`, print `Withdrawal denied!`.
5. Call `printAccount()` to display the final account information.

**Example 1:**

```text
Enter owner's first name: Alex
Enter initial balance: 100
Enter deposit amount: 50
Enter withdrawal amount: 30
Owner: Alex
Balance: $120.00
```

**Example 2:**

```text
Enter owner's first name: Sam
Enter initial balance: 20
Enter deposit amount: -5
Enter withdrawal amount: 50
Withdrawal denied!
Owner: Sam
Balance: $20.00
```

**Hints:**

- Include `<iostream>`, `<string>`, and `<iomanip>`.
- You can use `fixed << setprecision(2)` to print two decimal places.
- Remember that a class definition ends with a semicolon (`;`).

## Practice Problem 2 - Two Objects, Two Balances

Modify your program from Practice Problem 1. This time, create **two different `BankAccount` objects** inside `main()`:

```cpp
BankAccount account1("Alex", 100);
BankAccount account2("Jordan", 200);
```

Then:

1. Deposit `$25` into `account1`.
2. Withdraw `$50` from `account2`.
3. Print both accounts using `printAccount()`.
4. Try to withdraw `$500` from `account1`. If the withdrawal fails, print `Withdrawal denied!`.
5. Print both accounts again to verify that their balances did not change after the failed withdrawal.

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

**Discussion questions:**

1. `account1` and `account2` are created from the same class. Why do they have different balances?
2. What is the difference between a **class** and an **object**?
3. Why should `balance` be declared `private` instead of `public`?
4. What would happen if you tried to write `account1.balance = -100;` in `main()`?

## Practice Problem 3 - Add a Transfer Method

Extend your `BankAccount` class with this additional **public** member function:

```cpp
bool transferTo(BankAccount& other, double amount);
```

The method should transfer money **from the current account to `other`**. It should return `true` if the transfer succeeds, and `false` otherwise.

Rules:

- The amount must be positive.
- The current account must have enough money.
- If a transfer fails, neither account's balance should change.
- Do not allow a transfer to the same object.
- Use your existing `withdraw()` and `deposit()` methods where possible.

In `main()`, create these objects:

```cpp
BankAccount account1("Alex", 100);
BankAccount account2("Jordan", 40);
```

Try transferring `$30` from Alex to Jordan, print both accounts, then attempt to transfer `$200` from Jordan to Alex. Print `Transfer denied!` when a transfer fails.

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

**Think about it:** Why does `transferTo` take `BankAccount& other` rather than `BankAccount other`? What is the purpose of the `&`?

## Before You Finish

Make sure you can explain what the constructor does, how to call a method on an object using the dot (`.`) operator, and why private data members help protect the state of an object. Your programs should use **objects**, not separate standalone variables to track each account balance.
