#  Discussion Problems Week 7

## Practice Problem 1 - Double Trouble

Write a program that asks the user for a number and doubles it — but the doubling has to happen through a pointer.

Implement a function `void doubleValue(int* num)` that takes a pointer to an integer and doubles the value it points to. The function shouldn't return anything.

In `main()`, ask the user for a number, call `doubleValue()` passing in its address, then print the number.

Example:
```
Enter a number: 7
Doubled value: 14
```

## Practice Problem 2 - The Swap Operator

Write a program that asks the user for two numbers and swaps them, using pointers.

Implement a function `void swapNumbers(int* a, int* b)` that swaps the values pointed to by `a` and `b`.

In `main()`, ask the user for two numbers, call `swapNumbers()` passing in the addresses of both variables, then print them in their new order.

Example:
```
Enter first number: 3
Enter second number: 9
After swap: 9 3
```

A student tries writing `swapNumbers` like this instead:
```
void swapNumbers(int* a, int* b) {
    int* temp = a;
    a = b;
    b = temp;
}
```
Try it out — does it still work? Be ready to explain why or why not.

## Practice Problem 3 - Array Whisperer

Write a program that reads 5 integers into an array and adds them up — but no square brackets allowed anywhere in your sum.

Implement a function `int sumArray(int* arr, int size)` that returns the sum of the array using pointer arithmetic (think `*(arr + i)`) instead of `arr[i]`.

In `main()`, ask the user for 5 integers, store them in an array, call `sumArray()`, and print the total.

Example:
```
Enter 5 integers: 1 2 3 4 5
Sum: 15
```
