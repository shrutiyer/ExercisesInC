/*
 *  This program is the implementation of command tee.
 *  For more info, read http://man7.org/linux/man-pages/man1/tee.1.html
*/

/*
 *  I have never used or even heard about the command `tee`. So the initial
 *  hurdle was to learn how the command can be used. Once, I understood that,
 *  the problem decomposition became really easy. The overall implementation of
 *  the program required a bit of searching online and a little bit of debugging.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int argc, char **argv[]) {
    FILE *file_read;
    FILE *file_write;
    char buffer;

    // Check for the appropriate number of arguments
    if(argc != 3){
        printf("Incorrect number of arguments given to the command");
        exit(0);
    }

    // TODO: Check if stdin is null



    file_read = fopen(*argv[1], "r");
    file_write = fopen(*argv[2], "w");

    while (!feof(file_read)) {
        buffer = fgetc(file_read);
        printf("%c", buffer);
        fputc(buffer, file_write);
    }

    fclose(file_read);
    fclose(file_write);
}
