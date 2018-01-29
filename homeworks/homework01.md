## Homework 1

### C Exercises

Modify the link below so it points to the `ex01` directory in your
student repository.

[Here is a link to the ex01 directory in my repository](https://github.com/shrutiyer/ExercisesInC/tree/master/exercises/ex01)

### Think OS Chapter 1 reading questions

For each of the reading questions below, write answers in the form of
a clear, concise, complete sentence or two.

1) Give an example of a feature common in interpreted languages that is rare in
 compiled languages.

Ans. All errors in interpreted languages are always found at run-time because
they are statically typed (unless you are using an IDE) while many errors can be
 found in compiled languages during compilation.

2) Name two advantages of static typing over dynamic typing.

Ans. a) Static typed languages take up less space in memory during runtime when
compared to dynamic typed languages.
b) The code becomes easier to read and understand since all variables have types
declared and all functions have types for inputs and outputs.

3) Give an example of a static semantic error.

Ans. When a function is declared using the following definition:
```c
void foo(int some_int) {
  ...
}
```
But, when the function is actually called from outside, wrong type (maybe a char
array) of argument is passed.

4) What are two reasons you might want to turn off code optimization?

Ans. a) During debugging, a programmer might want to make sure that no weird
optimizations is causing an undesirable behavior or a bug.
b) Many times, the inner workings of a optimization is a black-box which makes
it hard to check if there are in any bugs in the optimization algorithm itself.

5) When you run `gcc` with `-S`, why might the results look different on different computers?

Ans. `gcc` creates assembly language code depending on the architecture of the
machine the programmer is working on. So, an x86 architecture machine will be
different from an ARM architecture.

6) If you spell a variable name wrong, or if you spell a function name wrong, the error messages you get might look very different.  Why?

Ans. When a variable is misspelled, the error says that the variable is an
undeclared reference. When a function name is misspelled, the error says that
it is an implicit declaration. It is because the linker is looking for the
function in the standard libraries.

7) What is a segmentation fault?

Ans. Segmentation fault occurs when the program tries to read or write to an
incorrect memory location.
