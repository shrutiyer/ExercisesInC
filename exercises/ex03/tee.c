/*
 *  This program is the implementation of command `tee`.
 *  Only includes the flag `a`.
 *  For more info, read http://man7.org/linux/man-pages/man1/tee.1.html

 *  Author: Shruti Iyer (shrutiyer)
*/

/*  3)
 *  I have never used or even heard about the command `tee`. So the initial
 *  hurdle was to learn how the command can be used. Once, I understood that,
 *  the problem decomposition became really easy. The overall implementation of
 *  the program required a bit of searching online and a little bit of debugging.
 *  I did wasted a little time when I was incorrectly running the actual UNIX
 *  command tee instead of my implementation. Next time, I would name my
 *  implementation with a different name to avoid confusion and waste of time.

 *  4)
 *  When comparing to the professional implementation of the command, there are
 *  a lot neater organization and setup with the use of structs and arrays.
 *  They also have additional flags that can be used with the command `tee`.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void main(int argc, char *argv[]) {
    FILE *file_read;
    FILE *file_write[argc];
    char buffer;

    int opt;
    int append = 0;

    // Check for the appropriate number of arguments
    if (argc < 2){
        printf("Incorrect number of arguments given to the command");
        exit(0);
    }

    // Checking for the command-line argument `a`
    while ((opt = getopt(argc, argv, "a")) != -1) {
        append = 1;
    }

    // Read from stdin
    file_read = stdin;
    if (file_read == NULL) {
        printf("Standard Input is NULL");
        exit(0);
    }

    // Create new files according to the number that user inputed
    for (int file_count=1+append; file_count<argc; file_count++) {
        if (append) {
            file_write[file_count] = fopen(argv[file_count], "a");
        } else {
            file_write[file_count] = fopen(argv[file_count], "w");
        }
    }

    // Continue reading until end of file for stdin
    while (!feof(file_read)) {
        buffer = getc(file_read);
        printf("%c", buffer);
        // Write the stdout and to all the files
        for (int file_count=1+append; file_count<argc; file_count++) {
            fputc(buffer, file_write[file_count]);
        }
    }

    // Close all files
    fclose(file_read);
    for (int file_count=1+append; file_count<argc; file_count++) {
        fclose(file_write[file_count]);
    }
}
