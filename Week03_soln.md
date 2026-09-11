# Discussion Problems Week 3 — Solutions

So far in the course, you have learned about the Terminal, Vim, and a the basics of C++. These practice problems focus on these topics.

## Practice Problem 1

The following C++ program is intended to print out the value of `22/7`, which is a pretty good approximation to π. The program contains some mistakes.

```
#include iostream
using namespace std;
int main() {
    cout < 22/7 < endl;
    return 0;
}
```

1. First identify the mistakes (there are four in total, depending on how you count). To practice reading code carefully, try to identify them without compiling the program (three are compiler errors and one is a "bug").

> ### Solution
> The mistakes are missing angle brackets around `iostream`, using only `<` instead of `<<` both times in the output line, and finally `22/7` gets rounded down, so we need to do something like `22.0/7` instead.

2. Now let's practice using vim to fix the mistakes. If you were to open this file (cursor starts top left), what sequence of keystrokes would fix all the mistakes? Write out your sequence explicitly, and try to be efficient (no less than 30 keys are needed). No arrow keys. You can type `Esc` for the escape key.

Try to do this problem at first without actually running vim. Then test out your answer and see if it worked as you expected (don't feel bad if you made some mistakes).

Try out your neighbor's solution too! There's more than one way to do it.

> ### Solution
> Here's one vim keystroke sequence to fix it (using `#` for comments):
> 
> ```
> wwi<Esc9la>Esc     # Here fixing the angle brackets
> 3jhi<Esc           # Fixing the latter stream insertion operator
> 3bi.0Esc           # Adding a .0 to the 22
> 3bi<               # Fixing the first stream insertion operator
> ```

## Practice Problem 2
Assume we have variables `int x` and `int y`. Later in the program we need to check some conditions. Practice writing the following `if` statements (just the `if (condition)` part).

1. Write an `if` statement that checks if either of `x` or `y` is negative.

> ### Solution
> All of these solutions will use `&&` and `||` for AND and OR. It is also correct to write `and` and `or` instead. 
> 
> `if (x < 0 || y < 0)`

2. Write an `if` statement that checks if `x` is a positive number less then 100. We do not consider 0 to be positive.

> ### Solution
> `if (x > 0 && x < 100)`

3. Write an `if` statement that checks if both `x` and `y` are between `50` and `60` inclusive.

> ### Solution
> `if (x >= 50 && x <= 60 && y >= 50 && y <= 60)`

4. Write an `if` statement that checks if `x` is not between `50` and `60` inclusive. 

> ### Solution
> `if (!(x >= 50 && x <= 60))`
> another way to do this is
> `if (x < 50 || x > 60))`

5. Repeat the previous problem, but do it in a different way. If you used an AND before, then find a way to use an OR instead, and vice versa. The key is to use `!`.

> ### Solution
> The two ways are:
> `if (!(x >= 50 && x <= 60))`
> and
> `if (x < 50 || x > 60))`



## Practice Problem 3

Make Rock Paper Scissors in C++! This is a great exercise for working with `if` statements and loops. This is no small feat: your program will probably be almost 100 lines long, but by the end you'll have a fun game to play with. Here is an example session:

```
~/Desktop/cs2 $ g++ -o rps rock_paper_scissors.cpp
~/Desktop/cs2 $ ./rps
Welcome to Rock Paper Scissors!
Choose your next move:
0) Rock
1) Paper
2) Scissors
3) Quit
1
You chose Paper.
CPU chose Rock.
You won!

Choose your next move:
0) Rock
1) Paper
2) Scissors
3) Quit
1
You chose Paper.
CPU chose Paper.
You tied!

Choose your next move:
0) Rock
1) Paper
2) Scissors
3) Quit
1
You chose Paper.
CPU chose Scissors.
You lost!

Choose your next move:
0) Rock
1) Paper
2) Scissors
3) Quit
3
Goodbye!
```

1. In this first draft, make the CPU player simply cycle between `Rock` then `Paper` then `Scissors`. We will enhance that in part 2. 

Some tips:

- Declare two variables `int user_choice` and `int cpu_choice`. Then you can use the numbers `0`, `1`, or `2` to represent Rock, Paper, and Scissors. Don't try to use string variables (even if you know about those already).
    - For readability, it's a good idea to define three constants `const int ROCK = 0;` and `const int SCISSORS = 1;` and `const int PAPER = 2`. For example, we can check if CPU chose rock with `if (cpu_choice == ROCK)`. It's just more readable that way.

- You'll need to write out several `if` statements to determine the winner. First, check if it's a tie (this is the easiest case to handle). But if it's not a tie, then you'll have three cases: depending on if `cpu_choice` is `ROCK` or `PAPER` or `SCISSORS`. Each of those cases will have two sub-cases, one where `You won!` and one where `You lost!`.
    - There may be more concise ways of determining the winner, but let's go with this basic `if` approach for practice.

> ### Solution
> ```cpp
> #include <iostream>
> 
> using namespace std;
> 
> const int ROCK = 0;
> const int PAPER = 1;
> const int SCISSORS = 2;
> 
> int main() {
>     cout << "Welcome to Rock Paper Scissors!" << endl;
>     int user_choice = -1;
>     int cpu_choice = 0;
>     while (true) {
>         cout << "Choose your next move: " << endl;
>         cout << "0) Rock" << endl;
>         cout << "1) Paper" << endl;
>         cout << "2) Scissors" << endl;
>         cout << "3) Quit" << endl;
>         cin >> user_choice;
>         if (user_choice == 3) {
>             break;
>         }
> 
>         // Printing user_choice
>         if (user_choice == ROCK) {
>             cout << "You chose Rock" << endl;
>         }
>         else if (user_choice == PAPER) {
>             cout << "You chose Paper" << endl;
>         }
>         else {
>             cout << "You chose Scissors" << endl;
>         }
> 
>         // Printing cpu_choice
>         if (cpu_choice == ROCK) {
>             cout << "CPU chose Rock" << endl;
>         }
>         else if (cpu_choice == PAPER) {
>             cout << "CPU chose Paper" << endl;
>         }
>         else {
>             cout << "CPU chose Scissors" << endl;
>         }
> 
>         // Determining the winner
>         if (cpu_choice == user_choice) {
>             cout << "You tied!" << endl;
>         }
>         else if (cpu_choice == ROCK) {
>             if (user_choice == PAPER) {
>                 cout << "You won!" << endl;
>             }
>             else {
>                 cout << "You lost!" << endl;
>             }
>         }
>         else if (cpu_choice == PAPER) {
>             if (user_choice == SCISSORS) {
>                 cout << "You won!" << endl;
>             }
>             else {
>                 cout << "You lost!" << endl;
>             }
>         }
>         else {
>             if (user_choice == ROCK) {
>                 cout << "You won!" << endl;
>             }
>             else {
>                 cout << "You lost!" << endl;
>             }
>         }
>         cout << endl;
>         cpu_choice = (cpu_choice + 1) % 3; // cycling 0,1,2,0,1,2,...
>     }
>     cout << "Goodbye!" << endl;
>     return 0;
> }
> ```
> 


2. Make the following enhancements to Rock Paper Scissors:

- Make the CPU choice effectively random instead of following the simple cyclic pattern.
- If you user misbehaves and enters anything other than `0`, `1`, or `2`, then quit the program.

It doesn't take a lot of code to add these enhancements, but you'll need to learn some background first. Here's the info you need:

- To generate random numbers in C++, we call `rand()` (from the `cstdlib` system header). Actually `rand()` may return any integer number between `0` and `RAND_MAX` (a constant also defined in `cstdlib`). Therefore, in this case, we should use `rand() % 3` to get either `0`, `1`, or `2`. 
- You'll also want to seed the random number generator in the beginning so the results change with each run. It's common to use the system clock for that, which is done with `srand(time(NULL))` (the `time()` function comes from `ctime` system header).
- When the user enters a non-integer, then `cin` will enter a fail state, which you can check with `cin.fail()` (returns a `bool`).

> ### Solution
> ```cpp
> #include <iostream>
> #include <cstdlib>
> #include <ctime>
> 
> using namespace std;
> 
> const int ROCK = 0;
> const int PAPER = 1;
> const int SCISSORS = 2;
> 
> int main() {
>     srand(time(NULL));
> 
>     cout << "Welcome to Rock Paper Scissors!" << endl;
>     int user_choice = -1;
>     int cpu_choice = rand() % 3;
>     while (true) {
>         cout << "Choose your next move: " << endl;
>         cout << "0) Rock" << endl;
>         cout << "1) Paper" << endl;
>         cout << "2) Scissors" << endl;
>         cout << "3) Quit" << endl;
>         cin >> user_choice;
>         if (user_choice < 0 or user_choice > 2 or cin.fail()) {
>             break;
>         }
> 
>         // Printing user_choice
>         if (user_choice == ROCK) {
>             cout << "You chose Rock" << endl;
>         }
>         else if (user_choice == PAPER) {
>             cout << "You chose Paper" << endl;
>         }
>         else {
>             cout << "You chose Scissors" << endl;
>         }
> 
>         // Printing cpu_choice
>         if (cpu_choice == ROCK) {
>             cout << "CPU chose Rock" << endl;
>         }
>         else if (cpu_choice == PAPER) {
>             cout << "CPU chose Paper" << endl;
>         }
>         else {
>             cout << "CPU chose Scissors" << endl;
>         }
> 
>         // Determining the winner
>         if (cpu_choice == user_choice) {
>             cout << "You tied!" << endl;
>         }
>         else if (cpu_choice == ROCK) {
>             if (user_choice == PAPER) {
>                 cout << "You won!" << endl;
>             }
>             else {
>                 cout << "You lost!" << endl;
>             }
>         }
>         else if (cpu_choice == PAPER) {
>             if (user_choice == SCISSORS) {
>                 cout << "You won!" << endl;
>             }
>             else {
>                 cout << "You lost!" << endl;
>             }
>         }
>         else {
>             if (user_choice == ROCK) {
>                 cout << "You won!" << endl;
>             }
>             else {
>                 cout << "You lost!" << endl;
>             }
>         }
>         cout << endl;
>         cpu_choice = rand() % 3;
>     }
>     cout << "Goodbye!" << endl;
>     return 0;
> }
> ```
> 

(In C programs, we would actually need to include `stdlib.h` and `time.h`, but in C++ programs, it's conventional to call them `cstdlib` and `ctime` instead. This reminds the programmer that these headers come from C and not C++.)
