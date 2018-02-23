## Homework 3

### C Exercises

Modify the link below so it points to the `ex03` directory in your
student repository.

[Here is a link to the ex03 directory in my repository](https://github.com/shrutiyer/ExercisesInC/tree/master/exercises/ex03)

### Think OS Chapter 4 reading questions

**Files and file systems**

1) What abstractions do file systems provide?  Give an example of something that is logically 
true about files systems but not true of their implementations.

    Ans. Looking at a file system with its abstractions, the file name and the file contents look 
    like they are key-value pairs. The file also appears like it is a sequence of bytes. It is 
    logically true that files are byte-based but in reality, the persistent storage is block-based.  

2) What information do you imagine is stored in an `OpenFileTableEntry`?

    Ans. The data structure would probably contain the contents of the file, the pointer that 
    keeps track of how much of the file has been read, and file name, file type, the owners and 
    members, etc.

3) What are some of the ways operating systems deal with the relatively slow performance of persistent storage?

    Ans. If a file needs data from the slow persistent storage, the operating system will interrupt 
    the process until the I/O request to get data from the disk is complete and instead run other processes 

4) Suppose your program writes a file and prints a message indicating that it is done writing.  
Then a power cut crashes your computer.  After you restore power and reboot the computer, you find that the 
file you wrote is not there.  What happened?

    Ans. The file contents might have been saved in memory if it was going to occupy less than a block 
    on the disk. Once there is at least a block worth of memory to write, the file will be saved 
    permanently on the disk. The power cut might have happened before the OS had a chance to write 
    that block.

5) Can you think of one advantage of a File Allocation Table over a UNIX inode?  Or an advantage of a inode over a FAT?

    Ans. File Allocation Table has all the file information it needs inside one table whereas UNIX inode 
    has information distributed into many different indirection blocks. UNIX inode might be faster since 
    contents of the files are located next to each other but the same cannot be promised of FAT system.

6) What is overhead?  What is fragmentation?

    Ans. Overhead is the extra resource (usually memory or time) that are required for proper functioning 
    of a certain task. Fragmentation is when storage space within a system is inefficiently used.

7) Why is the "everything is a file" principle a good idea?  Why might it be a bad idea?

    Ans. Because of that principle, we can treat everything as stream of bytes. The output from one 
    program or process could be directed as an input to another program or process. That way, programs 
    don't need to be specific about how they are reading or writing data. One of the reasons it might be 
    a bad idea is when the output from one program needs to be personalized according to the receiving program.

If you would like to learn more about file systems, a good next step is to learn about journaling file systems.  
Start with [this Wikipedia article](https://en.wikipedia.org/wiki/Journaling_file_system), then 
[Anatomy of Linux Journaling File Systems](http://www.ibm.com/developerworks/library/l-journaling-filesystems/index.html).  
Also consider reading [this USENIX paper](https://www.usenix.org/legacy/event/usenix05/tech/general/full_papers/prabhakaran/prabhakaran.pdf).




