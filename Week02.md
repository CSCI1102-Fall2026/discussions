# Discussion Problems Week 2

So far in the course, you have learned about the Terminal, Vim, and a glimpse of C++. These practice problems focus on these topics.

## Practice Problem 1

Imagine opening Terminal, and suppose we wish to do the following (in this exact order):

-  Create a folder `cs2` on our Desktop (assume it doesn't exist).
-  Change current directory to the new `cs2` folder.
-  Create a file `notes.txt` within the `cs2` folder.

Let's assume your home directory is `/Users/foobar` and the Desktop folder is in the usual place, which would be `/Users/foobar/Desktop`.

Answer the following.

1.  Using only **relative paths**, what three commands need to be entered? Assume that, as usual, when we open the terminal we start in the home directory.

> ### Solution
>
> ```
> mkdir Desktop/cs2 
> cd Desktop/cs2 
> touch notes.txt
> ```

2.  Starting over, this time you can only use **absolute paths**. What three commands need to be entered?

> ### Solution
>
> ```
> mkdir /Users/foobar/Desktop/cs2 
> cd /Users/foobar/Desktop/cs2 
> touch /USers/foobar/Desktop/notes.txt
> ```

3.  Suppose we swap the order of the last two tasks (so, we must create the `notes.txt` file before changing current directory). How would this change your answers to the previous two questions?

> ### Solution
>
> For absolute paths, we just interchange the last two commands from the previous answer: 
> ```
> mkdir /Users/foobar/Desktop/cs2 
> touch /Users/foobar/Desktop/cs2/notes.txt 
> cd /Users/foobar/Desktop/cs2 
> ```
> 
> For relative paths, we are still in the home directory when creating `notes.txt` so note the different path in the 2nd to last line below: 
> ```
> mkdir Desktop/cs2 
> touch Desktop/cs2/notes.txt 
> cd Desktop/cs2
> ```

## Practice Problem 2

When we write a C++ program, the last line of `main()` is almost always `return 0;`. This value `0` is called the *exit status* and gets sent back to the operating system. When you run an executable from the command-line, you can inspect its exit status by running the command `echo $?` immediately after.

1.  Write a minimalist C++ program (3 lines maximum) that does nothing but return the integer `102` as its exit status. Use `echo $?` after running your executable to verify that it worked.

> ### Solution
>
> `int main() {return 102;}`

2.  Let's inspect the exit status of some other commands. What is the exit status of `g++` when the compilation succeeds? To find out, try compiling your file again with `g++`, and then run `echo $?` immediately after `g++` finishes.

> ### Solution
>
> When `g++` compiles successfully, the exit status is 0.

3.  What is the exit status of `g++` when the compilation fails? To find out, modify your C++ file so that it fails to compile (e.g. remove a semicolon). Now when you run `g++` it prints an error, but did it also change the exit status of `g++`?

> ### Solution
>
> When `g++` fails to compile, the exit status is 1.

4.  Pick another command you learned in class recently (it could be `cd` or `mkdir` for example). Experiment with it and check the exit status. Does it usually give an exit status of zero? Can you find a way to make it return a non-zero exit status?

> ### Solution
>
> Usually `cd` returns 0. But if I try to `cd` to a path that doesn't exist, then the exit status is 1.

5.  Repeat with another command (check the typical exit status, and try to make it give a non-zero exit status). What seems to be the pattern for zero vs non-zero exit status?

> ### Solution
>
> Usually `mkdir` returns 0. But if I try to `mkdir` with a path that doesn't exist, then the exit status is 1. The pattern is: the exit status of a typical command is 0 when it succeeds, and 1 (or nonzero) when there is a failure of some sort.

## Practice Problem 3
Here is the classic C++ Hello World program. Oops, I think there might be a few typos!

```
include iostream;
using std namespace;
int main():
   cout < Hello World < endl;
```

Every single line has a mistake here, can you find all the errors?

1. What is the mistake in the first line, `include iostream;`? What's the corrected line?

> ### Solution
>
> Missing punctuation including pound sign and angle brackets. Shouldn't have a semi-colon. The corrected line is `#include <iostream>`.

2. What is the mistake in the second line, `using std namespace;`? What's the corrected line?

> ### Solution
>
> The order is wrong: it should be `using namespace std;`.


3. What is the mistake in the third line, `int main():`? What's the corrected line?

> ### Solution
>
> In C++ we don't use colons to start a function (unlike Python). Instead it should be `int main() {`, and with a closing brace at the end.


4. What is the mistake in the fourth line, `cout < Hello World < endl;`? What's the corrected line?

> ### Solution
>
> We need two `<` signs for `cout`, and double quotes around Hello World. So `cout << "Hello World" << endl;`.

5. Now that you've got a working Hello World program, modify it so it outputs these five lines:

```
Mary had a little lamb
Little lamb
Little lamb
Mary had a little lamb
whose fleece was white as snow.
```

> ### Solution
>
> 
> ```
> #include <iostream>
> using namespace std;
> int main() {
>     cout << "Mary had a little lamb" << endl;
>     cout << "Little lamb" << endl;
>     cout << "Little lamb" << endl;
>     cout << "Mary had a little lamb" << endl;
>     cout << "whose fleece was white as snow." << endl;
>     return 0;
> }
> ```
        
