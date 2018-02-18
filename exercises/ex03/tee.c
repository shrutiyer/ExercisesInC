/*
 *  This program is the implementation of command tee.
 *  For more info, read http://man7.org/linux/man-pages/man1/tee.1.html
*/

/*
 *  I have never used or even heard about the command `tee`. So the initial
 *  hurdle was to learn how the command can be used. Once, I understood that,
 *  the problem decomposition became really easy. The overall implementation of
 *  the program required a bit of searching online and a little bit of debugging.

 * 
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

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
