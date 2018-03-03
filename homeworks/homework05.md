## Homework 5

### C Exercises

Modify the link below so it points to the `ex05` directory in your
student repository.

[Here is a link to the ex05 directory in my repository](https://github.com/shrutiyer/ExercisesInC/tree/master/exercises/ex05)

### Think OS Chapter 5 reading questions

**Bits and bytes**

1) Suppose you have the value 128 stored as an unsigned 8-bit number.  What happens if you convert
it to a 16-bit number and accidentally apply sign extension?

  An unsigned 8-bit number 128 in binary is 1000 0000. If sign extension is accidentally applied, the leftmost bit will be interpreted as the signed bit and extended to 16 bits to a new number 1111 1111 1000 0000.

2) Write a C expression that computes the two's complement of 12 using the XOR bitwise operator.
Try it out and confirm that the result is interpreted as -12.

12 = 0000 1100
1111 1111 = 255

```c
#include <stdio.h>
/* This program finds the two's complement of 12 and prints it.
*/
void main() {
  int number = 12;
  int complement = (number^255) + 1;
  printf("Two's complement %i\n", complement);
}
```

3) Can you guess why IEEE floating-point uses biased integers to represent the exponent rather than a
sign bit or two's complement?

By using an exponent bias for the signed bit, we can start using a positive number to represent even negative exponents. By using the bias, comparison between two floating-point numbers become really easy and can be done using fixed point hardware while comparing signed bit exponents are much harder.

*Source: https://en.wikipedia.org/wiki/Exponent_bias*

4) Following the example in Section 5.3, write the 32-bit binary representation of -13 in single precision
IEEE floating-point.  What would you get if you accidentally interpreted this value as an integer?

  Signed bit: 1, Exponent: 130 or 1000 0010, Coefficient: 101 0000 0000 0000 0000 0000

  -13 in IEEE floating point is 1100 0001 0101 0000 0000 0000 0000 0000

  If that number is interpreted as a plain signed integer, the number will be incorrectly interpreted as -1051721728

5) Write a function that takes a string and converts from lower-case to upper-case by flipping the sixth bit.  
As a challenge, you can make a faster version by reading the string 32 or 64 bits at a time, rather than one
character at a time.  This optimization is made easier if the length of the string is a multiple of 4 or 8 bytes.

```c
/* This program converts a string to all upper case
*/
#include <stdio.h>
#include <ctype.h>

void main() {
  char input_string[] = "foobar";
  int string_length = sizeof(input_string);

  for (int i; i<string_length); i++) {
    if (islower(input_string[i])) {
      input_string[i] = input_string[i]^32;
    }
  }
  printf("%s\n", input_string);
}
```
