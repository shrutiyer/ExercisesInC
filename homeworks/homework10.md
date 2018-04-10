## Homework 10

### C Exercises

Modify the link below so it points to the `ex12` directory in your
student repository.  That's right, Homework 10 is to do Exercise 12.

[Here is a link to the ex12 directory in my repository](https://github.com/shrutiyer/ExercisesInC/tree/master/exercises/ex12)

### Think OS Chapter 10 reading questions

1) What does it mean to say that a data structure is thread safe?

When a data structure can be accessed by many threads at the same time, it is called thread safe.

2) In the circular buffer implementation of a queue, why is the maximum number of elements in the queue `n-1`,
if `n` is the size of the array?

The empty element in the buffer helps identify between a full and an empty queue.

3) If there is no mutex to protect the queue, give an example of a sequence of steps that could leave
the queue in an inconsistent state.

When multiple threads are taking elements out of the queue while a thread is adding new elements to the queue, each thread will end up with a different version of the queue, making the data structure "thread unsafe".

4) When a thread calls `cond_wait`, why does it have to unlock the mutex before blocking?

If the thread does not unlock the mutex before blocking, no other thread will be able to access the queue. Therefore, no new items will be added or removed from the queue.

5) When a thread returns from `cond_wait`, what do we know is definitely true?  What do we think is probably true?

We know that the condition that the thread was waiting for is going to be true. The condition has probably stayed true between the cond_wait returning and the next executiion.

6) What happens if you signal a condition variable when there are no waiting threads?

Nothing happens.

7) Do you have to lock the mutex to signal a condition variable?

No.

8) Does the condition have to be true when you signal a condition variable?

Yes.
