/* Test code for the library util.c

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "trout/util.c"
#include "minunit.h"

int tests_run = 0;

static char *test1() {
    int* res = Calloc(1, sizeof(int));
    char *message = "test1 failed: Calloc(1, sizeof(int)) should return a pointer to an int 0";
    mu_assert(message, *res == 0);
    return NULL;
}

static char * all_tests() {
    mu_run_test(test1);
    return NULL;
}

int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != NULL) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}
