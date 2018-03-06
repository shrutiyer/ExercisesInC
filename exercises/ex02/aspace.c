/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

void print_local_var_address() {
    int local_var = 5;
    printf ("Address of local_var is %p\n", &local_var);
}

int main ()
{
    int var2 = 5;
    void *p = malloc(128);
    char *s = "Hello, World";

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    printf ("p points to %p\n", p);
    printf ("s points to %p\n", s);

    print_local_var_address();

    void *random_memory_1 = malloc(2);
    void *random_memory_2 = malloc(2);
    printf ("Address of random_memory_1 is %p\n", random_memory_1);
    printf ("Address of random_memory_2 is %p\n", random_memory_2);

    return 0;
}
