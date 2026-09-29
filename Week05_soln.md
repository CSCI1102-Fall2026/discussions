# Discussion Problems Week 5 — Solutions

## Practice Problem 1

The following program is intended to print out the first 12 prime numbers, but it has a bug in it!  Can you spot it?
```
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    const int num_primes = sizeof(primes);
    for (int i = 0; i < num_primes; ++i) {
        cout << "primes[" << i << "]: " << primes[i] << endl;
    }
    return EXIT_SUCCESS;
}
```
Here are a few notes about the code above that may help you:
- Your textbook uses the `sizeof` operator to show the sizes of various types, such as `int`. The `sizeof` operator can be applied to a variable as easily as to the name of a type.  When it is applied to a variable, it returns the size of that variable's type. Note that both `primes` and `primes[0]` are variables.
- When applied to an _array_, the `sizeof` operator returns the size of the array in bytes — that is, the number of bytes that the array occupies in memory.
- The expression `EXIT_SUCCESS`, used as the return value of `main`, is a symbolic constant synonymous with `0`.  It is declared in the header `cstdlib`, which is `#icnlude`d here.  This makes the meaning of the returned `0` clear:  it is the exit status meaning "success."
1. Build this program into an executable and run it.  What happens?
> _Either the program will crash, or, more likely, it will print 12 x 4 = 48 elements, of which the first 12 are correct and the rest are unpredictable garbage._
2. Where is the bug and why does it cause the program to behave incorrectly?
> _The bug is the use of the `sizeof` operator on the array, which (probably) returns 48 because the array contains 12 elements of (probably) 4 bytes each.  It causes the program to iterate beyond the end of the array and thus to read uninitialized values._
3. Fix the bug and test your fixed version.  What are your options for fixing this bug?
> _Replace `sizeof(primes)` with `sizeof(primes) / sizeof(primes[0])`. Another solution is to divide `sizeof(primes)` by `sizeof(int)`, but, if you change the base type of the array — say, from `int` to `long` — you must remember also to change this detail, or you will have a bug again.  You could also use a numeric literal (4), but that is not a portable solution, since different systems or compilers may define `int` has having a size other than 4 bytes.  Also, a bare numeric literal does not make it obvious how the programmer got that number. (You would have to declare a symbolic constant, which takes up more space.)_
4. In the first statement in `main`, the square brackets are empty.  Why?  What other options does the programmer have to accomplish the same thing?  And what are the advantages of accomplishing it this way?
> _You can leave the square brackets empty if you initialize an array with an initialization list.  The compiler counts the number of elements for you and uses that number to allocate the right amount of space in memory. You could also count the number of elements and insert that number as a numeric literal explicitly into the square brackets.  Or you could first decide how many elements you want the array to be able to hold and declare the local constant  `num_primes` before declaring the array, initializing it with a numeric literal. Three advantages to doing things the way shown above are (a) that letting the compiler count the number of elements for you allows you to avoid counting errors; (b) the compiler will always make an exact count, so the memory space allocated will be exactly what you need, no less and no more; (c) you can always add elements to the initialization list or remove elements from it without having to change anything else in your code._

## Practice Problem 2

Alphabetic and punctuation characters are represented internally, just like any other data, as patterns of off and on states corresponding to the 0s and 1s of binary numbers.  In particular, such characters are _encoded_ according to a scheme called ASCII (American Standard Code for Information Interchange) that maps each character to a number between 0 and 127 (inclusive).  The binary forms of these numbers determine the electronic off-and-on patterns in memory.  You can see the ASCII encoding by entering `man ascii` at the command line.

With these facts in mind, consider the following program:
```
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    const char greeting[] = {72, 101, 108, 108, 111, 33};
    const int num_chars = sizeof(greeting);
    for (int i = 0; i < num_chars; ++i) {
        cout << greeting[i];
    }
    cout << endl;
    return EXIT_SUCCESS;
}
```
1. What would you guess the above program prints to the command line?
 > _It prints `Hello` ._
