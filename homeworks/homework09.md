## Homework 9

### C Exercises

Modify the link below so it points to the `ex09` directory in your
student repository.

[Here is a link to the ex09 directory in my repository](https://github.com/shrutiyer/ExercisesInC/tree/master/exercises/ex09)

### Think OS Chapter 9 reading questions

1) Why does each thread have its own stack?

Each thread is sort of like its own process and doesn't want to disturb other running threads and processes. So, it has its own thread.

2) What does the gcc flag `-lpthread` do?

It links the pthread library to the code.

3) What does the argument of `pthread_exit` do?

`pthread_exit` can be used to pass a value to a thread that joins with the thread.

4) Normally the same thread that created a thread also waits to join it.
What happens if another thread tries to join a thread it did not create?

The thread trying to join another thread (that was not created by it) will succeed if it uses the right function calls. All threads are allowed to join other threads.

5) What goes wrong if several threads try to increment a shared integer at the same time?

Multiple different threads should not be changing the same shared integer value since it can lead to the integer getting incremented chaotically and randomly, sometimes two threads trying to increment at the same time.

6) What does it mean to "lock a mutex"?

When a mutex gets locked, it bars other threads from accessing the value and only allows the current thread to access and update it.
