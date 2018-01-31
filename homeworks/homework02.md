## Homework 2

### C Exercises

Modify the link below so it points to the `ex02` directory in your
student repository.

[Here is a link to the ex02 directory in my
repository](https://github.com/shrutiyer/ExercisesInC/tree/master/exercises/ex02)

### Think OS Chapter 2 reading questions

For each of the reading questions below, write answers in the form of
a clear, concise, complete sentence or two.

1) Give a real-world example of virtualization (ideally not one of
the ones in the book).  What is abstractly true about the system that
is not literally true about the implementation?

Ans. When I transfer money from one bank account to another bank account, I
should see the money in the other account with just a click of a button.       
Abstractly, it seems like a simple money deducted from one bank gets transfered
directly to the other bank (with some delay). But, in reality, there is request
for the money transfer that needs to be sorted by the Automated Clearing House
(ACH) that processes the request and transfers the money to the other account
all abstracted out from the customer.

2) What is the difference between a program and a process?

Ans. A program is a set of instructions whereas a process is the program in
action.

3) What is the primary purpose of the process abstraction?

Ans. By abstracting a process, the program (and the programmers) doesn't need to
figure out the details of the device hardware, virtual memory or sharing run-time
with other programs. The process abstraction simplifies the knowledge required for
a program to run.

4) What illusion does the process abstraction create?

Ans. When a program runs, the process abstraction makes it seem like the program
has all the memory on a machine available and no interruptions while the program
is running. In reality, memory is allocated according to the program needs while
it is running and the OS will interrupt the process, save its state for restarting
it later.

5) What is the kernel?

Ans. The kernel is the core of the operating system that performs many important 
functionalities crucial to a proper functioning operating system.

6) What is a daemon?

Ans. A daemon is a process that runs in the background, without any direct control 
from the user.
