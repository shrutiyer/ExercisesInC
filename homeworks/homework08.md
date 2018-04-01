## Homework 8

### C Exercises

Modify the link below so it points to the `ex07` directory in your
student repository.

[Here is a link to the ex08 directory in my repository](https://github.com/shrutiyer/ExercisesInC/tree/master/exercises/ex08)

### Think OS Chapter 8 reading questions

**Multitasking**

1) What is the kernel's most basic task?

    The basic job of kernel is to handle interrupts.

2) When an interrupt occurs, what part of the hardware state is saved by hardware?

    Once all the instructions are either complete and or reversed to a state
    before it was started, the program counter is saved by the hardware.

3) What is the difference between an interrupt and a context switch?

    Interrupts occur when there is a need to stop the normal instruction cycle
    and call the "interrupt handler". Context switch happens when the kernel
    switches one process out to let another process run. In interrupts, a select
     few registers' state needs to be saved but a context switch needs the whole
     state to be saved.

4) Give an example of an event that might cause a process to move from the blocked to the ready state.

    If the process was waiting to receive user input, the process will become
    ready once it has received input from the user.

5) Why might a scheduler want to give higher priority to an I/O bound process?

    An I/O bound process might overall run faster if data input or output
    happens quicker. Hence, prioritizing that process will help it run faster.

6) When I make French toast, I usually make a batch of 12 slices.  But my griddle only has room for 8 slices.
Each piece of toast has to cook for 5 minutes on each side.  How can I schedule 12 slices onto 8 "cores"
to minimize the elapsed time to cook all 12 slices?  (Note: this question is not hypothetical;
this is really how I make French toast.)

    Let's divide the 12 slices in to batches of 4 slices, named B1, B2 and B3.

    Here is how we can schedule it.
    1. B1 B2 (for 5 mins)
    2. B1 B3 (for 5 mins)
    3. B2 B3 (for 5 mins)

    This gives each batch 10 mins total on the griddle.
