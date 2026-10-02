#  Discussion Problems Week 6

## Practice Problem 1 - Emoji Mood Translator

Write a program that asks the user to enter a number from 1 to 5, each representing a mood (emoticon):
1 → Happy :)
2 → Sad :(
3 → Angry >:(
4 → Surprised  :D
5 → Cool  ^_^


Your program should:

Use a function string getMoodEmoticon(int moodNumber) that takes the number and returns the corresponding emoji as a string.
In main(), ask the user for a number, call the function, and print the result.
If the number is not between 1 and 5, return "Invalid mood!".
Example:
```
Enter a number (1-5) to select your mood: 4
Your mood is: :D
```

## Practice Problem 2 - Echo Machine

Write a program that asks the user for their first name and a number n.

Implement a function void echoName(string name, int n) that prints the name n times, one per line.

In main(), ask the user for input and call the function.

Example:
```
Enter your first name: Alex
How many times should I echo it? 3
Alex
Alex
Alex
```

## Practice Problem 3 - Secret Code Reverser

Write a program that encodes a secret word by reversing it.

Implement a function string reverseWord(string word) that returns the reversed string.

In main(), ask the user to enter a word, call the function, and print the secret code.

Example:
```
Enter a word to encode: hello
Your secret code is: olleh
```

## Practice Problem 4 – Word Pyramid Builder

Write a program that builds a “word pyramid” from a given word.

Your program should have two functions.

Ask the user to enter a word.

Create a function called `getPrefix(string word, int length)` must return a substring of the first length letters.

The second function should be called `printWordPyramid(string word)` should call getPrefix() repeatedly inside a loop, increasing length each time.

The pyramid should grow line by line until the full word is printed.

Example:
```
Enter a word: HELLO
H
HE
HEL
HELL
HELLO
```

Example:
```
Enter a word: CAT
C
CA
CAT
```