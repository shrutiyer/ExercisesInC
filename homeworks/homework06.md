## Homework 6

### C Exercises

Modify the link below so it points to the `ex06` directory in your
student repository.

[Here is a link to the ex06 directory in my repository](https://github.com/shrutiyer/ExercisesInC/tree/master/exercises/ex06)

### Think OS Chapter 6 reading questions

**Memory management**

1) Which memory management functions would you expect to take constant time?
Which ones take time proportional to the size of the allocated chunk?

`malloc` and `free` take constant time while `calloc` and `realloc` probably take proportional time.

2) For each of the following memory errors, give an example of something that might go wrong:

a) Reading from unallocated memory.

Either read some random/old stored value or segmentation fault will occur.

b) Writing to unallocated memory.

Writing to an unallocated memory might go undetected for a long time before it is read and starts 
creating problems. It might also overwrite some of `malloc` and `free`'s data structures.

c) Reading from a freed chunk.

In one scenario, there might be valid data still present at the freed chunk causing no error. In other 
cases, the freed chunk might have gotten allocated to other data resulting in undesirable behaviors.

d) Writing to a freed chunk.

Writing to a freed chunk might not guarantee that you will be able to read from the chunk at a later 
point in time. The chunk might also get allocated to a different variable and writing to it will 
overwrite what belongs to other variables.

e) Failing to free a chunk that is no longer needed.

If a chunk that is no longer needed is still occupying space in the heap, the size of the heap will keep 
growning with less space available for other variables there. This might slow down the whole program if 
it runs for a long enough time.

3) Run

```
    ps aux --sort rss
```

to see a list of processes sorted by RSS, which is "resident set size", the amount of physical 
memory a process has.  Which processes are using the most memory?

Firefox and Atom are using the most memory right now.

4) What's wrong with allocating a large number of small chunks?  What can you do to mitigate the problem?

The problem with allocation a large number of small chunks, the heap might get fragmented with the free 
space broken into small pieces.

If you want to know more about how malloc works, read 
[Doug Lea's paper about dlmalloc](http://gee.cs.oswego.edu/dl/html/malloc.html)
