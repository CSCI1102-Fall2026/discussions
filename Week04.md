# CSCI1102 Discussion Section — Week 4

## 1. Overview

The goal this week is to practice `for` loops in C++. As discussed in class, you can always use a `while` loop instead of a `for` loop. For these problems, use `for` loops specifically to get comfortable with them.

## 2. Problem A: `pi.cpp`

Write a program that uses the **Leibniz formula** to approximate pi. Here are some examples (user inputs are shown as entered after the prompts):

```text
[user@cslabv2 discussions]$ ./pi
Enter k: -1
k must be at least zero!

[user@cslabv2 discussions]$ ./pi
Enter k: 1
0: ~4.0000000000
1: ~2.6666667461

[user@cslabv2 discussions]$ ./pi
Enter k: 20
0: ~4.0000000000
1: ~2.6666667461
2: ~3.4666666985
3: ~2.8952381611
4: ~3.3396825790
5: ~2.9760463238
6: ~3.2837386131
7: ~3.0170719624
8: ~3.2523660660
9: ~3.0418398380
10: ~3.2323160172
11: ~3.0584030151
12: ~3.2184031010
13: ~3.0702550411
14: ~3.2081861496
15: ~3.0791537762
16: ~3.2003657818
17: ~3.0860800743
18: ~3.1941881180
19: ~3.0916240215
20: ~3.1891849041
[user@cslabv2 discussions]$
```

This is the formula (from Wikipedia):

$$
\frac{\pi}{4}
= 1 - \frac{1}{3} + \frac{1}{5} - \frac{1}{7} + \frac{1}{9} - \cdots
= \sum_{k=0}^{\infty} \frac{(-1)^k}{2k+1}
$$

When `k = 0`, it's only the first term in the series, which is 1. You then multiply that by 4 to get the approximation of 4. When `k = 1`, it's $1 - \frac{1}{3}$, which is $\frac{2}{3}$, then multiply by 4 to get $2\frac{2}{3}$.

The summation formula is the easiest way to approach this. Simply start with your approximation at zero, then loop over the `k` values and add the kth term to the approximation. Don't forget to multiply by 4 for each output.

The program will print out each approximation as it is computed, to **10 decimal places**. You must do error checking that `k` is a valid input before proceeding. As always, make sure your input and output messages match the example above.

## 3. Problem B: `count_digits.cpp`

Write a program that allows the user to input a series of positive integers and prints how many digits were in the longest and shortest numbers. Here are some examples (user inputs are shown as entered after the prompts):

```text
[user@cslabv2 discussions]$ ./count_digits
Enter n (positive): 0
n must be positive!

[user@cslabv2 discussions]$ ./count_digits
Enter n (positive): 4
Now enter 4 positive integers:
12
3456
789
4
The longest number had 4 digits.
The shortest number had 1 digit.
[user@cslabv2 discussions]$ ./count_digits
```

```text
Enter n (positive): 2
Now enter 2 positive integers:
0
Skipping non-positive value
-1
Skipping non-positive value
No valid numbers entered!
[user@cslabv2 discussions]$ ./count_digits
```

```text
Enter n (positive): 3
Now enter 3 positive integers:
123456789
0
Skipping non-positive value
12345
The longest number had 9 digits.
The shortest number had 5 digits.
[user@cslabv2 discussions]$
```

The program first prompts the user for `n`, the number of values they will enter next. If `n` is not positive, then print an error message and exit. Otherwise, read in `n` integers from the user. If any of these integers is not positive, print a warning message (see above) and keep going.

After the user has entered all `n` numbers (including non-positive values), print how many digits were in the longest and shortest numbers. You will need to include code to handle printing `"digit"` vs. `"digits"` correctly. You also need to handle the case where the user enters all invalid numbers.

As always, make sure your input and output messages match the example above.
