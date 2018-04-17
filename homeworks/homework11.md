## Homework 11

### C Exercises

Modify the link below so it points to the `ex11` directory in your
student repository.

[Here is a link to the ex11 directory in my repository](https://github.com/shrutiyer/ExercisesInC/tree/master/exercises/ex11)

### Think OS Chapter 11 reading questions

1) Why is is a bad idea to pass a `sem_t` as a parameter?

By creating and passing `sem_t` as a parameter, we will be creating a copy. The behavior of copy in POSIX is undefined.

2) When you use a Semaphore as a mutex, what should its initial value be?

The initial value for a Semaphore as a mutex is __1__.

3) Can you think of another use for a Semaphore where you might use a different initial value?

If there are three chunks of memory to be used by 10 different threads, we can use a Semaphore with an initial value of __3__ so that only three threads at a time are accessing the three memory chunks.

4) In my solution to the producers-consumers problem using Semaphores,
what does it mean if the value of `queue->spaces` is `3` at some point in time?

It means that 3 threads can safely execute `queue_push`.

5) What does it mean if `queue->space` is `-3`?

It means that 3 threads are waiting to execute `queue_push`.

6) Why doesn't `queue_pop` have to use `queue_empty` to check whether the queue is empty?

The line of code `semaphore_wait(queue->items);` will wait if there are no items in the queue, essentially checking if the queue is empty,

7) Any problem that can be solved with Semaphores can also be solved with mutexes and condition variables.
How can you prove that that's true?

Semaphores only allow *n* number of threads to access some resource at a time. If we had to achieve the same with mutexes and condition variables, we can create two variables to keep track of number of threads currently running and currently waiting. And use the mutexes to protect any changes made to these two variables.

8) What is Property 3?  Hint: see *The Little Book of Semaphores*,
[Section 4.3](http://greenteapress.com/semaphores/LittleBookOfSemaphores.pdf).

Proper 3 is "If there are threads waiting on a semaphore when a
thread executes `signal`, then one of the waiting threads has to be
woken."