2. Build and run the program to test your hypothesis.
> _(Build and run.)_
3. Does it run normally?  If so, why is the use of `sizeof` OK to determine the iteration bound in this case?
> _Because `char` always has a size of one byte._
4. Use the same technique (however tedious, granted) to print out the message, "Go Eagles!" — build and test.
> ```
> #include <cstdlib>
> #include <iostream>
> 
> using namespace std;
> 
> int main() {
>     const char greeting[] = {71, 111, 32, 69, 97, 103, 108, 101, 115, 33};
>     const int num_chars = sizeof(greeting);
>     for (int i = 0; i < num_chars; ++i) {
>         cout << greeting[i];
>     }
>     cout << endl;
>     return EXIT_SUCCESS;
> }
> 
> ```


## Practice Problem 3
As you may recall, you can choose from three different techniques to represents strings (sequences of characters) in C++:
- An array of characters initialized expicitly, either with individual values or with an initialization list.  If you need to know the length of the string, you need to keep track of that information yourself as programmer.
- A sequence of characters loaded into an array (a _buffer_) from `cin`, which automatically gets a _null termination character_ appended to the end.  The same format actually applies to _string literal_ constants, which are strings that the programmer writes in double quotation marks, such as the "Hello, world!" message in the first program presented in our textbook.  (That is, "Hello, world!" contains a hidden null termination character at the end.) In this case, you can always find out the length of the string by counting characters from the beginning up to (but not including) the null termination character.
- An instance of the C++ **string** class, initialized either with a string literal or from `cin`.  In this case, you can get the length of the string by calling its `length` function.

For this exercise, let us focus on the use of an array initialized from `cin`.

1. Write a program that prompts the user for a string and then reports the string's length.  Assume that the user will not include spaces in the input string. How can you use the null termination character to help you to determine the string's length?
> ```
> #include <cstdlib>
> #include <iostream>
> 
> using namespace std;
> 
> int main() {
>     const int max_length = 256;
>     char buffer[max_length] = {'\0'};
>     cout << "Enter a string of no more than " << max_length - 1 << " characters."
>         << endl;
>     cout << "> ";
>     cin >> buffer;
>     int length = 0;
>     while (buffer[length]) {
>         ++length;
>     }
>     cout << "Your string, \"" << buffer << ",\" contains " << length << 
>         " characters." << endl;
>     return EXIT_SUCCESS;
> }
> ```


2. Suppose you wish to use no more than 128 bytes to store the input. What is the maximum length of a string that the user should be allowed to enter?
> _The maximum length must be 127 characters, in order to leave room for the null termination character automatically inserted by the redirection to `cout`._

3. Modify your program so that it repeats the steps — prompt, count, report — until the user enters "$" (any string beginning with the character "$").  Below is exactly how a session should look if the user enters "Boston" and then "College" and then quits:
> ```
> Enter a string of no more than 255 characters, or "$" to quit.
> > Boston
> Your string, "Boston," contains 6 characters.
> 
> Enter a string of no more than 255 characters, or "$" to quit.
> > College
> Your string, "College," contains 7 characters.
> 
> Enter a string of no more than 255 characters, or "$" to quit.
> > $
> ```
> ```
> #include <cstdlib>
> #include <iostream>
> 
> using namespace std;
> 
> int main() {
>     const int max_length = 256;
>     char buffer[max_length] = {'\0'};
>     cout << "Enter a string of no more than " << max_length - 1 << " characters, "
>         "or \"$\" to quit." << endl;
>     cout << "> ";
>     cin >> buffer;
>     while (buffer[0] != '$') {
>         int length = 0;
>         while (buffer[length]) {
>             ++length;
>         }
>         cout << "Your string, \"" << buffer << ",\" contains " << length << 
>             " characters." << endl;
>         cout << endl;
>         cout << "Enter a string of no more than " << max_length - 1 << " characters, "
>             "or \"q\" to quit." << endl;
>         cout << "> ";
>         cin >> buffer;
>     }
>     return EXIT_SUCCESS;
> }
> ```
4. If the user enters a string of 256 characters or more, what can we expect to happen?
> _We cannot have any expectations in this case: writing past the end of an array results in undefined behavior.  This is one of several reasons to prefer using the C++ std::string class when possible._

