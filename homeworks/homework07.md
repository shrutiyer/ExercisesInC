## Homework 6

### C Exercises

Modify the link below so it points to the `ex06` directory in your
student repository.

[Here is a link to the ex07 directory in my repository](https://github.com/shrutiyer/ExercisesInC/tree/master/exercises/ex07)

### Think OS Chapter 7 reading questions

### Caching

1) What happens if a program writes a new value into the program counter?

    The next instruction to be executed will be changed to the address that the new program 
    counter is pointing to.

2) What is the fundamental problem caches are meant to solve?

    The time it takes to fetch data from memory or load data to memory is much larger than 
    the time it takes to perform an instruction. This creates a memory bottleneck where it 
    the instructions take longer to execute if every instruction needs to be loaded from memory.

3) If cache access time is 1 ns and memory access time is 10 ns, what is the average
access time of a program with hit rate 50%?  How about 90%?

    Average access time is calculated using the formula:
    ```
    average_time = hit_rate*cache_hit_time + miss_rate*cache_miss_time
    ```
    With a 50% hit rate, `average_time = 0.5 * 1 ns + 0.5 * 10 ns = 5.5 ns`
    
    With a 90% hit rate, `average_time = 0.9 * 1 ns + 0.1 * 10 ns = 1.9 ns`

4) The book gives several examples of programming language features, like loops, that tend 
to improve locality in the access pattern of instructions and/or data.  Can you think of other examples?  
Or counter-examples that might decrease locality?

    If the same variable gets used/updated by consecutive instructions within the program, the temporal locality 
    for data can be improved. If functions and/or instructions acccess variables stored in the heap, far away from 
    variables in the same function, the spacial locality can be negatively affected.

5)  If you refactor a program to improve locality, would you say the program is "cache aware"?  Why not?

    By definition, a cache aware program is one that takes advantage of a cache's behavior to improve cache hit rate. 
    So, when the program is refactored, the program is going to have better awareness of cache. But, the program will 
    not exactly know what the cache looks like.
    
    *Source:* https://stackoverflow.com/questions/473137/a-simple-example-of-a-cache-aware-algorithm

6) See if you can estimate the cost of a memory cache by comparing the prices of two similar CPUs with 
different cache sizes.

    

7) Why are cache policies generally more complex at the bottom of the memory hierarchy?

8) Can you think of a strategy operating systems could use to avoid thrashing or recover when it occurs?



