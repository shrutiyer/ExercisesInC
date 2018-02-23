## Homework 2.5

### C Exercises

Modify the link below so it points to the `ex02.5` directory in your
student repository.

[Here is a link to the ex02.5 directory in my repository](https://github.com/YOUR_GITHUB_USERNAME_HERE/ExercisesInC/tree/master/exercises/ex02.5)

### Think OS Chapter 3 reading questions

### Virtual memory

1) The Georgian alphabet has 33 letters.  How many bit are needed to specify a letter?

    Ans. Since 2^6 bits are needed to specify 64 values, 6 bits will be required to specify a letter in the Georgian alphabet. 

2) In the UTF-16 character encoding, the binary representation of a character can take up to 32 bits.  
Ignoring the details of the encoding scheme, how many different characters can be represented?

    Ans. Using 32 bits, a total of 2^32 values (= 4294967296) can be represented in the UTF-16 character encoding.

3) What is the difference between "memory" and "storage" as defined in *Think OS*?

    Ans. In *Think OS*, "memory" refers to the random access memory that stores most of the data for an active process. 
    Whereas, "storage" means the disk to which a process reads or writes files.

4) What is the difference between a GiB and a GB?  What is the percentage difference in their sizes?

    Ans. GiB is the size of the main "memory" in binary units and GB is the size of the "storage" in decimal units.
    GiB is 2^30 bytes (or 1,073,741,824 bytes) and GB is 10^9 bytes (or 1,000,000,000 bytes). The percent difference 
    between their sizes is 6.867% (when compared to 2^30 bytes) and 7.37% (when compared to 10^9 bytes).
    
    *Source:https://en.wikipedia.org/wiki/File_size*

5) How does the virtual memory system help isolate processes from each other?

    Ans. Each process has a separate virtualized memory system that gets translated to the physical address. One process
    cannot access the virtual address space of another process, hence isolating processes.  

6) Why do you think the stack and the heap are usually located at opposite ends of the address space?
    
    Ans. Heap and stack need to increase and decrease their size as different programs need. So, it is necessary to put them 
    in the opposite ends so that the space in between is divided according to the program being run and to avoid any clash.

7) What Python data structure would you use to represent a sparse array?

    Ans.  A `dict` where the keys contain the virtual page number and page offset in a tuple and the the value is the physical address.

8) What is a context switch?

    Ans. When the OS pauses a running process and saves its state to make way to run a different process, a "context switch" occurs.

