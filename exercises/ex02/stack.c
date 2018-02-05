/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
    int array[SIZE];          // A local array of size 5 initialized

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = 42;        // All elements of the array set to 42
    }
    return array;             // Pointer to the local array returned
}

void bar() {
    int i;
    int array[SIZE];          // A local array of size 5 initialized

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = i;         // Each element of the array set to its index
    }
}

int main()
{
    int i;
    int *array = foo();       // Receives the pointer to the array foo() created
    bar();                    // bar() possibly replaces foo() on the stack

    for (i=0; i<SIZE; i++) {  // Reads from an illegal address space and segfaults
        printf("%d\n", array[i]);
    }

    return 0;
}
